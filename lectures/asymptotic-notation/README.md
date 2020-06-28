# Asymptotic Notation

## Learning Goals

| Term | What is it? |
| :--- | :--- |
| Big-O Notation | Big-O notation represents the upper bound of the running time of an algorithm. Thus, it gives the worst case complexity of an algorithm. |
| [Little Oh](https://www.tutorialspoint.com/little-oh-notation-o#:~:text=The%20little%20o%20notation%20is,that%20map%20positive%20real%20numbers.) | Big O, but we don't drop constants. "Little o notation is used to describe an upper bound that cannot be tight. In other words, loose upper bound of f\(n\)." |
| Theta Notation | Theta notation encloses the function from above and below. Since it represents the upper and the lower bound of the running time of an algorithm, it is used for analyzing the average case complexity of an algorithm. |
| Omega Notation | Omega notation represents the lower bound of the running time of an algorithm. Thus, it provides best case complexity of an algorithm. |

> Definitions \(except little o\) are from [programiz](https://www.programiz.com/dsa/asymptotic-notations). See their super awesome [article](https://www.programiz.com/dsa/asymptotic-notations) for more! Little o definition is from [tutorials point.](https://www.tutorialspoint.com/little-oh-notation-o#:~:text=The%20little%20o%20notation%20is,that%20map%20positive%20real%20numbers.)

## Big-O Notation

> Big-O notation represents the upper bound of the running time of an algorithm. Thus, it gives the **worst case complexity** of an algorithm.

### 

![Note: x is the same as n in the below definitions.](../../.gitbook/assets/image%20%2838%29.png)

### Formal Definition

{% hint style="warning" %}
I don't understand what `C(g(n)` is. 
{% endhint %}

```text
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

![Source: Wikimedia Commons](../../.gitbook/assets/image%20%2837%29.png)

### [Applications](https://en.wikipedia.org/wiki/Big_O_notation#Orders_of_common_functions)

![](../../.gitbook/assets/image%20%2839%29.png)

## [Little Oh Notation \(o\)](https://www.tutorialspoint.com/little-oh-notation-o#:~:text=The%20little%20o%20notation%20is,that%20map%20positive%20real%20numbers.)

> Little o notation is used to describe an upper bound that cannot be tight. In other words, loose upper bound of f\(n\).

Mathematically, we can say `f(n) = o(g(n))` means $$\underset{n \to \infty }{lim} \frac{f(n)}{g(n)} = 0$$ 

### Example \(TutorialsPoint\)

Let's assume

$$
f(n) = n^2 \texttt{ and } g(n) = n^3
$$

Then, we can use the above limit definition to determine:

![](https://www.tutorialspoint.com/assets/questions/media/26170/formula1.jpg)

\_\_

## Works Cited

| Title | Content Used | Author |
| :--- | :--- | :--- |
| [Lecture 03](lecture-03-asymptotic-notations-part-2.md#little-o) | Little o notation. | Dr. Zhongmei Yao |
| [Asymptotic Notations](https://www.programiz.com/dsa/asymptotic-notations) | Definitions, Graphs | Programiz |
| [Big O Notation](https://en.wikipedia.org/wiki/Big_O_notation) | [Applications / Orders of Common Functions](https://en.wikipedia.org/wiki/Big_O_notation#Orders_of_common_functions) | [Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation#Orders_of_common_functions) |
| [Little Oh Notation \(o\)](https://www.tutorialspoint.com/little-oh-notation-o#:~:text=The%20little%20o%20notation%20is,that%20map%20positive%20real%20numbers.) | Little-o notation. | [Tutorials Point](https://www.tutorialspoint.com/little-oh-notation-o#:~:text=The%20little%20o%20notation%20is,that%20map%20positive%20real%20numbers.) |

