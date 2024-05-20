#include "functionalities.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>

void choice(){
    int user_choice = 0;

    printf("What do you want to do ? Enter the coresponding number :\n");
    printf("1 : Create a new DataFrame\n");
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

    scanf(user_choice);

    switch(user_choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        default:
            printf("The number is invalid");
            return 0;
    }
}

void modify_dataframe(){

    printf("What do you want to do ?\n");
    printf("1 : Add a row of values\n");
    printf("2 : Delete a row of values\n");
    printf("3 : Add a column to the dataframe\n");
    printf("4 : Delete a column of the dataframe\n");
    printf("5 : Rename a column\n");
    printf("6 : Modify the value at the given position\n");
}