# Postfix-Calculator
This project implements a stack data structure using fixed-sized arrays (stack_a.cpp), dynamically-sized arrays (stack_b.cpp), and doubly linked lists (stack_c.cpp). Each implementation efficiently manages memory and supports essential stack operations required for a postfix notation calculator.

## Overview

Stacks are essential data structures in computer science, following the Last In, First Out (LIFO) principle. They are widely used for managing function calls, expression evaluation, undo mechanisms, and more.

### Implementation Details

1. **Fixed-sized Arrays (`stack_a.cpp`)**:
   - Uses a static array of size 1024.
   - Implements basic stack operations (`push`, `pop`) with error handling for stack overflow and underflow.
   - Supports accessing elements from the top and bottom, printing the stack, and arithmetic operations (`add`, `subtract`, `multiply`, `divide`).

2. **Dynamically-sized Arrays (`stack_b.cpp`)**:
   - Starts with a minimum capacity of 1024 elements.
   - Automatically doubles its size when reaching capacity.
   - Shrinks to half its size when the number of elements reduces below a threshold.
   - Includes all basic stack operations and arithmetic operations with robust error handling for memory allocation failures.

3. **Doubly Linked Lists (`stack_c.cpp`)**:
   - Utilizes a doubly linked list for dynamic memory management.
   - Provides operations to insert and delete elements, access elements from top and bottom, and perform arithmetic operations (`add`, `subtract`, `multiply`, `divide`).
   - Handles errors such as accessing elements from an empty stack and division by zero.

### Usage

Each implementation offers a `Stack` class with a uniform interface across all methods, ensuring easy integration into applications needing stack functionality. These implementations cater to different needs based on memory constraints and operational requirements.

### Compilation and Execution

To compile and use these implementations:
```sh
$ g++ main.cpp stack_a.cpp -o stack_a
$ ./stack_a

$ g++ main.cpp stack_b.cpp -o stack_b
$ ./stack_b

$ g++ main.cpp stack_c.cpp list.cpp node.cpp -o stack_c
$ ./stack_c
