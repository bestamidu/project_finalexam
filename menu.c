#include <stdio.h>
#include "menu.h"
#include "function.h"
#include "datatype.h"
#include <stdlib.h>
void mainMenu(){
    printf("\n========================================\n");
    printf("         %s\n", "HE THONG QUAN LY CUA HANG ");
    printf("========================================\n");
    printf("         %s\n", "MENU CHINH  ");
    printf("| %-3s | %-25s |\n", "STT", "CHUC NANG");
    printf("----------------------------------------\n");
    printf("| %-3d | %-25s |\n", 1, "QUAN LY CATEGORY ");
    printf("| %-3d | %-25s |\n", 2, "QUAN LY PRODUCT ");
    printf("| %-3d | %-25s |\n", 0, "THOAT CHUONG TRINH");
    printf("==========================================\n");
    printf("%s","MOI NHAP LUA CHON CHUC NANG CUA BAN: "); 
}
void manageCategory(Category mycategory[], int size){	
    int categorychoice;
    do{
    printf("\n========================================\n");
    printf("         %s\n", "MENU QUAN LI DANH MUC  ");
    printf("| %-3s | %-25s |\n", "STT", "CHUC NANG");
    printf("----------------------------------------\n");
    printf("| %-3d | %-25s |\n", 1, "HIEN THI CAC DANH MUC");
    printf("| %-3d | %-25s |\n", 2, "THEM CAC DANH MUC ");
    printf("| %-3d | %-25s |\n", 3, "SUA DANH MUC");
    printf("| %-3d | %-25s |\n", 4, "XOA DANH MUC");
    printf("| %-3d | %-25s |\n", 5, "TIM KIEM  DANH MUC  ");
    printf("| %-3d | %-25s |\n", 6, "SAP XEP DANH MUC  ");
    printf("| %-3d | %-25s |\n", 0, "QUAY LAI MAIN MENU");
    printf("%s", "MOI NHAP LUA CHON CHUC NANG CUA BAN: "); 
    scanf("%d",&categorychoice);
    printf("========================================");
    fflush(stdin);
    switch(categorychoice){
    	case 1 :
    	system("cls");
        
		showCategoryList(mycategory,size);
		
		break;
		
		case 2 : 
		system("cls");
		addCategory(mycategory, &size);
		
		break;
		
		case 3:
			system("cls");
	    editCategory(mycategory ,size);	
	    
		break;
		
		case 4:
			system("cls");
			deleteCategory(mycategory,&size);
			
		break;
		
		case 5:
			system("cls");
	    findCategory(mycategory,size);
	    
		break;
		
		case 6:
			system("cls");
		 sortCategoryname(mycategory,size);
		break;

		case 0 : 
		system("cls");
		printf("quay lai chuong trinh\n ");
		return;
		default:
		printf("Loi chuong trinh");
			break;
	}
    
     }while(categorychoice!=0);
}
//void manageProduct();
 void sortMenu(){
 	 printf("Nhap thu tu sap xep\n");
	 printf("\n1. Sap xep tang dan\n");
	 printf("\n2. Sap xep giam dan\n ");
	 printf("Lua chon cua ban la :");
 }
 void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Clear the buffer
}