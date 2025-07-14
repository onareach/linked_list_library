/**
 * @file llist_str.c
 * @brief String Linked List Library - Implementation
 * @author David Long
 * @date 2024
 * 
 * This file contains the implementation of all functions declared in llist_str.h.
 * The library provides functionality for managing singly linked lists that store string values.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "llist_str.h"

/* ========================================================================
 * CREATION AND DESTRUCTION FUNCTIONS
 * ======================================================================== */

StringNode *create_string_node(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    StringNode *new_node = malloc(sizeof(StringNode));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for string node\n");
        return NULL;
    }

    new_node->str = malloc(strlen(str) + 1);
    if (new_node->str == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for string\n");
        free(new_node);
        return NULL;
    }

    strcpy(new_node->str, str);
    new_node->next = NULL;
    return new_node;
}

StringNode *delete_string_list(StringNode *head) {
    if (head != NULL) {
        delete_string_list(head->next);
        free(head->str);
        free(head);
    }
    return NULL;
}

/* ========================================================================
 * PRINT FUNCTIONS
 * ======================================================================== */

void print_string_list(StringNode *head) {
    StringNode *current = head;
    int i = 0;

    while (current != NULL) {
        printf("(Node%3d: \"%s\")\n", i, current->str);
        i++;
        current = current->next;
    }
    printf("\n");
}

/* ========================================================================
 * INSERT FUNCTIONS
 * ======================================================================== */

StringNode *insert_string_at_head(StringNode *head, const char *str) {
    StringNode *new_node = create_string_node(str);
    if (new_node == NULL) {
        return head;
    }

    new_node->next = head;
    return new_node;
}

StringNode *insert_string_at_tail(StringNode *head, const char *str) {
    StringNode *new_node = create_string_node(str);
    if (new_node == NULL) {
        return head;
    }

    if (head == NULL) {
        return new_node;
    }

    StringNode *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

/* ========================================================================
 * DELETE FUNCTIONS
 * ======================================================================== */

StringNode *delete_string_at_head(StringNode *head) {
    if (head == NULL) {
        return NULL;
    }

    StringNode *new_head = head->next;
    free(head->str);
    free(head);
    return new_head;
}

StringNode *delete_string_match(StringNode *head, const char *str, bool *was_deleted) {
    *was_deleted = false;

    if (head == NULL || str == NULL) {
        return head;
    }

    if (strcmp(head->str, str) == 0) {
        StringNode *new_head = head->next;
        free(head->str);
        free(head);
        *was_deleted = true;
        return new_head;
    }

    StringNode *current = head->next;
    StringNode *prev = head;

    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            prev->next = current->next;
            free(current->str);
            free(current);
            *was_deleted = true;
            return head;
        }
        prev = current;
        current = current->next;
    }

    return head;
}

/* ========================================================================
 * LIST ANALYSIS FUNCTIONS
 * ======================================================================== */

int string_list_length(StringNode *head) {
    int count = 0;
    StringNode *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

bool string_list_contains(StringNode *head, const char *str) {
    if (str == NULL) {
        return false;
    }

    StringNode *current = head;
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}
