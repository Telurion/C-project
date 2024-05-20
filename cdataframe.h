#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"
#include <stddef.h>

typedef struct {
    COLUMN **columns;
    size_t size;
    size_t capacity;
} ColumnArray;

ColumnArray* init_column_array();

int add_column_to_array(ColumnArray *array, COLUMN *column);

void free_column_array(ColumnArray *array);

void print_column_array(ColumnArray *array);

void print_column_names(ColumnArray *array);

void rename_column(ColumnArray *array);

void hard_fill(ColumnArray *array);

void add_row(ColumnArray *array);

#endif //CDATAFRAME_H
