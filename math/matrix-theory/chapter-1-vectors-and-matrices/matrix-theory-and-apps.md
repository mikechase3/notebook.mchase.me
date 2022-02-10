# Chapter 1: Matrix Basics

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

![](<../../../.gitbook/assets/image (530).png>)

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

![](<../../../.gitbook/assets/image (536).png>)

We solved this by using the formula:

$$cos(\theta)=\frac{\vec{a} \cdot \vec{b}}{||\vec{a}|| \ast ||\vec{b}||} = \frac{-2+12}{(33)(21)}$$&#x20;

#### Find Two Independent Vectors in the Plane

![](<../../../.gitbook/assets/image (540).png>)

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

![](<../../../.gitbook/assets/image (564).png>)



## Multiplying Matrices

### Column-Column Method

* We interpret both `A` and `B` as columns (vectors).
* We use a column `i` of `B` as weights on the columns of `A` to define column `i` of `AB`.

#### Example: Column-Column Method of Multiplying Vectors

![First example of multiplying vectors in Dr. Bush's Course.](<../../../.gitbook/assets/image (543).png>)

### Row-Row Methods

#### Example: Row-Row Method of Multiplying Vectors

Here, we're taking the rows&#x20;



![Example from Su p.51. Annotated by me.](<../../../.gitbook/assets/image (544).png>)

## Factoring a Matrix Into Two Products

**Goal:** Factor a matrix `A` into `A=CR` to make the column space and its dimensions more obvious and the size of the column space more obvious. This factorization is designed to get rid of dependent columns.

### Steps to factor a Matrix into 2 Products

1. Find the dependent column of `A` by sight or intuition.
2. Define `C` with just the independent columns of A (and cross out the dependent ones).
3. For `R`, define its columns by using weights on the columns of `C` that equal the corresponding column of `A`.

#### Example 1: Factoring a Matrix

$$
A=\begin{bmatrix}1 & 2 & 3\\-1 & 3 & 2\\1 & 2 & 3\end{bmatrix}
$$

**Step 1:** Identify what is independent and dependent.

* Somehow, we figured out that the first two columns were independent.

**Step 2:** Figure out what C is and determine the size. C is just the independent columns, so we'll take the first two from above.

$$
C=\begin{bmatrix} 1 & 2\\-1 & 3\\1 & 2 \end{bmatrix}
$$

**Step 3:** Define R's Columns by using the weights on the columns of `C` that equal the corresponding column of `A`.

* The first column of `A` is in&#x20;

$$
R=\begin{bmatrix}1 & 0 & 1\\0 & 1 & 1 \end{bmatrix}
$$



### Steps (Restated Differently)

$$
\begin{bmatrix}1 & -1 & -1 & 0\\-2 & 2 & 0 & -6 \end{bmatrix}
$$

1. Find the independent and dependent.
   1. We start with only a 0 vector. The first adds something new to the column space.
   2. The second column is just a multiple, so we skip that. It's dependent.
   3. The third one is Independent.
   4. The fourth is dependent because it's a linear combination.
2. I know I'm going to need 4 columns in `R` because that's how many I'm solving for.
   1. For the first column, how many of the first and how many of the 2nd do you need to equal the original?
   2. Do this for each set of columns to get `R`.

![](<../../../.gitbook/assets/image (549) (1).png>)

![](<../../../.gitbook/assets/image (550) (1).png>)

### Good Example

Start here because I 100% understood this problem and how to do it at one point.

![](<../../../.gitbook/assets/image (552).png>)

## Second Model: Row-Column Model

The second model for matrix multiplication is called the _Row-Column Model._

$$
A^{m \times n} \ast B^{n \times p} = M^{m \times p}
$$

* A is a a collection of `m` rows.
* B is a collection of `p` columns.

### Subtopic Unknown

The entry in row `i` column `j` of `M` is the dot product of row `i` of `A` and column `j` of `B`.

$$
AB \begin{bmatrix} 3 & 1 & 6 \\ 2 & 4 & -1 \end{bmatrix} \begin{bmatrix}1 & 2 \\ 0 & -1 \\ 2 & -1 \end{bmatrix} = \begin{bmatrix} 15 & 3 \times 2 + (-1) 6 \times 4 \\ \_ & \_ \end{bmatrix}
$$

### Subtopic Unknown

* Vectors are always columns $$n \times 1$$ by default. To turn a vector or matrix on its side, we write $$\triangledown^T$$  or $$A^T$$&#x20;
* **T** means to transpose of all columns into rows or vice versa.
* With this notation, the dot product is just _regular_ multiplication

$$
\vec{u}_{(n \times 1)} \cdot \vec{v}_{(n \times 1)} = \vec{u}^T_{(n \times 1)} \vec{v}_{(n \times 1)} = d_{1 \times 1}
$$

* **T** is often called the inner product versus the _outer product_ $$\vec{u}_{n \times 1} \vec{v}^T_{1 \times n} = M_{n \times n}$$&#x20;
* The matrix has rank 1. The column space dimension is one, or a line.

## Third Model: Column/Row Model

$$
A^{m \times n} \ast B^{n \times p} = M^{m \times p}
$$

* **A** is a collection of `n` numbers.
* **B** is a collection of `n` rows.

### Example

There's three for loops. I will be 1, 2, and 3.

$$
AB \begin{bmatrix} 3 & 1 & 6 \\ 2 & 4 & -1 \end{bmatrix} \begin{bmatrix}1 & 2 \\ 0 & -1 \\ 2 & -1 \end{bmatrix} = \begin{bmatrix} 15 & 3 \times 2 + (-1) 6 \times 4 \\ \_ & \_ \end{bmatrix}
$$

#### When i=1:

$$
\begin{bmatrix}3 \\ 2 \end{bmatrix} \begin{bmatrix}1 & 2 \end{bmatrix} = 
\begin{bmatrix} 3 & 6\\2 & 4 \end{bmatrix}
$$

#### When i =2:

$$
\begin{bmatrix}1 \\ 4 \end{bmatrix} \begin{bmatrix}0 & -1 \end{bmatrix} = 
\begin{bmatrix} 0 & -1\\0 & -4 \end{bmatrix}
$$

#### When i=3:

$$
\begin{bmatrix}6 \\ -1 \end{bmatrix} \begin{bmatrix}2 & -1 \end{bmatrix} = 
\begin{bmatrix} 12 & -6\\-2 & 1 \end{bmatrix}
$$

#### It gives you the same answer

$$
M= \begin{bmatrix}(3+0+12) & (6+-1+-6) \\ 0 & 1 \end{bmatrix}
$$

## Column-Column Model

We use the columns of `B` as weights on a linear combinations of columns of `A`

$$
\begin{bmatrix} 3 & -2 \\ 5 & 0 \end{bmatrix} \begin{bmatrix}1 & 3 \\ -2 & 2 \end{bmatrix} = \begin{bmatrix} 7 & 5 \\ 5 & 15 \end{bmatrix}
$$

* Row 1: $$3 \begin{bmatrix}1 & 3 \end{bmatrix} + -2 \begin{bmatrix} -2 & 2 \end{bmatrix} = \begin{bmatrix} 7 & 5 \end{bmatrix}$$&#x20;
* Row 2: $$5 \begin{bmatrix}1 & 3 \end{bmatrix} + 0 \begin{bmatrix} -2 & 2 \end{bmatrix} = \begin{bmatrix} 5 & 15\end{bmatrix}$$&#x20;

From this, two facts about transposes follow:

$$
(M^T)^T = M \land (AB)^T = B^TA^T
$$

* We use the columns of $$A^T$$ as weights on the columns of $$B^T$$. The answer is a column.
* To multiply this product, we use the _rows_ of `A` as weights on the _rows_ of `B`. The answer is a row.
* The only difference between these statements if a formatting difference. When we do the first method, the answer is a column.&#x20;



## When to use each model

{% hint style="danger" %}
Ask Dr. Arthur when to use each model.
{% endhint %}

## \[Summary] Matrix Multiplication

* **Matrixes are Associative**: $$ABC = (AB)C = A(BC)$$&#x20;
* Matrixes are **not communitive:** $$AB \neq BA$$ , so the order matters.

## Identity Matrixes

Identity matrixes say that in an `nxm` square matrix with `1` in every diagonal position and `0` everywhere else.

$$
A_{m \times n} I_n = A \land I_mA_{m \times n} = A
$$

* We can not divide a matrix by another matrix.

### Ex1

![](<../../../.gitbook/assets/image (571).png>)

We should really think of this problem as:

$$
a(-4) +b(-3) = -4
$$

$$
[-4, -3]  \begin{bmatrix} a & b \\ c & d \end{bmatrix} = -3
$$



## Works Cited

* Bush, Arthur. "MTH 301 Matrix Theory and Applications." _Physical Class at the University of Dayton._
* Su, Francis. "Mastering Linear Algebra: An Introduction with Applications." _Great Courses Press._

