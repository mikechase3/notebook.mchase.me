# Chatper 2: Probability

## Schools of Probability:

* Frequentist
* [Bayesian](https://en.wikipedia.org/wiki/Bayesian\_probability)

## Event Basics

* **Random experiment**: a process that generates results that cannot be predicted in advance.
* **Sample space:** the set of all possible outcomes, denoted by `S`.&#x20;
  * Example: the sample space for rolling 1 6-sided die is: `S={1, 2, 3, 4, 5, 6}`
* **Events:** an outcome, or any subset of a sample space.
  * Example, the event "roll an odd number" yields the sample space `S={1, 2, 3}`.
  * **Union**: `A U B` -> the outcome is in A or B.
  * **Intersection**: $$A \cap B$$ -> both.
  * **Compliment**: denoted $$A^C$$ -> Anything "not" in A.
* **Mutually Exclusive** or **Disjoint Events**: two sets are said to be "disjoint" if everything in `event A` does not exist in `event B`.&#x20;

## Probability

* We'll denote the "probability" that event A happens as `P(A)`.&#x20;
  * In a frequentist paradigm, this is the proportion of times the event A would happen if done over and over again.

### Axioms

* Let `S` be the sample space. Then `P(S)` is 1.
* If A and B are mutually exclusive, then $$P \cup B$$ = $$P(A) + P(B)$$.&#x20;

### Derived Rules

* **Compliment rule**: $$P(A^C)=1-P(A)$$
* **Empty** set: $$P( \empty) = 0$$
* Addition:&#x20;
  * P(A U B) = P(A) + P(A) only when A and B are mutually exclusive .
  * P(A U B) = P(A) + P(B) – P(A ∩ B) is always true.

### Example: Student Majors

> Suppose the probability that a randomly chosen UD student is math major is .10, the probability a randomly chosen student is a computer science major is .25, and the probability that randomly chosen student is both a math major and a computer science major is .05.&#x20;
>
> What is the probability that a randomly chosen student is either a math major or a computer science major?

This is $$P(M \cup C) = P(M)+P(C)-P(M \cap C) = 0.10 + 0.25 -0.05 = 0.3$$

> What is the probability that a randomly chosen is neither a math major nor a computer science major?

{% hint style="info" %}
TODO
{% endhint %}

> Suppose the probability a randomly chosen student is an econ major is .2. Is is possible that the probability a randomly chosen student is both a math major and an econ major is .12? Explain.

This isn't possible. We're told 10% of the student body is (at most) a math major, so you can't have 12% be a double major in economics and math because it exceeds the percentage of math majors.&#x20;

## Counting

{% hint style="info" %}
I don't understand what I'm supposed to know.
{% endhint %}

* Suppose there are `k` operations to be performed such that there are $$n_i$$ ways to perform the sequence. We'd say:
  * There are `n` ways to perform the first
  * There are `k` ways...

### Example: Buying a Car

Suppose a certain car can be bought:

* In red/blue/green
* With auto or manual.
* With or without a sunroof.

> How many different cars could I buy?

There are `3*2*2` arrangements or 12 possible versions of this car.

## Permutations & Combinations

### Permutations & Soccer Picks

A **permutation** is an ordering of a collection of objects. For example, in the collection `{A, B, C}`, the number of permutations is `n!`.

#### Generic example.&#x20;

Suppose there are `n` marbles in the bag.

* There are `n` choices for the first marble.
* There are `n-1` choices for the second.
* There are `n-2` choice for the third.
* There is `1` choice for the `n`th marble.

So - you get $$n(n-1)(n-2) = 1$$

> If a soccer game remains tied after extra time, it may go to penalties. Each team selects 5 players to attempt penalty kicks in order.&#x20;
>
> Given the team has already decided which 5 players will takes the penalty kicks, how many possible orders can they go in?

5! or 120.

> A soccer team has 11 players. How many different penalty shootout configurations are possible for the team?

You'd get $$(11)(10)(9)(8)(7) \implies 55,440$$ possibilities.&#x20;

### Combinations & Team Building

The number of possible permutations of `k` objects chosen from `n` objects is:

$$
\frac{n!}{(n-k)!k!} \lor  (n-k) \implies 0
$$

> A manager has funds to send a team 3 employees to a conference. Suppose that 10 employees express interest. How many possible teams of 3 employees could the manager form. (Assume that the order the employees are chosen in doesn’t matter.)

There are $$\frac{10!}{7!  \times 3!}$$ (this might be wrong)

> Suppose I’m one of the employees who wants to go. If the manager forms the team by choosing uniformly at random from among all possible teams of 3, what is the probability I get to go?

### The Wayne Brady Problem

{% hint style="info" %}
I don't get this
{% endhint %}

> Wayne Brady is the host of Let’s Make a Deal which works as follows 3 closed doors, one has a car behind it (good prize) and the other two have goats behind them (consolation prize) You choose one of the 3 doors Wayne Brady opens one of the doors you didn’t choose and shows you a goat Wayne Brady then offers to trade you the remaining unopened door for the door you choose Should you take his deal?

There's a 66% chance you'll win if you switch?

> Suppose as before but with an important change After you pick, Wayne Brady opens one of the remaining doors at random If Wayne Brady opens the door with the car, the game is reset and you play again from the beginning Should you switch?

Now, it's 50/50.

![](<../../.gitbook/assets/image (644).png>)

## Conditional Probability

* What if I had information that says "what if I can rule something out?
* Unconditional probability example: what is `P(A)` given that I have no particular information beyond `S` and the probability of all outcomes in `S`.
* Conditional probability: what is `P(A)` given that I have information that causes me to restrict the possible outcomes to a subset of `S`.



## Works Cited

* Course: Wascher, Matthew. "Chapter 1 Class/Powerpoint" _MTH 367 Statistics._ Spring 2022. University of Dayton.
* Navidi, William. Statistics for Engineers & Scientists (4th edition).



