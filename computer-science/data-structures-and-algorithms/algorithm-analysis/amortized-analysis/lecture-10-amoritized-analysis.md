# Amortized Analysis

## Introduction

> **Amortized analysis allows one to estimate the cost `T(n)` of a sequence of `n` operations on a data structure.**

> In an **amortized analysis**, we average the time required to perform a sequence of data-structure operations over all the operations performed.
>
> * We can show that the average cost of an operation is small, if we average over a sequence of operations, even though a single operation within the sequence might be expensive.
> * Probability is not involved.
> * It guarantees the **average performance of east operation in the worst case.**
>
> _Source: Introduction to Algorithms; Cormen et. al._

### The Goal of Amortized Analysis

We want to show that although some individual operations may be expensive, on average, the cost-per-operation is lower than the cost of those expensive ones.

On average, the cost per operation is lower than the cost of those expensive ones. **We want to measure the average cost of operation** instead of the worst case.

### Three Different Approaches

Below are 3 different approaches to figure out how to measure the average cost of operation: the aggregate method, the accounting method, and the potential method.

| Method     | What it is       | When to use it |
| ---------- | ---------------- | -------------- |
| Aggregate  | A quick average. |                |
| Accounting | A bank account.  |                |
| Potential  | ?                |                |

{% hint style="warning" %}
When should we use each one?
{% endhint %}

## Heap Sort Example

### What are Heaps?

![](<../../../../.gitbook/assets/image (13).png>)

> A heap is a binary tree storing keys at its internal nodes and satisfying the following properties:

Min-Heap Properties

* **Heap Order:** Every child node must be larger than the parent node.
* **Complete Binary Tree**: You have to fill an entire level before moving onto the next level.

### What is Heap Sort?

Heap-sort lets you put things in order by using a heap.

