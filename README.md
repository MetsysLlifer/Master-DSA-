# Master DSA - Data Structures and Algorithms

A comprehensive repository containing implementations and explanations of fundamental Data Structures and Algorithms.

## Table of Contents

1. [Introduction](#introduction)
2. [Linear Data Structures](#linear-data-structures)
3. [Abstract Data Types](#abstract-data-types)
4. [Trees](#trees)
5. [Graphs](#graphs)
6. [Getting Started](#getting-started)

## Introduction

### Fundamentals
- **Data Structure** - Organization and storage of data
- **Algorithm** - Step-by-step procedure to solve a problem
- **ADT (Abstract Data Type)** - Specification of data type with allowed operations

### List Operations
- Insert
- Delete
- Member
- Makenull
- Initialize

## Linear Data Structures

### Linked List
- **Singly Linked List** - Each node points to the next node
- **Doubly Linked List** - Nodes point to both previous and next nodes
- **Pointer Traversal** - Navigation through nodes
- **Head Node & Tail Pointers** - Efficient access to ends of list

### ADT Stack
- **Implementations**: Array-based and Linked List-based
- **LIFO Principle** - Last In, First Out
- **Applications**: Function calls, undo operations, expression evaluation

### ADT Queue
- **Implementations**: Array-based and Linked List-based
- **FIFO Principle** - First In, First Out
- **Applications**: Operating Systems (process scheduling), network queues

### ADT Set and Set Operations
- **Set vs List** - Unordered, unique elements
- **Bit-Vector Implementation** - Space-efficient using bitwise operations
- **Array of Integers Implementation** - Using computer words

## Abstract Data Types

### ADT Dictionary
- **Simple Dictionary** - Basic key-value storage
- **Hash Table Data Structure**
  - Internal Hashing
  - External Hashing
- **Efficiency Analysis** - Time and space complexity

## Trees

### Tree Fundamentals
- **Traversals**
  - **Breadth-First (Level-order)** - Layer by layer traversal
  - **Depth-First** - Recursive traversal strategies
    - Preorder (Root, Left, Right)
    - Postorder (Left, Right, Root)
    - Inorder (Left, Root, Right)

### Binary Trees
- **Expression Trees** - Represent mathematical expressions
- **Binary Search Trees (BST)** - Ordered binary trees
- **AVL Trees** - Self-balancing BST
- **Huffman Coding** - Optimal prefix-free codes

### ADT Priority Queue
- **Heap Data Structure** - Complete binary tree with ordering property
- **Maxheap and Minheap** - Different ordering strategies
- **Partially Ordered Trees (POT)**
- **Heap Sort** - Efficient sorting algorithm using heaps

## Graphs

### Basic Graph Concepts
- Vertices and Edges
- Directed and Undirected Graphs
- Weighted and Unweighted Graphs

### Graph Representations
- **Adjacency Matrix** - 2D array representation
- **Adjacency List** - Linked list representation

### Graph Algorithms
- **Shortest Path Problems**
  - Single-Source Shortest Path (Dijkstra's)
  - All-Pairs Shortest Path (Floyd-Warshall)
- **Graph Traversals**
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)

### Minimum Spanning Tree
- **Prim's Algorithm** - Greedy approach
- **Kruskal's Algorithm** - Edge-based approach
- **Floyd-Warshall Algorithm** - All-pairs shortest paths

## Getting Started

### Prerequisites
- C/C++ compiler (clang, gcc)
- Make utility
- Understanding of pointers and basic data structures

### Building
```bash
make run      # Compile and run
make clean    # Remove compiled files
```

### Switching Implementations
Edit the `VERSION` variable in the makefile to test different implementations:
```makefile
VERSION = v1  # Change to v2, v3, etc.
```

## Project Structure

```
Master(DSA)/
├── Tree/
│   ├── main.c
│   ├── makefile
│   └── headers/
│       ├── v1.c
│       ├── v1.h
│       └── tree.h
├── LinkedList/
├── Stack/
├── Queue/
└── ...
```

<!-- ## Contributing

Feel free to add implementations, optimize algorithms, or improve documentation. -->

## License

Educational purposes - Master's DSA Course

---

**Last Updated**: December 2025
