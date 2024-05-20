#include "functionalities.h"
#include "column.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

void choice(ColumnArray *array){
    int user_choice = 0;

    printf("What do you want to do ? Enter the coresponding number :\n");
    printf("1 : Create a new DataFrame (it will erase the previous one)\n");
    printf("2 : Modify the dataframe\n");
    printf("3 : Display the dataframe\n");
    printf("4 : Display only some rows of the dataframe\n");
    printf("5 : Display only some columns of the dataframe\n");
    printf("6 : Check if a value exists in the dataframe\n");
    printf("7 : Get the value at the given position\n");
    printf("8 : Display the names of all the columns\n");
    printf("9 : Display the number of rows\n");
    printf("10 : Display the number of columns\n");
    printf("11 : Display the number of cells equal to a given input\n");
    printf("12 : Display the number of cells superior to a given input\n");
    printf("13 : Display the number of cells inferior to a given input\n");

    scanf("%d", &user_choice);

    switch(user_choice){
        case 1:
            init_column_array();
            break;
        case 2:
            modify_dataframe(array);
            break;
        case 3:
            print_column_array(array);
            break;
        case 4:
            int start = 0;
            int end = 0;
            printf("Enter the number of the first and the last row that you want to display in the form : first/last");
            scanf("%d/%d", &start, %end);
            void display_row(array, start, end);
            break;
        case 5:
            int start = 0;
            int end = 0;
            printf("Enter the number of the first and the last column that you want to display in the form : first/last");
            scanf("%d/%d", &start, %end);
            display_column(array, start, end);
            break;
        case 6:
            if (value_exists){
                printf("The value exists in the dataframe");
            }
            else{
                printf("The value doesn't exists un the dataframe");
            }
            break;
        case 7:
            int column = 0;
            int row = 0;
            printf("Enter the position of the value you want with the form : column/row");
            scanf("%d/%d", &column, &row);
            print_value_at(array, column, row);
            break;
        case 8:
            print_column_names(array);
            break;
        case 9:
            print_number_of_rows(array);
            break;
        case 10:
            printf("%d", array->size);
            break;
        case 11:
            void value;
            printf("What value do you want to search for ?");
            scanf("%s", &value);
            printf("%d", count_cells_equal_to_value(array, value));
            break;
        case 12:
            void value;
            printf("What value do you want to search for ?");
            scanf("%s", &value);
            printf("%d", count_cells_superior_to_value(array, value));
            break;
        case 13:
            void value;
            printf("What value do you want to search for ?");
            scanf("%s", &value);
            printf("%d", count_cells_inferior_to_value(array, value));
            break;
        default:
            printf("The number is invalid");
            return 0;
    }
}

void modify_dataframe(ColumnArray *array){
    int user_choice = 0;

    printf("What do you want to do ?\n");
    printf("1 : Add a row of values\n");
    printf("2 : Delete a row of values\n");
    printf("3 : Add a column to the dataframe\n");
    printf("4 : Delete a column of the dataframe\n");
    printf("5 : Rename a column\n");
    printf("6 : Modify the value at the given position\n");

    scanf("%d", &user_choice);

    switch(user_choice){
        case 1:
            add_row(array);
            break;
        case 2:

            break;
        case 3:
            char* type;
            char* title;
            printf("What type do you want the column to be ? (INT, UINT, CHAR, FLOAT, DOUBLE, STRING)");
            scanf("%s", &type);
            printf("What do you want the title of the column to be ?")
            scanf("%s", &title);
            col = create_column(type, title);
            add_column_to_array(array, col);
            break;
        case 4:
            char
            break;
        case 5:
            rename_column(array);
            break;
        case 6:
            int column = 0;
            int row = 0;
            printf("Enter the position of the value you want with the form : column/row");
            scanf("%d/%d", &column, &row);
            void change_value_at(array, column, urow);
            break;
        default:
            printf("The number is invalid");
            return 0;
    }
}

