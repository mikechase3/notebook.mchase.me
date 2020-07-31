# Linear Programming \(L20\)

## What is Optimization?

When we are faced with a linear programming problem, we usually want to optimize a bunch of different conditions.

### Examples

{% tabs %}
{% tab title="General" %}
### General Linear Problem

* We are given `n` real numbers $$c_1, c_2, ... c_n$$ 
* We are also given `m` real numbers $$b_1, b_2, ... b_m$$ .
* We wish to find the solution to `n` variables $$x_1, x_2, ... x_n$$ that maximize or minimize _the objective function_ subject to the constraints.

{% hint style="info" %}
I skipped this section because it was confusing. Left off at 04:25
{% endhint %}
{% endtab %}

{% tab title="Investment" %}
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
{% endtab %}

{% tab title="LP Fractional Knapsack" %}
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
{% endtab %}

{% tab title="LP Maxflow" %}
### LP Maximum Flow Problem

{% hint style="warning" %}
I don't really understand the motivation behind this problem.
{% endhint %}

Our goal is to solve this maximum flow problem 

#### Constraints

![Graphical Depiction of Constraints](../.gitbook/assets/image%20%2899%29.png)

* There is an inequality constraint for every edge.
* There is an equality constraint for every vertex.

{% hint style="info" %}
Notation: $$x_{ij} \implies \text{flow in edge } i \rightarrow j$$ 
{% endhint %}



| Edge Capacity Constraints | Equilibrium Constraints |
| :--- | :--- |
| $$x_{s1} ≤ 2$$  | $$x_{ts} = x_{s1} + x_{s2}$$ \(node s to 1\) |
| $$x_{4t} ≤ 3$$  | $$x_{s1} = x_{13} + x_{14}$$ \(node 1 to 3\) + \(node 1 to 4\) |
| $$\begin{pmatrix}. \\ . \\ .  \end{pmatrix}$$  | $$\begin{pmatrix}. \\ . \\ .  \end{pmatrix}$$  |

More words here.
{% endtab %}

{% tab title="Toy Factory" %}
### 

### 
{% endtab %}
{% endtabs %}

## Simplex Method



{% tabs %}
{% tab title="Summary" %}
### **Summary**

The simplex method says: travel along the corner points until you reach a local maximum. This is best illustrated through examples.

### Steps

Phase 1 \(start-up\): Find any corner point feasible solution. In many standard LPs the origin can serve as the start-up comer point

Phase 2 \(iterate\): Repeatedly move to a better adjacent corner point feasible solution until no further better adjacent comer point feasible solution can be found. The final corner point defines the optimum point
{% endtab %}

{% tab title="Toy Factory" %}
### Toy Factory

#### Step 1: Understand the problem

* A toy factory produces dolls and cars.
* Each doll sold makes the company $10.
* Each car sold makes the company $15.
* The packing machine can only pack 4 items/day.
* If Danny can produce 2 cars and 3 dolls per day, what should Danny produce?

#### Step 2: Describe the problem for linear programming

* Let $$x_1 \text{ and } x_2$$ denote the number of cars and dolls produced by Danny.

![](../.gitbook/assets/image%20%2895%29.png)

| Constraint | Caption |
| :--- | :--- |
| $$z = 15x_1 + 10x_2$$ | Formula describing z money for production of products. |
| $$x_1 ≤ 2$$  | Danny can produce 2 cars/day. |
| $$x_2 ≤ 3$$  | Danny can produce 3 dolls/day. |
| $$x_1 + x_2 ≤ 4$$  | The packaging machine can only pack 4 items. |
| $$x_2 \lor x_1 ≥ 0$$  | He can't produce negative items. |

#### Step 3: Make Objective Lines

The objective line is measured by the value of: $$z \text{ (which was defined to be) }= 15x_1 + 10x_2$$ 



![](../.gitbook/assets/image%20%2896%29.png)

{% hint style="info" %}
Left off at 17:45: [link](https://udayton.zoom.us/rec/play/6ZF7fu2vq2g3GtycuASDAaAoW9S6L6msg3AeqPtZmUm2W3EBM1CkMLtGYeEe71GeSrQ-f5JB85E2soWm?continueMode=true). Of quality watching.
{% endhint %}

#### Step 4: Observe:

1. An optimum solution is always at a corner point. 
   1. It might be that the constant line is parallel to a constraint line, in which case, there are many optimum points.
2. There is a finite number of **corner points** or feasible solutions.
3. If a corner point feasible solution has an objective function value that is better than or equal to **all**  its **adjacent corner point** feasible solutions, then **it is optimal.**

Summary: The simplex method says: travel along the corner points until you reach a local maximum.

#### Phase Steps

![](../.gitbook/assets/image%20%28102%29.png)

Here, we'll iterate through all the points where there is an intersection between the feasible region and examine what `z` is at each point.

> Phase 1: start at \(0, 0\) ~ Objective value = Z\(0, 0\)=0 
>
> Iteration 1: Move to \(2, 0\) ~ Z\(2, 0\)=30. An Improvement 
>
> Iteration 2: Move to \(2, 2\) ~ Z\(2, 2\)=50. An Improvement 
>
> Iteration 3: Consider moving to \(1, 3\) ~ Z\(1, 3\) = 45 &lt; 50
>
> Conclude that \(2, 2\) 1s optimum corner!
{% endtab %}
{% endtabs %}











## Works Cited

| Resource | Author |
| :--- | :--- |
| [Chapter 29 Linear Programming](https://udayton.zoom.us/rec/play/6ZF7fu2vq2g3GtycuASDAaAoW9S6L6msg3AeqPtZmUm2W3EBM1CkMLtGYeEe71GeSrQ-f5JB85E2soWm?continueMode=true) | Dr. Zhongmei Yao |
|  |  |

