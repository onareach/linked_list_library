/**
 * @file llist_str.h
 * @brief String Linked List Library - Header File
 * @author David Long
 * @date 2024
 * 
 * This header file defines the interface for a string linked list library.
 * The library provides functions for creating, manipulating, and managing singly linked lists
 * that store string values.
 */

#ifndef LLIST_STR_H
#define LLIST_STR_H

#include <stdbool.h>

/**
 * @brief Node structure for string linked list
 * 
 * Each node contains a string pointer and a pointer to the next node in the list.
 */
typedef struct string_node {
    char *str;                      /**< String value stored in the node */
    struct string_node *next;       /**< Pointer to the next node in the list */
} StringNode;

/* ========================================================================
 * CREATION AND DESTRUCTION FUNCTIONS
 * ======================================================================== */

/**
 * @brief Create a new string node
 * @param str String to store in the node (will be copied)
 * @return Pointer to the new node, or NULL if allocation fails
 */
StringNode *create_string_node(const char *str);

/**
 * @brief Delete the entire list and free all memory
 * @param head Pointer to the head of the list
 * @return NULL pointer
 */
StringNode *delete_string_list(StringNode *head);

/* ========================================================================
 * PRINT FUNCTIONS
 * ======================================================================== */

/**
 * @brief Print all strings in a linked list
 * @param head Pointer to the head of the list
 */
void print_string_list(StringNode *head);

/* ========================================================================
 * INSERT FUNCTIONS
 * ======================================================================== */

/**
 * @brief Insert a new string node at the head of the list
 * @param head Pointer to the current head of the list
 * @param str String to insert (will be copied)
 * @return Pointer to the new head of the list
 */
StringNode *insert_string_at_head(StringNode *head, const char *str);

/**
 * @brief Insert a new string node at the tail of the list
 * @param head Pointer to the head of the list
 * @param str String to insert (will be copied)
 * @return Pointer to the head of the list
 */
StringNode *insert_string_at_tail(StringNode *head, const char *str);

/* ========================================================================
 * DELETE FUNCTIONS
 * ======================================================================== */

/**
 * @brief Delete the head node from the list
 * @param head Pointer to the current head of the list
 * @return Pointer to the new head of the list
 */
StringNode *delete_string_at_head(StringNode *head);

/**
 * @brief Delete the first node with a specific string value
 * @param head Pointer to the head of the list
 * @param str String to delete
 * @param was_deleted Pointer to boolean indicating if deletion occurred
 * @return Pointer to the head of the list
 */
StringNode *delete_string_match(StringNode *head, const char *str, bool *was_deleted);

/* ========================================================================
 * LIST ANALYSIS FUNCTIONS
 * ======================================================================== */

/**
 * @brief Get the length of the string list
 * @param head Pointer to the head of the list
 * @return Number of nodes in the list
 */
int string_list_length(StringNode *head);

/**
 * @brief Check if a string exists in the list
 * @param head Pointer to the head of the list
 * @param str String to search for
 * @return true if string is found, false otherwise
 */
bool string_list_contains(StringNode *head, const char *str);

#endif /* LLIST_STR_H */
