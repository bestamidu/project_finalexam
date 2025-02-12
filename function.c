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

  //  printf("===========================================\n");
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
    printf("\n============================================\n");
	printf("\nTHEM CATEGORY VO DANH SACH\n");
	printf("\nNhap ID cua category\n");
	scanf("%s", &mycategory[*size].categoryId);
	getchar();  
	printf("\nNhap NAME cua category\n");
    fgets(mycategory[*size].categoryName, sizeof(mycategory[*size].categoryName), stdin);
	(*size)++;
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

void editCategory(Category mycategory[],int size){
	char id[6];
	int found=0;
	printf("\nNhap id ban muon sua category\n");
	scanf("%5s",id);
    for(int i=0 ; i<size ; i++){
    	if(strcmp(mycategory[i].categoryId,id)==0){
    		found =1;
    		printf("\nThong tin hien tai cua danh muc la\n");
    		printf("ID: %s , CategoryName : %s ",mycategory[i].categoryId,mycategory[i].categoryName);
    		
    	printf("Moi ban nhap thong tin moi cho category\n");
    	printf(" Moi ban nhap Namecategory : ");
    	 getchar(); // cai nay dung de xoa bo nho dem 
    	fgets(mycategory[i].categoryName,sizeof(mycategory[i].categoryName),stdin);
    	 mycategory[i].categoryName[strcspn(mycategory[i].categoryName, "\n")] = 0;// xoa ky tu do fgets them vo 
    	printf("danh muc da duoc sua thanh cong");
    	break;
		}
	}
	if(!found){
		printf("Thong tin Id cua ban nhap vao chua chinh xac");
	}

	  char choice;
    do{
         printf("\nGo back (b)? or Exit (0)?: ");
    	scanf(" %c",&choice);
    	if(choice=='b'){
    		return;
		}else if(choice=='0'){
			exit(0);
		}else {
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
	
	}
    }while(1);
}
 