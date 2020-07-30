# Linear Programming \(L20\)

## What is Optimization?

When we are faced with a linear programming problem, we usually want to optimize a bunch of different conditions.

## Optimization Examples

{% tabs %}
{% tab title="General" %}

{% endtab %}

{% tab title="Investment" %}

{% endtab %}

{% tab title="LP Knapsack" %}

{% endtab %}

{% tab title="" %}
LP Maximum Flow Problem

Our goal is to solve this maximum flow problem 

#### Constraints

* There is an inequality constraint for every edge.
* There is an equality constraint for every vertex.

{% hint style="info" %}
Notation: $$x_{ij} \implies \text{flow in edge } i \rightarrow j$$ 
{% endhint %}

<table>
  <thead>
    <tr>
      <th style="text-align:left">Edge Capacity Constraints</th>
      <th style="text-align:left">Equilibrium Constraints</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align:left">
        <img src="../.gitbook/assets/image (97).png" alt/>
      </td>
      <td style="text-align:left">
        <p></p>
        <p>
          <img src="../.gitbook/assets/image (98).png" alt/>
        </p>
      </td>
    </tr>
  </tbody>
</table>

![](../.gitbook/assets/image%20%2896%29.png)

* 
{% endtab %}
{% endtabs %}

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

### Fractional Knapsack Problem

#### Problem

* Suppose a thief is stealing stuff.
* You want to optimize the total value.

| Symbol | Meaning |
| :--- | :--- |
| $$v_j$$  | The value of the \(entire\) item j. |
| $$w_j$$  | The weight of the \(entire\) item j. |
| $$x_j$$  | The fraction of item j that is taken. |

#### Maximizing Value

* You want to maximize the value of all the items you choose.: $$v_1x_1 + ... + v_nx_n$$ .
* We are subjected to the weight limit: $$w_1x_1 + ... + w_nx_n \leq W$$ 
* The fractional of each item must be between: $$0 \leq x_j \leq 1, \text{for } j = 1, ..., n$$ .



## Works Cited

| Resource | Author |
| :--- | :--- |
| [Chapter 29 Linear Programming](https://udayton.zoom.us/rec/play/6ZF7fu2vq2g3GtycuASDAaAoW9S6L6msg3AeqPtZmUm2W3EBM1CkMLtGYeEe71GeSrQ-f5JB85E2soWm?continueMode=true) | Dr. Zhongmei Yao |
|  |  |

