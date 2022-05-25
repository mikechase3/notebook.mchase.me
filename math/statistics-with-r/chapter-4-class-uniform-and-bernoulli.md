---
description: INCOMPLETE!!
---

# Chapter 4 Class: Uniform and Bernoulli

## 4.1: Bernoulli Distribution

{% embed url="https://www.khanacademy.org/math/statistics-probability/random-variables-stats-library/binomial-mean-standard-dev-formulas/v/mean-and-variance-of-bernoulli-distribution-example" %}



## Unbiased Estimators and Precision

* Often, there are many choices for unbiased estimators.
* We **prefer the more precise unbiased estimator** (with lower variance)

![](<../../.gitbook/assets/CleanShot 2022-02-23 at 15.49.52@2x.jpg>)

## David Blackwell (1919-2010)

* Statisticians who work on:
  * Probability
  * Baysian statistics
  * Game theory
  * Information theory
* He was the first black tenured faculty member at UC Berkeley
* First black American member of the National Academy of Science
* Denied opportunities at Princeton and UC Berkley due to his race.

## Rao-Blackwell Theorem

* Suppose we have data $$x_1, ..., x_n$$ from a distribution $$f(x;\theta)$$and want to estimate the parameter $$\theta$$
* Let $$\sigma$$ to be an unbiased estimator of theta so E(sigma) = 0
* Let T be a sufficient statistic for theta.

More notes...

### Ex: Phone Calls

* Suppose that I observe the number of times a phone rings over two separate 1-minute intervals.
* Assume the number of rings in a 1 minute interval is Poisson(\lambda)
* My observations X_1 and X_2 are independet draws from a Poisson distribution
* Estimate: P(no rings in the next 1 minute interval)
* Let $$X_3$$\~ Poisson(\lambda) be the number of rings in the next 1-minute interval.

![](<../../.gitbook/assets/CleanShot 2022-02-23 at 16.01.04@2x.jpg>)

### Applying Rao-Blackwell

![](<../../.gitbook/assets/CleanShot 2022-02-23 at 16.05.34@2x.jpg>)

More on this...

![](<../../.gitbook/assets/CleanShot 2022-02-23 at 16.10.24@2x.jpg>)

* $$(1/2)^T e[0,1]$$
* This is a better, more precise, unbiased estimator.

## Uniform Distribution

* If X is a real number drawn uniformly from the interval \[a,b] or (a,b), we say X is a **continuous uniform random variable on \[a,b]**
* If X is an integer drawn uniformly from the set {a, a+1, ..., b}, we say&#x20;

{% hint style="info" %}
Re-write. Missing notes from this.
{% endhint %}

![](<../../.gitbook/assets/CleanShot 2022-02-23 at 16.17.16@2x.jpg>)

### Ex: Uniform Distribution

![](<../../.gitbook/assets/CleanShot 2022-02-23 at 16.19.34@2x.jpg>)

### Ex: German Tank Problem

![](<../../.gitbook/assets/CleanShot 2022-02-23 at 16.23.58@2x (2).jpg>)

## Exponential Distribution

* X has an exponential distribution with rate \lambda means the PDF of X is:
* $$f(x) = \lambda e^{- \lambda x}, x > 0 \texttt{ or 0 otherwise}$$
* The exponential distribution is used to model waiting times.
* We often abbreviate X \~ Exp(\lambda)
* The $$1-e^{- \lambda x}$$

![](<../../.gitbook/assets/CleanShot 2022-02-23 at 16.28.19@2x.jpg>)

{% hint style="warning" %}
Find/review missing notes!
{% endhint %}

### Example: Exponential Distribution

Suppose the time in hours until a lightbulb burns out follows an exponential distribution with rate 0.002. Let X be the number of hours until the lightbulb burns out.

* What is the probability it lasts less than 200 hours:&#x20;
* What is the probability it last more than 500?
* How long is the lightbulb expected to last?&#x20;

## Memoryless Property of Exp

* The exponential distribution is **memoryless**
  * Future waiting time doesn't depend on the past (time already waited)
  * Mathematically, $$P(X > t + s | X > t) = P(X > s)$$
* Proof is in the slides.

## Poisson Process & Exponential

Suppose we observe events from a poisson process with rate of \lambda events per unit of time and space:

* If X is the total number of events in `t` units of time and space, X\~Poisson(\lambda t)
* If `T` is the waiting time until the next event (starting from any point in time), then `T~exp(\lambda)`

``![](<../../.gitbook/assets/CleanShot 2022-02-23 at 16.40.07@2x.jpg>)``

### Ex: Poisson Process and Exponential

* Suppose a pulsar emits pulses according to a poission process with rate 0.2 pulses per second. We observe the pulsar for 10 seconds.

![](<../../.gitbook/assets/CleanShot 2022-02-23 at 16.43.49@2x.jpg>)

## Waiting with Multiple Processes

* _If `X~Exp(\lambda1)` and_ `Y~Exp(\lambda_2)` are independent exponentially distributed random variables, then: $$min(X,Y) Exp(\lambda_1 + \lambda_2)$$ __&#x20;
* We can use this if we are waiting on multiple independent processes and care about the first event... (missed notes)

### Ex: Supermarket Lines

I'm in the line at a supermarket with 2 checkout counters. Suppose the first counter serves customers at rate 1 per 2 minutes, the second serves customers at rate 1 per 3 minutes, and they are independent. If I assume the waiting time until each counter becomes available follows an exponential distribution, how long should I expect to wait before I can be served?

