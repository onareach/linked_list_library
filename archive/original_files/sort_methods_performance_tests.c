// file name: sort_methods_performance_tests.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 100

// Bubble sort:
void sort_list_bubble(const char * arr_bub[], int n);

// Selection sort;
void sort_list_selection(const char * arr_sel[], int n);

//Quick sort;
static int myCompare(const void* a, const void* b);
void sort_words(const char* arr[], int n);


int main()
{
    clock_t tic, toc; // Instantiate timer

    // Bubble Sort timing:
    const char * arr_bub[] = 
    {
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter"
    };
    
    int n = sizeof(arr_bub) / sizeof(arr_bub[0]);

    printf("\nBubble Sort List Loaded.\n");
    //printf("List before bubble sort: \n");
    //for (int i = 0; i < n; i++)
    //    printf("%3d:  %s\n", i+1, arr_bub[i]);

    tic = clock();
    sort_list_bubble(arr_bub, n);
    toc = clock();
    printf("\nBubble (or sinking) sort method time: %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    //printf("\nList after bubble sort: \n");
    //for (int i = 0; i < n; i++)
    //    printf("%3d:  %s\n", i+1, arr_bub[i]);


    // Selection Sort timing:
    const char * arr_sel[] = 
    {
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter"
    };
    
    n = sizeof(arr_sel) / sizeof(arr_sel[0]);

    printf("\nSelection Sort List Loaded.\n");
    //printf("List before selection sort: \n");
    //for (int i = 0; i < n; i++)
    //    printf("%3d:  %s\n", i+1, arr_sel[i]);

    tic = clock();
    sort_list_selection(arr_sel, n);
    toc = clock();
    printf("\nSelection sort method time: %fs\n\n", (double)(toc - tic) / CLOCKS_PER_SEC);


    //printf("\nList after selection sort: \n");
    //for (int i = 0; i < n; i++)
    //    printf("%3d:  %s\n", i+1, arr_sel[i]);


    // Quick Sort timing:
    const char* arr[] = 
    {
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter",
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar", "Tanya", "Alex", "Dante", "Elizabeth", "Peter"
    };

    n = sizeof(arr) / sizeof(arr[0]);

    printf("Bubble Sort List Loaded.\n");
    //printf("\nPrint the given names before Quick Sort:\n");
    //for (int i = 0; i < n; i++)
    //    printf("%d: %s \n", i, arr[i]);
    
    tic = clock();
    sort_words(arr, n);
    toc = clock();
    printf("\nQuick sort method time: %fs\n\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    //printf("\nSorted list of names after Quick Sort:\n");
    //for (int i = 0; i < n; i++)
    //    printf("%d: %s \n", i, arr[i]);


return 0;

}

// Bubble Sort:
void sort_list_bubble(const char * arr_bub[], int n)
{
const char * temp[] = {"temp"};

for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (strcmp(arr_bub[i], arr_bub[j]) < 0)
            {
                temp[0] = arr_bub[i];
                arr_bub[i] = arr_bub[j];
                arr_bub[j] = temp[0];
            }
        }
    }
}

// Selection Sort:
void sort_list_selection(const char * arr_sel[], int n)
{

int i, j, min_idx;   // In addition to the loop (i, j) and array 
                        // size (n), there's a variable the index
                        // of the lowest value.

const char * temp[] = {"temp"};

// One by one, move the boundary of the unsorted subarray.
const char * minStr[] = {"temp"};
// char minStr[MAX_LEN];
    
    for (i = 0; i < n; i++)
    {
        // Find the minimum element in the unsorted array.
        // Begin by making the first element's index and value the lowest.
        min_idx = i;
        minStr[0] = arr_sel[i];
        
        // Loop through the second element (i+1) on.
        for (j = i+1; j < n; j++)
        {
            
            if (strcmp(minStr[0], arr_sel[j]) > 0) // If minimum is higher than str[j]...
            {
                minStr[0] = arr_sel[j]; // ...then re-set the low value and low index
                min_idx = j;            // to the lower ones found.
            }
        }

        if (min_idx != i) // If a lower value in the subarray was found...
        {
            //char temp[MAX_LEN];
            temp[0] =  arr_sel[i]; // ...swap the new lower value into 
            arr_sel[i] = arr_sel[min_idx];
            arr_sel[min_idx] = temp[0]; // This pushes the high value out in the list
        }                               // but it could push it too far.
    }
}

// Quicksort

// This short function calls the standard qsort functions, which has an argument
// of a comparison function that needs to be altered based on the data type
// being sorted.

void sort_words(const char* arr[], int n)
{
    qsort(arr, n, sizeof(const char*), myCompare);
}

// This static int declaraton is like a "blueprint" to the qsort function.
// It's a "roadmap" that tells qsort what datatype it's sorting. In this case,
// it's telling qsort that whatever it's sorting, it's of a char datatype.
static int myCompare(const void* a, const void* b)
{
   return strcmp(*(const char**)a, *(const char**)b);
}


