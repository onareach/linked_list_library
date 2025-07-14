// File name: test-non-array-and-array-handoffs-from-main-to-function.c
#include <stdio.h>

void print_variable_values(const char * arr[], int n);

int main()
{
    const char * arr[] = {"test1", "test2"};
    int n = 5;

    printf("char[1] and n: %s and %d\n", arr[0], n);

    // **********************************************************************************
    // Notice that the datatype identifiers "const char *" and "int" are not needed
    // in the print command above to their value in the statement above, nor will they be
    // needed in the *body* of the function below. However, they are needed when they
    // originally *declared* and loaded above and in the declaration and defintion of
    // the function. 
    // **********************************************************************************

    print_variable_values(arr, n);

    return 0;
}

void print_variable_values(const char * arr[], int n)
{

printf("char[1] and n: %s and %d\n", arr[0], n);

arr[0] = arr[1];
n = 8;

printf("char[1] and n: %s and %d\n", arr[0], n);

}

    
