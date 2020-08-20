---
description: >-
  The first half uses the k-bit counter as a review of aggregate & accounting
  methods. Then, we learn about potential.
---

# Lecture 11: More Amortized Analysis

## Review

> \[An\] amortized analysis allows one to estimate the cost `T(n)` of a sequence of `n` operations on a data structure.

{% hint style="warning" %}
Dr. Yao's slides say _"Make no distinction between operation types_." What does that mean? This contradicts what we did in the accounting method where we assign different values different costs.

Furthermore, how do we know what operations we're doing? What if we just had an operation that just doubled the array size and copied all the elements? Wouldn't we run out money in the accounting problem? if we had 3 items and called that function infinite times, then `T(n)` is infinite?
{% endhint %}

### The Three Methods

| Method | What it is | When to use it |
| :--- | :--- | :--- |
| Aggregate | A quick average. |  |
| Accounting | A bank account. |  |
| Potential | ? |  |

{% hint style="warning" %}
When should we use each one?
{% endhint %}

## The K-Bit Counter Accounting Example

![K-bit counter, at the low level.](../../.gitbook/assets/image%20%2821%29.png)

### Understanding The [Problem](https://www.youtube.com/watch?v=2kUTu0sI_Rs)

#### Mathematical Notation

| Symbol | Meaning |
| :--- | :--- |
| `A` | The array, containing integers 0 or 1. |
| `i` | Which element we're referring to? |
| `k` | "The most significant bit" OR len\(A\)? OR the number of bits being flipped? |
| `n` | The number of increment operations performed. |

{% hint style="warning" %}
What does this mathematical notation mean? What is A\[i\]? I thought "i" is the number we're trying to represent, but then we have "A\[i\]" which refers to an index, so we can't have both.

Also, if `i` is the index, then what is `k`? We use `k-1` sometimes. 
{% endhint %}

> * K-bit counter
>   * A\[0\] is the least significant bit.
>   * A\[k-1\] is the most significant bit.
> * The value of the counter is: $$\sum_{i=0}^{k-1}A[i]2^i$$



#### Simple Example

```python
myList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0] #9 bits; implies 0.

def increment_counter(list: Int) -> None:
    if list = [0, 0, 0, 0, 0, 0, 0, 0, 0]:
        list = [0, 0, 0, 0, 0, 0, 0, 0, 1]
    elif list = [0, 0, 0, 0, 0, 0, 0, 0, 1]:
        list = [0, 0, 0, 0, 0, 0, 0, 1, 0] #Change it twice.
    elif list = [0, 0, 0, 0, 0, 0, 0, 0, 1]:
        list = [0, 0, 0, 0, 0, 0, 0, 1, 1] #Change once.
    elif list = [0, 0, 0, 0, 0, 0, 0, 1, 1]:
        list = [0, 0, 0, 0, 0, 0, 1, 0, 0] # Change 3 times.
    elif list = [0, 0, 0, 0, 0, 0, 1, 0, 0]:
        list = [0, 0, 0, 0, 0, 0, 1, 0, 1] #Change 1 time.
        
    ... And So on ...
    
    elif list = [1, 1, 1, 1, 1, 1, 1, 1, 1]:
        list = [0, 0, 0, 0, 0, 0, 0, 0, 0] #Worst case is k flips.
```

### More Practical Implementation

```python
def increment_Counter(A, k):
    i = 0
    while i < k and A[i] is 1: #I is like the palcehodler. 
        A[i] = 0. # Reset the bits.
        i = i + 1
    if i < k #set i-th bit.
        A[i] = 1
```

K is the number of bits that we have. And we want to count things and manage each digit.

```text
Example where k = 6. (There are 6 bits).
======

000000
000001 //Costs 1 flip from above.
000010 //Costs 2 flips
000011 //Costs 1 flip
000100 //Costs 3 flips
000101 //Costs 1 flip
000110 //Costs 2 flips.
...
111111
000000 //Costs k flips
```

* We can make a _predicted cost_: after `n` operations, we will have done $$2 \cdot n$$ flips.
  * This sets an upper bound that's surprising accurate 👇 

![Source: &quot;The k-bit counter&quot;](../../.gitbook/assets/image%20%2819%29.png)

Notice how our predicted cost never exceeds the actual cost. This is good!

![](../../.gitbook/assets/image%20%2820%29.png)

1. The worst case cost of a single _increment_ operation is $$k \in O(k)$$ .
   1. The worst case is that we flip all the bits.
   2. But probably... we don't flip all the base. So it's _in_ `O(k)`
