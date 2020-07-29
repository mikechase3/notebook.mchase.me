# Linear Programming

## What is Optimization?

When we are faced with a linear programming problem, we usually want to optimize a bunch of different conditions.

### Investment Profile Example

For example, you might be able to invest your money in different funds. Stocks might pay 10%, bonds, 7%, and cash 3%; however, there may be institutional restrictions. The amount in stock cannot be more than 1/3rd of the amount in bonds, and the amount in cash must be at least 1/4th of the amount in bonds. Using this information, we ask _how should an investor maximize his profits given these constraints?_

We can define these constraints using functions. We can model this problem like so:

#### Step 1: Define Variables

* X: The amount of money in stocks.
* Y: The amount of money in bonds
* Z: The amount of money in cash.
* Optimization: Total amount of money. 

#### Step 2: Write your constraints as functions

1. $$x+y+z = 100$$ 
2. $$x \leq \frac{y}{3}$$ 
3. $$z \geq \frac{x+y}{4}$$ 
4. $$x \geq 0 \land y \geq 0 \land z \geq 0$$ 

### General Linear Problem

* We are given `n` real numbers $$c_1, c_2, ... c_n$$ 
* We are also given `m` real numbers $$b_1, b_2, ... b_m$$ .
* We wish to find the solution to `n` variables $$x_1, x_2, ... x_n$$ that maximize or minimize _the objective function_ subject to the constraints.

{% hint style="info" %}
I skipped this section because it was confusing. Left off at 04:25
{% endhint %}









## Works Cited

| Resource | Author |
| :--- | :--- |
| [Chapter 29 Linear Programming](https://udayton.zoom.us/rec/play/6ZF7fu2vq2g3GtycuASDAaAoW9S6L6msg3AeqPtZmUm2W3EBM1CkMLtGYeEe71GeSrQ-f5JB85E2soWm?continueMode=true) | Dr. Zhongmei Yao |
|  |  |

