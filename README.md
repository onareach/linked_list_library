# Linked List Library

A comprehensive C library for managing singly linked lists with support for both integer and string data types.

**Author:** David Long  
**License:** BSD-3-Clause  
**Language:** C (C99 standard)

## Overview

This library provides a complete set of functions for creating, manipulating, and managing singly linked lists. It includes separate implementations for integer and string data types, with comprehensive documentation and examples.

## Features

### Integer Linked Lists (`llist_int`)
- **Basic Operations:** Insert, delete, search, and traverse
- **Advanced Operations:** Sort, reverse, merge, duplicate
- **Memory Management:** Automatic cleanup and error handling
- **Performance Optimized:** Efficient algorithms for common operations
- **Two-List Operations:** Add, merge, and compare multiple lists

### String Linked Lists (`llist_str`)
- **String Storage:** Automatic string copying and memory management
- **Basic Operations:** Insert, delete, search, and display
- **Memory Safe:** Proper cleanup of both nodes and string data

## Project Structure

```
linked_list_library/
├── src/                    # Library source code
│   ├── llist_int.h        # Integer linked list header
│   ├── llist_int.c        # Integer linked list implementation
│   ├── llist_str.h        # String linked list header
│   └── llist_str.c        # String linked list implementation
├── examples/              # Usage examples
│   └── basic_usage.c      # Comprehensive usage demonstration
├── tests/                 # Test programs
│   └── performance_test.c # Performance comparison tests
├── build/                 # Build artifacts (created by make)
├── Makefile              # Build system
├── README.md             # This file
└── LICENSE               # BSD-3-Clause license
```

## Quick Start

### Building the Library

```bash
# Build all examples and tests
make

# Build optimized release version
make release

# Build static library
make liblinkedlist.a

# Show all available targets
make help
```

### Running Examples

```bash
# Run basic usage examples
make run-example

# Run performance tests
make run-performance

# Run all tests
make test
```

### Basic Usage Example

```c
#include "src/llist_int.h"
#include <stdio.h>

int main() {
    // Create an empty list
    Node *list = NULL;
    
    // Add some elements
    list = insert_at_head(list, 10);
    list = insert_at_head(list, 20);
    list = insert_at_tail(list, 5);
    
    // Print the list
    print_list(list);
    
    // Clean up
    list = delete_list(list);
    
    return 0;
}
```

## API Reference

### Integer Linked List Functions

#### Creation and Destruction
- `Node *delete_list(Node *head)` - Delete entire list and free memory

#### Insertion Functions
- `Node *insert_at_head(Node *head, int value)` - Insert at beginning
- `Node *insert_at_tail(Node *head, int value)` - Insert at end
- `Node *insert_after(Node *head, int new_value, int after_value)` - Insert after specific value

#### Deletion Functions
- `Node *delete_at_head(Node *head)` - Delete first node
- `Node *delete_at_tail(Node *head)` - Delete last node
- `Node *delete_first_match(Node *head, int value, bool *was_deleted)` - Delete first matching value
- `Node *efficient_delete_match(Node *head, int value, int *num_deleted)` - Delete all matching values
- `void delete_duplicates(Node *head)` - Remove duplicate values

#### List Manipulation
- `Node *reverse_list(Node *head)` - Reverse the list order
- `void sort_list(Node *head)` - Sort using bubble sort
- `Node *merge_sorted_lists(Node *list1, Node *list2)` - Merge two sorted lists
- `Node *append_list(Node *head1, Node *head2)` - Append one list to another

#### Analysis Functions
- `int length(Node *head)` - Get list length (iterative)
- `int recursive_length(Node *node)` - Get list length (recursive)
- `bool is_member_r(Node *node, int value)` - Check if value exists
- `int count_matches_r(Node *node, int value)` - Count occurrences of value
- `void replace_matches_r(Node *node, int find_value, int replace_value)` - Replace values

#### Two-List Operations
- `void add_lists(Node *head1, Node *head2)` - Add corresponding values
- `Node *duplicate_list(Node *head)` - Create a copy of the list
- `Node *duplicate_list_recursive(Node *node)` - Recursive list duplication

#### Display Functions
- `void print_list(Node *head)` - Print all values
- `void print_two_lists(Node *head1, Node *head2)` - Print two lists side by side

### String Linked List Functions

#### Creation and Destruction
- `StringNode *create_string_node(const char *str)` - Create new string node
- `StringNode *delete_string_list(StringNode *head)` - Delete entire string list

#### Insertion Functions
- `StringNode *insert_string_at_head(StringNode *head, const char *str)` - Insert at beginning
- `StringNode *insert_string_at_tail(StringNode *head, const char *str)` - Insert at end

#### Deletion Functions
- `StringNode *delete_string_at_head(StringNode *head)` - Delete first node
- `StringNode *delete_string_match(StringNode *head, const char *str, bool *was_deleted)` - Delete matching string

#### Analysis Functions
- `int string_list_length(StringNode *head)` - Get list length
- `bool string_list_contains(StringNode *head, const char *str)` - Check if string exists

#### Display Functions
- `void print_string_list(StringNode *head)` - Print all strings

## Performance Characteristics

### Time Complexity
- **Insertion at head:** O(1)
- **Insertion at tail:** O(n)
- **Deletion at head:** O(1)
- **Deletion at tail:** O(n)
- **Search:** O(n)
- **Sort (bubble sort):** O(n²)
- **Merge sorted lists:** O(n + m)

### Space Complexity
- **Per node overhead:** 8-16 bytes (depending on architecture)
- **Total space:** O(n) where n is the number of elements

## Memory Management

The library follows these memory management principles:

1. **Automatic Cleanup:** All functions properly free memory when deleting nodes
2. **Error Handling:** Functions check for allocation failures and handle them gracefully
3. **String Safety:** String functions automatically copy input strings to prevent dangling pointers
4. **Leak Prevention:** Comprehensive cleanup functions provided for all data structures

## Testing and Validation

### Memory Leak Testing
```bash
# Requires valgrind
make memcheck
```

### Performance Testing
The library includes comprehensive performance tests comparing linked list operations with equivalent array operations:

```bash
make run-performance
```

## Development Tools

### Code Formatting
```bash
# Requires clang-format
make format
```

### Static Library Creation
```bash
make liblinkedlist.a
```

### System Installation
```bash
# Install library system-wide (requires sudo)
make install
```

## Migration from Original Code

If you're migrating from the original scattered files:

1. **Replace includes:** Change `#include "llist_int.h"` to `#include "src/llist_int.h"`
2. **Function renames:** Some functions have been renamed for consistency:
   - `add_lists_shorter_recursive_version` → `add_lists_recursive`
   - `duplicate_list_shorter_version_recursive` → `duplicate_list_recursive`
3. **Improved error handling:** Functions now include better error checking and memory management
4. **Consistent documentation:** All functions now have comprehensive documentation

## Contributing

When contributing to this library:

1. Follow the existing code style and documentation format
2. Add comprehensive tests for new functionality
3. Update this README for any API changes
4. Ensure all memory is properly managed
5. Run `make test` and `make memcheck` before submitting

## License

This project is licensed under the BSD-3-Clause License. See the LICENSE file for details.

## Changelog

### Version 2.0 (2024)
- Complete reorganization and cleanup of codebase
- Added comprehensive documentation
- Improved memory management and error handling
- Added string linked list support
- Created proper build system with Makefile
- Added performance testing suite
- Consolidated duplicate code
- Added proper header guards and includes

### Version 1.0 (Original)
- Basic integer linked list functionality
- Performance comparison tests
- Various experimental implementations
