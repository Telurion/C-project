#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "cdataframe.h"

void choice(ColumnArray *array);
void modify_dataframe(ColumnArray *array);
void display_row(ColumnArray *array, int start, int end);
void display_column(ColumnArray *array, int start, int end);
int value_exists(ColumnArray *array, void *value);
void print_value_at(ColumnArray *array, size_t column_index, unsigned long long int row_index);
void print_number_of_rows(ColumnArray *array);
int count_cells_equal_to_value(ColumnArray *array, void *value);
int count_cells_superior_to_value(ColumnArray *array, void *value);
int count_cells_inferior_to_value(ColumnArray *array, void *value);
void change_value_at(ColumnArray *array, size_t column_index, unsigned long long int row_index);

#endif