---
description: Chapter 3
---

# Lecture 02: Asymptotic Notation

* Checkout [this](https://www.programiz.com/dsa/asymptotic-notations#:~:text=Theta%20Notation%20%28%CE%98%2Dnotation%29,case%20complexity%20of%20an%20algorithm) amazing resource first!

## Asymptotic Notation Describes Growth To Infinity

1. Asymptotic notation is a way to describe the behavior when n goes to infinity.
2. We will study other notations besides Big Oh. 

## Notation Goals

1. Provide **Sufficient Conditions** so that big oh notations are valid.
2. Discuss **Necessary Conditions** of each notation.

## Big Oh Running Time

To find the running time… 1. Describe the algorithm in pseudocode so you know what's going on. 2. Count how many operations happen on each line by writing it to the left. _We go through the loop n-1 times. Then do an if statement n-1 times. And in the worst case, it assigns it n-1 times._ 3. Add up all of the individual operations together to find the total.

### Finding `O(g)` for some `f(n)`

1. Drop the lower-order terms and constant factors
2. Use the smallest possible class of functions
3. Use the simplest expression of the class.
4. When we read instructions, we write `f(n) = O(g(n))`. We would say that `f(n)` is contained in `O(g(n))`
   * `O(...)`is a set of function `f(n)`

### Defining O\(N\) as a function

By **definition**, O\(n\) or big Oh-notation says that `O(g(n)) = {f(n): there exist positive constants c and no such that 0 <= f(n) <= c*g(n) for n >= n0}`

### Example Problem

Can you prove that `f(n) = 2n+10 is in O(n)?` 1. If the maximum is `c*n`, then we can put that on the right. \`2n+10 ≤ c\*n 2. Pick constants for c and n0 and see if it makes sense.

## Questions for Dr. Yao

1. What does it mean that a function is contained in another function? _See functions_

