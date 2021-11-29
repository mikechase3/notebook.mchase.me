# Lecture 03: Multiplying and Factoring Matrices

## Multiplying Matrices

### Column-Column Method

* We interpret both `A` and `B` as columns (vectors).
* We use a column `i` of `B` as weights on the columns of `A` to define column `i` of `AB`.

#### Example: Column-Column Method of Multiplying Vectors

![First example of multiplying vectors in Dr. Bush's Course.](<../../.gitbook/assets/image (543).png>)

### Row-Row Methods

#### Example: Row-Row Method of Multiplying Vectors

Here, we're taking the rows&#x20;



![Example from Su p.51. Annotated by me.](<../../.gitbook/assets/image (544).png>)

## Factoring a Matrix Into Two Products

**Goal: **Factor a matrix `A` into `A=CR` to make the column space and its dimensions more obvious and the size of the column space more obvious. This factorization is designed to get rid of dependent columns.

### Steps to factor a Matrix into 2 Products

1. Find the dependent column of `A` by sight or intuition.
2. Define `C` with just the independent columns of A (and cross out the dependent ones).
3. For `R`, define its columns by using weights on the columns of `C `that equal the corresponding column of `A`.

#### Example 1: Factoring a Matrix

$$
A=\begin{bmatrix}1 & 2 & 3\\-1 & 3 & 2\\1 & 2 & 3\end{bmatrix}
$$

**Step 1: **Identify what is independent and dependent.

* Somehow, we figured out that the first two columns were independent.

**Step 2: **Figure out what C is and determine the size. C is just the independent columns, so we'll take the first two from above.

$$
C=\begin{bmatrix} 1 & 2\\-1 & 3\\1 & 2 \end{bmatrix}
$$

**Step 3: **Define R's Columns by using the weights on the columns of `C` that equal the corresponding column of `A`.

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

![](<../../.gitbook/assets/image (549) (1).png>)

![](<../../.gitbook/assets/image (550) (1).png>)

### Good Example

Start here because I 100% understood this problem and how to do it at one point.

![](<../../.gitbook/assets/image (552).png>)

## Works Cited

* Bush, Arthur. "MTH 301 Matrix Theory and Applications." _Physical Class at the University of Dayton._
* Su, Francis. "Mastering Linear Algebra: An Introduction with Applications." _Great Courses Press._
