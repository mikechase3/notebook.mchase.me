---
description: Nov 7 2023. Dr. Kirbas. CPS536. Kleinberg Tardos Slides.
---

# Weighted Interval Scheduling

## Useful External Resources

{% embed url="https://stumash.github.io/Algorithm_Notes/dynamic/weighted_intervals/weighted_interval.html" %}
\\
{% endembed %}

## Understanding the Problem

**Goal**: find a compatible subset of intervals that return the highest maximum value (e.g. money).

{% embed url="https://stumash.github.io/Algorithm_Notes/dynamic/weighted_intervals/intervals_sorted.png" %}

* Job j starts at s\_j, finishes at f\_j, and has weight or value v\_j.
* Two jobs are **compatible** if they don't overlap.
* **Goal**: find the max weight of compatible jobs.

## Why Greedy Approach Doesn't Work

Recall the unweighted interval scheduling:

* **Observation:** Greedy algorithm can fail spectacularly if arbitrary weights are allowed.
* **Recall**: greedy algorithm only works if all weights are 1.
  * Consider jobs in ascending order of finish time
  * Add job to subset if it's compatible.

## Weighted Interval Scheduling Approach

First, we'll create a formalization of our solution. We have to define a specific function called "p of job j" which is defined as the largest index of the job that finishes before job `j` starts. So what does that means?

* Find all the jobs that finish before job j starts & find the one that has the largest finish time & t

<figure><img src="../../../../.gitbook/assets/image (676).png" alt=""><figcaption></figcaption></figure>

### Binary Choice

{% hint style="warning" %}
Review how this works cause I don't get it.
{% endhint %}

<figure><img src="../../../../.gitbook/assets/image (680).png" alt=""><figcaption></figcaption></figure>

### Brute Force

* **Observation**: recursive algorithm fails spectacularly because of redundant sub problems -> exponential algorithms.
* For example, the number of recursive calls for family of _layered_ instances grows like _Fibonacci_.

```
Compute-Optimal(j){
    if (j = 0)
        return 0
    else
        return max(v_j + Compute-Optimal(p(j)), Compute-Opt(j-1))
}
```

So the time complexity of this initial design is exponential. The reason for this high time complexity is because we're recalling our function with the same input multiple times so we need to memoize.

<figure><img src="../../../../.gitbook/assets/image (678).png" alt=""><figcaption><p>Ignore the text on the top left.</p></figcaption></figure>

## Weighted Interval Scheduling with Memoization

* This is apparently what makes dynamic programming what it is.
* Keep a hash table.
  * Key is the input parameters
  * Value is the output.
  * Now, we don't have to recompute.

<figure><img src="../../../../.gitbook/assets/image (679).png" alt=""><figcaption></figcaption></figure>

### Post Processing

**Q**: Dynamic programming algs compute the optimal value. What if we want the optimal solution schedule itself? **A:** do some postprocessing.

<figure><img src="../../../../.gitbook/assets/image (682).png" alt="" width="375"><figcaption></figcaption></figure>

### Example of "not the most efficient solution"

<figure><img src="../../../../.gitbook/assets/image (684).png" alt=""><figcaption></figcaption></figure>

## Best Method

* Instead of starting from the last element, why don't we just start with the first & populate the table from left to right?

<figure><img src="../../../../.gitbook/assets/image (686).png" alt=""><figcaption></figcaption></figure>



<figure><img src="../../../../.gitbook/assets/image (687).png" alt=""><figcaption></figcaption></figure>
