---
description: >-
  In this section, we learn to analyze running times of divide & conquer
  algorithms so we can use this strategy to solve new problems.
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
3. Combines it together _in linear time._

> #### Given the following equation:

$$
T(n) ≤ 2T(n/2)+O(n)
$$

> * _\(n/2\)_ is the **split** \(divide\) part of the routine.
> * _2_ is the 2 additional calls that are created.
> * _O\(n\)_ is the merge subroutine.
> * Increases efficiency.
>   * For Merge Sort, we took an algorithm that is normally O\(N^2\) and made it O\(n\*log\(n\)\).

### Example: Closest Pair of Points

{% hint style="danger" %}
This example is from _Back to Back SWE,_ entitled _Divide and Conquer Methodology_. It will not make sense unless you watch the video at 4:02.
{% endhint %}

* Given a plane with a set of points `P1, P2... P6`, what is the closest set of points in the plane.
* We have an x-y coordinate mapping and we can see with our eyes what the answer is.

#### To solve quadratically:

1. There is nC2 ways, or n! ways to connect the points. That's O\(n^2\).
2. Solve by brute force: 2 for loops comparing points.

#### To solve using Divide & Conquer

1. Take a vertical slice of the points. 
2. **Split** the first input in half vertically.
   1. Find the closest points in the left half to the line.
   2. Find the closest points in the right half to the line.
3. **Merge** them in linear time _\(not explained here\)._

## Analyzing Running Time

When we analyze the running time of recurrence functions, we do so using piecewise functions. 

![An example of a piecewise function defining the running time.](../.gitbook/assets/recurrence-function-time-example.jpg)



