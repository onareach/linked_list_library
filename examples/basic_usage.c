/**
 * @file basic_usage.c
 * @brief Basic usage examples for the linked list library
 * @author David Long
 * @date 2024
 * 
 * This file demonstrates basic operations with both integer and string linked lists.
 */

#include <stdio.h>
#include <stdbool.h>
#include "../src/llist_int.h"
#include "../src/llist_str.h"

void demonstrate_integer_list(void) {
    printf("=== INTEGER LINKED LIST DEMONSTRATION ===\n\n");
    
    // Create and populate a list
    Node *list = NULL;
    list = insert_at_head(list, 10);
    list = insert_at_head(list, 20);
    list = insert_at_tail(list, 5);
    list = insert_after(list, 15, 10);
    
    printf("Initial list:\n");
    print_list(list);
    
    // Demonstrate search and analysis
    printf("List length: %d\n", length(list));
    printf("Contains 15: %s\n", is_member_r(list, 15) ? "Yes" : "No");
    printf("Count of 10: %d\n", count_matches_r(list, 10));
    
    // Demonstrate deletion
    bool was_deleted;
    list = delete_first_match(list, 15, &was_deleted);
    printf("\nAfter deleting 15 (success: %s):\n", was_deleted ? "Yes" : "No");
    print_list(list);
    
    // Demonstrate sorting
    list = insert_at_head(list, 25);
    list = insert_at_head(list, 1);
    printf("Before sorting:\n");
    print_list(list);
    
    sort_list(list);
    printf("After sorting:\n");
    print_list(list);
    
    // Clean up
    list = delete_list(list);
    printf("List deleted.\n\n");
}

void demonstrate_string_list(void) {
    printf("=== STRING LINKED LIST DEMONSTRATION ===\n\n");
    
    // Create and populate a string list
    StringNode *str_list = NULL;
    str_list = insert_string_at_head(str_list, "world");
    str_list = insert_string_at_head(str_list, "hello");
    str_list = insert_string_at_tail(str_list, "!");
    
    printf("String list:\n");
    print_string_list(str_list);
    
    printf("List length: %d\n", string_list_length(str_list));
    printf("Contains 'hello': %s\n", string_list_contains(str_list, "hello") ? "Yes" : "No");
    printf("Contains 'goodbye': %s\n", string_list_contains(str_list, "goodbye") ? "Yes" : "No");
    
    // Clean up
    str_list = delete_string_list(str_list);
    printf("String list deleted.\n\n");
}

void demonstrate_two_list_operations(void) {
    printf("=== TWO-LIST OPERATIONS DEMONSTRATION ===\n\n");
    
    // Create two lists for addition
    Node *list1 = NULL;
    Node *list2 = NULL;
    
    list1 = insert_at_tail(list1, 1);
    list1 = insert_at_tail(list1, 2);
    list1 = insert_at_tail(list1, 3);
    
    list2 = insert_at_tail(list2, 10);
    list2 = insert_at_tail(list2, 20);
    list2 = insert_at_tail(list2, 30);
    
    printf("Before addition:\n");
    print_two_lists(list1, list2);
    
    add_lists(list1, list2);
    printf("After adding list2 to list1:\n");
    print_list(list1);
    
    // Demonstrate list duplication
    Node *duplicate = duplicate_list(list1);
    printf("Duplicate of list1:\n");
    print_list(duplicate);
    
    // Clean up
    list1 = delete_list(list1);
    list2 = delete_list(list2);
    duplicate = delete_list(duplicate);
    printf("All lists deleted.\n\n");
}

int main(void) {
    printf("LINKED LIST LIBRARY - BASIC USAGE EXAMPLES\n");
    printf("==========================================\n\n");
    
    demonstrate_integer_list();
    demonstrate_string_list();
    demonstrate_two_list_operations();
    
    printf("All demonstrations completed successfully!\n");
    return 0;
}
