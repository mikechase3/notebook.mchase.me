# Greedy Algorithms

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
I don't understand what's the point of this section. _\(Time: 00:15\)_
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

## 

## Works Cited

| Title | Author | Content Used |
| :--- | :--- | :--- |
| [Greedy Algorithms Fundamentals](https://backtobackswe.com/platform/content/greedy-algorithms-fundamentals) | Benyam Ephrem | Making Change Example |
| [Erase Interval Overlaps](https://backtobackswe.com/platform/content/erase-interval-overlaps) | Back to Back Team | Problem, Solution |
| Searching for the optimal solution | Dr. Yao | Her structure, what she said. |

