---
description: 'TODO: citation needed, fair use verification.'
---

# Chapter 2 Study Guide

## Basic Ingredients

* There are 2 schools of probability. Frequentists measure probability as a long-run frequency. Bayesian measures probability by the strength of belief. We use the frequentist paradigm.
* **Sample spaces** describe all possible outcomes of an experiment. We represent this with the variable `S`.
* **Experiments** result in unpredictable outcomes.
* **Events** are subsets of sample spaces.

### Combining Events

* **Unions** is just a logical or.
* **Intersections** are logical ands.
* **Complements**: show that sets aren't in a specified event.

![Illustration of unions, intersections, and complements. (Source: Navidi)](<../../.gitbook/assets/image (643) (1) (1) (1) (1).png>)

### Mutually Exclusive Events

* **Mutually exclusive** is a term describing two events (subsets) that don't share any outcomes.
* If outcomes are mutually exclusive, the following tools can be used:
  * [The addition rule](chapter-2-study-guide.md#undefined)

### Probabilities

* `Probability(<event>)` denotes how probable the event (aka outcome ) is to happen.
* P(event) must be btw 0 and 1.
* If there are multiple events `P{<outcome 1>, <outcome 2> ..., <outcome n>}`, and they are mutually exclusive.
* Empty sets are denoted with a $$\varnothing$$ symbol.

### Sample Spaces with Equally Likely Outcomes

If the outcomes are equally likely, the probability that event A happens is:

$$
P(A) = \frac{k}{N}
$$

* `k` is an outcome (e.g. the die rolls #1). It can be a set (e.g. die lands on an even number).
* `N` is the number of total outcomes.

### The Addition Rule: Finding $$P(A \lor B) \land P(A \oplus B)$$

$$
P(A \cup B) = P(A) + P(B) \iff P(A \cap B) = \varnothing
$$

* $$P(A \lor B)$$: We can add mutually exclusive/independent probabilities to determine the probability that either occur.
* $$P(A \oplus B)$$: to find the probability that either of two events then subtract the possibility that they both occur:

$$
P(A \cup B) = P(A) + P(B) - P(A \cap B) \implies P(A \oplus B)
$$

* If you want to find the probability that `event A` will happen, regardless of whether `event B/d/`E`...` happens or not, you are looking for:

![Img Source: Navidi](<../../.gitbook/assets/image (646) (1) (1) (1).png>)

$$
P(A) = P(A \cap B) + P(A \cap B^C) + [P(A \cap D^C) + P(A \cap E^C)...]
$$

## Counting Methods

### Multiplication (Fundamental) Principle

* The **fundamental principle of counting** tells us how to find the total number of possibilities given `n` number of events and you can make an `n`-dimensional table.

### Permutations

* We calculate permutations by using factorials.
* If there are `n` objects, the number of permutations is `n!` or $$n(n-1)(n-2)...(3)(2)(1)$$
* `0! = 1` (definition)

#### Permutations of `k` objects chosen from a group of `n` objects:

$$
\frac{n!}{(n-k)!}
$$

### Combinations

{% hint style="warning" %}
Review example with Matt for accuracy - this is my own example I made up.
{% endhint %}

* The number of combinations of `k` objects from a group of `n` objects is:

$$
\binom{n}{k} = \frac{n!}{k!(n-k)~}
$$

* If a set needs to be divided into more than two subsets (group `k` and group `n-k` not chosen), we'll do it in two steps.
  * Example: assume we have a group of 9 students
    * First operation: select combination of 4 students to make up the group of 4.
    * Second operation: select a group of 3 from remaining students.
    * Last operation: the group of 2 automatically consists of the 2 students left.
  * 1st: $$\binom{9}{4} = \frac{9!}{4! \times (9-4)!} \implies 126$$
  * 2nd: $$\binom{5}{3} = \frac{5!}{3!(5-3)!} \implies 10$$
  * 3rd: there's 2 people left, so 2! combination remain.
* The total number of ways to perform the sequence is:

$$
\frac{9!}{4! \times 5!} \times \frac{5!}{3! \times 2!} \implies \frac{9!}{4! \times 3! \times 2!} \implies 1260
$$

## Conditional Probability & Independence

* **Unconditional probabilities** describe things that are outside the sample space.
* **Conditional Probability** describes the outcomes from a certain part of the sample space.
* Knowledge involving certain conditions to predict a conclusion doesn't tell us about the entire sample, only the sample/population that meets the conditional criteria.
* **Notation**: to say that `P(<new quality we're measuring> | <such that it meets this conditional criteria>)`.
* For example, if we were making rods and you wrote this: `P(diameter is ok | length is ok)`, it would answer "how many, of the rods that are the correct length, also have an `ok` diameter?"

_Left off at the beginning of chapter 2.3_