2. The total cost of `n` _increment_ operations \(starting from all 0s\) is $$\leq 2\cdot n \in O(n)$$ .
3. So, on a single _increment_ operation, the _**average cost, or amortized**_ cost of an increment is `2`, and $$2 \in O(1)$$ 

{% hint style="info" %}
If we used the worst-case cost, we would have dramatically over-estimated the actual cost. By using an amortized analysis, we got a much tighter bound.
{% endhint %}

### Aggregate Analysis for the K-Bit Counter

So obviously, by this point, we know two important things. And as a result of these two facts, we know that using amortized analyses is useful.

1. The worst case is `O(k)` because at some point, every single bit gets flipped. _This is when the array is when our_ `list = [1, 1, 1, 1, 1, 1, 1, 1, 1]`and every bit needs to get flipped.
2. Our average case is not going to be our worst case. Clearly, not every bit is getting flipped all the time.

 

![Notice A\[0\] \(At the right\) is flipped every time. A\[1\] \(2nd from right\) is flipped n/2 times, and so on.](../../.gitbook/assets/image%20%2835%29.png)

#### Using Geometric Series

* The pattern we're noticing, `n`, `n/2`, `n/4`... is a [geometric series](https://media.pearsoncmg.com/cmg/pmmg_mml_shared/mathstats_html_ebooks/ThomasCalcET14e/page_592.html) because geometric series have the form:

![Source: Thomas Calculus](../../.gitbook/assets/image%20%2830%29.png)

$$
n + n/2 + n/4 + ... ⇒  \sum _{n=1}^{\infty } 2^{-n}=1
$$

If we graph this, it'll look exactly like this:

![](../../.gitbook/assets/wolframalpha-1_2___1_4___1_8___1_16____________2020_06_27_21_32.jpeg)

So clearly, this is a geometric series, and the series approaches 1:

$$
\sum _{n=1}^{\infty } 2^{-n}=1\
$$

#### Final Conclusions

1. The total cost of the sequence is `T(n) = O(n)`
2. The amortized cost per operation is `O(1)`.

### Accounting Method

* Recall, for the accounting method, we design an amortized cost _\(which is our budget\)_ for increment operations. 
* Here, we declared **our budget is $2**.
* And below, we **prove we have enough budget to cover `n` operations**. 
  * For every bit flip from 0 to 1, we use $1 for the flip.
  * We associate the extra $1 with bit 1, which will be used when we flip this bit from 1 back to 0.

![](../../.gitbook/assets/image%20%2832%29.png)

#### Conclusions

Clearly, we have enough budget to cover all the bit flips. This means the balance is never negative. Therefore, we can **conclude** that **since the balance is never negative and our amortized cost for increment operation is $2 which is O\(1\), we can conclude our amortized cost per operation is `O(1)`. and the cost of `n` operations is** $$O(1) * n \in O(n)$$ .

## The Potential Method

The potential method is similar to the accounting method, but it's a little bit more formally defined. We will use some potential phi function. Then, we'll map the data structure's current status to a real number. 

#### Formal Definition 

