# Amoritized Analysis

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

![](../.gitbook/assets/image%20%2814%29.png)

> A heap is a binary tree storing keys at its internal nodes and satisfying the following properties:

Min-Heap Properties

* **Heap Order:** Every child node must be larger than the parent node. 
* **Complete Binary Tree**: You have to fill an entire level before moving onto the next level.

### What is Heap Sort?

Heap-sort lets you put things in order by using a heap.

1. Insert a key into the heap.
2. Let the heap sort itself so that the number/letter you just added is in order & follows the [heap properties.](amoritized-analysis.md#what-are-heaps)
3. Repeat steps 1 and 2 until all the keys are added to the heap.
4. Finally, remove every object from the root of the heap. That way, it will be done in order!



## Works Cited

| Title | Content Used | Author |
| :--- | :--- | :--- |
| Introduction to Algorithms | Definitions | Cormen et. al. |
| Non-commercial reuse labeled pictures | Pictures | Various. Labeled by Google. |

