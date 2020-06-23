# Lecture 10: Amortized Analysis

## Introduction

> In an **amortized analysis**, we average the time required to perform a sequence of data-structure operations over all the operations performed.
>
> * We can show that the average cost of an operation is small, if we average over a sequence of operations, even though a single operation within the sequence might be expensive.
> * Probability is not involved.
> * It guarantees the **average performance of east operation in the worst case.**
>
> _Source: Introduction to Algorithms; Cormen et. al._

## Heap Sort Example

### What are Heaps?

![](../../.gitbook/assets/image%20%2817%29.png)

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

## The Goal of Amortized Analysis

We want to show that although some individual operations may be expensive, on average, the cost-per-operation is lower than the cost of those expensive ones. 

On average, the cost per operation is lower than the cost of those expensive ones. **We want to measure the average cost of operation** instead of the worst case. 

{% hint style="info" %}
Below are 3 different approaches to figure out how to measure the average cost of operation: the aggregate method, the accounting method, and the potential method.
{% endhint %}

### Three Different Approaches

1. Aggregate Method
2. Accounting Method:

   > Assign costs to each operation so that it is easy to sum them up while still ensuring that result is accurate - Dr. Yao

3. Potential Method:

   > A more sophisticated version of the accounting method - Dr. Yao

## Aggregate Method: Augmented Stack

![](../../.gitbook/assets/image%20%2815%29.png)

### Multipop Method

{% hint style="info" %}
It's a stack, but you can pop multiple items from the stack at the same time.
{% endhint %}

```java
Multipop(S, k)
    while S is not empty and k > 0
        Pop(S)
        k = k-1
```

* We will repeat k times, and S contains the items on the stack.
* If k is 3, we can pop 3 items at once instead of just one.

| Operations | Description |
| :--- | :--- |
| push\(S, x\) |  |
| Pop\(S\) | Pops the top item off the stack. |
| Multipop\(S, k\) | Pop the top k elements, k ≤ size of S. |

{% hint style="info" %}
From Dr. Yao: When we use the notation \|S\|, that refers to the size of the stack. When we use ’S’, it means we’re referring to the size of the estack.
{% endhint %}

{% hint style="warning" %}
I don't know what the parameters mean for the push\(S,x\) mean.
{% endhint %}

* Implement this with either an array or linked list.
  * Time for each push is O\(1\)
  * Time for each pop is `O(1)`
  * Time for each multipop is $$O(min(|S|, k))$$ .

{% hint style="warning" %}
I don't understand what \|S\| is, or why it's in an absolute value bracket. She said "of 2 values..." but what two values? I don't see two values.
{% endhint %}

### The Aggregate Method

* Show that a sequence of `n` operations takes T\(n\) time.
* We can say that the amortized cost per operation ****is then T\(n\)/n
* Makes no distinction between operation types.

{% hint style="warning" %}
I don't understand this at all. Where'd we get T\(n\)/n from
{% endhint %}

#### Simple Argument

{% hint style="warning" %}
Argument of what?
{% endhint %}

> In a sequence of `n` operations, the stack never holds more than `n` elements. So the cost of a multipop is O\(n\).
>
> The worst-case of any sequence of n operations is O\(n^2\). Hence, the amortized cost per operation is: $$O(n^2/n) = O(n)$$ .
>
> But this is an over-estimate!

{% hint style="warning" %}
Why is it an overestimate? I thought the whole point of amortized analysis was so we don't have over-estimates.
{% endhint %}

### The Aggregate Method... Again?

> Key idea: total number of elements popped in the entire sequence of n operations is at most the total number of pushes done for both pop and multipop.
>
> The maximum number of pushes is n.
>
> So time for the entire sequence is O\(n\) + O\(n\)

* O\(n\) is for the pushes.
* O\(n\) is for both pops and multipops.

> And amortized cost per operation is  $$O(\frac{2n}{n}) = O(1)$$

{% hint style="warning" %}
How did she come to this conclusion? Where'd she get the 2n/n?
{% endhint %}

## Accounting Method

> A bank account allows us to save our excess money, and the money can be used later when needed.

* This bank account idea is similar to the accounting method.

> Each operation has an amortized cost \(i.e. budget\)
>
> * If amortized cost ≥ actual cost, we save the excess in the bank.
> * Else, we use savings to help the payment.

* Never let the account be negative.

### The Augmented Stack

Let's revisit this from the last section.

#### Assign these amortized costs \(budget\)

* Push is 2.
* Pop is 0.
* Multipop is 0.

{% hint style="info" %}
These were assigned arbitrarily.
{% endhint %}

{% hint style="warning" %}
Why did she assign them? She had some thinking and justified it in 17:50.
{% endhint %}

> Which operation "saves money to the bank" when performed?
>
> For push, the actual cost is 1. Store the extra 1 as a crtedit, associated with the pushed element.

Another question:

> Which operation "Needs money from the bank" when performed?
>
> * The actual cost for Pop 1 is 1. For multipop, the actual cost is min\(\|S\|, k\)

{% hint style="info" %}
There are other questions; see her slides.
{% endhint %}

### Conclusion

#### We can make a conclusion in 3 steps.

1. Assign these amortized costs \(budget\) like we did above.
2. I don't know what step 2 is. It's long.

![What does this mean?](../../.gitbook/assets/image%20%2814%29.png)

> \[The\] amortized cost per operation is O\(1\) since budget for any operation is O\(1\) given in step 1 and we show that the bank account is never negative.

{% hint style="warning" %}
 🤷🏻  How did she make this conclusion?
{% endhint %}





## Works Cited

| Title | Content Used | Author |
| :--- | :--- | :--- |
| Introduction to Algorithms | Definitions for introduction | Cormen et. al. |
| Pictures | Pictures labeled for non-commercial reuse. | Various. Labeled by Google. |
| Class lecture & slideshow | Structures, definition, and content | [Dr. Zhongmei Yao](http://academic.udayton.edu/zhongmeiyao/) |

