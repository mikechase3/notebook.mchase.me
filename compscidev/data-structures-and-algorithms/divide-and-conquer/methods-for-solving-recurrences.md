# Methods for Solving Recurrences

There are 3 ways.



## Substitution and Mathematical Induction

Not on the test.

## Recursion Tree

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>



## Master Theorem

* Every recursive call has to have the form `T(n)=a*T(n/b)+f(n)` & `T(1)=c` where `a>=1, b>=2, c>0`

<figure><img src="../../../.gitbook/assets/image (2) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>



### Example: Karatsuba Multiplication

{% hint style="info" %}
See OneNote for some class-provided materials that are copyrighted & not sharable.
{% endhint %}

* Here, we have a function that is called three times
* The input is reduced by 3/4ths.
* Said again/differently: we'll use the recursion tree calling it three times each with 1/4th of the input size.

### Pitfalls

<figure><img src="../../../.gitbook/assets/image (3) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

### Polylogarithmic Exception

* Recall we can't use the master theorem if f(n) is not a polynomial.
* If you have a log factor in your **forcing function** you can just incorporate that into your solution and use a slightly different formula instead.

<figure><img src="../../../.gitbook/assets/image (4) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>
