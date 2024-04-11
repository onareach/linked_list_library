#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 100

// Bubble sort:
void sort_list_bubble(); // "Bubble" sort method - not recommended. (Slammed by Knuth.)

// Selection sort;
void sort_list_selection();

//Quick sort;
static int myCompare(const void* a, const void* b);
void sort_words(const char* arr[], int n);


int main()
{
    // Bubble Sort timing:
    clock_t tic, toc;
    tic = clock();
    sort_list_bubble();
    toc = clock();
    printf("\nBubble (or sinking) sort method time: %fs\n\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    // Selection Sort timing:
    tic = clock();
    sort_list_selection();
    toc = clock();
    printf("\nSelection sort method time: %fs\n\n", (double)(toc - tic) / CLOCKS_PER_SEC);


    // I need to either get the declaraton of the array into the called function as is done in the
    // Bubble and Selection Sort tests, or I have to figure out how to move those steps into the
    // main function as is done in the Quick Sort example below. I believe it will be most useful
    // to put the list creation the main function and only put the sorting into the called function.
    // That way, other programs which may load the data in different ways can still re-use the
    // sort functions.
    // Quick Sort timing:
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

// Bubble Sort:
void sort_list_bubble()
{
    int i, j, n;
    char str[10][25] = {"David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
                        "Boris", "Edgar"};
    char s[25];

    n = sizeof(str) / sizeof(str[0]);

    printf("\nPrint the given names:\n");
    for (int i = 0; i < n; i++)
        printf("%d: %s\n", i, str[i]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (strcmp(str[i], str[j]) < 0)
            {
                strcpy(s, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], s);
            }
        }
    }

    printf("\nThe first names sorted are:\n");
    for (i = 0; i < n; i++)
        printf("%d: %s\n", i, str[i]);
}

// Selection Sort:
void sort_list_selection()
{
    int i, j, n, min_idx;   // In addition to the loop (i, j) and array 
                            // size (n), there's a variable the index
                            // of the lowest value.
    char str[10][25] = {"David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
                        "Boris", "Edgar"};
    char s[25];

    n = sizeof(str) / sizeof(str[0]);

    printf("\nPrint the given names:\n");
    for (int i = 0; i < n; i++)
        printf("%d: %s\n", i, str[i]);

    // One by one, move the boundary of the unsorted subarray.
    char minStr[MAX_LEN];
    

    for (i = 0; i < n; i++)
    {
        // Find the minimum element in the unsorted array.
        // Begin by making the first element's index and value the lowest.
        min_idx = i;
        strcpy(minStr, str[i]);
        
        // Loop through the second element (i+1) on.
        for (j = i+1; j < n; j++)
        {
            
            if (strcmp(minStr, str[j]) > 0) // If minimum is higher than str[j]...
            {
                strcpy(minStr, str[j]); // ...then re-set the low value and low index
                min_idx = j;            // to the lower ones found.
            }
        }
    
    
        if (min_idx != i) // If a lower value in the subarray was found...
        {
            char temp[MAX_LEN];
            strcpy(temp, str[i]); // ...swap the new lower value into 
            strcpy(str[i], str[min_idx]);
            strcpy(str[min_idx], temp); // This pushes the high value out in the list
        }                               // but it could push it too far.
  }

    printf("\nThe first names sorted are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", str[i]);
    }
}

// Quicksort
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
