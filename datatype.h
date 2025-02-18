#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdbool.h>

typedef struct {
    char categoryId[06];
    char categoryName[50];
} Category;

typedef struct {
	char productId[5];
	char productName[50];
	int amount;
	int price;
} Product;
#endif 
