// Filename: stdlink.c
// When complete, this file will be converted into a standard linked
// list header file for use by other programs using linked lists.
#include <stdio.h>
#include <stdlib.h> // Used for calloc() calls.
#include <stdbool.h>
#include <time.h>


typedef struct node {   // This struct, tagged 'node', has three members:
    int value;          // One member of the struct is an integer name 'value'.
    char alpha;         // One member of the struct is a letter named 'alpha'.
    struct node *next;  // The final member is a pointer named 'next'.
} Node;                 // 'struct node' is given the shorter alias of 'Node'
                        // but can referred to either way. 

// Print functions:
void print_list(Node *head);            // The *head pointer is often used as
void print_list_value(Node *head);      // a convenient flag for the whole list.
void print_list_alpha(Node *head);      // Once *head is known, the rest of the data     
void print_list_next_pointer(Node *head); // in the list can be garnered.
void print_list_full(Node *head);       
void print_list_node_memory_addresses_and_next_pointer(Node *head);

// Insert and delete Node functions:
Node *insert_full_head(Node *head, int new_value, char new_alpha);
Node *insert_at_tail(Node *head, int new_value, char new_alpha);
Node *delete_head(Node *head);
Node *delete_tail(Node *head);
Node *delete_first_match_value(Node *head, int delete_value, bool *was_deleted);
Node *delete_first_match_alpha(Node *head, char delete_alpha, bool *was_deleted);
Node *delete_first_match_value_and_alpha(Node *head, int delete_value, char delete_alpha, bool *was_deleted);
Node *delete_all_match_value(Node *head, int delete_value, int *num_deleted);

// Length, Search, Count, and Replace functions.
int length(Node *node);
bool is_member_value(Node *node, int find_value);
bool is_member_alpha(Node *node, int find_alpha);
int count_matches_value(Node *node, int find_value);
char count_matches_alpha(Node *node, int find_alpha);
void replace_matches_value(Node *node, int find_value, int replace_value);
void replace_matches_alpha(Node *node, char find_alpha, char replace_alpha);


