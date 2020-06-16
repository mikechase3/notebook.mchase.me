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

\*\*\*\*

