/**
 * @file llist_int.c
 * @brief Integer Linked List Library - Implementation
 * @author David Long
 * @date 2024
 * 
 * This file contains the implementation of all functions declared in llist_int.h.
 * The library provides comprehensive functionality for managing singly linked lists
 * that store integer values.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "llist_int.h"

/* ========================================================================
 * PRINT FUNCTIONS
 * ======================================================================== */

void print_list(Node *head) {
    Node *current = head;
    int i = 0;

    while (current != NULL) {
        printf("(Node%3d: %3d)\n", i, current->value);
        i++;
        current = current->next;
    }
    printf("\n");
}

void print_two_lists(Node *head1, Node *head2) {
    Node *current = head1;
    int i = 0;

    printf("List 1:\n");
    while (current != NULL) {
        printf("(Node%3d: %3d)\n", i, current->value);
        i++;
        current = current->next;
    }
    printf("\n");

    printf("List 2:\n");
    current = head2;
    i = 0;
    while (current != NULL) {
        printf("(Node%3d: %3d)\n", i, current->value);
        i++;
        current = current->next;
    }
    printf("\n");
}

/* ========================================================================
 * INSERT FUNCTIONS
 * ======================================================================== */

Node *insert_at_head(Node *head, int new_value) {
    Node *new_node = calloc(1, sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return head;
    }
    
    new_node->value = new_value;
    new_node->next = head;
    return new_node;
}

Node *insert_at_tail(Node *head, int new_value) {
    Node *new_node = calloc(1, sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return head;
    }
    
    new_node->value = new_value;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

Node *insert_after(Node *head, int new_value, int after_value) {
    Node *new_node = calloc(1, sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return head;
    }
    
    new_node->value = new_value;
    
    if (head == NULL) {
        new_node->next = NULL;
        return new_node;
    }

    Node *current = head;
    while (current != NULL) {
        if (current->value == after_value) {
            new_node->next = current->next;
            current->next = new_node;
            return head;
        }
        current = current->next;
    }
    
    // If after_value not found, insert at tail
    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    new_node->next = NULL;
    current->next = new_node;
    return head;
}

/* ========================================================================
 * DELETE FUNCTIONS
 * ======================================================================== */

Node *delete_at_head(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    
    Node *new_head = head->next;
    free(head);
    return new_head;
}

Node *delete_at_tail(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node *current = head;
    Node *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    
    prev->next = NULL;
    free(current);
    return head;
}

Node *delete_first_match(Node *head, int delete_value, bool *was_deleted) {
    *was_deleted = false;
    
    if (head == NULL) {
        return NULL;
    }

    if (head->value == delete_value) {
        Node *new_head = head->next;
        free(head);
        *was_deleted = true;
        return new_head;
    }

    Node *current = head->next;
    Node *prev = head;

    while (current != NULL) {
        if (current->value == delete_value) {
            prev->next = current->next;
            free(current);
            *was_deleted = true;
            return head;
        }
        prev = current;
        current = current->next;
    }

    return head;
}

Node *efficient_delete_match(Node *head, int delete_value, int *num_deleted) {
    *num_deleted = 0;
    
    if (head == NULL) {
        return NULL;
    }

    Node *current = head;
    Node *temp;

    // Delete all matching nodes at the beginning
    while (current != NULL && current->value == delete_value) {
        temp = current;
        current = current->next;
        free(temp);
        (*num_deleted)++;
    }

    if (current == NULL) {
        return NULL;
    }

    Node *new_head = current;

    // Delete matching nodes in the rest of the list
    while (current->next != NULL) {
        if (current->next->value == delete_value) {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
            (*num_deleted)++;
        } else {
            current = current->next;
        }
    }

    return new_head;
}

void delete_duplicates(Node *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node *current1 = head;
    
    while (current1 != NULL && current1->next != NULL) {
        Node *current2 = current1;
        
        while (current2->next != NULL) {
            if (current1->value == current2->next->value) {
                Node *duplicate = current2->next;
                current2->next = current2->next->next;
                free(duplicate);
            } else {
                current2 = current2->next;
            }
        }
        current1 = current1->next;
    }
}

Node *delete_list(Node *head) {
    if (head != NULL) {
        delete_list(head->next);
        free(head);
    }
    return NULL;
}

/* ========================================================================
 * LIST MANIPULATION FUNCTIONS
 * ======================================================================== */

Node *append_list(Node *head1, Node *head2) {
    if (head1 == NULL) {
        return head2;
    }

    Node *current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
    return head1;
}

Node *reverse_list(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *current = head;
    Node *next_node = head->next;
    current->next = NULL;

    while (next_node != NULL) {
        Node *temp = next_node->next;
        next_node->next = current;
        current = next_node;
        next_node = temp;
    }
    
    return current;
}

void sort_list(Node *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node *current = head;
        Node *prev = NULL;

        while (current->next != NULL) {
            prev = current;
            current = current->next;
            
            if (current->value < prev->value) {
                int temp = prev->value;
                prev->value = current->value;
                current->value = temp;
                swapped = true;
            }
        }
    } while (swapped);
}