int main(void)
{
  Node *list1_head = NULL; // Declare an empty list.

  list1_head = insert_full_head(list1_head, 1, 'a');
  list1_head = insert_full_head(list1_head, 3, 'b');
  list1_head = insert_full_head(list1_head, 5, 'c');
  list1_head = insert_full_head(list1_head, 0, 'd');
  list1_head = insert_full_head(list1_head, 9, '.');
  list1_head = insert_at_tail(list1_head, 2, 'x');
  list1_head = insert_at_tail(list1_head, 4, 'y');
  list1_head = insert_at_tail(list1_head, 6, 'z');
    
  print_list(list1_head);
  print_list_value(list1_head);
  print_list_alpha(list1_head);
  print_list_next_pointer(list1_head);
  print_list_full(list1_head);
  print_list_node_memory_addresses_and_next_pointer(list1_head);
    
  list1_head = delete_head(list1_head);

  printf("Full list after deleting the head:\n");
  print_list_full(list1_head);

  list1_head = delete_tail(list1_head);

  printf("Full list after deleting the tail:\n");
  print_list_full(list1_head);

  printf("Length of list: %d\n\n", length(list1_head));

  if (is_member_value(list1_head, 3))
      printf("3 found in list.\n");
  else
      printf("3 NOT found in list.\n");

  if (is_member_value(list1_head, 22))
      printf("22 found in list.\n");
  else
      printf("22 NOT found in list.\n\n");
    
  if (is_member_alpha(list1_head, 'a'))
      printf("a found in list.\n");
  else
      printf("a NOT found in list.\n");

  if (is_member_alpha(list1_head, 'j'))
      printf("j found in list.\n");
  else
      printf("j NOT found in list.\n\n");

  printf("The value 3 was found %d time(s).\n\n", count_matches_value(list1_head, 3));

  printf("The character b was found %d time(s).\n\n", count_matches_alpha(list1_head, 'b'));

  replace_matches_value(list1_head, 3, 30);
    printf("List after replacing 3 with 30.\n");
    print_list(list1_head);

  replace_matches_alpha(list1_head, 'c', 'G');
    printf("List after replacing c with G.\n");
    print_list(list1_head);

  bool deleted_value;
  list1_head = delete_first_match_value(list1_head, 30, &deleted_value); // The memory address of the
  if (deleted_value)                                              // empty boolean 'deleted' is
    printf("A node with value 30 was deleted.\n\n");           // passed to the delete...
  else                                                      // and is returned set to true
    printf("A node with value 30 was NOT deleted.\n\n");       // or false.

  printf("List after attempting to delete 30...\n\n");
  print_list(list1_head);

  bool deleted_alpha;
  list1_head = delete_first_match_alpha(list1_head, 'G', &deleted_alpha); // The memory address of the
  if (deleted_alpha)                                              // empty boolean 'deleted' is
    printf("A node with character G was deleted.\n\n");           // passed to the delete...
  else                                                      // and is returned set to true
    printf("A node with character G was NOT deleted.\n\n");       // or false.

  printf("List after attempting to delete G...\n\n");
  print_list(list1_head);

  bool deleted_value_and_alpha;
  list1_head = delete_first_match_value_and_alpha(list1_head, 2, 'x', &deleted_value); // The memory address of the
  if (deleted_value_and_alpha)                                              // empty boolean 'deleted' is
    printf("A node with value and character of (2, x) was deleted.\n\n");           // passed to the delete...
  else                                                      // and is returned set to true
    printf("A node with value and character of (2, x) was NOT deleted.\n\n");       // or false.

  printf("List after attempting to delete (2, x)...\n\n");
  print_list(list1_head);

  int num_deleted = 0;
  list1_head = delete_all_match_value(list1_head, 30, &num_deleted);
  printf("\nList after deleting all 30s.\n");
  print_list(list1_head);
  printf("Number of deleted 30s: %d\n", num_deleted);

  // Test performance.
  // Create two large lists:
  Node *list2 = NULL, *list3 = NULL;  // Declare two empty lists.
  for (int i = 0; i < 50000; i++)     // Insert 50,000 nodes...
    list2 = insert_full_head(list2, i % 10, 'a');
  for (int i = 0; i < 100000; i++)
    list3 = insert_full_head(list3, i % 10, 'b');  

  clock_t tic, toc;
  tic = clock();
  list2 = delete_all_match_value(list2, 4, &num_deleted);
  toc = clock();
  printf("\ndelete_all_match_value in 50,000 nodes: %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  printf("elements deleted: %d\n", num_deleted);

  return 0;
}

void print_list(Node *head)
{
  Node *current;
  current = head;
  int i = 0;
  printf("Full list of integers and characters:\n");

  while (current != NULL)
  {
    printf("Node %d: %3d, %c\n", i, current->value, current->alpha );
    i++;
    current = current->next;
  }
  printf("\n");
}

void print_list_value(Node *head)
{
  Node *current;
  current = head;
  int i = 0;
  printf("List of integers:\n");

  while (current != NULL)
  {
    printf("Node %d: %3d\n", i, current->value );
    i++;
    current = current->next;
  }
  printf("\n");
}

void print_list_alpha(Node *head)
{
  Node *current;
  current = head;
  int i = 0;
  printf("List of characters:\n");

  while (current != NULL)
  {
    printf("Node %d: %c\n", i, current->alpha );
    i++;
    current = current->next;
  }
  printf("\n");
}

void print_list_next_pointer(Node *head)
{
  Node *current;
  current = head;
  int i = 0;
  printf("List of next node pointers:\n");

  while (current != NULL)
  {
    printf("Node %d: %p\n", i, current->next);
    i++;
    current = current->next;
  }
  printf("\n");
}

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

void print_list_node_memory_addresses_and_next_pointer(Node *head)
{
  Node *current;
  current = head;
  int i = 0;
  printf("List of node memory addresses and next node pointers:\n");

  while (current != NULL)
  {
    printf("Node %d: %p, %p\n", i, current, current->next);
    i++;
    current = current->next;
  }
  printf("\n");
}

Node *insert_full_head(Node *head, int new_value, char new_alpha)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;
  new_node->alpha = new_alpha;

  if (head == NULL) return new_node;        // If the list head pointer passed to the function
  else                                      // was NULL, the list was previously empty and
  {                                         // the new node is the head. Otherwise, the
    new_node->next = head;                  // new node's next pointer is pointed toward
    return new_node;                        // the old head. The new node address is returned
  }                                         // as the new head address, so that the list1_head
}                                           // (pointer) is updated.

Node *insert_at_tail(Node *head, int new_value, char new_alpha)
{
  Node *new_node = calloc(1, sizeof(Node)); // New node created on the heap.
  new_node->value = new_value;              // Value of new node set to passed integer.
  new_node->alpha = new_alpha;              // Alpha of new node set to passed character.

  if (head == NULL) return new_node;        // If the list head pointer passed to the function
  else                                      // was NULL, the list was previously empty and
  {                                         // and the new node (even though added to is the
                                            // "tail") is the new head also.
    Node *current = head;   //  A current node (pointer) variable is set equal to the head.                   
    while (current->next != NULL) current = current->next; // 'current' is updated until there
                                                           // is no next one.
    current->next = new_node; // That previously empty next is set to point to the new tail.                              
    return head;    // Return head so the list1_head variable can be updated.
  }
}

Node *delete_head(Node *head)
{
  if (head == NULL) return NULL;
  else
  {
    Node *to_return = head->next;
    free(head);
    return to_return;
  }
}

Node *delete_tail(Node *head)
{
  if (head == NULL) return NULL;
  else if (head->next == NULL) // If head->next is null, there's only one Node.
  {
    free(head); // Delete the one Node.
    return NULL;
  }
  else
  {
    Node *current = head;
    Node *prev = NULL;

    while (current->next != NULL)
      {
        prev = current;
        current = current->next;
      }
      prev->next = NULL;
      free(current);
      return head;
      }
  }

