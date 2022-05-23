# Lecture 03: Asymptotic Notations Part 2

## Little o

* In big O, we ignore all constants.
* In little o, we care about the constant of the largest term. The limit has to go to zero.
* `n^2 ⇒ (o(n^2))'` because the limit _of f(x)/g(x)_ is 1.
* `n^1.999 ⇒ (o(n^2))'` because the limit of _f(x)/g(x)_ is 1.

{% hint style="info" %}
Little o is like Big O notation, but we care about the constant of the largest term.
{% endhint %}

## Supremum, The Tightest Upper Bound

* **Supremum** is the _tightest upper bound_
* Example: Given the set sup{1, 2, 3}
  * _sup_ is the function we’re running on the set.
  * _3_ is the tightest upper-bound.
*   Example 2: Given the set sup{x: x^2 \\< 2}

    * _sup_ now applies to a function
    * _sqrt(2)_ is the tightest lower-bound.

    **Infimum** is the tightest lower-bound.

****

## **Infimum, The Tightest Lower Bound**

* **c** is the infimum of subset _S_ of real numbers.
  * We write c = inf(S)
* Example: In the set inf{1, 2, 3}
  * The tightest lower bound is 1.
* Inferior (INF) is the limit the function converges to on the bottom.
  * Infinity means the **tightest** lower-bound.
* Sometimes, the limit of a sequence may not exist _ie. f(n) = 1 + (-1)^n_
*   There are many upper bounds on f(n)

    **Sufficient Condition**
* Lemma 1: If the limit exists, then we can draw a conclusion about the upper bound _O(function)_, the lower bound _omega(function)_
* Lemma 2: Uses _sup_ which I don’t know what that means.&#x20;



## Bonus: who are my classmates?

* Yicheng Geng: _Graduate student in electrical engineering_
* Jenia Kulikova: _Computer information systems, junior, polish_
* Chenchen Li: _China_
* Yilang Li: _Studying for his masters in computer science_
* Zackary: _Works for the research institute; getting his masters._
* Karan: _Karan Panchai: Graduate student in UD. Fall 2019, majoring in computer science._
* Divya Shetty: \*Majoring in computer science. Came in 2019.
* Fen Yang: _From China, living in Dayton. Graduate student in electrical engineering._
* Kuangyi Zhang: _ECE, international student living in Dayton_
* Karan Panchai: Smart guy who was able to implement the Kth Largest Array.

## Works Cited

| Title         | Content Used                   | Author           |
| ------------- | ------------------------------ | ---------------- |
| Class Lecture | What we're learning; structure | Dr. Zhongmei Yao |

