#include <stdio.h>
#include "column.h"
#include "functionalities.h"
#include "cdataframe.h"

int main(){
    ColumnArray *array = init_column_array();
    hard_fill(array);
    while (True){
        choice(array);
    }
    return 0;
}