#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include <string.h>
#define REALLOC_SIZE 256

// Function to create a new column
COLUMN *create_column(ENUM_TYPE type, char *title) {
    COLUMN *newColumn = (COLUMN*) malloc(sizeof(COLUMN));
    if (newColumn == NULL) {
        printf("Error in memory allocation\n");
        return NULL;
    }
    else {
        newColumn -> column_type = type;
        newColumn -> title = title;

        newColumn -> size = 0;
        newColumn -> max_size = 0;
        newColumn -> data = NULL;
        newColumn -> index = NULL;
        printf("Column created successfully\n");
        return newColumn;
    }
}

// Function to insert a value into the column
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
            printf("Error in memory allocation !\n");
            return 0;
        }
        col -> data = test_alloc;
        col -> max_size += REALLOC_SIZE;
        printf("Reallocation done\n");
    }

    if (!value)
    {
        col->data[col->size] = (COL_TYPE *) malloc(sizeof(char *));
        *((char **) col->data[col->size]) = *((char **) "NULL");
    }
    else {
        switch (col->column_type) {
            case INT:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(int));
                *((int *) col->data[col->size]) = *((int *) value);
                break;
            case UINT:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(unsigned int));
                *((unsigned int *) col->data[col->size]) = *((unsigned int *) value);
                break;
            case FLOAT:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(float));
                *((float *) col->data[col->size]) = *((float *) value);
                break;
            case DOUBLE:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(double));
                *((double *) col->data[col->size]) = *((double *) value);
                break;
            case CHAR:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(char));
                *((char *) col->data[col->size]) = *((char *) value);
                break;
            case STRING:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(char *));
                 col->data[col->size] = value;
                break;
            default:
                printf("Error in variable type !\n");
                return 0;
        }
    }
    printf("Value inserted\n");
    col -> size ++;
    return 1;
}

// Function to delete a column
void delete_column(COLUMN **col) {
    if (col != NULL) {
        free((*col)->title);
        free((*col)->data);
        free((*col)->index);
    }
    free(*col);
    printf("Column deleted !\n");
}

// Function to convert a value to a string
void convert_value(COLUMN* col, unsigned long long int i, char* str, int size) {
    switch(col->column_type) {
        // Other cases...
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
                strcpy(str,col->data[i]);
                break;
            default:
                break;
        }
}

// Function to display the content of a column
void print_column(COLUMN *col) {
    char *val;
    printf("Output:\n");
    for (unsigned long long int i = 0; i < col->size; ++i) {
        val = (char*)malloc(col->size * sizeof(char)); // Allocate memory for val
        convert_value(col, i,  val, col->size);
        printf("[%llu] %s\n", i,  val);
        free(val); // Free memory after use
    }
}