Node *merge_sorted_lists(Node *list1, Node *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node *new_head;
    Node *current1 = list1;
    Node *current2 = list2;

    // Determine the head of the merged list
    if (current1->value <= current2->value) {
        new_head = current1;
        current1 = current1->next;
    } else {
        new_head = current2;
        current2 = current2->next;
    }

    Node *current = new_head;

    // Merge the remaining nodes
    while (current1 != NULL && current2 != NULL) {
        if (current1->value <= current2->value) {
            current->next = current1;
            current1 = current1->next;
        } else {
            current->next = current2;
            current2 = current2->next;
        }
        current = current->next;
    }

    // Append remaining nodes
    if (current1 != NULL) {
        current->next = current1;
    } else {
        current->next = current2;
    }

    return new_head;
}

/* ========================================================================
 * LIST ANALYSIS FUNCTIONS
 * ======================================================================== */

int length(Node *head) {
    int count = 0;
    Node *current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

int recursive_length(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + recursive_length(node->next);
}

bool is_member_r(Node *node, int find_value) {
    if (node == NULL) {
        return false;
    }
    if (node->value == find_value) {
        return true;
    }
    return is_member_r(node->next, find_value);
}

int count_matches_r(Node *node, int find_value) {
    if (node == NULL) {
        return 0;
    }
    if (node->value == find_value) {
        return 1 + count_matches_r(node->next, find_value);
    }
    return count_matches_r(node->next, find_value);
}

void replace_matches_r(Node *node, int find_value, int replace_value) {
    if (node != NULL) {
        if (node->value == find_value) {
            node->value = replace_value;
        }
        replace_matches_r(node->next, find_value, replace_value);
    }
}

/* ========================================================================
 * TWO-LIST OPERATIONS
 * ======================================================================== */

void add_lists(Node *head1, Node *head2) {
    Node *current1 = head1;
    Node *current2 = head2;

    while (current1 != NULL && current2 != NULL) {
        current1->value += current2->value;
        current1 = current1->next;
        current2 = current2->next;
    }
}

void add_lists_recursive(Node *list1, Node *list2) {
    if (list1 == NULL || list2 == NULL) {
        return;
    }
    list1->value += list2->value;
    add_lists_recursive(list1->next, list2->next);
}

Node *duplicate_list(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *new_head = calloc(1, sizeof(Node));
    if (new_head == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    
    new_head->value = head->value;
    new_head->next = NULL;

    Node *current_old = head->next;
    Node *current_new = new_head;

    while (current_old != NULL) {
        Node *new_node = calloc(1, sizeof(Node));
        if (new_node == NULL) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            delete_list(new_head);
            return NULL;
        }
        
        new_node->value = current_old->value;
        new_node->next = NULL;
        current_new->next = new_node;
        
        current_old = current_old->next;
        current_new = current_new->next;
    }

    return new_head;
}

Node *duplicate_list_recursive(Node *node) {
    if (node == NULL) {
        return NULL;
    }

    Node *new_node = calloc(1, sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    
    new_node->value = node->value;
    new_node->next = duplicate_list_recursive(node->next);
    
    return new_node;
}
