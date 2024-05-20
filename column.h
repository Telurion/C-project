#ifndef COLUMN_H
#define COLUMN_H

// Enum for data types
enum enum_type {
    NULLVAL = 1, UINT, INT, CHAR, FLOAT, DOUBLE, STRING
};
typedef enum enum_type ENUM_TYPE;

// Enum for data types
union column_type {
    unsigned int        uint_value;
    signed int          int_value;
    char                char_value;
    float               float_value;
    double              double_value;
    char*               string_value;
};
typedef union column_type COL_TYPE ;

// Column structure definition
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

void print_column(COLUMN* col);

int nb_occurence(COLUMN* col, void *value);

void* get_element_at(COLUMN *col, unsigned long long int pos);

int count_greater_than(COLUMN *col, void *x);

int count_less_than(COLUMN *col, void *x);

int count_equal_to(COLUMN *col, void *x);
#endif