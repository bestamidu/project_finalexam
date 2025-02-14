//khai báo chi tiết hàm 
#include "function.h"
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
    char choice;
    do{
         printf("\nGo back (b)? or Exit (0)?: ");
          while (getchar() != '\n');
    	scanf("%c",&choice);
    	if(choice=='b'){
    		return;
		}else if(choice=='0'){
			exit(0);
		}else {
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
	
	}
    }while(1);
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

    if (checkDuplicateId(mycategory, *size, newCategory.categoryId, newCategory.categoryName)) {
        printf("ID hoac ten danh muc da ton tai. Vui long nhap lai.\n");
        return;
    }
    mycategory[*size]= newCategory;
	(*size)++;
	
	writeToFile("categories.dat", mycategory, *size);
	printf("\nban da them ID va Name thanh cong cho category!!!\n");
    printf("\n============================================\n");
      char choice;
    do{
         printf("\nGo back (b)? or Exit (0)?: ");
    	scanf("%c",&choice);
    	if(choice=='b'){
    		return;
		}else if(choice=='0'){
			exit(0);
		}else {
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
	
	}
    }while(1);
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

            // Kiá»ƒm tra trÃ¹ng láº·p
            if (isDuplicateCategory(mycategory, size, id, newName)){
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
		writeToFile("categories.dat", mycategory, (size));
	}

    if (!found) {
        printf("Thong tin ID ban nhap khong chinh xac.\n");
    }
    char choice;
    do {
        printf("\nGo back (b)? or Exit (0)?: ");
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
		writeToFile("categories.dat", mycategory, *size);
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
     char deleteChoice;
     do{
     	 printf("\nGo back (b)? or Exit (0)?: ");
     	 while (getchar() != '\n');
     	 scanf(" %c ", &deleteChoice);
     	 
     	 if(deleteChoice=='b'){                  
     
		  }else if(deleteChoice=='0'){    
		  }else{
			  printf("Lua chon khong hop le. Vui long nhap lai.\n");
			  }
		  }while(1);
	}
 void sortCategoryname(Category mycategory[],int size){
 	if(size==0){
 		printf("Mang dang rong");
 		return;
	 }
	 int sortChoice;
	 sortMenu(); 
	 scanf("%d",&sortChoice);
	 getchar();
	 
	 for(int i =0 ; i < size-1 ; i++){
	 	for ( int j =0 ; j < size -i-1 ; i++){
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
	 char sortchoice;
	 do{
	 printf("\nGo back (b)? or Exit (0)?: ");
	 while (getchar() != '\n');
	 scanf(" %c", &sortchoice);
	 if(sortchoice== 'b'){
	 	return;                          
	 }else if( sortchoice == '0'){
	 }else{
	 	printf("Lua chon khong hop le. Vui long nhap lai.\n");
	 }
	 }while(1);
 }
 void findCategory(Category mycategory[], int size){
    char searchName[50];
    int found = 0;
    
    if (size == 0) {
        printf("Mang rong!!\n");
        return;
    }

    printf("Nhap ten category can tim: ");
    while (getchar() != '\n');
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
    char findchoice;
    do{
    printf("\nGo back (b)? or Exit (0)?: ");
    fflush(stdin);
    scanf(" %c", &findchoice);
    while (getchar() != '\n'); 

    if( findchoice== 'b' ){
    	return;
	}else if(findchoice =='0'){
		exit(0);
	}else{
	printf("Lua chon khong hop le. Vui long nhap lai.\n");
	}
    }while(1);
}

    int isDuplicateCategory(Category mycategory[], int size, char *id, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(mycategory[i].categoryId, id) == 0 && strcmp(mycategory[i].categoryName, name) == 0) {
            return 1;
        }
    }
    return 0;
}
 int checkDuplicateId(Category mycategory[], int size, char *id, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(mycategory[i].categoryId, id) == 0 ) {
            return 1;
        }
    }
    return 0;
}

void writeToFile(const char *filename, Category *categories, int size) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(&size, sizeof(int), 1, file);  // Save the size
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
        fread(&size, sizeof(int), 1, file);  // Read the size
        fread(categories, sizeof(Category), size, file);
        fclose(file);
        printf("Load data tu file thanh cong.\n");
    } else {
        printf("Loi doc file!\n");
    }
    return size;  // Return the number of elements read
}
