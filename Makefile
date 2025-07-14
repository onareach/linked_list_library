# Makefile for Linked List Library
# Author: David Long
# Date: 2024

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O2 -DNDEBUG

# Directories
SRC_DIR = src
EXAMPLES_DIR = examples
TESTS_DIR = tests
BUILD_DIR = build

# Source files
INT_SOURCES = $(SRC_DIR)/llist_int.c
STR_SOURCES = $(SRC_DIR)/llist_str.c
ALL_SOURCES = $(INT_SOURCES) $(STR_SOURCES)

# Object files
INT_OBJECTS = $(BUILD_DIR)/llist_int.o
STR_OBJECTS = $(BUILD_DIR)/llist_str.o
ALL_OBJECTS = $(INT_OBJECTS) $(STR_OBJECTS)

# Example and test executables
BASIC_EXAMPLE = $(BUILD_DIR)/basic_usage
PERFORMANCE_TEST = $(BUILD_DIR)/performance_test

# Default target
all: $(BUILD_DIR) $(BASIC_EXAMPLE) $(PERFORMANCE_TEST)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile object files
$(BUILD_DIR)/llist_int.o: $(SRC_DIR)/llist_int.c $(SRC_DIR)/llist_int.h
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

$(BUILD_DIR)/llist_str.o: $(SRC_DIR)/llist_str.c $(SRC_DIR)/llist_str.h
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Build examples
$(BASIC_EXAMPLE): $(EXAMPLES_DIR)/basic_usage.c $(ALL_OBJECTS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $< $(ALL_OBJECTS) -o $@

# Build tests
$(PERFORMANCE_TEST): $(TESTS_DIR)/performance_test.c $(INT_OBJECTS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $< $(INT_OBJECTS) -o $@

# Release builds (optimized)
release: CFLAGS += $(RELEASE_FLAGS)
release: clean all

# Run examples
run-example: $(BASIC_EXAMPLE)
	./$(BASIC_EXAMPLE)

# Run performance tests
run-performance: $(PERFORMANCE_TEST)
	./$(PERFORMANCE_TEST)

# Run all tests
test: run-example run-performance

# Static library target
liblinkedlist.a: $(ALL_OBJECTS)
	ar rcs $(BUILD_DIR)/liblinkedlist.a $(ALL_OBJECTS)

# Install library (optional)
install: liblinkedlist.a
	@echo "Installing library to /usr/local/lib and headers to /usr/local/include"
	@echo "Note: This requires sudo privileges"
	sudo cp $(BUILD_DIR)/liblinkedlist.a /usr/local/lib/
	sudo cp $(SRC_DIR)/llist_int.h /usr/local/include/
	sudo cp $(SRC_DIR)/llist_str.h /usr/local/include/

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Clean and rebuild
rebuild: clean all

# Check for memory leaks (requires valgrind)
memcheck: $(BASIC_EXAMPLE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(BASIC_EXAMPLE)

# Format code (requires clang-format)
format:
	clang-format -i $(SRC_DIR)/*.c $(SRC_DIR)/*.h $(EXAMPLES_DIR)/*.c $(TESTS_DIR)/*.c

# Show help
help:
	@echo "Available targets:"
	@echo "  all           - Build all examples and tests (default)"
	@echo "  release       - Build optimized release version"
	@echo "  run-example   - Run the basic usage example"
	@echo "  run-performance - Run performance tests"
	@echo "  test          - Run all tests and examples"
	@echo "  liblinkedlist.a - Build static library"
	@echo "  install       - Install library system-wide (requires sudo)"
	@echo "  clean         - Remove build artifacts"
	@echo "  rebuild       - Clean and rebuild"
	@echo "  memcheck      - Run memory leak check (requires valgrind)"
	@echo "  format        - Format source code (requires clang-format)"
	@echo "  help          - Show this help message"

# Declare phony targets
.PHONY: all release run-example run-performance test clean rebuild memcheck format help install
