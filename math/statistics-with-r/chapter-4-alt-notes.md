---
description: >-
  Professor Leonard's lectures on chapter 5 and 6 equivalent. Chapter 5 is
  discrete. Chapter 6 is continuous.
---

# Chapter 4 Alt Notes

## Using Probability Distributions

### Vocabulary

* **Random Variable:** the outcomes you can get, that depend on chance. A variable that has a number for each outcome and those outcomes are determined by chance. We use the letter `x` for our variable that has a value for each outcome of a procedure.&#x20;
* **Probability Distributions:** a table that gives us the probability for each value of a random variable.

![](<../../.gitbook/assets/image (658).png>)

* **Discrete Random Variables**
  * Ex: Counting the number of eggs that a chicken can lay in a week. Doesn't lay 3.2 eggs.
  * Must be a whole number.
* **Continuous Random Variable**: a variable with an infinite number of possible values.
  * Can be any # of decimal places out.

### Finding mean, variance, and standard deviation

#### Mean (aka "expected value")

![](<../../.gitbook/assets/image (648).png>)

#### Variance

![](<../../.gitbook/assets/image (650).png>)

#### Standard Deviation

![](<../../.gitbook/assets/image (657).png>)

### Find probability of exact number of successes

![](<../../.gitbook/assets/image (647).png>)

* To solve, find the probability that there's 501 _or more_ heads.&#x20;

## Binomial Probability Distribution

This is a probability distribution that has only two outcomes: success & failure.

#### Rules

1. You have to have a fixed number of trials.
2. Trials must be independent. The outcome of one trial does not affect the outcome of the others.&#x20;
3. Each trial has only to outcomes: success or failure..
4. The probability of success remains the same in all trials.

### Formula Variables

* `n` is the number of trials.
* `p` is the probability of a **successful** outcome in a **single** trial.
* `q` is the probability of a **failing** outcome in a **single** trial.
  * `p+q = 1`
* `x` is the **number of successes** that occur in the `n` trials.
  * `x` is not a probability. It's an **integer**.
* `P(x)` is the probability of getting `x` successes.

### Weighted Die: Exact Example

* The probability of rolling a 4 is 30%
* The die is rolled 10 times.
* **Goal:** find the probability of rolling exactly 8 4's.

#### Step 1: Fill out table of variables

| Symbol  | Meaning                              | Value |
| ------- | ------------------------------------ | ----- |
| n       | Number of trials                     | 10    |
| p       | Probability of failure in one trial. | 0.3   |
| q       | Probability of failure in one trial. | 0.7   |
| x       | Number of successes in `n` trials.   | 8     |
| P(x)    | Probability of x successes.          |       |
| Success | Rolling a '4'                        | N/A   |
| Failure | Rolling anything else.               | N/A   |

#### Step 2: Find Probability of Exactly 8 Successes

**Binomial Probability Formula:** The formula for how to find a probability:

$$
P(x) = \frac{n!}{(n-x)! \cdot x!} \cdot P^x \cdot q^{n-x} \implies _nC_x \cdot p^x \cdot q^{n-x}
$$

* The first part is the number of combinations or ways we can accomplish 8 successes out of 10 trials.
* The $$P^x$$ is the number of successes we want.
* The $$q^{n-x}$$ is the exact number of failures we want.

{% hint style="info" %}
**Remember the Binomial Probability Formula:**

$$P(x) = \frac{n!}{(n-x)! \cdot x!} \cdot P^x \cdot q^{n-x} \implies _nC_x \cdot p^x \cdot q^{n-x}$$
{% endhint %}

#### Step 3: plug in numbers:

![](<../../.gitbook/assets/image (649).png>)

The probability of rolling #4 on our weighted die exactly 8 times is 0.0014467.

### Weighted Die: At Most Example

* **Givens:** the probability of rolling a '4' is still 30%.
* **Goal:** find the probability of rolling at most 8 `4`'s.

#### Step 1: Use Addition Rule

* The probability of rolling at most 8 `4`'s is: $$P(0) + P(1) + P(2) ... P(8)$$.&#x20;
* For each of these, we have to plug it into our binomial probability formula.
  * Calculating this takes a lot of work
  * It's easier to use precomputed values and add them up.

#### Step 2: Refer to Table

{% embed url="https://uwf.edu/media/university-of-west-florida/colleges/cse/departments/mathematics-and-statistics/documents/student-resources/Binomial-Tables-1.pdf" %}
N is 10, x is 8, p is 0.3; Therefore P(8)=0.0014, but we must find P(7), P(6)
{% endembed %}

| P(x) | P(x) = n!/(n-x)!x! \* P^x \* q^(n-x) | Probability: Float between 0 and 1 |
| ---- | ------------------------------------ | ---------------------------------- |
| P(0) |                                      | .028                               |
| P(1) |                                      | 0.1211                             |
| P(2) |                                      | 0.2335                             |
| P(3) |                                      | 0.2668                             |
| P(4) |                                      | 0.                                 |
| P(5) |                                      |                                    |
| P(6) |                                      |                                    |
| P(7) |                                      |                                    |
| P(8) |                                      |                                    |

### TI-84

* Go to `DISTR` on a TI-84.
  * Option `0` is a **binomial point distribution function**. Aka: probability of an exact number.
  * Option `A` is a cumulative point distribution function: Aka: up to and including.
  * Option `B` does poisson
* Syntax: `binompdf(10, .30, 8)`; Parameters are `n=10, p=0.3, x=8`.

### Ex: Cards

{% embed url="https://youtu.be/iGKSxMGX0Do?t=3614" %}

## Mean, Variance, Std of Binomial Distribution

1. **Mean** or \mu is the number of successes you expect to occur from your procedure.



