#include <stdio.h>
#include "column.h"

int main(){
    COLUMN *mycol = create_column(INT, "My Integer Column");
    printf("%s %d", mycol -> title, mycol -> column_type);
    insert_value(mycol, NULL);
    return 0;
}