---
description: What is this madness?
---

# Lecture 04: Divide and Conquer Methodology

## Goals

1. Analyze the running time for divide/conquer algorithms.
2. Understand and apply this strategy.



## General Technique

1. **Divide** the problem into sub-problems.
2. **Conquer** sub-problems by _recursively_ solving them.
3. Solve the **base case** when problems are small enough to solve by brute force.
4. **Combine** solutions to sub-problems to build a solution to the original problem.

{% hint style="info" %}
Example:

In sorting algorithms, sometimes we divide arrays into smaller arrays so we can solve each small part by brute force and put them together.
{% endhint %}

### Example: Merge Sort

[Merge sort](https://medium.com/basecs/making-sense-of-merge-sort-part-1-49649a143478) works in 3 steps:

1. Takes the input array
2. Splits it in half.
3. Combines it together.

Given the following equation:

$$
T(n) ≤ 2T(n/2)+O(n)
$$

* _\(n/2\)_ is the **split** \(divide\) part of the routine.
* _2_ is the 2 additional calls that are created.
* _O\(n\)_ is the merge subroutine.



