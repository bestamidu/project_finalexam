//khai báo chi tiết hàm 
#include "function.h"
#include "globals.h"
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

void showCategoryList(Category mycategory[], int size) {
    if (size == 0) {
        printf("\nDanh sach chua duoc cap nhat\n");
        return;
    }

    printf("\n============ DANH SACH THU MUC ============\n");
    printf("| %-5s | %-25s|\n", "ID", "Category Name");
    printf("|%s|\n", "==================================");

    for (int i = 0; i < size; i++) {
       
        strtok(mycategory[i].categoryName, "\n");
        printf("| %-5s | %-25s|\n", mycategory[i].categoryId, mycategory[i].categoryName);
    }

    printf("===========================================\n");
    //goBackOrExit();
}
void addCategory(Category mycategory[] , int *size ){
	if (*size >= MAX ){
		printf("SO LUONG THEM DA DU ");
		return; 
	}
	Category newCategory;
	do {
        printf("\nNhap ID cua category (toi da 5 ky tu): ");
        fgets(newCategory.categoryId, sizeof(newCategory.categoryId), stdin);
        newCategory.categoryId[strcspn(newCategory.categoryId, "\n")] = 0; 
		
        if (strlen(newCategory.categoryId) == 0) {
            printf("ID khong duoc de trong. Vui long nhap lai.\n");
        }
    } while (strlen(newCategory.categoryId) == 0);

    do {
        printf("\nNhap NAME cua category (toi da 50 ky tu): ");
        fgets(newCategory.categoryName, sizeof(newCategory.categoryName), stdin);
        newCategory.categoryName[strcspn(newCategory.categoryName, "\n")] = 0; 

        if (strlen(newCategory.categoryName) == 0) {
            printf("Ten danh muc khong duoc de trong. Vui long nhap lai.\n");
        }
    } while (strlen(newCategory.categoryName) == 0);

    if (isDuplicateCategory(mycategory, *size, newCategory.categoryId, newCategory.categoryName, 1)) {
        printf("ID hoac ten danh muc da ton tai. Vui long nhap lai.\n");
        return;
    }
    mycategory[*size]= newCategory;
	(*size)++;
	
	writeToFile(CATEGORY_FILE_NAME, mycategory, *size);
	printf("\nban da them ID va Name thanh cong cho category!!!\n");
    printf("\n============================================\n");
    goBackOrExit();
}
    
void editCategory(Category mycategory[], int size) {
    char id[6];
    int found = 0;

    printf("\nNhap id ban muon sua category: ");
    scanf("%5s", id);
    while (getchar() != '\n');  // Xóa bộ nhớ đệm tránh lỗi nhập
	int success = 0;
    for (int i = 0; i < size; i++) {
      if (strcmp(mycategory[i].categoryId, id) == 0) {
            found = 1;
            printf("\nThong tin hien tai cua danh muc la:\n");
            printf("ID: %s, CategoryName: %s\n", mycategory[i].categoryId, mycategory[i].categoryName);

          
            printf("Moi ban nhap thong tin moi cho category:\n");
            printf("Moi ban nhap Namecategory: ");
           char newName[50];
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = 0; 
           while (strlen(newName) == 0) {
                printf("NAME khong duoc de trong. Vui long nhap lai: ");
                fgets(newName, sizeof(newName), stdin);
            	newName[strcspn(newName, "\n")] = 0; 
            }

            // kiem tra vong trung lap cua id va name 
            if (isDuplicateCategory(mycategory, size, id, newName, 2)){
                printf("Ten danh muc da ton tai. Vui long nhap lai.\n");
                return;
            }
            strcpy(mycategory[i].categoryName, newName);
            printf("Danh muc da duoc sua thanh cong!\n");
            success = 1;
            break;
        }
    }
    if(success == 1){
		writeToFile(CATEGORY_FILE_NAME, mycategory, (size));
	}

    if (!found) {
        printf("Thong tin ID ban nhap khong chinh xac.\n");
    }
    goBackOrExit();
}

