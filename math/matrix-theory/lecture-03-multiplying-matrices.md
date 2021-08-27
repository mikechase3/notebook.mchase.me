# Lecture 03: Multiplying and Factoring Matrices

## Multiplying Matrices

### Column-Column Method

* We interpret both `A` and `B` as columns \(vectors\).
* We use a column `i` of `B` as weights on the columns of `A` to define column `i` of `AB`.

#### Example: Column-Column Method of Multiplying Vectors

![First example of multiplying vectors in Dr. Bush&apos;s Course.](../../.gitbook/assets/image%20%28543%29.png)

### Row-Row Methods

#### Example: Row-Row Method of Multiplying Vectors

Here, we're taking the rows 



![Example from Su p.51. Annotated by me.](../../.gitbook/assets/image%20%28544%29.png)

## Factoring a Matrix Into Two Products

**Goal:** Factor a matrix `A` into `A=CR` to make the column space and its dimensions more obvious and the size of the column space more obvious. This factorization is designed to get rid of dependent columns.

### Steps to factor a Matrix into 2 Products

1. Find the dependent column of `A` by sight or intuition.
2. Define `C` with just the independent columns of A \(and cross out the dependent ones\).
3. For `R`, define its columns by using weights on the columns of `C` that equal the corresponding column of `A`.



## Works Cited

* Bush, Arthur. "MTH 301 Matrix Theory and Applications." _Physical Class at the University of Dayton._
* Su, Francis. "Mastering Linear Algebra: An Introduction with Applications." _Great Courses Press._

