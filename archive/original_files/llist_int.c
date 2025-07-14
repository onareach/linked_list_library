// file name: llist_int.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "llist_int.h"

// Print Functions:
void print_list(Node *head)
{
  Node *current;
  current = head;
  int i = 0;

  while (current != NULL)
  {
    printf("(Node%3d: %3d)\n", i, current->value );
    i++;  // Increment the virtual index.
    current = current->next;
  }
  printf("\n");
}

// This function illustrates simply how (1) two lists handles are passed to a function.
void print_two_lists(Node *head1, Node *head2)
{
    Node *current;
    current = head1;
    int i = 0;

    while (current != NULL)
    {
        printf("(Node%3d: %3d)\n", i, current->value );
        i++;  // Increment the virtual index.
        current = current->next;
    }
    printf("\n");

    // Switch current pointer to beginning of List #2
    current = head2;
    i = 0; // Reset the "virtual index/""

    while (current != NULL)
    {
        printf("(Node%3d: %3d)\n", i, current->value );
        i++;
        current = current->next;
    }
    printf("\n");
}

// Insert Functions:
Node *insert_at_head(Node *head, int new_value)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;
  if (head == NULL) return new_node;
  else
  {
    new_node->next = head;
    return new_node;
  }
}

Node *insert_at_tail(Node *head, int new_value)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;

  if (head == NULL) return new_node;
  else
  {
    Node *current = head;
    while (current->next != NULL) current = current->next;
    current->next = new_node;
    return head;
  }
}

// Delete Functions:
Node *delete_at_head(Node *head)
{
  if (head == NULL) return NULL;
  else
  {
    Node *to_return = head->next;
    free(head);
    return to_return;
  }
}

Node *delete_at_tail(Node *head)
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

Node *efficient_delete_match(Node *head, int delete_value, int *num_deleted)
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

