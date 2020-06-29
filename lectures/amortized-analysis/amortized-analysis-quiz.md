# Amortized Analysis Quiz

## K-Bit Counter

> Suppose we perform a sequence of n incremental operations on a K-bit counter given the counter's initial value is 0. What is the amortized cost after the sequence of n incremental operations is finished? Explain.
>
> You may use any method that we discussed in class.

The amortized cost, which we discussed in class, would be `O(1)`. The worst case cost is `O(n)` because you have to change every bit; however, since there is only an incremental operator, the amortized cost is `O(1)`.

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

