#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "datatype.h"
#define MAX 50 
#include "function.h"
int main(){
	int choice;
	int size =0;
	Category mycategory[MAX];
	size = readFromFile("categories.dat", mycategory);
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
			    //manageProduct();
			    
			break;
			case 0 :
				printf("Thoat chuong trinh ");
		     	break;
		}
	}while(choice!=0);
}                                 
                                  