// This function deletes that first Node that matches the value passed to it.
// It handles four cases: (1) the list is empty, (2) the head has the value, so it must
// be deleted and the second Node's pointer must be sent back as the new head, (3) the
// value is found in a later position, so that the ->next pointer in the previos Node
// must be pointed to the Node after the Node that's deleted, or (4) the value is not
// found in the list at all.
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted)
{
  if (head == NULL) 
  {
    *was_deleted = false;
    return NULL;
    printf("No nodes with value X found.\n");
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

// Append Functions:
Node *append_list(Node *head1, Node *head2)
{
  if (head1 == NULL) return head2;

  Node *current = head1;
  while (current->next != NULL) current = current->next; // Find the end of list 1.
  current->next = head2; // Point the tail of list 1 to the head of list 2 to connect them. 
  return head1;
}

// Reverse Functions:
Node *reverse_list(Node *head)
{
  if (head == NULL) return NULL; // If list is empty, there's nothing to reverse.
  if (head->next == NULL) return head;  // If list has one node, return the old
                                        // head as still in the head position.
  Node *current = head;             // Create current pointer to traverse the list.
  Node *next_node = head->next;     // Create a holder for the pointer next in the list.

  current->next = NULL; // Set the head node's next point to NULL, making it the tail.

  while (next_node != NULL)
  {
    Node *tmp = next_node->next;
    next_node->next = current; // The next node's next value gets pointed to the former head.
    current = next_node; // The current (index holder) gets moved to the node's address.
    next_node = tmp; // The next_node pointer gets moved forward like current just did.
  }
  return current; // At the end, current has moved to the former tail, and is now the head.
}

// Sort Functions:
// Bubble Sort:
void sort_list(Node *head)
{
  if (head == NULL) return ; // If there's nothing to sort, return nothing (nothing sorted).
  if (head->next == NULL) return ; // If there's only one node, return nothing (nothing sorted).

  bool swapped = false;

  do
  {
    swapped = false;
    Node *current = head;
    Node *prev = NULL;

    while (current->next != NULL)
    {
      prev = current;
      current = current->next;
      if (current != NULL)
      {
        if (current->value < prev->value)
        {
          int temp;
          temp = prev->value;
          prev->value = current->value;
          current->value = temp;
          swapped = true;
        }
      }
    }
  } while (swapped);  
}

// Find List Length, Count Matches, Replace Matches
int length(Node *head)
  {
    Node *current;
    current = head;
    int length = 0;
    while (current != NULL)
    {
      current = current->next;
      length++;
    }
    return (length);
  }

int recursive_length(Node *node)
{
  if (node == NULL) return 0;
  else return 1 + recursive_length(node->next);
}

bool is_member_r(Node *node, int find_value)
{
  if (node == NULL) return false; // Value not found in an empty list.
  else if (node->value == find_value) return true; // If value is found, return
                                                   // true. Run until true.
  else return is_member_r(node->next, find_value); // If value never found,
}                                                    // tail node with .next =
                                                     // NULL will trigger first
                                                     // line to return false.

int count_matches_r(Node *node, int find_value) // Find the number of times a value
{                                               // is found in the list. (Recursive.)
  if (node == NULL) return 0;
  else if (node->value == find_value)
    return 1 + count_matches_r(node->next, find_value);
  else return count_matches_r(node->next, find_value);
}

void replace_matches_r(Node *node, int find_value, int replace_value)
{
  if (node != NULL)  // If the head node is NULL (indicating an empty list) do nothing.
  {
    if (node->value == find_value) node->value = replace_value;
    replace_matches_r(node->next, find_value, replace_value);
  }
}

// Added Delete function:
void delete_duplicates(Node *head)
{
  if (head == NULL) return ; // If the list is emtpy, do nothing.
  if (head->next == NULL) return ; // If there's only one node, do nothing.

  // There are two loops below. The outside loop tranverses the list once, stopping
  // on each Node and checking (with the inside loop) to see if any of the other 
  // Nodes has the same value.
  Node *current1, *current2, *duplicate; // Declare pointers to track the nodes.
  current1 = head;  // Set the current1 Node pointer to the first Node.  
  while (current1 != NULL && current1->next != NULL)
  {
    current2 = current1;
    while (current2->next != NULL) // Restart when inner loop reaches end of list.
    {
      if (current1->value == current2->next->value)
        {
          duplicate = current2-> next; // Store the pointer of the Node to be deleted.
          current2->next = current2->next->next; // Connect the Node to the next, next
                                                  // Node before deleting the one in between.
          free(duplicate); // Delete the duplicate Node.
        }
        else current2 = current2->next; // Ratchet the inner loop forward.
    }
    current1 = current1->next; // Ratchet the out loop forward.
  }
}

// Added Insert function:
// This function is designed to insert the new value as the head if the list was
// previously empty, and insert the new value at the tail if none of the Nodes has
// the value specified to insert after. 
Node *insert_after(Node *head, int new_value, int after_value)
{
  Node *new_node = calloc(1, sizeof(Node)); // Create the new Node on the heap.
  new_node->value = new_value; // Set the value of the new Node to the value passed to the function.
  
  if(head == NULL) return new_node;  // If the list is empty, return the memmory address of the new
                                     // Node as the head address.
  else
  {
    Node *current = head; // Instantiate the current node tracker, set equal to the head Node.
    while (current->next != NULL) // While we're not at the end of the list...
    {
      if (current->value == after_value) // If the current Node's value is the value we want to insert
      {                                  // the new Node after...
        new_node->next = current->next;  // set the new Node's next pointer to the current Node's next pointer...
        current->next = new_node;        // and aim the current Node's next pointer at the new Node.
        return head;                     // Return the old (unchanged) head memory address.
      }
      else current = current->next; // Otherwise, move on the next Node to search for the "after value."
    }
    new_node->next = current->next; // If we've gotten all the way to the end of the list (without finding
                                    // the "after value"...
    current->next = new_node;       // aim the last Node next pointer to the new Node.
    return head;                    // Returh the old (unchanged) head memory address.
  }
}

// Add Delete function (that deletes entire list):
Node *delete_list(Node *node)
{
  if (node != NULL) // Traverse the list...
  {
    delete_list(node->next); // Save the next Node's memory address.
    free(node);  // Delete the current address.
  }
  return NULL;
}

void add_lists(Node *head1, Node *head2)
{
    Node *current1;
    Node *current2;
    current1 = head1;
    current2 = head2;  
    int i = 0;

    while ((current1 != NULL) && (current2 != NULL))
    {
        current1->value = (current1->value + current2->value);  
        i++;
        current1 = current1->next;
        current2 = current2->next;
    }
}

// In the following function, after eliminating the possibility of one list being exhausted,
// addition of the values of the current nodes passed to the function occurs on line 2, and 
// recursivly sending the next rung of corresponding nodes back into the function occurs on line 3.
// Note that in the recursive calls, it's no longer the head nodes of each list being passed, but
// instead is the next nodes in each list.
void add_lists_shorter_recursive_version(Node *list1, Node *list2) // Arguments NOT always the head nodes.
{                                                                  // Instead of "list1" and "list2",
    if (list1 == NULL || list2 == NULL) return ;                   // it might be better to label the
    list1->value = list1->value + list2->value;                    // arguments "list1_node" and "list2node".
    add_lists(list1->next, list2->next); // Recursively pass the next nodes of both lists to itself.
}

Node *duplicate_list(Node *switch_head)
{
    if (switch_head == NULL) return switch_head;
    else
    {
        // Create pointers needed to store values or traverse the old and new lists.
        Node *original_head; // Instantiate a pointer to hold inbound list's address.
        Node *current_old; // Instantial another pointer to traverse the list being duplicated.
        Node *current_new; // Instantial another pointer to traverse the new duplicate list.

        // Store the original list's head.
        original_head = switch_head; 
        
        // CREATE THE HEAD OF THE NEW DUPLICATE LIST.
        Node *new_head = calloc(1, sizeof(Node));

        // Set the *value* of the new head node equal to the old list's head value.
        new_head->value = original_head->value;

        // Store the address of the new list's head to be returned after the new
        // list is complete.
        switch_head = new_head;

        // Set the tracer of the old list to its head's address.
        current_old = original_head;
        // Set the tracer of the new list to its head's address.
        current_new = new_head;
        
        // IF THERE IS A SECOND NODE IN ORIGINAL LIST, ADD A SECOND NODE TO THE NEW LIST AND 
        // POINT THE NEW LIST'S HEAD AT IT.
        if (current_old->next != NULL) // If the old list has a second node...
        {
            Node *new_node = calloc(1, sizeof(Node)); // ...create a second node for the new list...
            switch_head->next = new_node; // and point the new list's head at it.
            new_node->value = current_old->next->value; // Load the new second node with the value
                                                        // stored in the original second node.
        }
        else // ...else if the old list has only one node, return the new list's head now.
            return switch_head;

        current_old = current_old->next->next; // Go the third node of old list.
        current_new = current_new->next;       // Go to the second node of new list.

        int length = recursive_length(original_head); // Get length of original list.
        
        for (int i = 0; i < (length - 2); i++)
            {
                Node *new_node = calloc(1, sizeof(Node)); // ...create a new node for the new list...
                current_new->next = new_node; // Set the previous node's next pointer to the new node.
                new_node->value = current_old->value; // Set the new node's value equal corresponding
                                                      // node of the old list.
                current_old = current_old->next;    // Move to the next node of the old list.
                current_new = current_new->next;    // Move to the next node of the new list (one behind
                                                    // the old list.)
            }
        
        // Return the new duplicate list's head:
        return switch_head;
    }
}

// Here's a recursive version of a duplicate list function.
// Unlike the duplicate_list function above, there's no need to segment out the creation of the
// head node, second node, and following nodes.  And the "looping" is taken care of by the
// recursive call of the function to itself using the original and new list's *next* values.
Node *duplicate_list_shorter_version_recursive(Node *node)
{
    if (node == NULL) return NULL; // When the tail is found, its next value should be NULL.

    Node *new_node = calloc(sizeof(Node), 1); // Create a node of a new list.
    new_node->value = node->value; // Pull the value of the corresponding from the old list.

    // The next line very efficiently sets the pointer of the new node to the node that's
    // created by calling itself and take the new node address as its return.
    new_node->next = duplicate_list_shorter_version_recursive(node->next);

    // This is an amazingly tight function. Almost every line serves two purposes. It would
    // be worth studying to figure out why so much of the code serves in more than one way.
    // It reminds me of the reflexive way in which the mind can watch itself watching itself.
    // This is baffling to a linear mindset. To that mindset, it seems deceptive in the way
    // it loops back on itself, but I am more convinced each day that this is a normal dynamic
    // that we ought to train ourselves grasp naturally. 

    // This is a great example of nature's elegant simplicity.

    return new_node;
}


Node *merge_sorted_lists(Node *list1, Node *list2)
{
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if ((list1 == NULL) && (list2 == NULL)) return NULL;
    
    // Create three pointers to trace which node in the two old lists
    // and the new list is being examined, as well as a holder for the 
    // head of the new list.
    Node *l1current, *l2current, *new_current, *new_head;

    // Set the tracers at the beginning of the two old lists.
    l1current = list1;
    l2current = list2;

    // Compare the first nodes of the two old lists. Depending on
    // which is lower, make that the head of the new merged list
    // and ratchet the tracer forward in the list who first node
    // was captured in the new list.
    if (l1current->value <= l2current->value)
    {
        new_head = l1current;
        l1current = l1current->next; // Ratchet forward in List 1
    }
    else
    {
        new_head = l2current;
        l2current = l2current->next; // Ratchet forward in List 2
    }
    
    // Set the po of the new list at its first node.
    new_current = new_head;
    
    // Now that the head of the new list is stored, as long as there
    // are nodes left in both lists, we continue to compare the values
    // of the current nodes in each list and point the tail of the new list at it.
    while (l1current != NULL && l2current != NULL)
    {
        if (l1current->value <= l2current->value)
        {
            new_current->next = l1current;
            new_current = l1current; // Move the new list tracer into the node just added to the tail of the new list.
            l1current = l1current->next; // Ratchet forward in list 1
        }
        else
        {
            new_current->next = l2current;
            new_current = l2current; // Move the new list tracer into the node just added to the tail of the new list.
            l2current = l2current->next; // Ratchet forward in list 1    
        }
    }
    // Then, after one of the lists has run out of nodes, we point the tail of the
    // new list at the remaining nodes of whatever list still has nodes.
    if (l1current == NULL)
    {
        new_current->next = l2current;
    }
    else if (l2current == NULL)
    {
        new_current->next = l1current;
    }

    return new_head;
}

// The purpose of this test function is to verifying experimentally
// that the list being returned by the function is not required to 
// have any connection to the two (or more) lists passed to in the
// the argument.
Node *test_two_parameter_one_return(Node *node1, Node *node2)
{
    Node *new_head_node = calloc(sizeof(Node), 1);
    new_head_node->value = node1->value;
    new_head_node->next = node2;
    
    return new_head_node;
}