The formal definition from [Wikipedia](https://en.wikipedia.org/wiki/Potential_method):

> Let o be any individual operation within a sequence of operations on some data structure, with $$S_{\text{before}}$$ denoting the state of the data structure prior to operation _o_ and $$S_{\text{after}}$$ denoting its state after operation _o_ has completed. Once Φ has been chosen, the amortized time for operation _o_ is defined to be

$$
{\displaystyle T_{\mathrm {amortized} }(o)=T_{\mathrm {actual} }(o)+C\cdot (\Phi (S_{\mathrm {after} })-\Phi (S_{\mathrm {before} }))}
$$

> Where C is a non-negative constant of proportionality \(in units of time\) that must remain fixed throughout the analysis. That is, the amortized time is defined to be the actual time taken by the operation plus C times the difference in potential caused by the operation.
>
> When studying [asymptotic computational complexity](https://en.wikipedia.org/wiki/Asymptotic_computational_complexity) using [big O notation](https://en.wikipedia.org/wiki/Big_O_notation), constant factors are irrelevant and so the constant C is usually omitted.

| Symbol | Meaning |
| :--- | :--- |
| `C` | A non-negative constant of proportionality \(in units of time\) that must remain fixed throughout the analysis. _**Is usually omitted.**_ |
| `Φ` | A function that maps states of the data structure to non-negative numbers |
| `S` | The state of a data strucutre |
| `Φ(S)` | represents work that has been accounted for \("paid for"\) in the amortized analysis but not yet performed. Thus, Φ\(S\) may be thought of as calculating the amount of [potential energy](https://en.wikipedia.org/wiki/Potential_energy) stored in that state [\[1\]](https://en.wikipedia.org/wiki/Potential_method#cite_note-gt-ad-1)[\[2\]](https://en.wikipedia.org/wiki/Potential_method#cite_note-clrs-2). |
| `0` | The potential value prior to the operation of initializing a data structure. |

#### Classroom Definition

$$
m_i = c_i + \Phi(D_i)-\Phi(D_{i-1})
$$

| Symbol | Meaning |
| :--- | :--- |
| $$m_i$$  | The amortized cost of the $$i^{th}$$ operation. |
| $$c_i$$  | The actual cost of the $$i^{th}$$ operation. |
| $$D_0$$  | The initial state of the data structure |
| $$D_i$$  | The state of the data structure after the $$i^{th}$$ operation. |
| $$\Phi$$  | A function that maps any _state_ of the data structures to a real number, $$\Phi(D_0) = 0$$  |

{% hint style="warning" %}
What is the _state_ of the data structure? Like, what does that mean?
{% endhint %}

{% hint style="warning" %}
What does $$\Phi(D_0) = 0$$ mean? A function that takes a data structure? Is that just an example that says when you put initial state of any data structure in it, it just returns zero?
{% endhint %}

### Augmented Stack Example

If the $$i^{th}$$ operation is a push and stack has `s` elements, this implies that:

$$
m_i = c_i + \Phi(D_i) - \Phi(D_{i-1}) ⇒ 1 + (s+1) -s ⇒2
$$

If the $$i^{th}$$ operation is a pop and stack has `s` elements, this implies that:

$$
m_i = c_i + \Phi(D_i) - \Phi(D_{i-1}) ⇒ 1 + (s-1) -s ⇒0
$$

If the $$i^{th}$$ operation is a Multipop and stack has `s` elements, this implies that:

$$
\text{Let } x = min(s,k), m_i = c_i + \Phi(D_i)-\Phi(D_{i-1}) = x+(s-x) -s = 0
$$

{% hint style="info" %}
Notice the `s+1` and `s-1` respectively.
{% endhint %}

{% hint style="warning" %}
I don't understand what these equations mean. Is this adding 2 elements and removing 2 elements? Is the `2` the budget we've decided to assign? But this isn't the accounting method.
{% endhint %}

{% hint style="warning" %}
Regarding the first two equations. In Dr. Yao's, she says equals instead of implications. However, **the first half**, before the implication is the exact same. Therefore, D\_i, or c\_i must be different. **What is different?**
{% endhint %}

#### Conclusions

* All operations have `O(1)` amortized cost.
* Therefore, the cost of the entire operation will be `O(n)`.

## Summary

| Method | What Is It? | How Do We Use It? |
| :--- | :--- | :--- |
| Aggregate | Average | Analyze the entire sequence and then calculate the amortized cost  |
| Accounting | ? | Assign an amortized cost per operation, and then check that the balance is never negative. _Tip: We usually link each saving \# to a specific object in the data structure \(i.e. item in a stack or bit in a binary counter\), which is called the credit stored in an object._ |
| Potential | Equation | ¯\\_\(ツ\)\_/¯ |

## Works Cited

| Title | Content Used | Author |
| :--- | :--- | :--- |
| Introduction to Algorithms | Definitions for introduction | Cormen et. al. |
| Wikimedia Commons | K-bit counter photo. | Various. Noncommercial reuse. |
| Class lecture & slideshow | Structures, definition, and content | [Dr. Zhongmei Yao](http://academic.udayton.edu/zhongmeiyao/) |
| [The K-Bit Counter](https://www.youtube.com/watch?v=2kUTu0sI_Rs) | K-bit example, graphs. | simrob \(Youtube\) |
| [Amortized Analysis \(of the k-bit counter\)](https://www.youtube.com/watch?v=U5XKyIVy2Vc) | None, but noteworthy. | simrob \(Youtube\) |
| Thomas Calculus | Geometric Series | Thomas. Pearson e-Text. Free |
| [Wikipedia: Potential Method](https://en.wikipedia.org/wiki/Potential_method) | Equations | Wikipedia Authors |



