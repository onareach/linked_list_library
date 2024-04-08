#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// People have asked why the word "struct node" appears twice in the struct declaration below – both
// before the {} and inside the {}. From what I can gather, the "struct node" inside the {}
// is not recursive – that is, it is not calling itself. Instead, you can think of it as a 
// qualifier of the "*next" member. In short, it's telling you that the *next member is the
// pointer variable for the struct. In other words, *next is not just any pointer, but THE
// pointer in struct that points to the next node. I prefer to think of "struct node *" as
// the datatype declaration for whatever variable name it appears in front of. In other words,
// "struct node *" is to "next" as "int" is to "value".
// It's useful to know that in C++ the need for the "struct" keyword inside the {} was eliminated. 
// However, in C++, you still see "struct" inside the "struct node" declaration in C++ either 
// because it is ignorantly copied or, better, because it makes the code backward-compatible with C.
typedef struct node {
    int value;
    char alpha;
    struct node * next;
} Node;

// Print functions:
void print_list_full(Node *head); 

// Insert and delete Node functions:
Node *insert_full_head(Node *head, int new_value, char new_alpha);


int main()
{
    // In the declaration below, the Node (struct) datatype is followed by a declaration of the 
    // name of a pointer to its head node. Later, if you want to operate on the list, you
    // simply place the phrase " list1_head = " (with no *) before the name of the function
    // that operates on it. There's nothing special about the name "list1_head" but the naming
    // identifies this as "list 1" out of possibly many lists used in the code, and "head" is a
    // reminder that this variable points to the head node of list1. Why the = sign? Again, 
    // mainly out of convention. The = sign is simply an efficient way of linking the list1_head
    // pointer to the function that is going to operate on it. Personally, I might use the 
    // symbol <=> as a way of associating the list with the function that is to operate on it,
    // but that would involve three characters ( < and = and > )instead of one (=).
    Node *list1_head = NULL;

    printf("\nThe address of the pointer list1_head itself: %p\n", &list1_head);
    printf("The value that the pointer list1_head currently holds: %p\n", list1_head);

    list1_head = insert_full_head(list1_head, 1, 'a');
  
    printf("\nList of Nodes after inserting a head:\n");
    print_list_full(list1_head);

    printf("The 0x0 value in the .next value of the Nodes list, shows there \n");
    printf("is no next node.\n");

    printf("\nThe address of the pointer list1_head itself: %p\n", &list1_head);
    printf("The value that the pointer list1_head currently holds: %p\n", list1_head);
    
    printf("\nNow that there is a head node, the list1_head pointer now holds a value.\n");
    printf("This latter value will change as the head node is replaced, but the memory \n");
    printf("address of the pointer itself will remain fixed as long as the list exists.\n");

    return 0;

}

// Print functions:
void print_list_full(Node *head)
{
  Node *current;
  current = head;
  int i = 0;
  printf("List of integers, characters, and next node pointer:\n");

  while (current != NULL)
  {
    printf("Node %d: %3d, %c, %p\n", i, current->value,
        current->alpha, current->next);
    i++;
    current = current->next;
  }
  printf("\n");
}

// Insert functions:
Node *insert_full_head(Node *head, int new_value, char new_alpha)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;
  new_node->alpha = new_alpha;

  if (head == NULL) return new_node;        
  else                                     
  {                                       
    new_node->next = head;                  
    return new_node;                        
  }                                         
}                                          