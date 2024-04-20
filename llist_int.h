// file name: llist_full.h
#include <stdbool.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

// Print functions:
void print_list(Node *head);
void print_two_lists(Node *head1, Node *head2);
 
// Insert and Delete functions:
Node *insert_at_head(Node *head, int new_value);
Node *insert_at_tail(Node *head, int new_value);
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted);
Node *efficient_delete_match(Node *head, int delete_value, int *num_deleted);
void delete_duplicates(Node *head);
Node *insert_after(Node *head, int new_value, int after_value);
Node *delete_list(Node *node);

// Append functions:
Node *append_list(Node *head1, Node *head2);

// Reverse Functions:
Node *reverse_list(Node *head);

// Sort Functions:
void sort_list(Node *head); // "Bubble" sort method - classic array sorting method.
//void merge_sorted_lists(Node *list1_head, Node *list2_head);

// Length, Search, Count, and Replace fucntions:
int length(Node *head);
int recursive_length(Node *node);
bool is_member_r(Node *node, int find_value);
int count_matches_r(Node *node, int find_value);
void replace_matches_r(Node *node, int find_value, int replace_value);

// Two List Functions:
void add_lists(Node *head1, Node *head2);
void add_lists_shorter_recursive_version(Node *list1, Node *list2);
Node *duplicate_list(Node *switch_head);
Node *duplicate_list_shorter_version_recursive(Node *node);
Node *test_two_parameter_one_return(Node *node1, Node *node2);
Node *merge_sorted_lists(Node *list1, Node *list2);

// Diagnostic function:
int length_var_test(Node * node);
