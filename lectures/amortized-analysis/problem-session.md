# Problem Session

## Quiz Review

### Longest Common Subsequence

The correct answer is A.

![](../../.gitbook/assets/image%20%2816%29.png)

### 0-1 Knapsack Problem

> Given n items and weight W&gt;0, where item i has integer weight w\[i\] and value b\[i\], what is the running time of the dynamic programming approach for solving the 0-1 knapsack problem?
>
> It's O\(n\*W\)

### Sorted Sequence

Given a sorted sequence of keys, where key k\[i\] is searched with probability p\[i\], for i = 0, 1, ... n-1, what is the running time of the dynamic programming approach for finding the optimal binary searchtree with the minimum cost?

* `O(n^3)`

### Maximum Subarray

Given an input with length `n`, what is the running time of the dynamic programming approach for finding the maximum subarray?: `O(n)`

### DFS

Given a graph of V nodes and E edges, which algorithm Design paradigm is exemplified by DFS? 

* **Brute Force,** because we want to visit all the nodes.
* It’s not greedy because we don’t sort them.
* It’s not dynamic programming because there’s not a table that we want to fill in.

### BFS

Given a graph with V nodes and E edges, which algorithm 

* Brute force approach.
* We can’t say _divide and conquer_ becuase there is no _conquer_ part of it.

### Kruskal’s Minimum Spanning Tree

* For Kruskal’s, we want to use edges to cover all nodes on the graph.
* Each edge costs money.
* We use a **greedy approach** because we sort the edges by their weights. 

### Dijkstra’s Single Source

* This is a **greedy** approach.
* We talked about this in CPS 350

### K-th Largest Item

* This is a partition algorithm.
* We partiiton this into two halves.
* This is a **divide and conquer approach.**
* We used the masters theorem to find the running time. It is not _O\(n\*log\(n\)\)_.

### Longest Palindromic Substring

Which algorithm design paradigm is exemplified by the longest palindromic substring algorithm we discussed in class?

* Dynamic programming.
* It’s **O\(n^2\)**



