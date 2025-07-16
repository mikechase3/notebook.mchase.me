---
description: Finished for the day at 17:00
---

# Lecture 06: Matrix Multiplication & Fibonacci

## Dynamic Programming Fundamentals

{% hint style="info" %}
This heading is covered in Back to Back SWE. Not class.
{% endhint %}

### What is Dynamic Programming?

There are three fundamental ideas of [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming).

> 1. Sub problems explicitly overlap.
> 2. Sub-problems can be related together.
> 3. Solutions to sub-problems can be stored in cache using [memoization](https://en.wikipedia.org/wiki/Memoization).
>
> _Source: Back to Back SWE. Dynamic programming fundamentals._

Unlike divide & conquer algorithms, the problems did not explicitly overlap, and we couldn't cache any of the solutions for later usage. It was straight-up recursion.

## Matrix Multiplication

$$
\begin{bmatrix}3, 4 \\ 7,2 \\ 5,9 \end{bmatrix} \cdot \begin{bmatrix}3, 1, 5 \\ 6, 7, 9 \end{bmatrix} =\begin{bmatrix}33, 39, 43 \\33, 25, 49 \\69, 86, 88 \end{bmatrix}
$$

### Understanding The Problem

If you're completely new to this like I was, this [video](https://www.youtube.com/watch?v=2spTnAiQg4M) is super helfpul!

* [ ] Multiply the first row by the first column. Place the value in the _1st row, 1st column_ of the new matrix.
  * [ ] 3x3 = 9
  * [ ] 4x6 = 24
  * [ ] 24+9=**33** _(add them)_
* [ ] Now, mulitply _1st row \* 2nd column._ Place that value in the _1st row, 2nd column_ of the matrix.
  * [ ] 3x1 = 3
  * [ ] 4x9 = 36
  * [ ] 36+3=**39**
* [ ] Repeat until you fill the matrix.

### Different Approaches to Matrix Multiplication

{% tabs %}
{% tab title="Brute Force" %}
To perform `A x B`, the straightforward algorithm is `Θ(n^3)`.

* We have to multiply one row by one column. That takes `O(n)` time.
* Then we have to add up those numbers. `O(n)`
* Then we have to do that for all the other columns. `Θ(n)` time.

$$
T(n) = O(n^3)
$$
{% endtab %}

{% tab title="Divide & Conquer" %}
{% hint style="info" %}
Assume we're using a 4x4 matrix. _See her video at 4:40_
{% endhint %}

* We can cut the original matrix into 4 smaller sub-matrics.
* Each separate matrix in A, the size is halved. Then it has `n/2` rows and `n/2` columns.
* We'll have 8 smaller matrix multiplications and 4 additions.
  * Dividing takes `Θ(1)` time, using index calculations.
  * Conquering makes 8 recursive calls ⇒`8T(n/2)`
  * Combining takes time to add `n/2` x `n/2` matrices four times ⇒ Θ(n^2) time.

When this is all set and done, we find that the run time is:

$$
T(n) = 8T\left (\frac{n}{2} \right )+\Theta \left (n^2 \right)
$$

**Master Theorem**

![Source: Brilliant, Master Theorem](<../../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png>)

Roughly, this theorem says:

![Source: Dr. Zhongmei Yao's Slides](<../../../../.gitbook/assets/image (3) (2).png>)

Here, `a=8`, `b=2`, and `f(n) = n^2`. We'll compare `f(n) = n^2` `to n^{\log_{b}a}`. Let's solve for that now:

$$
n^{\log_{b}a} \rightarrow n^{\log_{2}8} \rightarrow n^3
$$

Now we'll compare to find out which case we want to use.

$$
[f(n)] \approx ? [\log_{b}(n)] \rightarrow n^2 < n^3 \rightarrow \texttt{Use Case A}
$$

**Conclusion**

Therefore, we can conclude the running time is:

$$
T(n) = Θ(n^3)
$$

Which, unfortunately, is the same running time as our brute force method.
{% endtab %}

{% tab title="Strassen" %}
**The Main Idea**

Recall from earlier, the running time of the divide & conquer approach:

$$
T(n) = 8T\left (\frac{n}{2} \right )+\Theta \left (n^2 \right)
$$

Strassen's main idea is to make the recursion tree less bushy by lowering `a`. Here, we can **perform only 7 recursive multiplicaitons** of `n/2` x `n/2` matrices, rather than 8.

$$
\begin{cases} \Theta(1) & \text{ if } n=1 \\ 7T(\frac{n}{2}) & \text{ if } n>1 \end{cases}
$$

Now, `a` is 7 and b is 2, so:

$$
n^{log_2(7)}\rightarrow n^{2.81}
$$

**Finding Big Theta**

We'll use the master theorem again to compare `f(n) = Θ(n^2)` to `n^{log_b(a)} = 2.81` and we'll clearly be using case a.

![Source: Dr. Yao's Notes](<../../../../.gitbook/assets/image (3) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png>)

Now, we're at `Θ(n^2.81)` time instead of `Θ(n^3)`, but hey, that's way better.

**Optional Further Reading**

* The best case by this method runs in `Θ(n^(2.376)` time.
* _Textbook:_ Introduction to Algorithms by Thomas Cormen et. al., 3rd Edition _(Chapter 15_).
{% endtab %}
{% endtabs %}

## Dynamic Programming

### Four Step Method

> 1. **Characterize the structure of an optimal solution**. _(What are the sub-problems?)_
> 2. **Recursively define the value of an optimal solution.** _(i.e. recurrence for Fibonacci(n): Fib(n) = Fib(n-1)+(n-2), which is a formula involving only smaller sub-problems._
> 3. **Compute the value of an optimal solution in a \_bottom-up**\_\*\* fashion\*\*. Store (memorize) the results of all sub-problems, which can then be later accessed to solve other sub-problems.
> 4. **Construct an optimal solution from computed information.**
>
> _Source: Dr. Yao's Slides, Dynamic Programming Part 1. (Paraphrased)_

_\*\*\*\*_

***

### Example: Fibonacci Numbers

* Below is sample code for the Fibonacci sequence.
* Notice how we store values we've already calculated in the array `f[]`.

```java
// Fibonacci Series using Dynamic Programming 
class fibonacci 
{ 
   static int fib(int n) 
    { 
    /* Declare an array to store Fibonacci numbers. */
    int f[] = new int[n+2]; // 1 extra to handle case, n = 0 
    int i; 
       
    /* 0th and 1st number of the series are 0 and 1*/
    f[0] = 0; 
    f[1] = 1; 
      
    for (i = 2; i <= n; i++) 
    { 
       /* Add the previous 2 numbers in the series 
         and store it */
        f[i] = f[i-1] + f[i-2]; 
    } 
       
    return f[n]; 
    } 
       
    public static void main (String args[]) 
    { 
        int n = 9; 
        System.out.println(fib(n)); 
    } 
} 
/* This code is contributed by Rajat Mishra */
// Source: Geeks For Geeks.
```

## Works Cited

1. Dr. Zhongmei Yao's [CPS 450 course](http://academic.udayton.edu/zhongmeiyao/450592.html). _(Four-step method)._
2. [Back to Back SWE](https://backtobackswe.com/platform/content/quicksort/code) _(Quick sort video)_
3. _**Textbook:**_ Introduction to Algorithms by Thomas Cormen et. al., 3rd Edition _**(Chapter 4, 15**_).
4. [Brilliant: Master Theorem](https://brilliant.org/wiki/master-theorem/?subtopic=algorithms\&chapter=complexity-runtime-analysis)
5. Geeks for Geeks: Fibonacci Sequence

## Works Cited

| Title         | Content Used                   | Author           |
| ------------- | ------------------------------ | ---------------- |
| Class Lecture | What we're learning; structure | Dr. Zhongmei Yao |
