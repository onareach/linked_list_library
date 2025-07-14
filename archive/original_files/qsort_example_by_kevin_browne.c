#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int compare_int(const void *x_void, const void *y_void)
//{
//    int x = *(int *)x_void; // The (int *)x_void phrase casts the void 
//                            // pointer as an integer pointer (so the integer 
//                            // values can be compared). The the * in front
//                            // of that phrase de-references the integer
//                            // pointer to its integer value.
//                            // See Kevin's "Introduction to Pointers" video.)
//                            // Note: The complexity of this syntax is the
//                            // price of making the compare() function as
//                            // flexible as possible in the type of data it
//                           // will handle.
//    int y = *(int *)y_void; // Do the same for y.
//    return x - y;
//}
//
//int compare_char(const void *x_void, const void *y_void)
//{
//    int x = *(char *)x_void; // The (int *)x_void phrase casts the void 
//                            // pointer as an integer pointer (so the integer 
//                            // values can be compared). The the * in front
//                            // of that phrase de-references the integer
//                            // pointer to its integer value.
//                            // See Kevin's "Introduction to Pointers" video.)
//                            // Note: The complexity of this syntax is the
//                            // price of making the compare() function as
//                            // flexible as possible in the type of data it
//                            // will handle.
//    int y = *(char *)y_void; // Do the same for y.
//    return x - y;
//}

static int myCompare(const void* a, const void* b);
void sort_words(const char* arr[], int n);


int main()
{
   /* int a[] = {8, 7, 2, 4, 6, 3, 5, 1, 9, 0};
    int length = 10;

    qsort(a, length, sizeof(int),  compare_int);

    printf("\nSorted list of integers:\n");
    for (int i = 0; i < length; i++)
        printf("a[%d]: %d\n", i, a[i]);

    char b[] = {'a', 'g', 'b', 't', 'x', 'f', 'k', 'y', '9', 'q'};
    
    qsort(b, length, sizeof(char), compare_char);

    printf("\nSorted list of letters:\n");
    for (int i = 0; i < length; i++)
        printf("b[%d]: %c\n", i, b[i]);
*/
    const char* arr[] = 
    {
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar"
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nPrint the given names:\n");
    for (int i = 0; i < n; i++)
        printf("%d: %s \n", i, arr[i]);

    sort_words(arr, n);

    printf("\nSorted list of names:\n");
    for (int i = 0; i < n; i++)
        printf("%d: %s \n", i, arr[i]);

    return 0;
}


// This short function does the comparison of two values:
static int myCompare(const void* a, const void* b)
{
   return strcmp(*(const char**)a, *(const char**)b);
}

// This short function
void sort_words(const char* arr[], int n)
{
    qsort(arr, n, sizeof(const char*), myCompare);
}

// The qsort() function is relatively simple, except its 4th argument depends
// on the insertion of another function that compares the values of different
// kinds of data (integers, characters, even structs). Here is Kevin Browne's
// pseudocode for the comparator() function (which could be name anything):
//
// We need to provide a special function that we'll outline as:
//
// int comparator(const void *x, const void *y);
//
// The return value of this function wll effect the sorting order.
//
// <0 if x should go before y
// 0  if x is equivalent to y
// >0 if x should go after y
//
// In the above breakdown, by 'x' and 'y' we *really* mean
// the values pointed to by x and y, since x and y are pointers
// in the above function.
//