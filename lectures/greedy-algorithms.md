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

## Searching for the Optimal Solution

{% hint style="info" %}
I don't understand what was going on here; it's probably not important?
{% endhint %}

When we're trying to solve a problem, there are a few different ways we can try and solve it:

| Method | Explanation |
| :--- | :--- |
| Exhaustive Search \(Brute Force\) | We search through all the psosible solutions \(i.e., n letters in a sequence: `2^n` subsequences. |

## Works Cited

| Title | Author | Content Used |
| :--- | :--- | :--- |
| [Greedy Algorithms Fundamentals](https://backtobackswe.com/platform/content/greedy-algorithms-fundamentals) | Benyam Ephrem | Making Change Example |
| [Erase Interval Overlaps](https://backtobackswe.com/platform/content/erase-interval-overlaps) | Back to Back Team | Problem, Solution |
| Searching for the optimal solution | Dr. Yao | Her structure, what she said. |

