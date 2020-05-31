---
description: What is this madness?
---

# Lecture 04: Divide and Conquer

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

## Running Time

T\(n\) 

