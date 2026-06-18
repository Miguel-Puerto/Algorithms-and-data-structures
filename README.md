# Data Structures and Algorithms in C

This repository was built to organize and consolidate the core concepts learned throughout my Computer Science journey. It documents my progression from the fundamentals of structured programming logic and array manipulation to the implementation of complex dynamic data structures and low-level manual memory management.

---

## Repository Structure

The project is organized into three main modules that reflect my technical learning path:

### [01-logic-and-arrays](./01-logic-and-arrays/)
Focused on structured logic and static memory manipulation.
* `value-inversion.c`: Logic for sorting and reverse reading of numerical sequences.
* `mentalist-game.c`: An interactive guessing game applying loops, compound conditionals, and mathematical distance computation (`abs`).
* `matrix.c`: Operations and manipulation of two-dimensional data arrays.
* `vector-multiplication.c`: Mathematical algorithms and iteration over one-dimensional arrays.

### [02-compound-structures](./02-compound-structures/)
Introduction to custom data modeling and utility functions.
* `student-registration-struct.c`: A registry system using `structs` for data grouping, secure string manipulation using `fgets`, and time-seeded pseudo-random Student ID generation (`time.h`).

### [03-dynamic-structures](./03-dynamic-structures/)
The advanced core of this repository. It demonstrates proficiency over pointers, manual dynamic allocation (`malloc`/`free`), and linked data structures.
* `random-doubly-linked-list.c`: An evolution of the basic list layout, simulating automated testing through the randomized selection of nodes for deletion, an interactive terminal UI loop, and complete memory leak prevention.
* `doubly-linked-list.c`: Pure implementation of a bidirectional list featuring insertion, deletion, and both forward and backward traversal operations.
* `binary-trees/`: Source files dedicated to non-linear hierarchical data structures.

---

## Key Concepts & Technologies Learned

* **Language:** C (ANSI Standard)
* **Memory Management:** Dynamic allocation utilizing pointers, `malloc`, `free`, and best practices to eliminate *Memory Leaks*.
* **Modularization:** Function scoping and passing parameters by value vs. by reference.
* **Tooling:** GCC Compiler usage and basic terminal-driven automation.

---

## How to Compile and Run

Make sure you have a GCC compiler installed on your local machine.

1. Navigate to the directory containing the file you wish to run via your terminal:
   ```bash
   cd 03-dynamic-structures
