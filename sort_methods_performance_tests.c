#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 100

// Sort Functions:
void sort_list_bubble(); // "Bubble" sort method - not recommended. (Slammed by Knuth.)
//void sort_list_selection(char arr[][MAX_LEN], int n);
void sort_list_selection();

int main()
{
    
clock_t tic, toc;
tic = clock();
sort_list_bubble();
toc = clock();
printf("\nBubble (or sinking) sort method time: %fs\n\n", (double)(toc - tic) / CLOCKS_PER_SEC);


tic = clock();
sort_list_selection();
toc = clock();
printf("\nSelection sort method time: %fs\n\n", (double)(toc - tic) / CLOCKS_PER_SEC);

return 0;

}

// Bubble Sort:
void sort_list_bubble()
{
    int i, j, n;
    char str[MAX_LEN][MAX_LEN], s[100];
    printf("Enter the number of first names: ");
    scanf("%d", &n);

    printf("\nEnter %d first names in random order:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }

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
    {
        printf("%s\n", str[i]);
    }
}

// Selection Sort:
// void sort_list_selection(char arr[][MAX_LEN], int n)
void sort_list_selection()
{
    int i, j, min_idx, n;
    char str[MAX_LEN][MAX_LEN], s[100];
    printf("Enter the number of first names: ");
    scanf("%d", &n);

    printf("\nEnter %d first names in random order:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }

    // One by one, move the boundary of the unsorted subarray.
    char minStr[MAX_LEN];
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in the unsorted array.
        int min_idx = i;
        strcpy(minStr, str[i]);
        for (j = i+1; j < n; j++)
        {
            // If min is greater than arr[j]...
            if (strcmp(minStr, str[j]) > 0)
            {
                strcpy(minStr, str[j]);
                min_idx = j;
            }
        }
    
    // Swap the found minimum element with the first element in subarray.
    if (min_idx != i)
    {
        char temp[MAX_LEN];
        strcpy(temp, str[i]); // Swap item[pos] and item[i]
        strcpy(str[i], str[min_idx]);
        strcpy(str[min_idx], temp);
    }  
  }

  printf("\nThe first names sorted are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", str[i]);
    }
}