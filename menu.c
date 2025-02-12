#include <stdio.h>
#include "menu.h"
#include "function.h"
#include "datatype.h"
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
    
    switch(categorychoice){
    	case 1 :
		showCategoryList(mycategory,size);
		break;
		
		case 2 : 
		addCategory(mycategory, &size);
		break;
		
		case 3:
	    editCategory(mycategory ,size);	
		break;
		
		case 4:
		break;
		
		case 5:
		break;
		
		case 6:
		break;

		case 0 : 
		printf("quay lai chuong trinh\n ");
		return;
		default:
		printf("Loi chuong trinh");
			break;
	}
    
     }while(categorychoice!=0);
}
//void manageProduct();