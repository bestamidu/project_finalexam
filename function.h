#ifndef FUNCTION_H
#define FUNCTION_H
#include "datatype.h" 
#define MAX 50
void showCategoryList(Category mycategory[], int size);
void addCategory(Category mycategory[] , int *size );
void editCategory(Category mycategory[],int size);
void deleteCategory(Category mycategory[],int *size);
void sortCategoryname(Category mycategory[],int size);
void findCategory(Category mycategory[], int size);
 int isDuplicateCategory(Category mycategory[], int size, char *id, char *name, int mode);
void writeToFile(const char *filename, Category *categories, int size);
int readFromFile(const char *filename, Category *categories);
void clearInputBuffer();
void showProductList(Product myproduct[], int size);
void addProduct( Product myproduct[] , int *size1);
void editProduct(Product myproduct[],int size1);
void deleteProduct(Product myproduct[],int *size1);
void findProduct(Product myproduct[], int size1);
void sortProduct(Product myproduct[],int size1);
#endif
