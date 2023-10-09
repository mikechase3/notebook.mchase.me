# Asymptotic Notation

## Learning Goals

| Term                                                             | What is it?                                                                                                                                                                                                             |
| ---------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Big-O Notation                                                   | Big-O notation represents the upper bound of the running time of an algorithm. Thus, it gives the worst case complexity of an algorithm.                                                                                |
| [Little Oh](https://www.tutorialspoint.com/little-oh-notation-o) | Big O, but we don't drop constants. "Little o notation is used to describe an upper bound that cannot be tight. In other words, loose upper bound of f(n)."                                                             |
| Theta Notation $$\Theta$$                                        | Theta notation encloses the function from above and below. Since it represents the upper and the lower bound of the running time of an algorithm, it is used for analyzing the average case complexity of an algorithm. |
| Omega Notation $$\Omega$$                                        | Omega notation represents the lower bound of the running time of an algorithm. Thus, it provides best case complexity of an algorithm.                                                                                  |

> Definitions (except little o) are from [programiz](https://www.programiz.com/dsa/asymptotic-notations). See their super awesome [article](https://www.programiz.com/dsa/asymptotic-notations) for more! Little o definition is from [tutorials point.](https://www.tutorialspoint.com/little-oh-notation-o)

{% hint style="warning" %}
How do I analyze the running time of algorithms so I can develop equations that look like these?
{% endhint %}

## Recurrence Relations

If this makes no sense to you, you might want to go back and check out [recurrence relations](https://users.cs.duke.edu/\~ola/ap/recurrence.html).

## Big-O Notation

> Big-O notation represents the upper bound of the running time of an algorithm. Thus, it gives the **worst case complexity** of an algorithm.

###

![Note: x is the same as n in the below definitions.](<../../../.gitbook/assets/image (35).png>)

### Formal Definition

{% hint style="warning" %}
I don't understand what `C(g(n)` is.
{% endhint %}

```
O(g(n)) = { f(n): there exist positive constants c and n0
            such that 0 ≤ f(n) ≤ cg(n) for all n ≥ n0 }
```

> The above expression can be described as a function `f(n)` belongs to the set `O(g(n))` if there exists a positive constant `c` such that it lies between `0` and `cg(n)`, for sufficiently large `n`.
>
> For any value of `n`, the running time of an algorithm does not cross time provided by `O(g(n))`.
>
> Since it gives the worst case running time of an algorithm, it is widely used to analyze an algorithm as we are always interested in the worst case scenario.
>
> _Source: Programiz._

### Common Orders

![Source: Wikimedia Commons](<../../../.gitbook/assets/image (36).png>)

### [Applications](https://en.wikipedia.org/wiki/Big\_O\_notation#Orders\_of\_common\_functions)

![](<../../../.gitbook/assets/image (33).png>)

## [Little Oh Notation (o)](https://www.tutorialspoint.com/little-oh-notation-o)

> Little o notation is used to describe an upper bound that cannot be tight. In other words, loose upper bound of f(n).

Mathematically, we can say `f(n) = o(g(n))` means $$\underset{n \to \infty }{lim} \frac{f(n)}{g(n)} = 0$$

### Example (TutorialsPoint)

Let's assume

$$
f(n) = n^2 \texttt{ and } g(n) = n^3
$$

Then, we can use the above limit definition to determine:

![](https://www.tutorialspoint.com/assets/questions/media/26170/formula1.jpg)

## Theta Notation $$(\Theta)$$

* Theta is the **most accurate and tightest bound**.
* We'll use
* It encloses a function above and below.
* We use it to analyze average case complexity.

> In general, we always want to give a theta bound if possible because it is the most accurate and tightest bound. If we can’t give a theta bound, the next best thing is the tightest O bound possible.

### [Examples](https://www.freecodecamp.org/news/big-theta-and-asymptotic-notation-explained/)

> * “The delivery will be there within your lifetime.” (big-O, upper-bound)
> * “I can pay you at least one dollar.” (big-omega, lower bound)
> * “The high today will be 25ºC and the low will be 19ºC.” (big-theta, narrow)
> * “It’s a kilometer walk to the beach.” (big-theta, exact)

### It's Just Math!

So the notation is more of a mathematical concept than a computer science one. For example, I can describe my own graph using these terms. Here, I graphed the following 3 equations.

$$
y=\sin\left(x\right)+1.1^{x} \text{ | }y=1.1^{x}+1 \text{ | } y=1.1^{x}-1
$$

When I graphed them in Desmos, I got these:

![The first, second, and third equation is red, blue, and green respectively.](../../../.gitbook/assets/desmos-graph.png)

The bounds also don't have to be touching exactly. Here's an [example](https://www.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/big-big-theta-notation) from [Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/big-big-theta-notation):

![](<../../../.gitbook/assets/image (39) (1) (1).png>)

Note here that we don't care about the small cases, but only when `n` gets really large, or after the dashed line in this case.

## Big Omega Notation $$(\Omega)$$

* This describes the lower bound, or the **best case** running time.

> We say that the running time is “big-Ω of f(n).” We use big-Ω notation for **asymptotic lower bounds**, since it bounds the growth of the running time from below for large enough input sizes.

> **Difference between Big O and Big Ω**
>
> The difference between Big O notation and Big Ω notation is that Big O is used to describe the worst case running time for an algorithm. But, Big Ω notation, on the other hand, is used to describe the best case running time for a given algorithm.

## Works Cited

| Title                                                                                                                                | Content Used                                                                                                              | Author                                                                                                                         |
| ------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| [Asymptotic Notations](https://www.programiz.com/dsa/asymptotic-notations)                                                           | Definitions, Graphs                                                                                                       | Programiz                                                                                                                      |
| [Big O Notation](https://en.wikipedia.org/wiki/Big\_O\_notation)                                                                     | [Applications / Orders of Common Functions](https://en.wikipedia.org/wiki/Big\_O\_notation#Orders\_of\_common\_functions) | [Wikipedia](https://en.wikipedia.org/wiki/Big\_O\_notation#Orders\_of\_common\_functions)                                      |
| [Little Oh Notation (o)](https://www.tutorialspoint.com/little-oh-notation-o)                                                        | Little-o notation.                                                                                                        | [Tutorials Point](https://www.tutorialspoint.com/little-oh-notation-o)                                                         |
| [Big Theta and Asymptotic Notations Explained](https://www.freecodecamp.org/news/big-theta-and-asymptotic-notation-explained/)       | Pizza guy examples. Theta definition.                                                                                     | [FreeCodeCamp](https://www.freecodecamp.org/news/big-theta-and-asymptotic-notation-explained/)                                 |
| [Big Theta Notation](https://www.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/big-big-theta-notation) | Graph of running time with dash in it.                                                                                    | [Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/big-big-theta-notation) |
| [What is Big Omega Notation?](https://www.freecodecamp.org/news/big-omega-notation/)                                                 | Definitions                                                                                                               | Free Code Camp                                                                                                                 |
