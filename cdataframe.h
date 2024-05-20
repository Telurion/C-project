#ifndef CDATAFRAME_H
#define CDATAFRAME_H

typedef struct {
    COLUMN **columns;
    size_t size;
    size_t capacity;
} ColumnArray;

ColumnArray* init_column_array();

void hard_fill(ColumnArray *array);



void print_column_names(ColumnArray *array);



void add_row(ColumnArray *array);

void free_row(ColumnArray  *array);

int add_column_to_array(ColumnArray *array, COLUMN *column);

void free_column(ColumnArray *array);

void rename_column(ColumnArray *array);

void print_column_array(ColumnArray *array);

#endif //CDATAFRAME_H