void display_row(ColumnArray *array, int start, int end) {
    for (int row = start; row < end; row++) {
        for (int i = 0; i < array->size; i++) {
            COLUMN *col = array->columns[i];
            if (row < col->size) {
                char val[256];
                convert_value(col, row, val, sizeof(val));
                printf("%s\t", val);
            } else {
                printf("NULL\t");
            }
        }
        printf("\n");
    }
}

void display_column(ColumnArray *array, int start, int end){
    for (int col = start; col < end; col++){
        print_column(array->columns[col]);
    }
}

int value_exists(ColumnArray *array, void *value) {
    for (size_t i = 0; i < array->size; i++) {
        COLUMN *col = array->columns[i];

        for (unsigned int j = 0; j < col->size; j++) {
            switch (col->column_type) {
                case INT:
                    if (*((int *)value) == *((int *)col->data[j])) return 1;
                    break;
                case UINT:
                    if (*((unsigned int *)value) == *((unsigned int *)col->data[j])) return 1;
                    break;
                case FLOAT:
                    if (*((float *)value) == *((float *)col->data[j])) return 1;
                    break;
                case DOUBLE:
                    if (*((double *)value) == *((double *)col->data[j])) return 1;
                    break;
                case CHAR:
                    if (*((char *)value) == *((char *)col->data[j])) return 1;
                    break;
                case STRING:
                    if (strcmp((char *)value, *((char **)col->data[j])) == 0) return 1;
                    break;
                default:
                    printf("Unsupported column type\n");
                    break;
            }
        }
    }

    return 0;
}

void print_value_at(ColumnArray *array, size_t column_index, unsigned long long int row_index) {

    if (column_index >= array->size) {
        printf("Invalid column index\n");
        return;
    }

    COLUMN *target_column = array->columns[column_index];

    if (row_index >= target_column->size) {
        printf("Invalid row index\n");
        return;
    }

    char value_str[256];
    convert_value(target_column, row_index, value_str, sizeof(value_str));
    printf("Value at column %zu and row %llu : %s\n", column_index, row_index, value_str);
}

void print_number_of_rows(ColumnArray *array) {
    printf("Number of rows in each column:\n");
    for (size_t i = 0; i < array->size; i++) {
        printf("Column '%s' as %u rows\n", array->columns[i]->title, array->columns[i]->size);
    }
}

int count_cells_equal_to_value(ColumnArray *array, void *value) {
    int count = 0;

    for (size_t i = 0; i < array->size; i++) {
        COLUMN *col = array->columns[i];
        cont += nb_occurence(col, value);
    }
}

int count_cells_superior_to_value(ColumnArray *array, void *value) {
    int count = 0;

    for (size_t i = 0; i < array->size; i++) {
        COLUMN *col = array->columns[i];
        cont += count_greater_than(col, value);
    }
}

int count_cells_inferior_to_value(ColumnArray *array, void *value) {
    int count = 0;

    for (size_t i = 0; i < array->size; i++) {
        COLUMN *col = array->columns[i];
        cont += count_less_than(col, value);
    }
}

void change_value_at(ColumnArray *array, size_t column_index, unsigned long long int row_index) {
    void new_value;


    if (column_index >= array->size) {
        printf("Invalid column index\n");
        return;
    }

    COLUMN *target_column = array->columns[column_index];

    if (row_index >= target_column->size) {
        printf("Invalid row index\n");
        return;
    }

    printf("Value of type %s", array->columns[column_index]->column_type);
    printf("The value you will enter will be registered as the same type");
    printf("What is the new value ?");
    switch(array->columns[column_index]->column_type){
        case INT:
            scanf("%d", &new_value);
            break;
        case UINT:
            scanf("%u", &new_value);
            break;
        case FLOAT:
            scanf("%f", &new_value);
            break;
        case DOUBLE:
            scanf("%lf", &new_value);
            break;
        case CHAR:
            scanf("%c", &new_value);
            break;
        case STRING:
            scanf("%s", &new_value);
            break;
        default:
            printf("Unsupported column type\n");
            break;
    }

    array->columns[column_index]->data[row_index] = new_value;
}