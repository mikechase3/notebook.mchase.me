---
description: >-
  The first half uses the k-bit counter as a review of aggregate & accounting
  methods. Then, we learn about potential.
---

# Lecture 11: More Amortized Analysis

## Review

> \[An\] amortized analysis allows one to estimate the cost `T(n)` of a sequence of `n` operations on a data structure.

{% hint style="warning" %}
Dr. Yao's slides say _"Make no distinction between operation types_." What does that mean? This contradicts what we did in the accounting method where we assign different values different costs.

Furthermore, how do we know what operations we're doing? What if we just had an operation that just doubled the array size and copied all the elements? Wouldn't we run out money in the accounting problem? if we had 3 items and called that function infinite times, then `T(n)` is infinite?
{% endhint %}

### The Three Methods

| Method | What it is | When to use it |
| :--- | :--- | :--- |
| Aggregate | A quick average. |  |
| Accounting | A bank account. |  |
| Potential | ? |  |

{% hint style="warning" %}
When should we use each one?
{% endhint %}

## Example: The K-Bit Counter

![K-bit counter, at the low level.](../../.gitbook/assets/image%20%2821%29.png)

### Understanding The [Problem](https://www.youtube.com/watch?v=2kUTu0sI_Rs)

K is the number of bits that we have. And we want to count things and manage each digit.

```text
Example where k = 6. (There are 6 bits).
======

000000
000001 //Costs 1 flip from above.
000010 //Costs 2 flips
000011 //Costs 1 flip
000100 //Costs 3 flips
000101 //Costs 1 flip
000110 //Costs 2 flips.
...
111111
000000 //Costs k flips
```

* We can make a _predicted cost_: after `n` operations, we will have done $$2 \cdot n$$ flips.
  * This sets an upper bound that's surprising accurate 👇 

![Source: &quot;The k-bit counter&quot;](../../.gitbook/assets/image%20%2819%29.png)

Notice how our predicted cost never exceeds the actual cost. This is good!

![](../../.gitbook/assets/image%20%2820%29.png)

1. The worst case cost of a single _increment_ operation is $$k \in O(k)$$ .
2. The total cost of `n` _increment_ operations \(starting from all 0s\) is $$\leq 2\cdot n \in O(n)$$ .
3. So, on a single _increment_ operation, the _**average cost, or amortized**_ cost of an increment is `2`, and $$2 \in O(1)$$ 

{% hint style="info" %}
If we used the worst-case cost, we would have dramatically over-estimated the actual cost. By using an amortized analysis, we got a much tighter bound.
{% endhint %}



## Works Cited

| Title | Content Used | Author |
| :--- | :--- | :--- |
| Introduction to Algorithms | Definitions for introduction | Cormen et. al. |
| Wikimedia Commons | K-bit counter photo. | Various. Noncommercial reuse. |
| Class lecture & slideshow | Structures, definition, and content | [Dr. Zhongmei Yao](http://academic.udayton.edu/zhongmeiyao/) |
| [The K-Bit Counter](https://www.youtube.com/watch?v=2kUTu0sI_Rs) | K-bit example, graphs. | simrob \(Youtube\) |
| [Amortized Analysis \(of the k-bit counter\)](https://www.youtube.com/watch?v=U5XKyIVy2Vc) | None, but noteworthy. | simrob \(Youtube\) |