// This function deletes that first Node that matches the value passed to it.
// It handles four cases: (1) the list is empty, (2) the head has the value, so it must
// be deleted and the second Node's pointer must be sent back as the new head, (3) the
// value is found in a later position, so that the ->next pointer in the previos Node
// must be pointed to the Node after the Node that's deleted, or (4) the value is not
// found in the list at all.
Node *delete_first_match_value(Node *head, int delete_value, bool *was_deleted)
{
  if (head == NULL) 
  {
    *was_deleted = false;
    return NULL;
  }

  if (head->value == delete_value)
  {
    Node *temp = head->next;
    free(head);
    *was_deleted = true;
    return temp;  // When the head is deleted, we want to report that whatever Node it
                  // was pointing to is now the new head.
  }              
    
  Node *current = head->next;
  Node *prev = head;

  while (current != NULL)
  {
    if (current->value == delete_value)
    {
      prev->next = current->next;
      free(current);
      *was_deleted = true;
      return head;
    }
    prev = current;
    current = current->next;
  }

  *was_deleted = false;
  return head;
}

Node *delete_first_match_alpha(Node *head, char delete_alpha, bool *was_deleted)
{
  if (head == NULL) 
  {
    *was_deleted = false;
    return NULL;
  }

  if (head->alpha == delete_alpha)
  {
    Node *temp = head->next;
    free(head);
    *was_deleted = true;
    return temp;  // When the head is deleted, we want to report that whatever Node it
                  // was pointing to is now the new head.
  }              
    
  Node *current = head->next;
  Node *prev = head;

  while (current != NULL)
  {
    if (current->alpha == delete_alpha)
    {
      prev->next = current->next;
      free(current);
      *was_deleted = true;
      return head;
    }
    prev = current;
    current = current->next;
  }

  *was_deleted = false;
  return head;
}

Node *delete_first_match_value_and_alpha(Node *head, int delete_value, char delete_alpha, bool *was_deleted)
{
  if (head == NULL) 
  {
    *was_deleted = false;
    return NULL;
  }

  if ((head->value == delete_value) && (head->alpha == delete_alpha))
  {
    Node *temp = head->next;
    free(head);
    *was_deleted = true;
    return temp;  // When the head is deleted, we want to report that whatever Node it
                  // was pointing to is now the new head.
  }              
    
  Node *current = head->next;
  Node *prev = head;

  while (current != NULL)
  {
    if ((current->value == delete_value) && (current->alpha == delete_alpha))
    {
      prev->next = current->next;
      free(current);
      *was_deleted = true;
      return head;
    }
    prev = current;
    current = current->next;
  }

  *was_deleted = false;
  return head;
}

Node *delete_all_match_value(Node *head, int delete_value, int *num_deleted)
{
  *num_deleted = 0; // Why does *num_deleted continue to be referenced with an *
                    // but, say head, which was also passed with an * is not?
  if (head == NULL) return NULL; // If list is empty, return NULL.

  Node *current, *temp, *new_head;
  current = head;
  *num_deleted = 0; // Pass by reference (using the memory address);

  while (current->value == delete_value)
  {
    temp = current;
    current = current->next;
    free(temp);
    *num_deleted = *num_deleted + 1;

    if (current == NULL) return NULL;
  }
  new_head = current;

  while (current->next != NULL)
  {
    if (current->next->value == delete_value)
    {
      temp = current->next;
      current->next = current->next->next;
      free(temp);
      *num_deleted = *num_deleted + 1;
    }
    else current = current->next;
  }
return new_head;
}

int length(Node *node)
{
  if (node == NULL) return 0;
  else return 1 + length(node->next);
}

bool is_member_value(Node *node, int find_value)
{
  if (node == NULL) return false; // Value not found in an empty list.
  else if (node->value == find_value) return true; // If value is found, return true.
  else return is_member_value(node->next, find_value); // Recursively search.
}

bool is_member_alpha(Node *node, int find_alpha)
{
  if (node == NULL) return false; // Value not found in an empty list.
  else if (node->alpha == find_alpha) return true; // If value is found, return true.
  else return is_member_alpha(node->next, find_alpha); // Recursively search.
}

int count_matches_value(Node *node, int find_value) // (Recursive.)
{                                               
  if (node == NULL) return 0;
  else if (node->value == find_value)
    return 1 + count_matches_value(node->next, find_value);
  else return count_matches_value(node->next, find_value);
}

char count_matches_alpha(Node *node, int find_alpha) // (Recursive.)
{                                               
  if (node == NULL) return 0;
  else if (node->alpha == find_alpha)
    return 1 + count_matches_alpha(node->next, find_alpha);
  else return count_matches_alpha(node->next, find_alpha);
}

void replace_matches_value(Node *node, int find_value, int replace_value)
{
  if (node != NULL)  // If the head node is NULL (indicating an empty list) do nothing.
  {
    if (node->value == find_value) node->value = replace_value;
    replace_matches_value(node->next, find_value, replace_value);
  }
}

void replace_matches_alpha(Node *node, char find_alpha, char replace_alpha)
{
  if (node != NULL)  // If the head node is NULL (indicating an empty list) do nothing.
  {
    if (node->alpha == find_alpha) node->alpha = replace_alpha;
    replace_matches_alpha(node->next, find_alpha, replace_alpha);
  }
}