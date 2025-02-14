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
 int isDuplicateCategory(Category mycategory[], int size, char *id, char *name);
 void writeCategoriesToFile(Category mycategory[], int size, const char *filename);
 int readCategoriesFromFile(Category mycategory[], int maxSize, const char *filename);
#endif
