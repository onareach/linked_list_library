/**
 * @file llist_int.h
 * @brief Integer Linked List Library - Header File
 * @author David Long
 * @date 2024
 * 
 * This header file defines the interface for a comprehensive integer linked list library.
 * The library provides functions for creating, manipulating, and managing singly linked lists
 * that store integer values.
 */

#ifndef LLIST_INT_H
#define LLIST_INT_H

#include <stdbool.h>

/**
 * @brief Node structure for integer linked list
 * 
 * Each node contains an integer value and a pointer to the next node in the list.
 */
typedef struct node {
    int value;              /**< Integer value stored in the node */
    struct node *next;      /**< Pointer to the next node in the list */
} Node;

/* ========================================================================
 * PRINT FUNCTIONS
 * ======================================================================== */

/**
 * @brief Print all elements in a linked list
 * @param head Pointer to the head of the list
 */
void print_list(Node *head);

/**
 * @brief Print two linked lists side by side
 * @param head1 Pointer to the head of the first list
 * @param head2 Pointer to the head of the second list
 */
void print_two_lists(Node *head1, Node *head2);

/* ========================================================================
 * INSERT FUNCTIONS
 * ======================================================================== */

/**
 * @brief Insert a new node at the head of the list
 * @param head Pointer to the current head of the list
 * @param new_value Value to insert
 * @return Pointer to the new head of the list
 */
Node *insert_at_head(Node *head, int new_value);

/**
 * @brief Insert a new node at the tail of the list
 * @param head Pointer to the head of the list
 * @param new_value Value to insert
 * @return Pointer to the head of the list
 */
Node *insert_at_tail(Node *head, int new_value);

/**
 * @brief Insert a new node after the first occurrence of a specific value
 * @param head Pointer to the head of the list
 * @param new_value Value to insert
 * @param after_value Value after which to insert the new node
 * @return Pointer to the head of the list
 */
Node *insert_after(Node *head, int new_value, int after_value);

/* ========================================================================
 * DELETE FUNCTIONS
 * ======================================================================== */

/**
 * @brief Delete the head node from the list
 * @param head Pointer to the current head of the list
 * @return Pointer to the new head of the list
 */
Node *delete_at_head(Node *head);

/**
 * @brief Delete the tail node from the list
 * @param head Pointer to the head of the list
 * @return Pointer to the head of the list
 */
Node *delete_at_tail(Node *head);

/**
 * @brief Delete the first node with a specific value
 * @param head Pointer to the head of the list
 * @param delete_value Value to delete
 * @param was_deleted Pointer to boolean indicating if deletion occurred
 * @return Pointer to the head of the list
 */
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted);

/**
 * @brief Delete all nodes with a specific value (efficient version)
 * @param head Pointer to the head of the list
 * @param delete_value Value to delete
 * @param num_deleted Pointer to integer storing number of deleted nodes
 * @return Pointer to the new head of the list
 */
Node *efficient_delete_match(Node *head, int delete_value, int *num_deleted);

/**
 * @brief Delete all duplicate nodes from the list
 * @param head Pointer to the head of the list
 */
void delete_duplicates(Node *head);

/**
 * @brief Delete the entire list and free all memory
 * @param head Pointer to the head of the list
 * @return NULL pointer
 */
Node *delete_list(Node *head);

/* ========================================================================
 * LIST MANIPULATION FUNCTIONS
 * ======================================================================== */

/**
 * @brief Append one list to the end of another
 * @param head1 Pointer to the head of the first list
 * @param head2 Pointer to the head of the second list
 * @return Pointer to the head of the combined list
 */
Node *append_list(Node *head1, Node *head2);

/**
 * @brief Reverse the order of nodes in the list
 * @param head Pointer to the head of the list
 * @return Pointer to the new head of the reversed list
 */
Node *reverse_list(Node *head);

/**
 * @brief Sort the list using bubble sort algorithm
 * @param head Pointer to the head of the list
 */
void sort_list(Node *head);

/**
 * @brief Merge two sorted lists into one sorted list
 * @param list1 Pointer to the head of the first sorted list
 * @param list2 Pointer to the head of the second sorted list
 * @return Pointer to the head of the merged sorted list
 */
Node *merge_sorted_lists(Node *list1, Node *list2);

/* ========================================================================
 * LIST ANALYSIS FUNCTIONS
 * ======================================================================== */

/**
 * @brief Get the length of the list (iterative)
 * @param head Pointer to the head of the list
 * @return Number of nodes in the list
 */
int length(Node *head);

/**
 * @brief Get the length of the list (recursive)
 * @param node Pointer to a node in the list
 * @return Number of nodes from this point to the end
 */
int recursive_length(Node *node);

/**
 * @brief Check if a value exists in the list (recursive)
 * @param node Pointer to a node in the list
 * @param find_value Value to search for
 * @return true if value is found, false otherwise
 */
bool is_member_r(Node *node, int find_value);

/**
 * @brief Count occurrences of a value in the list (recursive)
 * @param node Pointer to a node in the list
 * @param find_value Value to count
 * @return Number of occurrences of the value
 */
int count_matches_r(Node *node, int find_value);

/**
 * @brief Replace all occurrences of a value with another value (recursive)
 * @param node Pointer to a node in the list
 * @param find_value Value to find and replace
 * @param replace_value Value to replace with
 */
void replace_matches_r(Node *node, int find_value, int replace_value);

/* ========================================================================
 * TWO-LIST OPERATIONS
 * ======================================================================== */

/**
 * @brief Add corresponding values of two lists (modifies first list)
 * @param head1 Pointer to the head of the first list (modified)
 * @param head2 Pointer to the head of the second list (read-only)
 */
void add_lists(Node *head1, Node *head2);

/**
 * @brief Add corresponding values of two lists (recursive version)
 * @param list1 Pointer to a node in the first list
 * @param list2 Pointer to a node in the second list
 */
void add_lists_recursive(Node *list1, Node *list2);

/**
 * @brief Create a duplicate of the list (iterative)
 * @param head Pointer to the head of the list to duplicate
 * @return Pointer to the head of the new duplicate list
 */
Node *duplicate_list(Node *head);

/**
 * @brief Create a duplicate of the list (recursive)
 * @param node Pointer to a node in the list to duplicate
 * @return Pointer to the corresponding node in the new duplicate list
 */
Node *duplicate_list_recursive(Node *node);

#endif /* LLIST_INT_H */
