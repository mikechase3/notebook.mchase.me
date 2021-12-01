# Class 01 & 02: Matrices Review

## Class 01: Calc 3 Review

#### Multiply a Vector by a Scalar

We know how to multiply a vector by a scalar (scalar = number). Multiply each component.

$$
k \overrightarrow{v} = k\begin{bmatrix}
k & v_x \\ 
k & v_y \\
k & v_z
\end{bmatrix} = k<v_x, v_y, v_z>
$$

#### Adding Vectors

Add up each component separately.

#### Linear Combination

When we combine both together, we get a **linear combination** of vectors.

$$
a \overrightarrow{u}+b \overrightarrow{v} = \begin{bmatrix}
a u_x + bv_y\\ 
au_y + b_vy\\
au_z + bv_z
\end{bmatrix}
$$

We can write a linear combination in a slightly more compact form:

![](<../../.gitbook/assets/image (530).png>)

The key equation for linear algebra is:

$$
A\overrightarrow{x} = \overrightarrow{b}
$$

* We can solve this if A & **x** are given.
* More interesting is what to do when A and **b** are given.

## Class 02: Dot Product

### Uses for Dot Product

$$
\vec{u} \cdot \vec{v} \implies u_1 v_1 + u_2 v_2 + ... u_n v_n
$$

There are two uses for the dot product. First, it is convenient for writing the length/magnitude. Second, dot products are **related** to the angle between two vectors. For example, if we consider the unit vector $$\vec{v} = \begin{bmatrix} 1\\ 0 \end{bmatrix}$$ and another unit vector $$\vec{w} = \begin{bmatrix} cos(\theta) \\ sin(\theta) \end{bmatrix}$$ then $$\vec{v} \cdot \vec{w} = 1cos(\theta)+0sin(\theta)=cos(\theta)$$&#x20;

To restate, $$\vec{u} \cdot \vec{v}$$ is always the angle between $$\vec{u} \texttt{ and } \vec{v}$$ for any unit vector.

#### Converting Non Unit Vectors to Unit Vectors

$$\vec{v} \implies \frac{1}{||\vec{v}||} \vec{v}$$  and $$\vec{w} \implies \frac{1}{|| \vec{w} ||} \vec{w}$$  therefore:

$$\frac{1}{||v||} \vec{v} \cdot \frac{1}{||w||}\vec{w} = cos(\theta)$$  and therefore...

$$\frac{1}{||\vec{v}|| \cdot ||\vec{w}||} = cos(\theta)$$&#x20;

We can derive a couple of rules and take the dot product and determine if it's positive or negative to see if it's acute or obtuse.

* $$\vec{v} \cdot \vec{u} >0 \implies \texttt{angle between the vectors is acute}$$&#x20;
* If it's equal to zero, it means they are perpendicular/orthogonal.&#x20;
* Also: $$v \cdot w < 0 \implies \texttt{Angle is obtuse}$$&#x20;

### Cauchy Schwartz Inequality

There's a French and German person who discover that the absolute value of a dot product is guaranteed to be less than the product of the lengths.

$$|\vec{v} \cdot \vec{w} | \leq ||\vec{v}|| \ast ||\vec{w}||$$&#x20;

Therefore,&#x20;

$$|cos(\theta)| = \frac{\vec{v} \cdot \vec{w}|}{||\vec{v}|| \ast ||\vec{w}||} \leq 1$$  meaning that $$|\vec{v} \ast \vec{w}| \leq ||\vec{v}|| \ast ||\vec{w}||$$&#x20;

### Triangle Inequality

****$$||\vec{v} + \vec{w}|| \leq ||\vec{v}|| + ||\vec{w}||$$ ****&#x20;

This also means if we square both sides, then if we dot it, we can simplify it like we'd expand two binomials.

> Here is his proof:
>
> $$||\vec{v} + \vec{w}||^2 \leq ||\vec{v}||^2 + ||\vec{w}||^2 \implies (\vec{v}+\vec{w})\cdot(\vec{v} + \vec{w})\vec{v}\vec{v}+2\vec{v}\cdot\vec{w}+\vec{w}\cdot\vec{w} \leq ||\vec{v}||^2+2|\vec{v}\cdot\vec{w} + ||\vec{w}||^2 = (||\vec{v}|| + ||\vec{w}||)^2$$&#x20;

We next went over some cool stuff about column space with the following lab:

{% embed url="https://www.geogebra.org/resource/cfeayta7/9fTewx4V0FmMQs82/material-cfeayta7.pdf" %}



{% embed url="https://www.geogebra.org/m/fkk8j959" %}

### Sample Problems

#### Finding Angle Between Vectors

![](<../../.gitbook/assets/image (536).png>)

We solved this by using the formula:

$$cos(\theta)=\frac{\vec{a} \cdot \vec{b}}{||\vec{a}|| \ast ||\vec{b}||} = \frac{-2+12}{(33)(21)}$$&#x20;

#### Find Two Independent Vectors in the Plane

![](<../../.gitbook/assets/image (540).png>)

Here, we basically ran out of time. But we plugged things in and got the answers \[4,1,0] and \[3,0,3]

## Miscellaneous

### Angle Between Two Vectors

1. First do the dot product between the two vectors
2. Second, find the lengths of each and multiply them together, put that on the denominator.
3. Lastly, find the arccos of that.

$$
\texttt{angle}=\arccos({\frac{\vec{v}\cdot\vec{w}}{||\vec{v}||\ast||\vec{w}||}})
$$

You're probably more familiar with the formula below:

![](<../../.gitbook/assets/image (564).png>)



