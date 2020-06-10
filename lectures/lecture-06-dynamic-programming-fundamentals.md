# Lecture 06: Dynamic Programming Fundamentals

## Dynamic Programming Fundamentals

{% hint style="info" %}
This heading is covered in Back to Back SWE. Not class.
{% endhint %}

### What is Dynamic Programming?

There are three fundamental ideas of [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming).

1. Sub problems explicitly overlap.
2. Sub-problems can be related together.
3. Solutions to sub-problems can be stored in cache using [memoization](https://en.wikipedia.org/wiki/Memoization).

Unlike divide & conquer algorithms, the problems did not explicitly overlap, and we couldn't cache any of the solutions for later usage. It was straight-up recursion.

### Scheduling Example

_Source: Back to Back SWE: Dynamic Programming Fundamentals_

{% hint style="info" %}
This example is incomplete and will not make sense to anyone besides me. Venture onward, my friend.
{% endhint %}

Every interval has a start and a finished, notated by:

$$
(s_i, f_i) ⇒ f_i ≤ s_{i+1}
$$

With this, we can make sure that every finish interval is going to be before the next block's starting interval.

#### Weights

Now, if we introduce weights, the goal is to maximize the weight. Now, our greedy algorithms fail here and we have to use 

{% hint style="warning" %}
I did not understand this problem and need to re-watch it.
{% endhint %}

#### Base Case

* It's an input to our algorithm that's often known in O\(1\) time.
* It provides the knowledge we need to solve recursive cases.

## Matrix Multiplication

$$
\begin{bmatrix}3, 4
\\ 7,2
\\ 5,9
\end{bmatrix}

\cdot 

\begin{bmatrix}3, 1, 5
\\ 6, 7, 9
\end{bmatrix}

=\begin{bmatrix}33, 39, 43
\\33, 25, 49
\\69, 86, 88
\end{bmatrix}
$$

### How To Multiply A Matrix

If you're completely new to this like I was, this [video](https://www.youtube.com/watch?v=2spTnAiQg4M) is super helfpul!

* [ ] Multiply the first row by the first column. Place the value in the _1st row, 1st column_ of the new matrix.
  * [ ] 3x3 = 9
  * [ ] 4x6 = 24
  * [ ] 24+9=**33** _\(add them\)_
* [ ] Now, mulitply _1st row \* 2nd column._ Place that value in the _1st row, 2nd column_ of the matrix.
  * [ ] 3x1 = 3
  * [ ] 4x9 = 36
  * [ ] 36+3=**39**
* [ ] Repeat until you fill the matrix.



### Running Time

{% tabs %}
{% tab title="Brute Force" %}
To perform `A x B`, the straightforward algorithm is `Θ(n^3)`.

* We have to multiply one row by one column. That takes `O(n)` time.
* Then we have to add up those numbers. `O(n)`
* Then we have to do that for all the other columns. `Θ(n)` time.
{% endtab %}

{% tab title="Divide & Conquer Improvements" %}
{% hint style="info" %}
Assume we're using a 4x4 matrix. _See her video at 4:40_
{% endhint %}

* We can cut the original matrix into 4 smaller sub-matrics.
* Each separate matrix in A, the size is halved. Then it has `n/2` rows and `n/2` columns.
* We'll have 8 smaller matrix multiplications and 4 additions.
  * Dividing takes `Θ(1)` time, using index calculations.
  * Conquering makes 8 recursive calls ⇒`8T(n/2)`
  * Combining takes time to add `n/2` x `n/2` matrices four times ⇒ Θ\(n^2\) time.

$$
T(n) = 8T\left (\frac{n}{2}  \right )+Θn^2
$$
{% endtab %}
{% endtabs %}



## Works Cited

1. Dr. Zhongmei Yao's [CPS 450 course](http://academic.udayton.edu/zhongmeiyao/450592.html). _\(\)._
2. [Back to Back SWE](https://backtobackswe.com/platform/content/quicksort/code) \(Quicksort video\)
3. _**Textbook:**_ Introduction to Algorithms by Thomas Cormen et. al., 3rd Edition _**\(Chapter 4, 15**_\).

