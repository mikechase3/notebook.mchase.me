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

{% hint style="danger" %}
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

![](<../../.gitbook/assets/image (644) (1).png>)

## Conditional Probability

* What if I had information that says "what if I can rule something out?
* Unconditional probability example: what is `P(A)` given that I have no particular information beyond `S` and the probability of all outcomes in `S`.
* Conditional probability: what is `P(A)` given that I have information that causes me to restrict the possible outcomes to a subset of `S`.

### Definition of Conditional Probability of A Given B

$$
P(A|B) = \frac{P(A \cap B)}{P(B)}
$$

### Example: Manufacturing Flaws

Suppose that a certain component is produced. We have the following data:

* It's produced shorter than specification 2% of the time.
* It's produced both shorter/thinner than specification 1% of the time.

> Suppose a randomly chosen component is shorter than specification is shorter than specification? What is the probability it is also thinner than specification?

The probability is 0.5.

## Independent Events

* A and B are **independent** if knowing the ooutcome of one tells you nothing about the other.

> Suppose A and B are independent? What is P(A|B)?

#### Answer

P(A|B) = P(A)

#### Explanation/Proof

> 𝑃(𝐴"∩" 𝐵)/(𝑃(𝐵))= (𝑃(𝐴)𝑃(𝐵))/(𝑃(𝐵))=𝑃(𝐴)

### Example: Servers

> Suppose a central server fails on 10% of days, an auxiliary server fails on 20% of days, and they both fail on 3% of days. Are the failures of these two servers independent events?

{% hint style="warning" %}
Review - I don't know how to tell myself.
{% endhint %}

### Determining Independence

* We can define this by saying $$P(A \cap B) = \emptyset$$

### Multiplication Rule for Independent Events

From Wascher, verbatim:

> * If A and B are independent P(A ∩ B) = P(A)P(B)&#x20;
> * For an independent collection P(A1 ∩ . . . An) = P(A1) . . . P(An)&#x20;
> * Generally P(A ∩ B) = P(A|B)P(B) Why?

#### Ex: Cooling Systems

> Suppose that if a reactor temperature ever exceeds 700C, the cooling system activates. Here is the data we collected:
>
> * The primary cooling system activates with probability .98&#x20;
> * If the primary cooling system fails to activate, the backup cooling system activates with probability .95 $$P(B|A^C) = 0.95$$
> * If both cooling systems fail, the reactor shuts down.

{% hint style="warning" %}
I don't understand how to solve this:
{% endhint %}

Questions

> What is the probability the reactor shuts down?

To figure this out, we'll need to calculate $$P(A^C \cap B^C) = P(B^C | A^C) P(A^C) = 0.001$$



## Law of Total Probability

Verbatim:

![Source: Wascher. Slide 36.](<../../.gitbook/assets/image (646).png>)

#### Example Continued:

We're still talking about the [cooling system](chatper-2-probability.md#ex-cooling-systems):

> What is the probability that the backup cooling system activates?

The probability is...?

### Example: Lunchtime

In class, we went over an example:

![](<../../.gitbook/assets/image (645).png>)

Note: we changed pizza to have a probability of 0.3 so it'd all add up to 1.

## Bayes' Theorem

Suppose I know P(A|B) and I want to find P(B|A). Baye's rule connects these:

![](<../../.gitbook/assets/image (647).png>)

{% embed url="https://www.freecodecamp.org/news/bayes-rule-explained" %}

### Example: Testing for Disease

Why don't we test people for rare disease?&#x20;

{% hint style="warning" %}
Review/discuss with him.
{% endhint %}

## Random Variables

* A random variable is a function assigning a numerical value to each element of the sample space denoted by capital letters such as `X`, `Y`, and `Z`.

#### Example: Flipping two coins

The sample space S is clearly `{HH, HT, TH, TT}`

Let the random variable X count the number of heads:

* X({HH}) = 2
* X({HT}) = X({TH}) = 1
* X({TT}) = 0.

### Discrete Vs. Continuous

* Continuous
  * Things like time, space, and money are continuous.
  * You can never truly measure things that are continuous.
  * Money is continuous because we stop counting at a fraction of a cent. In the stock market, I can't sell $0.00326345679 worth of Apple. At some point, you have to stop, usually at two decimals
* Discrete



![](<../../.gitbook/assets/image (642).png>)

### Example: Mo Manufacturing Flaws

![](<../../.gitbook/assets/image (643).png>)

To solve this, let's do this:

* P(x=0) = 0.78
* P(x=1) = 0.18
* P(x=2) = 0.07
* P(X=3) = 0.04

$$
F(x) = 0 \iff x<0 \land F(x) = 0.71 \iff 0 \leq x \leq 1
$$

## Probability Mass Function

![](<../../.gitbook/assets/image (644).png>)



## Works Cited

* Navidi, William. Statistics for Engineers & Scientists (4th edition).
* Wascher, Matthew. "Chapter 1 Class/Powerpoint" _MTH 367 Statistics._ Spring 2022. University of Dayton.



