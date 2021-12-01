# Lecture 05: Column-Column Model

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



## Examples

### Ex1

![](<../../.gitbook/assets/image (571).png>)

We should really think of this problem as:

$$
a(-4) +b(-3) = -4
$$

$$
[-4, -3]  \begin{bmatrix} a & b \\ c & d \end{bmatrix} = -3
$$

