# Lecture 03 Asymptotic Notations Part 2

## Little o
- In big O, we ignore all constants.
- In little o, we care about the constant of the largest term. The limit has to go to zero.
- `n^2 ⇒ (o(n^2))'` because the limit *of f(x)/g(x)* is 1.
- `n^1.999 ⇒ (o(n^2))'` because the limit of *f(x)/g(x)* is 1.

## Supremum, The Tightest Upper Bound
- **Supremum** is the *tightest upper bound*
- Example: Given the set sup{1, 2, 3}
	- *sup* is the function we’re running on the set.
	- *3* is the tightest upper-bound.
- Example 2: Given the set sup{x: x^2 \< 2}
	- *sup* now applies to a function
	- *sqrt(2)* is the tightest lower-bound.
## Infimum, The Tightest Lower Bound
- **Infimum** is the tightest lower-bound.
- **c** is the infimum of subset *S* of real numbers.
	- We write c = inf(S)
- Example: In the set inf{1, 2, 3}
	- The tightest lower bound is 1.


- Inferior (INF) is the limit the function converges to on the bottom.
	- Infinity means the **tightest** lower-bound.
- Sometimes, the limit of a sequence may not exist *ie. f(n) = 1 + (-1)^n*
- There are many upper bounds on f(n)
## Sufficient Condition
- Lemma 1: If the limit exists, then we can draw a conclusion about the upper bound *O(function)*, the lower bound *omega(function)*
- Lemma 2: Uses *sup* which I don’t know what that means. <!-- COMMENT -->

## Quiz Questions

## Who’s In The Class
- Yicheng Geng: *Graduate student in electrical engineering*
- Jenia Kulikova: *Computer information systems, junior, polish*
- Chenchen Li: *China*
- Yilang Li: *Studying for his masters in computer science*
- Zackary: *Works for the research institute; getting his masters.*
- Karan: *Karan Panchai: Graduate student in UD. Fall 2019, majoring in computer science.*
- Divya Shetty: \*Majoring in computer science. Came in 2019.
- Fen Yang: *From China, living in Dayton. Graduate student in electrical engineering.*
- Kuangyi Zhang: *ECE, international student living in Dayton*