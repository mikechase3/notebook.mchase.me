---
description: 'In our last lecture on dynamic programming, we focus on the hardest problems.'
---

# Lecture 08: Knapsack Problem

## The Knapsack Problem

### Defining The Problem

Imagine you're a burglar, but you're on a bicycle instead of a car. Now, you're one of those evil protesters that are not being peaceful after the protest and looting Target, but you don't have your car so you can only carry 50 pounds worth of stuff.

Now, in order to feed yourself, you want to take the most expensive items and sell them on eBay because everyone stole the food already. There are a range of items left.

| Item | Quantity Remaining | Weight \(Int\) | Value \(Int\) | Value/lb |
| :--- | :--- | :--- | :--- | :--- |
| Nintendo Switch Lite | 1 | 6 lb. | $200 | $33.33 |
| Camera | 1 | 10 lb. | $300 | $30 |
| Mechanical Pencils | 1 | 1 lb. | $6 | $30 |
| Blade-less Fans | 1 | 5 lb. | $200 | $40 |
| Red Bull | 1 | 10 lb. | $40 | $4 |
| Off-Brand Laptops | 1 | 10 lb. | $150 | $15 |
| Sandbags | 1 | 10 lb. | $10 | $1 |

What do we want to take? We want to be as rich as possible, so we must **maximize the value/lb.** of the items we take.

### Brute Force Approach

* `2^n` possible combinations of items.
  * We can either take the item or not 
  * That means there are two choices per each item.
  * That means there are `2^n` possible combinations of items.

{% hint style="warning" %}
I don't understand anything after this.
{% endhint %}

### The Subproblem 

| Symbol | Meaning |
| :--- | :--- |
| B\[x, y\] | The maximum value when choosing from `k` items. |
| k | Represents an item: `1, 2, ..., k` |
| w | The weight limit of that particular item. |

$$
\texttt{Item 1: }w_1 = 2 \texttt{ pounds, } b_1 = \texttt{\$}3
$$



The subproblem is to compute the maximum value by choosing items from `1, 2, ...k`, up to the weight limit `w`. 

For example, `B[2, 3]` means the maximum value when we consider items `1` and `2` with a weight limit of `3`.

### Recursive Formula

> * Item k's weight $$W_k$$ &lt; w. Item _k_ cannot be part of the solution
> * Case $$w_k ≤ w$$. Item k should be in the solution if it increases the total value.

$$
B[k,w] =

\begin{Bmatrix}B[k-1, w] \texttt{ if } w_k > w
 & \\ \texttt{max} \{B[k-1], w], B[k-1, w-w_k]+b_k\} \texttt{ else}
 &
\end{Bmatrix}
$$

{% hint style="danger" %}
I've got no idea what this formula means.
{% endhint %}

### Decomposition Table

* Once we solve a smaller problem, we need to place it into a table. 

| Item / Weight | 0 | 1 | 2 | 3 | 4 | 5 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 3 | 3 | 3 | 3 |
| 2 | 0 | 0 | 3 | 4 | 4 | 7 |
| 3 |  |  |  |  |  |  |
| 4 |  |  |  |  |  |  |

{% hint style="danger" %}
I don't understand this decomposition table.
{% endhint %}

### Solution to Maximize B\[n,w\]

* Once we solve something, we need to put it in a table. 

```java
for w = 0 to W
    B[0, w] = 0
for i = 1 to n
    B[i,0];
for i = 1 to n
    for i = 1 to n
        if wi ≤ w //item i can be part of the solution
            B[i,w] = bi + B[i-1, w-wi] //Add item i.
        else
            B[i,w] = B[i-1,w]
    else B[i,w] = B[i-1,w] //wi > w; does not add item i.
```

## Optimal Binary Search Tree With Minimum Search Cost

### Problem

Given the sequence $$K = \{k_1, k_2, ..., k_n\}$$ of `n` distinct keys:

* AND sorted $$k_1 < k_2 < ... < k_n$$ 
* AND the probability of searching $$k_i \texttt{ is } p_i$$ 

**The goal is to create a binary search tree with minimum expected search cost.**

* The number of items examined ⇒Actual cost.
* For key $$k_i$$ the cost is equal to $$\texttt{depth}_T (k_i) + 1$$ , where $$\texttt{depth}_t(k_i) = \texttt{depth of }k_i$$ in BST _T_ \(the root has depth 0\).
* The expected cost of search a key in the tree:

$$
\sum_{i=1}^{n}(\texttt{depth}_T(k_i) + 1) \cdot p_i
$$

$$
\sum_{i=1}^{n}\texttt{depth}_T(k_i) + 1 \cdot p_i + \sum_{i=1}^{n}p_i
$$

{% hint style="warning" %}
Why are there two equations? What do these mean \(ahhhh\)
{% endhint %}

### Solution

{% hint style="warning" %}
What do these even mean? i and pi and kr?
{% endhint %}

* We take the full problem with a range of $$k_i \text{ to }k_j$$ and divide it up into two parts: $$k_i \text{ to } k_{r-1}$$ and $$k_{r+1} \text{ to } k_j$$ 

![Source: Dr. Yao&apos;s Slides](../../.gitbook/assets/image%20%289%29.png)

If we consider the subproblem: `k1, k2, k3:`

> * $$k_1$$ in the root, left subtree of root is empty,  $$\{k_2 \text{, } k_3\}$$ is on right subtree of the root:
>   * The optimal BST for {k2, k3} is already solved with a cost of 0.3
>   * So the cost for {k1, k2, k3} with k1 as root is 0 \(from empty left-subtree\) + 0.3 \(from right-subtree\) + p1 + p2 + p3 = 0.8
> * k2 in root, {k1} is on the left subtree of the root, k3 is on the right subtree
>   * So the cost is 0.25 from left subtree + 0.05 from the right subtree + p1 + p2 + p3 = 0.8
> * k3 in root, {k1, k2} is on left subtree of the root, right subtree is empty.
>   * The optimal tree for {k1, k2} is already solved, with cost 0.65
> * Select 1 or 2 as optimal BST for {k1, k2, k3}

{% hint style="warning" %}
At this point, I'm so far gone that I just put this here.
{% endhint %}

![Source: Dr. Yao](../../.gitbook/assets/image%20%287%29.png)

![Source: Dr. Yao&apos;s Slides](../../.gitbook/assets/image%20%288%29.png)



## Works Cited

1. Dr. Zhongmei Yao's [CPS 450 course](http://academic.udayton.edu/zhongmeiyao/450592.html). _\(Table content, solutions, and full slides. TODO: Remove\)._
2. [Back to Back SWE](https://backtobackswe.com/platform/content/quicksort/code) _\(Nothing yet, but I'm sure I'll use it when I review.\)_

