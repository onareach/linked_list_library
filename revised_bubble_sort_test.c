// file name: revised_bubble_sort_test.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sort_list_bubble(const char * arr_bub[], int n);

int main()
{
    const char * arr_bub[] = 
    {
        "David", "Bob", "Joe", "Mary", "Tony", "Laura", "Elliot", "George",
        "Boris", "Edgar"
    };
    
    int n = sizeof(arr_bub) / sizeof(arr_bub[0]);

    printf("List before bubble sort: \n");
    for (int i = 0; i < n; i++)
        printf("%3d:  %s\n", i+1, arr_bub[i]);

    sort_list_bubble(arr_bub, n);

    printf("\nList after bubble sort: \n");
    for (int i = 0; i < n; i++)
        printf("%3d:  %s\n", i+1, arr_bub[i]);

    return 0;
}

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