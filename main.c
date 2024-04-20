// file name: main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "llist_int.h" // File that defines interfaces.

int main(void)
{
    int num_elements = 10000;
    clock_t tic, toc;
    printf("\n\n");

    int *array = malloc(num_elements * sizeof(int));
    for (int i = 0; i < num_elements; i++) 
        array[i] = i;

    tic = clock();
    for (int i = 1; i < num_elements; i++)
    {
        int *newarray = malloc((num_elements - i) * sizeof(int));
        for (int j = 0; j < num_elements - i; j++)
        {
            newarray[j] = array[j + i];
        }
        free(array);
        array = newarray;
    }
    toc = clock();

    printf("Elapsed time to shrink an array %d times: %f seconds\n", num_elements, 
                    (double)(toc - tic) / CLOCKS_PER_SEC);

    free(array);

    Node *listp = NULL;
    for (int i = 0; i < num_elements; i++)
    {
        listp = insert_at_head(listp, i);
    tic = clock();
    for (int i = 0; i< num_elements; i++)
        listp = delete_at_head(listp);
    toc = clock();
    }

    printf("Elapsed time to delete %d head nodes from a linked list: %f seconds\n", 
                    num_elements, (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}