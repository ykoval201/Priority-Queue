"Priority Queue Implementation
=============================

Overview
--------

This header file defines a templated class `priorityqueue` in C++ that implements a priority queue using a custom binary search tree (BST) structure. The priority queue organizes elements based on their priority, allowing for efficient insertion, deletion, and access to the element with the highest priority (or lowest, depending on the implementation details).

Features
--------

- **Templated Class:** Allows storing any data type `T`.
- **Custom BST:** Utilizes a binary search tree to maintain the order of elements based on priority. Nodes can have links to handle duplicate priorities via a linked list.
- **Duplicate Priority Handling:** Manages duplicate priorities by linking nodes with the same priority in a linked list, maintaining order within those priorities.
- **Efficient Operations:** Aims to provide efficient operations such as `enqueue` (insertion), `dequeue` (removal), and `peek` (accessing the next element) with considerations for both unique and duplicate priorities.
- **Memory Management:** Includes methods for clearing the queue, copying the queue, and destructing the queue to manage memory effectively.

Key Operations
--------------

- **Enqueue:** Inserts a new element into the priority queue according to its priority.
- **Dequeue:** Removes and returns the element with the next priority in the queue.
- **Peek:** Returns the value of the next element in the priority queue without removing it.
- **Size:** Returns the number of elements in the priority queue.
- **Clear:** Removes all elements from the priority queue and frees memory.
- **toString:** Returns a string representation of the priority queue, showing priorities and values in order.

Implementation Details
----------------------

- The class uses a private `NODE` struct that includes the priority, value, duplication flag, parent pointer, link pointer (for duplicates), and pointers to left and right children.
- The `priorityqueue` maintains a pointer to the root of the BST, the size of the queue, and a current node pointer for traversal purposes.
- Helper functions are used for recursive operations like clearing the queue, copying the queue, checking for equality, and building the string representation.

Usage
-----

To use the `priorityqueue`, include this header file in your C++ project. Ensure your project is set up to compile with C++ standards that support templating and the STL library. Create an instance of `priorityqueue` with the desired type, and use its methods to manipulate the priority queue.