1. Insert a key into the heap.
2. Let the heap sort itself so that the number/letter you just added is in order & follows the [heap properties.](lecture-10-amoritized-analysis.md#what-are-heaps)
3. Repeat steps 1 and 2 until all the keys are added to the heap.
4. Finally, remove every object from the root of the heap and store the output into an array.
5. That array will be in order and you're done!

### Amortized Analysis of Heap Sort

#### How efficient is this?

1. Each of the `n` calls to insert into the heap operates on a heap with at most `n` elements.
2. Inserting a new item into a heap with n elements takes $$O(log(n))$$ time.
3. The total time spent doing the `n` insertions is $$O(n \cdot log(n))$$ time.

#### This could be an over-estimate

* Different insertions take different amounts of time.
* Many of the insertions are on significantly smaller heaps.

## Aggregate Method: Augmented Stack

![](<../../../../.gitbook/assets/image (14).png>)

### Multipop Method

{% hint style="info" %}
It's a stack, but you can pop multiple items from the stack at the same time.
{% endhint %}

```java
multipop(S, k)
    while S is not empty and k > 0
        Pop(S)
        k = k-1
```

* We will repeat k times, and S contains the items on the stack.
* If k is 3, we can pop 3 items at once instead of just one.

| Operations           | Description                            |
| -------------------- | -------------------------------------- |
| `push(S, x)`         | Pushes one item on the stack.          |
| `pop(S)`             | Pops the top item off the stack.       |
| `multipop(\|S\|, k)` | Pop the top k elements, k ≤ size of S. |

{% hint style="info" %}
When we use the notation |S|, that refers to the size of the stack.
{% endhint %}

{% hint style="warning" %}
I don't know what the parameters mean for the push(S,x) mean.
{% endhint %}

* Implement this with either an array or linked list.
  * Time for each push is O(1)
  * Time for each pop is `O(1)`
  * Time for each multipop is $$O(min(|S|, k))$$ .

{% hint style="warning" %}
I don't understand what |S| is, or why it's in an absolute value bracket. She said "of 2 values..." but what two values? I don't see two values.
{% endhint %}

### The Aggregate Method

* Show that a sequence of `n` operations takes T(n) time.
* We can say that the amortized cost per operation \*\*\*\* is then T(n)/n
* Makes no distinction between operation types.
* T(n) is the time it takes to do `n` operations; and the n is the total operations.

{% hint style="warning" %}
I don't understand this at all. Where'd we get `T(n)/n` from. Doesn't T(n) depend on how many operations there are? Like if we make 10 copies of arrays, we'd have T(10\*n), so what's `T(n)`

And how can `T(n)` be divided by n if `T(n)` depends on what `n` is? Are they mismatched parentheses? Should it be `T(n/n)`? But that makes no sense because it's just 1.
{% endhint %}

#### Simple Argument

{% hint style="warning" %}
Argument for what?
{% endhint %}

> In a sequence of `n` operations, the stack never holds more than `n` elements. So the cost of a multipop is O(n).

* So it's talking about any combination of operations.
* You can do some pushes, some pops, in whatever order you want.

{% hint style="info" %}
The goal is to find out the worst-case running time of any `n` operations.
{% endhint %}

> The worst-case of any sequence of n operations is O(n^2). Hence, the amortized cost per operation is: $$O(n^2/n) = O(n)$$ .
>
> But this is an over-estimate!

* We got the n^2 by saying n remove stack operations, and each operation is O(n).
  * It's the maximum running time for completing n operations.

{% hint style="warning" %}
Why is it an overestimate? I thought the whole point of amortized analysis was so we don't have over-estimates.
{% endhint %}

### Aggregate, cont.

> Key idea: total number of elements popped in the entire sequence of n operations is at most the total number of pushes done for both pop and multipop.
>
> The maximum number of pushes is n.

The maximum amount of work you can do is add `n` elements and remove `n` elements, so it's just `O(n) + O(n)`.

* O(n) is for the pushes.
* O(n) is for both pops and multipops.

> So time for the entire sequence is O(n) + O(n)

> And amortized cost per operation is $$O(\frac{2n}{n}) = O(1)$$

{% hint style="success" %}
This doesn't tell you the running time of an algorithm, but the average running time of a whole bunch of operations.
{% endhint %}

{% hint style="warning" %}
How did she come to this conclusion? Where'd she get the 2n/n?
{% endhint %}

### Summary

{% hint style="info" %}
In Notes.
{% endhint %}

## Accounting Method

In the accounting method, we pretend like we have a **bank account** which can never be over-drafted. We can use this method to address multiple operations within a function and find an upper-bound on the average running time. The upper bound is the cost per operation; while the average refers to the entire set.

This will be more clear with an example, but generally, it's a 2-step process:

1. Assign a "cost" for every operation. _For example, if we were adding elements into a dynamically resizing array, we might say "The add function costs O(3), even though it only costs O(1). We'll just store an extra O(2) in a bank for later use._
2. When we have to do weird operations for cases that are more rare, we'll use the money we stored from the bank. _In a dynamic array, once we run out of space, we'll copy all the values from the small array into a larger array. We'll take these funds from our bank._

{% hint style="danger" %}
Is this an accurate statement? I wrote it myself.
{% endhint %}

### Example: Augmented Stack

This example uses the same augmented stack as the example in the last section. Let's take this example and follow the 2-step method I just described above.

#### Step 1: Assign functions an amortized cost.

Remember science labs when you had an **independent** and **dependent** variable? We cannot control the actual cost of _how many operations does resizing take_ because to resize an array, it will always take `O(n)`. But what we can control is the _cost_, or what we charge our user for performing these calculations.

Like in a business, our **price, or amortized cost, is the independent variable.** We can charge however much we want; however, to stay in business and be competitive, we want to keep it as small as we can without losing money. **Our production costs, our profit/loss** isn't something we can really control.

Let's provide a working example first where we control our independent variables and assign them prices in such a way that we will **never have a negative balance**. In the accounting method, it is vital that at any point, we never have a negative balance (because then it is not an accurate upper bound).

| Method   | Price / Amortized Cost | Production Cost / Actual Cost | Comment                                |
| -------- | ---------------------- | ----------------------------- | -------------------------------------- |
| Push     | $2, O(2)               | O(1)                          | We're saving more money into the bank. |
| Pop      | $0, O(0)               | O(1)                          | We withdraw from the bank.             |
| Multipop | $0                     | O(1)                          | We withdraw from the bank.             |

{% hint style="info" %}
Notice how in some instances, we're losing money? This is like a _buy 3 push, get 3 pops free_ advertisement. Notice that even though we're losing money in some cases, we never go bankrupt.
{% endhint %}

Another question:

> Which operation "Needs money from the bank" when performed?
>
> * The actual cost for Pop 1 is 1. For multipop, the actual cost is min(|S|, k)

#### Questions to Consider

> Which operation "saves money to the bank" when performed?

* The push cost really only takes `T(1)` time.
* We pretend that it costs `T(2)` time and store an extra `T(1)` in the bank.

> Which operation "needs money from the bank when performed?"

* Pop needs `T(1)`.
* Multipop's actual cost is `min(|S|, k)`.
  * We have two options here.
  * Either, we pop k elements from the stack.
  * OR, if the user tries to remove more elements than the stack actually holds, we only remove |S| elements.
  * |S| is the size of the stack, so it's like saying _remove all the elements from the stack, and stop trying to because it's empty, even though the user keeps trying because they're an idiot and don't know there's nothing there._

> **Does our bank have enough to pay for each multipop operation?**

This is the most important question to consider. If our bank account ever goes negative, we can't make any conclusions about the amortized cost per operation.

If our bank does, then we've established an upper bound on the _amortized cost per operation._

## Works Cited

| Title                      | Content Used                               | Author                                                       |
| -------------------------- | ------------------------------------------ | ------------------------------------------------------------ |
| Introduction to Algorithms | Definitions for introduction               | Cormen et. al.                                               |
| Pictures                   | Pictures labeled for non-commercial reuse. | Various. Labeled by Google.                                  |
| Class lecture & slideshow  | Structures, definition, and content        | [Dr. Zhongmei Yao](http://academic.udayton.edu/zhongmeiyao/) |
