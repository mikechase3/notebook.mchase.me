# Lecture 04: Row Column Model

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

* Vectors are always columns $$n \times 1$$ by default. To turn a vector or matrix on its side, we write $$\triangledown^T$$  or $$A^T$$ 
* **T** means to transpose of all columns into rows or vice versa.
* With this notation, the dot product is just _regular_ multiplication

$$
\vec{u}_{(n \times 1)} \cdot \vec{v}_{(n \times 1)} = \vec{u}^T_{(n \times 1)} \vec{v}_{(n \times 1)} = d_{1 \times 1}
$$

* **T** is often called the inner product versus the _outer product_ $$\vec{u}_{n \times 1} \vec{v}^T_{1 \times n} = M_{n \times n}$$ 
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

## When to use each model

{% hint style="danger" %}
Ask Dr. Arthur when to use each model.
{% endhint %}

