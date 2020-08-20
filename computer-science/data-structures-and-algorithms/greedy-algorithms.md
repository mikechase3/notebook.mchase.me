# Greedy Algorithms \(L09\)

## Fundamentals

* We **choose the locally optimal to solve a global problem.**
* Greedy algorithms are tricky because greedy solutions are simple.
* Proving a greedy algorithm is correct requires proofs and are super hard.
* You can't know they're right until you prove that they're right.

### Famous Examples

* Scheduling problems like [_interval scheduling maximization_](https://en.wikipedia.org/wiki/Interval_scheduling#Interval_Scheduling_Maximization).
* [Minimum spanning tree finding](https://en.wikipedia.org/wiki/Minimum_spanning_tree) \(Where Kruskal's and Prim's exist\).

### Example: Making Change

Let's say we run a grocery store and we hire a bunch of Canadians to work inside the US. It turns out that no matter how much training we give them, sometimes they mix up coins and they don't know how to make change quick enough, so we want a computer to tell them:

```text
To make change for $1.50 give the customer:
1 | $1 coin.
2 | $0.25 coins.
```

How would we design an algorithm that makes change for $1.50 in the least amount of coins? Given that the options are `$1, $0.25, $0.10, $0.05, and $0.01`?

So, we could start at $1.50 and ask: _what's the largest coin we can put in there?_, which would be $1. Then we have $0.50 left and fit that coin in there. That's the optimal because it uses only two coins.

However, that greedy approach might not always be the best approach. 

## Finding the Optimal Solutions

{% hint style="info" %}
I don't understand what this section is about.. _\(Time: 00:15\)_
{% endhint %}

| Method | Explanation |
| :--- | :--- |
| Exhaustive Search \(Brute Force\) | We search through all the psosible solutions \(i.e., n letters in a sequence: `2^n` subsequences. |
| Dynamic Programming | Search through a very small fraction of the feasible solutions \(e.g., prefix of a sequence\) |
| Greedy | Only **one** partial solution is maintained and grown. |

#### More on the Dynamic Approach

* **Optimal substructure:** To keep the search small, the problem needs to have a sufficient structure.
  * Recall: if T is optimal and T' ⊂ T, then T' is optimal to the subproblem.
* Typically, dynamic programming involves **recursive procedures**
  * At each iteration, a small \(polynomial size\) set of partial solutions is maintained, one of which will lead to the optimal solution
  * In the next iteration, members of the se tare extended based on information from other members of the set
  * At the last step, the optimal solution is chosen from the set

#### Greedy Cont.

This may be viewed as the ultimate form of dynamic programming, in which only one partial solution is maintained.

The problem needs be more structured for this approach to work \(i.e., a matroid\)?

## Fractional Knapsack Problem

### Understanding the New Problem

#### Recall: 0-1 Knapsack Problem

* The items cannot be divided?
* The thief must take the entire item or leave it behind.
* Dynamic programming solution: _if item weights are an integer, the running time is `Θ(nW)`_

#### What makes fractional different?

* The thief can take partial items
  * For instance, if items are liquids or powders
* This is where we'll want to use the greedy algorithm approach.

{% hint style="success" %}
Summary: the fractional knapsack problem now lets us take fractions of items.
{% endhint %}

### The Greedy Approach

1. Sort the items in decreasing order of value per pound. Rank them by value/weight: $$b_i/w_i$$ .
2. While there is still room in the knapsack \(with a limit of _W_ pounds\):
   1. Consider the next item in the sorted list
   2. Take as much possible \(all there is or as much as what will fit\)

```python
def fracctional_knapsack(v, w, W):
    load = 0
    i = 1
    while load < W and i ≤ n:
        if initial_weight ≤ W-load:
            take all of the item i
        else:
            take (W-load)/wi of item i #wi is w_i. (w sub i)
            i = i + 1 #Add what was taken to load
```

{% hint style="warning" %}
I don't understand what all these variables are.

* W is the total amount of weight you can carry?
* v \(I have no idea\)
* w \(I have no idea\)
* initial\_weight: why is this in the while loop? Is this how much space you have left?
* i: Is this the total number of items that are available?
* W\_i \(Sub i\): The weight of each item.
{% endhint %}

### Greedy Will Fail

* Greedy will fail in general.
  * The greedy choice property is that a globally optimal solution can be arrived at by making a local optimal \(greedy\) choice.
* Greedy algorithms are easily designed, but correctness of the algorithm is harder to show.
  * We'll later examine proofs.

{% hint style="warning" %}
Why did the knapsack problem fail? It seems like it will work.
{% endhint %}

## Matroids: An Abstract Structure

> **Matroids** characterize a group of problems for which the greedy algorithm yields an optimal solution.

### Notation Definitions

| Symbol | Meaning |
| :--- | :--- |
| S | A finite set of items. |
| F | A nonempty collection of subsets \(S\) |

### Notation Examples

Let `S` be a finite set, and F a non-empty collection of subsets S.

![](../../.gitbook/assets/image%20%2823%29.png)

#### What does it mean to be in a subset? What's the size of a subset?

![](../../.gitbook/assets/image%20%2827%29.png)

### Defining a Matroid

{% hint style="info" %}
TODO: _**Replace slides with my own content!**_
{% endhint %}

{% hint style="warning" %}
What does all of this notation mean?
{% endhint %}

![](../../.gitbook/assets/image%20%2824%29.png)

### Example: Graphic Matroids

#### Proving if \(S, F\) is a matroid

{% hint style="warning" %}
What is \(S, F\).  What does it mean that "F is a subset of S?" Is S an element? A collection of elements?
{% endhint %}

![](../../.gitbook/assets/image%20%2826%29.png)

### Weighted Matroids

* We call a matroid weighted if it contains a weight function?

{% hint style="warning" %}
What's a weight function? What does the definition _A_ mean? **I'm getting lost in the notation.**
{% endhint %}

![](../../.gitbook/assets/image%20%2828%29.png)

{% hint style="info" %}
Click this [link](https://www.dropbox.com/s/iwf13fzz4tbbfna/Lecture%2009%20Greedy%20Approach.pdf?dl=0) to see Dr. Yao's slides on correctness where I get lost in notation again, spanning trees, Kruskal's Minimum Spanning Tree, and the running time of these greedy algorithms.
{% endhint %}

## Kruskal's Minimum Spanning Tree

* A **tree** is really just a graph with no cycles.
* A **minimum spanning tree** is just a spanning tree where the sum of the weights is minimal.
* Kruskal's is sort-of like Dikstra's.. But you start off saying every thing is in it's own bubble.
  * Then you take the edge that's the smallest and merge the bubbles.
  * You repeat this until there is only one bubble left. 

## Works Cited

| Title | Author | Content Used |
| :--- | :--- | :--- |
| [Greedy Algorithms Fundamentals](https://backtobackswe.com/platform/content/greedy-algorithms-fundamentals) | Benyam Ephrem | Making Change Example |
| [Erase Interval Overlaps](https://backtobackswe.com/platform/content/erase-interval-overlaps) | Back to Back Team | Problem, Solution |
| Lecture Notes & Slides | Dr. Zhongmei Yao | Definitions, some problems/examples. ⚠️ |