void deleteCategory(Category mycategory[], int *size) {
    if (*size == 0) {
        printf("⚠ Khong co danh muc nao de xoa!\n");
        return;
    }
	char Iddelete[6];
	int found=0;
	printf("Moi ban nhap id can xoa category :");
	scanf("%5s",&Iddelete);
	 while (getchar() != '\n'); // Xóa bộ đệm
	 
	for(int i =0;i < *size ;i++){
		if(strcmp(mycategory[i].categoryId,Iddelete)==0){
			found=1;
			printf("Thong tin category ban muon xoa :");
			printf("%s",mycategory[i].categoryName);
			
			char confirm;
			printf("Ban co chac chan xoa category khong (Y/N)");
			scanf(" %c",&confirm);
			while (getchar() != '\n'); // Xóa bộ đệm
		if (confirm == 'Y' || confirm == 'y'){
		for(int j =i;j < *size-1 ;j++){	
		mycategory[j]=mycategory[j+1];
	}
		(*size)--;
		writeToFile(CATEGORY_FILE_NAME, mycategory, *size);
		printf("Danh muc da duoc xoa thanh cong");
	}else{
		printf("Huy Thao tac xoa");
	}
	return;
	}
    }   
 if(!found){
     printf("Id chua chinh xac");
     }
     goBackOrExit();
	}
void sortCategoryname(Category mycategory[],int size){
 	if(size==0){
 		printf("Mang dang rong");
 		return;
	 }
	 int sortChoice;
	 sortMenu(); 
	 scanf("%d",&sortChoice);
	 
	 for(int i =0 ; i < size-1 ; i++){
	 	for ( int j =0 ; j < size -i-1 ; j++){
	 	  if ((sortChoice == 1 && strcmp(mycategory[j].categoryName, mycategory[j + 1].categoryName) > 0) ||
                (sortChoice == 2 && strcmp(mycategory[j].categoryName, mycategory[j + 1].categoryName) < 0)) {
			 	Category temp = mycategory[j];
			 	mycategory[j]=mycategory[j+1];
			 	mycategory[j+1]=temp;
			 }		
		 }
	 }
	 printf("Ban da sap xep thanh cong!!!");
	 showCategoryList(mycategory,size);
	 goBackOrExit();
 }
 void findCategory(Category mycategory[], int size){
    char searchName[50];
    int found = 0;
    
    if (size == 0) {
        printf("Mang rong!!\n");
        return;
    }

    printf("Nhap ten category can tim: ");
    
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    printf("\n============= KET QUA TIM KIEM =============\n");
    printf("| %-5s | %-25s |\n", "ID", "Category Name");
    printf("|%s|\n", "-----------------------------------");

    for (int i = 0; i < size; i++) {
        mycategory[i].categoryName[strcspn(mycategory[i].categoryName, "\n")] = 0; 

        if (strstr(mycategory[i].categoryName, searchName) != NULL) {
            printf("| %-5s | %-25s |\n", mycategory[i].categoryId, mycategory[i].categoryName);
            found = 1;
        }
    }

    if (!found) {
        printf("Ten can tim kiem khong hop le\n");
    }
    goBackOrExit();
}

    int isDuplicateCategory(Category mycategory[], int size, char *id, char *name, int mode) {
    for (int i = 0; i < size; i++) {
        if (strcmp(mycategory[i].categoryId, id) == 0 && mode != 2) {//mode = 2 la sua thi khong check trung id
//            trung id
            return 1;
        }
        if (strcmp(mycategory[i].categoryName, name) == 0) {
//           printf trung ten
            return 1; 
        }
    }
    return 0;
}
void writeToFile(const char *filename, Category *categories, int size) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(&size, sizeof(int), 1, file);  // luu file
        fwrite(categories, sizeof(Category), size, file);
        fclose(file);
        printf("Luu du lieu thanh cong.\n");
    } else {
        printf("Loi mo file!\n");
    }
}


int readFromFile(const char *filename, Category *categories) {
    int size = 0;
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(&size, sizeof(int), 1, file);  // doc size
        fread(categories, sizeof(Category), size, file);
        fclose(file);
        printf("Load data tu file thanh cong.\n");
    } else {
        printf("Loi doc file!\n");
    }
    return size;  // tra ve so
}

