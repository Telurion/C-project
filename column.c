#include <stdio.h>
#include <stdlib.h>
#include "column.h"

#define REALLOC_SIZE 256

COLUMN *create_column(ENUM_TYPE type, char *title) {
    COLUMN *newColumn = (COLUMN*) malloc(sizeof(COLUMN));
    if (newColumn == NULL) {
        printf("Error in memory allocation");
        return NULL;
    }
    else {
        newColumn -> column_type = type;
        newColumn -> title = title;

        newColumn -> size = 0;
        newColumn -> max_size = 0;
        newColumn -> data = NULL;
        newColumn -> index = NULL;
        return newColumn;
    }
}

int insert_value(COLUMN *col, void *value){
    if (col->size >= col->max_size) {
        COL_TYPE **test_alloc = NULL;
        if (col->data == NULL) {
            test_alloc = (COL_TYPE **) malloc(REALLOC_SIZE);
        }
        else {
            test_alloc = realloc(col->data, (col->max_size + REALLOC_SIZE) * sizeof(COL_TYPE *));
        }
        if (test_alloc == NULL) {
            printf("Error in memory allocation !");
            return 0;
        }
        col -> data = test_alloc;
        col -> max_size += REALLOC_SIZE;
    }
    switch (col->column_type) {
        case INT:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(int));
            *((int*)col->data[col->size]) = *((int*)value);
            break;
        case UINT:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(unsigned int));
            *((unsigned int*)col->data[col->size]) = *((unsigned int*)value);
            break;
        case FLOAT:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(float));
            *((float*)col->data[col->size]) = *((float*)value);
            break;
        case DOUBLE:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(double));
            *((double*)col->data[col->size]) = *((double*)value);
            break;
        case CHAR:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(char));
            *((char*)col->data[col->size]) = *((char*)value);
            break;
        case STRING:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(char*));
            *((char**)col->data[col->size]) = *((char**)value);
            break;
        default:
            printf("Error in variable type !");
            return 0;
    }
    col -> size ++;
    return 1;
}

void delete_column(COLUMN **col) {
    if (col != NULL) {
        free((*col)->title);
        free((*col)->data);
        free((*col)->index);
    }
    free(*col);
    printf("Column deleted !");
}

void convert_value(COLUMN* col, unsigned long long int i, char* str, int size){
    switch(col->column_type){
        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        case UINT:
            snprintf(str, size, "%u", *((unsigned int*)col->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float*)col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double*)col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char*)col->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", *((char**)col->data[i]));
            break;
        default:
            break;
    }
}

void print_col(COLUMN* col) {
    printf("Output:\n");
    for (unsigned long long int i = 0; i < col->size; ++i) {
        char str[REALLOC_SIZE];
        convert_value(col, i, str, REALLOC_SIZE);
        printf("%s\n", str);
    }
}


int nb_occ(COLUMN* col, void value){
    
}