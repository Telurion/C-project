#include <stdio.h>

#include "column.h"
#include "cdataframe.h"



int main(){
    ColumnArray *array = init_column_array();

    hard_fill(array);

    add_row(array);

    free_column_array(array);
}