void goBackOrExit(){
	char choice;
    do {
        printf("\nGo back (b)? or Exit (0)?: ");
        fflush(stdin);
        scanf(" %c", &choice);
        while (getchar() != '\n'); // Xóa bộ đệm
        if (choice == 'b') {
            return;
        } else if (choice == '0') {
            exit(0);
        } else {
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (1);
}

void showProductList(Product myproduct[], int size1 ) {
	if( size1 == 0){
		printf("Danh sach mang rong . Vui long nhap them");
		return;
	}
	
    printf("\n================= DANH SÁCH SẢN PHẨM =================\n");
    printf("| %-5s | %-25s | %-7s | %-10s |\n", "ID", "NameProduct", "Amount", "Price");
    printf("|----------------------------------------------------------|\n");
	 for(int i = 0 ; i< size1 ; i++){
	 	 strtok(myproduct[i].productName, "\n");
   	     printf("| %-5s | %-25s | %-7d | %-10d |\n", myproduct[i].productId ,myproduct[i].productName,
		 myproduct[i].amount, myproduct[i].price);
	}
	 printf("============================================================\n");
}
void addProduct( Product myproduct[] , int *size1){
	if(*size1 > MAX){
		printf("SO LUONG THEM DA DU");
		return;
	}
	Product newproduct;
	while(strlen(newproduct.productId)== 0){
		printf("Nhap ID moi cho San Pham : ");
		fgets(newproduct.productId, sizeof(newproduct.productId), stdin);
		newproduct.productId[strcspn(newproduct.productId,"\n")] = 0;
		
		if(strlen(newproduct.productId) == 0){
		 printf("ID khong duoc de trong. Vui long nhap lai.\n");
		}
	}
	while( strlen(newproduct.productName) == 0){
		printf("Moi nhap Name cho San Pham : ");
	    fgets(newproduct.productName, sizeof(newproduct.productName), stdin);
		newproduct.productName[strcspn(newproduct.productName,"\n")] = 0;
		
		if (strlen(newproduct.productName) == 0){
			printf("NAME khong duoc de trong. Vui long nhap lai.\n");
		}
	}
	    printf("Nhap Amount cho San Pham : ");
      	scanf("%d",&newproduct.amount);
	
     	printf("Nhap Price cho San Pham : ");
    	scanf("%d",&newproduct.price);
        if (isDuplicateCategory(myproduct, *size1, newproduct.productId, newproduct.productName, 1)) {
            printf("ID hoac ten danh muc da ton tai. Vui long nhap lai.\n");
        return;
    }
    	
    	myproduct[*size1] = newproduct;
   	   (*size1)++;
       	printf("\nban da them ID ,Name, Amount , Price thanh cong cho Product!!!\n");
        printf("\n============================================\n");
    goBackOrExit();
}
void editProduct(Product myproduct[],int size1){
	if( size1 == 0){
		printf("Mang dang rong.Vui long nhap lai!!");
		return;
	}
	char idEdit[5];
	int found=0;
	printf("Vui long nhap ID cua San Pham ban muon sua");
	scanf(" %s",&idEdit );
    while (getchar() != '\n');
    for(int i =0 ; i< size1 ; i++ ){
    	if (strcmp(myproduct[i].productId,idEdit) == 0){
    	   printf("\n================= DANH SÁCH SẢN PHẨM =================\n");
           printf("| %-5s | %-25s | %-7s | %-10s |\n", "ID", "NameProduct", "Amount", "Price");
           printf("|----------------------------------------------------------|\n");
           printf("| %-5s | %-25s | %-7d | %-10d |\n", myproduct[i].productId ,myproduct[i].productName,
		   myproduct[i].amount, myproduct[i].price);
	
	       printf("==========================================================\n");
		char newName[50];
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = 0; 
        while (strlen(newName) == 0) {
                printf("NAME khong duoc de trong. Vui long nhap lai: ");
                fgets(newName, sizeof(newName), stdin);
            	newName[strcspn(newName, "\n")] = 0; 
            }
            strcpy(myproduct[i].productName, newName);
            printf("Danh muc da duoc sua thanh cong!\n");
            break;
        }
		}
	if(!found){
		printf("Id Nhap chua chinh xac. Vui long nhap lai!!!");
	}
	   goBackOrExit();
}
void deleteProduct(Product myproduct[],int *size1){
	if(*size1 == 0){
		printf("Mang rong . Vui long nhap lai!!!");
		return;
	}
	int found = 1;
	char idDelete[5];
	printf("Nhap Id ban muon xoa ");
	scanf("%s",&idDelete);
	
	while (getchar() != '\n');
	for(int i =0 ; i< *size1 ; i++){
		if (strcmp(myproduct[i].productId,idDelete) == 0){
		   printf("\n================= DANH SÁCH SẢN PHẨM =================\n");
           printf("| %-5s | %-25s | %-7s | %-10s |\n", "ID", "NameProduct", "Amount", "Price");
           printf("|----------------------------------------------------------|\n");
           printf("| %-5s | %-25s | %-7d | %-10d |\n", myproduct[i].productId ,myproduct[i].productName,
		   myproduct[i].amount, myproduct[i].price);
	
	    printf("==========================================================\n");
    	printf("Ban co chac chan xoa San Pham khong (Y/N)");
	char answer;
 	    scanf("%c",&answer);
   	while (getchar() != '\n');
	    if(answer == 'Y' || answer == 'y'){
	 	for (int j =i ; j < *size1 ; j++){
	 		myproduct[j] = myproduct[j+1];
		 }
		 (*size1)--;
		 printf("Danh muc da duoc xoa thanh cong");
	 
     	}else{
		printf("Huy Thao tac xoa");
     	}
       	return;
    	}
       }   
	    if(!found){
	 	  printf("Id Nhap chua chinh xac. Vui long nhap lai!!!");
     	}
		 goBackOrExit();
    	}
void findProduct(Product myproduct[], int size1){
     if(size1 == 0){
     	printf("Mang rong . Vui long nhap lai!!!");
     	return;
	 }	
	 char searchName[50];
	 int found=0;
	    printf("Moi ban nhap ten San Pham muon tim : ");
     	fgets(searchName, sizeof(searchName), stdin);
     	searchName[strcspn(searchName,"\n")] =0;
     	
     	  printf("\n================= Danh Sach San Pham Duoc Tim Kiem  =================\n");
          printf("| %-5s | %-25s | %-7s | %-10s |\n", "ID", "NameProduct", "Amount", "Price");
          printf("|----------------------------------------------------------|\n");
    for(int i =0 ; i< size1 ; i++){
    	if(strstr(myproduct[i].productName,searchName) !=NULL){
           printf("| %-5s | %-25s | %-7d | %-10d |\n", myproduct[i].productId 
		   ,myproduct[i].productName, myproduct[i].amount, myproduct[i].price);
	    found =1;
		}
	}
	if(!found){
		printf("Ten tim kiem khong hop le!!");
		return;
	}
	goBackOrExit();
}

void sortProduct(Product myproduct[],int size1){
   if(size1 ==0){
   	printf("Mang dang rong. Vui long nhap lai!!");
   	return;
   }
   int sortChoice;
   sortMenu();
   printf("Moi ban nhap lua chon (1/2) : ");
   scanf("%d",&sortChoice);
   
   for(int i =0 ; i< size1- 1 ; i++){
   	for( int j =0 ; j < size1-1-i ; j++){
   		if(( sortChoice==1 && myproduct[j].price > myproduct[j+1].price ) ||
		    ( sortChoice==2 && myproduct[j].price < myproduct[j+1].price) ){
		    	Product temp = myproduct[j];
		    	myproduct[j]= myproduct[j+1];
		    	myproduct[j+1]=temp;
			}
	   }
   }   
    printf("Ban da sap xep thanh cong!!!\n");
    showProductList(myproduct, size1);
    goBackOrExit();
}
    int isDuplicateProduct(Product myproduct[], int size1, char *id, char *name, int mode) {
    for (int i = 0; i < size1; i++) {
        if (strcmp(myproduct[i].productId, id) == 0 && mode != 2) {//mode = 2 la sua thi khong check trung id
//            trung id
            return 1;
        }
        if (strcmp(myproduct[i].productName, name) == 0)  {
//           printf trung ten
            return 1; 
        }
    }
    return 0;
}
