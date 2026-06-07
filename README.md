# Hash Table Implementation in C++

A custom hash table implementation built from scratch in C++ using open addressing for collision resolution.

## Overview

This project implements a hash table without relying on the C++ Standard Library hash containers. The goal was to understand how hash tables work internally by designing and implementing the core operations manually.

## Features

* Insert key-value pairs
* Search for existing keys
* Delete entries
* Handle collisions through open addressing
* Store and retrieve data efficiently

## Data Structure Design

The hash table uses:

* A custom hash function
* Fixed-size underlying storage
* Open addressing to resolve collisions

When two keys map to the same index, the table probes for the next available location until an empty slot is found.

## Core Operations

### Insert

Adds a new key-value pair to the table.

### Search

Locates a key and returns its associated value if found.

### Delete

Removes a key-value pair while preserving the integrity of the probing sequence.

## Concepts Demonstrated

* Hash Functions
* Open Addressing
* Collision Resolution
* Arrays
* Classes and Objects
* Dynamic Memory Management
* Algorithm Design

## Time Complexity

Average case:

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(1)       |
| Search    | O(1)       |
| Delete    | O(1)       |

Worst case:

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(n)       |
| Search    | O(n)       |
| Delete    | O(n)       |

## What I Learned

Through this project I gained a deeper understanding of:

* How hash tables are implemented internally
* Why collisions occur
* Open addressing and probing techniques - Quadratic
* Tradeoffs between average-case and worst-case performance
* Building data structures from scratch in C++
## Future improvement
- implement incremental rehashing via two tables
- include different policies to rebuild hash table
## Author

Mensima Dadson
