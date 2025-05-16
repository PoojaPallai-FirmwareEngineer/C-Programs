# 🔍 Searching Algorithms in C  
_This document provides a comprehensive list of common searching algorithms implemented in C, categorized by their respective data structures and use cases. Each section can include explanation and C code implementations._

---

## 📦 Array-based Searching Algorithms

These algorithms work on arrays (sorted or unsorted):

1. **Linear Search** – Sequentially checks each element in the array.  
2. **Binary Search** – Efficient search on sorted arrays using divide and conquer.  
3. **Jump Search** – Uses fixed-size jumps to reduce comparisons.  
4. **Interpolation Search** – Improves binary search using a formula to guess the position.  
5. **Exponential Search** – Combines binary search with exponential range detection.  
6. **Fibonacci Search** – Searches using Fibonacci numbers to divide the range.  
7. **Ternary Search** – Divides the range into three parts for search (used in unimodal functions).

---

## 🌲 Tree-based Searching Algorithms

Used in hierarchical or sorted data structures like trees:

8. **Binary Search Tree (BST) Search** – Search using properties of BST (left < root < right).  
9. **AVL Tree Search** – Balanced BST for faster lookups.  
10. **Red-Black Tree Search** – Self-balancing BST used in libraries (e.g., C++ STL).  
11. **Trie Search** – Search for strings using prefix tree structure.  
12. **B-Tree Search** – Used in databases and file systems (multi-level).  
13. **Segment Tree Search** – Efficient for range queries and updates.  
14. **Fenwick Tree (Binary Indexed Tree) Search** – Optimized for cumulative frequency or range sum.  
15. **Quad Tree Search** – Used in 2D spatial partitioning (image processing, maps).  
16. **Octree Search** – 3D version of Quad Tree (used in 3D graphics and simulations).

---

## 🌐 Graph-based Searching Algorithms

Used in pathfinding and traversals in graph structures:

17. **Depth First Search (DFS)** – Explores paths as deep as possible before backtracking.  
18. **Breadth First Search (BFS)** – Explores all neighbors level-by-level.  
19. **Dijkstra's Algorithm** – Finds shortest path from a source in weighted graphs.  
20. **A\* Search Algorithm** – Heuristic-based shortest path algorithm (used in AI).  
21. **Bellman-Ford Algorithm** – Handles graphs with negative weights.  
22. **Floyd-Warshall Algorithm** – All-pairs shortest path in weighted graphs.  
23. **Jump Point Search (JPS)** – Optimized grid-based pathfinding (used in games).  
24. **Bidirectional Search** – Runs BFS from both start and goal to meet in the middle.

---

## 🧵 Pattern/String Searching Algorithms

Used for substring or pattern finding within strings or texts:

25. **Knuth-Morris-Pratt (KMP) Algorithm** – Uses prefix table for efficient linear search.  
26. **Rabin-Karp Algorithm** – Hash-based substring matching, great for multiple patterns.  
27. **Boyer-Moore Algorithm** – Fast searching with heuristics like bad character rule.  
28. **Z-Algorithm** – Builds Z-array to efficiently find pattern occurrences.  
29. **Aho-Corasick Algorithm** – Trie-based multi-pattern string matching using failure links.  
30. **Suffix Array Search** – Uses sorted suffix array and binary search.  
31. **Suffix Tree Search** – Allows fast substring search in linear time.  
32. **Rolling Hash** – Used in Rabin-Karp for sliding hash window.  
33. **FM-index (Full-text Minute Index)** – Compressed index for fast search (used in bioinformatics).  
34. **Burrows–Wheeler Transform (BWT)** – Text transformation used for compression and indexing.  
35. **Ukkonen’s Algorithm** – Linear time suffix tree construction.

---

## 🔐 Hash-based Searching Algorithms

Efficient for constant-time lookup based on keys:

36. **Hash Table Search** – Key-based search using hash functions.  
37. **Hashing with Chaining** – Handles collisions by storing items in buckets.  
38. **Hashing with Open Addressing** – Linear/Quadratic probing and double hashing methods.

---

## 🧠 Advanced and Specialized Searching Algorithms

Used in optimization, parallelism, AI, and quantum computing:

39. **Grover's Algorithm** – Quantum algorithm for searching an unsorted database.  
40. **Parallel Binary Search** – Divide search operations among threads/processors.  
41. **Backtracking Search** – Used in puzzles like Sudoku, maze solving.  
42. **Simulated Annealing Search** – Probabilistic technique for global optimization.  
43. **Genetic Algorithm** – Search based on evolution and natural selection.  
44. **Monte Carlo Search** – Randomized trials used in game playing and optimization.
