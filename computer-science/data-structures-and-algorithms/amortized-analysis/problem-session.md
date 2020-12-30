# Problem Session

## Quiz Review

### Longest Common Subsequence

The correct answer is A.

![](../../../.gitbook/assets/image%20%2818%29%20%281%29%20%281%29%20%281%29.png)

### 0-1 Knapsack Problem

> Given n items and weight W&gt;0, where item i has integer weight w\[i\] and value b\[i\], what is the running time of the dynamic programming approach for solving the 0-1 knapsack problem?
>
> It's O\(n\*W\)

### Sorted Sequence

Given a sorted sequence of keys, where key k\[i\] is searched with probability p\[i\], for i = 0, 1, ... n-1, what is the running time of the dynamic programming approach for finding the optimal binary searchtree with the minimum cost?

* `O(n^3)`

### Maximum Subarray

Given an input with length `n`, what is the running time of the dynamic programming approach for finding the maximum subarray?: `O(n)`

### DFS

Given a graph of V nodes and E edges, which algorithm Design paradigm is exemplified by DFS? 

* **Brute Force,** because we want to visit all the nodes.
* It’s not greedy because we don’t sort them.
* It’s not dynamic programming because there’s not a table that we want to fill in.

### BFS

Given a graph with V nodes and E edges, which algorithm 

* Brute force approach.
* We can’t say _divide and conquer_ becuase there is no _conquer_ part of it.

### Kruskal’s Minimum Spanning Tree

* For Kruskal’s, we want to use edges to cover all nodes on the graph.
* Each edge costs money.
* We use a **greedy approach** because we sort the edges by their weights. 

### Dijkstra’s Single Source

* This is a **greedy** approach.
* We talked about this in CPS 350

### K-th Largest Item

* This is a partition algorithm.
* We partiiton this into two halves.
* This is a **divide and conquer approach.**
* We used the masters theorem to find the running time. It is not _O\(n\*log\(n\)\)_.

### Longest Palindromic Substring

Which algorithm design paradigm is exemplified by the longest palindromic substring algorithm we discussed in class?

* Dynamic programming.
* It’s **O\(n^2\)**

## Practice Problems

{% hint style="info" %}
See the PDF Dr. Yao attached on Isidore
{% endhint %}

### First Problem

> If the set of stack operations included a multipush operation, which push k items onto the stack would the O\(1\) bound on the amoritized cost of stack operation continue to hold? Explain

Push, pop, multipop\(k\), multipush\(k\)

> We will consider n operations. We will figure out the cost for n operations. T\(n\)/n implies the amortized cost or the cost per operation.

What if all n operations are multipush\(k\)? What is the total cost then?

* We can assume that since each operation takes `O(k)`, we can multiply it by `n` operations, which means tot total cost is `O(n*k)`.
* Multipop is still `O(1)` because it depends on the number of items we push on the stack.

### Second Problem

> Suppose we perform a sequence of stack operations on a stack whose size never exceeds k. After every k operations, we make a copy of the entire stack for backuip pusposes. Show that the cost of `n` stack operations, including the copying the stack, is O\(n\) by assigning suitable amoritized costs to the various stack operations.

* It’s O\(n\) for the explanation above.

### Accounting Method

{% hint style="warning" %}
I’m so confused.
{% endhint %}

> Suppose we perform a sequence of stack operations on a stack whose size never exceeds k. After every k operations, we make a copy of the entire stack for backup purposes. Show that the cost of n stack operations, including the copying the stack is O\(n\) by assigning suitable amortized costs to the various stack operations.

#### Step 1: Assign Budget for Operations

* Push, we assign $5
* Pop, we assign $1
* Copy, we assign $0.

#### Step 2: We will show we have enough budget for n operations.

After every `k` operations, we will have copy: K operations.

* The push costs $1, so do we have savings here? _Yes, save $4._
* Pop: costs $1, so do we have a savings here? _No, we save $0._

We will show we have enough budget for `n` operations: after every k operations, we will have copy:

* k operations
* Push, cost $1, do we have saving here? Save $1? \(She crossedf out $4\)
* Pop: Cost $1. ~~We can use $4 that we save via push for pop~~ save $1.

> ”But you can see we saved enough money. Our bank balance is never negative.

#### Summary

We start from an arbitrary budget, but then we revise our budget to make our argument simple and strong.

### Third Problem

> Amortized anlysis determines the running time for a sequence of operations. Consider a FIFO queue that is implemented using two stacks:
>
> 1. Enqueue\(x\): push x onto stack1
> 2. dequeue\(\): if stack2 is empty then pop the entire contents of stack1 pushing each element in turn onto stack 2. Now pop from stack2 and return the result.
>
> Enqueue\(A\), B, C
>
> dequeue\(\): Return A
>
> enqueue\(D\), E, F
>
> dequeue\(\): which tiem? Reutnr B.
>
> What is T\(n\), the cost of n operations?

{% hint style="warning" %}
I don’t know what this means.
{% endhint %}

> Recall stacks three operations: push, pop, and empty. Each having cost 1. Analyze the total cost \(i.e. running time of a sequence of `n` operations on the queue for n&gt;1. Initially, the queue is empty.

* Our total cost is T\(n\).
* You can change your money as long as it’s a fixed number?



