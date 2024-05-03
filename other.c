/** 
 * Alternate file using the same linked list library (llist_int.h)
 * This file uses comment markers that Doxygen can interpret.
 * 
 * @file other.c
 * @author David Long
 * @date Friday, April 19, 2024
 * 
 * The purpose of this file was simply to include the same
 * linked list library for a list of integer values (llist_int.h)
 * that is used by another file (main.c) to illustrate the
 * a principle of modular development – that *multiple* files
 * can include and call functions in *one* common library file. 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "llist_int.h" // File that defines interfaces.

int main(void)
{
    srand(time(NULL)); /**< Instantiate a random number generator. */
    Node *list11 = NULL; /**< Instantiate a new list. */
    for (int i = 0; i < 10; i++) /**< Setup a loop to... */
        list11 = insert_at_head(list11, rand() % 99); /**< Populate list with random numbers up to 99.*/
    sort_list(list11); /**< Sort the list. */
    list11 = insert_at_head(list11, 5); /**> Add two nodes a the front of the file with the value of 5.*/
    list11 = insert_at_head(list11, 5);
    print_list(list11); /**< Print the list. */

    return 0;
}