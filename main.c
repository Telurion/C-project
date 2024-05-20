#include <stdio.h>

#include "column.h"
#include "cdataframe.h"



int main(){
    COLUMN *mycol1 = create_column(UINT, "UNSIGNED INTEGER");

    int a = 34215, b = 364543664, x = 23480;
    insert_value(mycol1, &a);
    insert_value(mycol1, &b);
    insert_value(mycol1, &x);

    print_column(mycol1);

    delete_column(&mycol1);
}