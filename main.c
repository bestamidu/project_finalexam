#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "menu.h"
#include "datatype.h"
#include "function.h"
int main(){
	int choice;
	int size =0;
	int size1=0;
	Category mycategory[MAX];
	Product myproduct[MAX];
	size = readFromFile(CATEGORY_FILE_NAME, mycategory);
	do{
		mainMenu();
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice){
			case 1:
				system("cls");
			    manageCategory(mycategory ,size );
				break;
			case 2: 
		    	system("cls");
			    manageProduct(myproduct , size1 );
			    
			break;
			case 0 :
				printf("Thoat chuong trinh ");
		     	break;
		}
	}while(choice!=0);
}                                 
                                  