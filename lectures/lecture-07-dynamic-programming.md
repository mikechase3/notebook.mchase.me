---
description: We present and discuss further examples.
---

# Lecture 07: Dynamic Programming

## Recall: Four Step Method

> 1. **Characterize the structure of an optimal solution**. _\(What are the sub-problems?\)_
> 2. **Recursively define the value of an optimal solution.** _\(i.e. recurrence for Fibonacci\(n\): Fib\(n\) = Fib\(n-1\)+\(n-2\), which is a formula involving only smaller sub-problems._
> 3. **Compute the value of an optimal solution in a** _**bottom-up**_ **fashion**. Store \(memorize\) the results of all sub-problems, which can then be later accessed to solve other sub-problems.
> 4. **Construct an optimal solution from computed information.**
>
> _Source: Dr. Yao's Slides, Dynamic Programming Part 1. \(Paraphrased\)_

## The Longest Common Subsequence Problem

### The Problem

Given 2 sequences \(shown below\), find a subsequence common to both whose length is _longest_.

$$
X=\{x_1, x_2, ... x_n\} \text{ and } Y=\{y_1, y_2, ... y_n\}
$$

{% tabs %}
{% tab title="Brute Force" %}
So the run time is pretty bad. I didn't write out how to do it, but Dr. Yao says it's:

$$
T=O(2^n)
$$
{% endtab %}

{% tab title="Second Tab" %}

{% endtab %}
{% endtabs %}

