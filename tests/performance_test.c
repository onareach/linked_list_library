/**
 * @file performance_test.c
 * @brief Performance comparison between linked lists and arrays
 * @author David Long
 * @date 2024
 * 
 * This program compares the performance of linked list operations versus
 * equivalent array operations, particularly focusing on deletion performance.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../src/llist_int.h"

/**
 * @brief Test array shrinking performance
 * @param num_elements Number of elements to test with
 * @return Elapsed time in seconds
 */
double test_array_shrinking(int num_elements) {
    clock_t start, end;
    
    // Create and initialize array
    int *array = malloc(num_elements * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for array\n");
        return -1.0;
    }
    
    for (int i = 0; i < num_elements; i++) {
        array[i] = i;
    }

    start = clock();
    
    // Simulate array shrinking by creating new smaller arrays
    for (int i = 1; i < num_elements; i++) {
        int *new_array = malloc((num_elements - i) * sizeof(int));
        if (new_array == NULL) {
            fprintf(stderr, "Error: Memory allocation failed during shrinking\n");
            free(array);
            return -1.0;
        }
        
        for (int j = 0; j < num_elements - i; j++) {
            new_array[j] = array[j + 1];
        }
        
        free(array);
        array = new_array;
    }
    
    end = clock();
    free(array);
    
    return (double)(end - start) / CLOCKS_PER_SEC;
}

/**
 * @brief Test linked list head deletion performance
 * @param num_elements Number of elements to test with
 * @return Elapsed time in seconds
 */
double test_linked_list_deletion(int num_elements) {
    clock_t start, end;
    
    // Create and populate linked list
    Node *list = NULL;
    for (int i = 0; i < num_elements; i++) {
        list = insert_at_head(list, i);
    }

    start = clock();
    
    // Delete all nodes from head
    for (int i = 0; i < num_elements; i++) {
        list = delete_at_head(list);
    }
    
    end = clock();
    
    return (double)(end - start) / CLOCKS_PER_SEC;
}

/**
 * @brief Test linked list insertion performance
 * @param num_elements Number of elements to test with
 * @return Elapsed time in seconds
 */
double test_linked_list_insertion(int num_elements) {
    clock_t start, end;
    Node *list = NULL;

    start = clock();
    
    for (int i = 0; i < num_elements; i++) {
        list = insert_at_head(list, i);
    }
    
    end = clock();
    
    // Clean up
    list = delete_list(list);
    
    return (double)(end - start) / CLOCKS_PER_SEC;
}

/**
 * @brief Test array insertion performance (for comparison)
 * @param num_elements Number of elements to test with
 * @return Elapsed time in seconds
 */
double test_array_insertion(int num_elements) {
    clock_t start, end;
    
    int *array = malloc(num_elements * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for array\n");
        return -1.0;
    }

    start = clock();
    
    for (int i = 0; i < num_elements; i++) {
        array[i] = i;
    }
    
    end = clock();
    
    free(array);
    
    return (double)(end - start) / CLOCKS_PER_SEC;
}

/**
 * @brief Run comprehensive performance tests
 * @param num_elements Number of elements to test with
 */
void run_performance_tests(int num_elements) {
    printf("Performance Test Results (%d elements):\n", num_elements);
    printf("=====================================\n\n");
    
    // Test array operations
    double array_shrink_time = test_array_shrinking(num_elements);
    double array_insert_time = test_array_insertion(num_elements);
    
    // Test linked list operations
    double list_delete_time = test_linked_list_deletion(num_elements);
    double list_insert_time = test_linked_list_insertion(num_elements);
    
    // Display results
    printf("Array Operations:\n");
    printf("  Insertion time:     %f seconds\n", array_insert_time);
    printf("  Shrinking time:     %f seconds\n", array_shrink_time);
    printf("\n");
    
    printf("Linked List Operations:\n");
    printf("  Insertion time:     %f seconds\n", list_insert_time);
    printf("  Head deletion time: %f seconds\n", list_delete_time);
    printf("\n");
    
    // Performance comparison
    printf("Performance Comparison:\n");
    if (array_insert_time > 0 && list_insert_time > 0) {
        double insert_ratio = array_insert_time / list_insert_time;
        printf("  Insertion: Array is %.2fx %s than Linked List\n", 
               insert_ratio > 1 ? insert_ratio : 1/insert_ratio,
               insert_ratio > 1 ? "slower" : "faster");
    }
    
    if (array_shrink_time > 0 && list_delete_time > 0) {
        double delete_ratio = array_shrink_time / list_delete_time;
        printf("  Deletion:  Array is %.2fx %s than Linked List\n", 
               delete_ratio > 1 ? delete_ratio : 1/delete_ratio,
               delete_ratio > 1 ? "slower" : "faster");
    }
    
    printf("\n");
}

int main(void) {
    printf("LINKED LIST LIBRARY - PERFORMANCE TESTS\n");
    printf("=======================================\n\n");
    
    // Test with different sizes
    int test_sizes[] = {1000, 5000, 10000, 20000};
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);
    
    for (int i = 0; i < num_tests; i++) {
        run_performance_tests(test_sizes[i]);
    }
    
    printf("Key Insights:\n");
    printf("- Linked lists excel at insertion/deletion at the head\n");
    printf("- Arrays require expensive memory copying for shrinking\n");
    printf("- Linked lists have memory overhead per node\n");
    printf("- Arrays provide better cache locality for traversal\n");
    
    return 0;
}
