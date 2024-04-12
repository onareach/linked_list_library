// file name: revised_selection_sort_test.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 100

void sort_list_selection(const char * arr_sel[], int n);

int main()
{
const char * arr_sel[] = 
    {
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar"
    };
    
    int n = sizeof(arr_sel) / sizeof(arr_sel[0]);

    printf("List before selection sort: \n");
    for (int i = 0; i < n; i++)
        printf("%3d:  %s\n", i+1, arr_sel[i]);

    sort_list_selection(arr_sel, n);

    printf("\nList after selection sort: \n");
    for (int i = 0; i < n; i++)
        printf("%3d:  %s\n", i+1, arr_sel[i]);

    return 0;
}

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