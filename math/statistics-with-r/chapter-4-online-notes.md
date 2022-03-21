---
description: >-
  INCOMPLETE Professor Leonard's lectures on chapter 5 and 6 equivalent. Chapter
  5 is discrete. Chapter 6 is continuous.
---

# Chapter 4 Online Notes

## Works Cited

{% embed url="https://www.youtube.com/playlist?list=PL5102DFDC6790F3D0" %}
Prof. Leonard: click playlist icon on top right. Start at #13
{% endembed %}

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



## Binomial Probability Distributions

The binomial probability distribution deals with two outcomes: successes and failures. There can be multiple outcomes, but only one can be successful and the rest must be a failure.

### Example: Weighted Die (Setup)

* This example will be referenced henceforth until otherwise noted.
* The premise is that you have a weighted die with the following probabilities
* We're going to **find the mean, variance, and standard deviation and calculate probabilities that follow a binomial probability distribution**.

| x (one outcome) | P(x) |
| --------------- | ---- |
| 1               | .05  |
| 2               | .15  |
| 3               | .35  |
| 4               | .30  |
| 5               | .10  |
| 6               | .05  |

### Expected Mean, Var, and SD For ?

{% hint style="danger" %}
Matt - what's this called? Mean of a binomial probability? If that's the case, what's the  $$\mu = n \cdot p$$ formula called?
{% endhint %}

#### Expected Mean

![](<../../.gitbook/assets/image (648).png>)

* For the weighted die example, our expected value is 3.4.

#### Variance

* Variance says to add the square of the `x`'s
* Instead of frequency, we have probability.
* We're going to subtract the

![](<../../.gitbook/assets/image (650) (1).png>)

#### Standard Deviation

![](<../../.gitbook/assets/image (657) (1).png>)



It helps to create a table when calculating/adding the mean, variance, and standard deviation.

![](<../../.gitbook/assets/image (641).png>)

* The mean is 12.9
* Variance/Std:

![](<../../.gitbook/assets/image (654).png>)

### Usual and Unusual Values

![](<../../.gitbook/assets/image (639).png>)

If `P(A) <= 0.05`, then the event `A` is considered unusual.



### Rules for binomial distributions

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

### Example: [Weighted Die](chapter-4-online-notes.md#example-weighted-die-setup): Exacts

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

#### Step 2: Refer to a Table

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

### TI-84 `DISTR` Menu

To get this menu, hit `DISTR` on your calculator. (It's a shift key, so hit `2nd => Vars`).

{% embed url="https://youtu.be/VUyn9In8wE4?t=6" %}

#### `binomcdf`: Binomial Point Distribution Function

This finds the probability of an exact number. It takes 3 parameters separated by commas:

1. Number of trials.
2. Probability of a singular success.
3. The number of successes you want.

```
binompdf(10,.30,8)  // 10 trials, P(x)=0.3, for 8 successes.
```

#### `binomcdf`: Cumulative Distribution Function

* Up to and including the number.

```
binompdf(10,.30,8)  // returns probability there are 0 or 1...8 successes.
```



### Ex: [Cards](https://youtu.be/iGKSxMGX0Do?t=3614)

* This example will be used henceforth until otherwise noted.
* **Game:** you draw 7 cards with replacement.

#### Winning via 'exactly 4 hearts'

* Use a calculator. Do `binompdf(10,.25,4)`.

### [Mean Value, SD, Var of Binomial Dist](https://www.youtube.com/watch?v=4Ew60JEPGUk\&t=961)

Last time, we wanted to find mean _probability_ that an outcome occurred. This time, we are finding the mean value.

{% hint style="info" %}
#### Mean Formula: $$\mu = n \cdot p$$
{% endhint %}

* The mean is the number of successes you expect to occur from your procedure.
* Recall the weighted die example. If you roll it 100 times and `p(rolling #4)` = 0.3, you should expect to see roughly 30 `4's`.

{% hint style="info" %}
**Variance**: $$\sigma^2= n *p*q$$  `where q is probability of not happening.`
{% endhint %}

* Your variance and standard deviation will always be based on the mean, so always find the mean first.

{% hint style="info" %}
**Standard Deviation**: $$\sigma = \sqrt{n*p*q}$$
{% endhint %}

### Example: Mexican-Americans

In some town in New Mexico, they picked juries out of the population. 80% is Mexican-American, but the juries were 80% Caucasian every time. You're supposed to be tried by your peers. In this case, that's not Caucasians. Anyways, some research was conducted on the subject and the following was found:

* **Population**: 80% Mexican-Americans.
* **Population**: 12 people? :question:
* **Question:** is there evidence that the government is selecting bad juries purposely? (They sued)

#### Step 1: Find Successes/Failures

Since our goal is to have more Mexican-Americans representing the population in court, we'll define that as our success:

![](<../../.gitbook/assets/CleanShot 2022-03-21 at 00.42.03@2x.jpg>)

#### Step 2: Identify Key Information

* There are 12 trials => `n=12;`
* The probability of a successful trial: selecting a Mexican American. If you have a population that's 80% Mexican-American your chances of selecting a Mexican-American at random should be 80%. Therefore `p=0.80`.&#x20;
* `q` describes the probability of failure. The probability of failure should be people who are not Mexican-American. Therefore, `q=0.20.`

#### **Step 3: Calculate mean value, var, and std**

* **Mean:** is `n*p` => 12\*.80 => 9.6.
  * 9.6 is our mean value.&#x20;
  * If you selected a whole bunch of juries of people, you'd get 9.6 Mexican-Americans on average.
* **Variance** is `n*p*q`  => 1.93
* **Standard Deviation**: sqrt(var) => 1.39

#### Step 4: Are these normal values?



