#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "column.h"
#include "cdataframe.h"

#define REALLOC_SIZE 256

ColumnArray* init_column_array() {
    ColumnArray *array = (ColumnArray*)malloc(sizeof(ColumnArray));
    if (array == NULL) {
        return NULL;
    }
    array->columns = NULL;
    array->size = 0;
    array->capacity = 0;
    return array;
}

int add_column_to_array(ColumnArray *array, COLUMN *column) {
    if (array->size >= array->capacity) {
        size_t new_capacity = (array->capacity == 0) ? 1 : array->capacity * 2;
        COLUMN **new_columns = realloc(array->columns, new_capacity * sizeof(COLUMN*));
        if (new_columns == NULL) {
            return 0;
        }
        array->columns = new_columns;
        array->capacity = new_capacity;
    }
    array->columns[array->size++] = column;
    return 1;
}

void free_column_array(ColumnArray *array) {
    if (array != NULL) {
        free(array->columns);
        free(array);
    }
}

void print_column_array(ColumnArray *array) {
    printf("Columns:\n");
    for (size_t i = 0; i < array->size; ++i) {
        printf("Column %zu:\n", i+1);
        print_column(array->columns[i]);
        printf("\n");
    }
}

void print_column_names(ColumnArray *array) {
    printf("Columns:\n");
    for (size_t i = 0; i < array->size; ++i) {
        printf("Column %zu: %s\n", i+1, array->columns[i]->title);
    }
}

void rename_column(ColumnArray *array) {
    printf("Current Column Names:\n");
    print_column_names(array);

    printf("\nEnter the name of the column to rename: ");
    char old_name[REALLOC_SIZE];
    fgets(old_name, sizeof(old_name), stdin);
    old_name[strcspn(old_name, "\n")] = '\0'; // Remove trailing newline, if any

    // Find the index of the column with the old name
    size_t index = 0;
    for (; index < array->size; ++index) {
        if (strcmp(array->columns[index]->title, old_name) == 0) {
            break;
        }
    }

    // If the column with the old name is found
    if (index < array->size) {
        // Prompt the user to enter the new name
        printf("Enter the new name for the column: ");
        char new_name[REALLOC_SIZE];
        fgets(new_name, sizeof(new_name), stdin);
        new_name[strcspn(new_name, "\n")] = '\0'; // Remove trailing newline, if any

        // Update the column name
        array->columns[index]->title = strdup(new_name);

        printf("Column '%s' has been renamed to '%s'\n", old_name, new_name);
    } else {
        printf("Column '%s' not found!\n", old_name);
    }

    printf("Current Column Names:\n");
    print_column_names(array);
}

void hard_fill(ColumnArray *array) {
    COLUMN *mycol1 = create_column(UINT, "UNSIGNED INTEGER");
    int a = 34215, b = 364543664;
    insert_value(mycol1, &a);
    insert_value(mycol1, &b);
    add_column_to_array(array, mycol1);

    COLUMN *mycol2 = create_column(INT, "INTEGER");
    unsigned int c = 312, d = 3456;
    insert_value(mycol2, &c);
    insert_value(mycol2, &d);
    add_column_to_array(array, mycol2);

    COLUMN *mycol3 = create_column(CHAR, "CHARACTER");
    char *e = "A", *f = "m";
    insert_value(mycol3, e);
    insert_value(mycol3, f);
    add_column_to_array(array, mycol3);

    COLUMN *mycol4 = create_column(FLOAT, "FLOAT");
    float g = 17, h = 213.6;
    insert_value(mycol4, &g);
    insert_value(mycol4, &h);
    add_column_to_array(array, mycol4);

    COLUMN *mycol5 = create_column(DOUBLE, "DOUBLE");
    double i = 17, j = 213.6;
    insert_value(mycol5, &i);
    insert_value(mycol5, &j);
    add_column_to_array(array, mycol5);

    COLUMN *mycol6 = create_column(STRING, "STRING");
    char** k = "stp marche", **l = "par pitie, fonctionne !";
    insert_value(mycol6, k);
    insert_value(mycol6, l);
    add_column_to_array(array, mycol6);
}

void add_row(ColumnArray *array) {
    char input[REALLOC_SIZE];

    for (size_t i = 0; i < array->size; i++) {
        printf("Column %zu: %s\nEnter the value to add (or type 'none' to skip): ", i + 1, array->columns[i]->title);

        // Read input from the user
        scanf("%s", input);

        // Check if the user wants to skip this column
        if (strcmp(input, "'none'") == 0) {
            printf("Skipping column %zu\n", i + 1);
            continue;
        }
        else {

            // Insert the value based on column type
            switch (array->columns[i]->column_type) {
                case INT: {
                    int value;
                    if (sscanf(input, "%d", &value) != 1) {
                        printf("Invalid input! Please enter a valid integer.\n");
                        i--; // Repeat for the same column
                        continue;
                    }
                    insert_value(array->columns[i], &value);
                    break;
                }
                case UINT: {
                    unsigned int value;
                    if (sscanf(input, "%u", &value) != 1) {
                        printf("Invalid input! Please enter a valid unsigned integer.\n");
                        i--;
                        continue;
                    }
                    insert_value(array->columns[i], &value);
                    break;
                }
                case FLOAT: {
                    float value;
                    if (sscanf(input, "%f", &value) != 1) {
                        printf("Invalid input! Please enter a valid float.\n");
                        i--;
                        continue;
                    }
                    insert_value(array->columns[i], &value);
                    break;
                }
                case DOUBLE: {
                    double value;
                    if (sscanf(input, "%lf", &value) != 1) {
                        printf("Invalid input! Please enter a valid double.\n");
                        i--;
                        continue;
                    }
                    insert_value(array->columns[i], &value);
                    break;
                }
                case CHAR: {
                    // Check if input is a single character
                    if (strlen(input) != 1) {
                        printf("Invalid input! Please enter a single valid character.\n");
                        i--; // Repeat for the same column
                        continue;
                    }
                    char value = input[0];
                    insert_value(array->columns[i], &value);
                    break;
                }
                case STRING: {
                    // Directly insert the string if valid
                    insert_value(array->columns[i],
                                 strdup(input)); // Duplicate the string to avoid potential issues with memory management
                    break;
                }
                default:
                    printf("Unsupported data type!\n");
                    break;
            }
        }
    }
    print_column_array(array);
}