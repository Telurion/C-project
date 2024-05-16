#ifndef COLUMN_H
#define COLUMN_H

enum enum_type { //Enumerate all types of data possible that can be used
    NULLVAL = 1, UINT, INT, CHAR, FLOAT, DOUBLE, STRING
};
typedef enum enum_type ENUM_TYPE;

union column_type { //Determine the type of value entered
    unsigned int        uint_value;
    signed int          int_value;
    char                char_value;
    float               float_value;
    double              double_value;
    char*               string_value;
};
typedef union column_type COL_TYPE ;

struct column {
    char *title;
    unsigned int size; //logical size
    unsigned int max_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;

COLUMN *create_column(ENUM_TYPE type, char *title);

int insert_value(COLUMN *col, void *value);

void delete_column(COLUMN **col);

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

void print_col(COLUMN* col);


#endif