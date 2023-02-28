# Chapter 2: Solving Linear Equations

## 2.1: The Idea of Elimination

### Back Substitution

Last Friday, we were talking about matrices and how to solve systems without having to do much work with back-substitution.

* When a matrix is an _**upper triangular (U)**_, $$U\vec{x}=b$$ can be solved by _**back-solution**_ whenever the diagonal entries or pivots are non-zero.
* If a pivot is zero, the system has no solution or has infinity many solutions.

### Example: No Solution

![](<../../.gitbook/assets/image (603).png>)

Notice:

* The second row corresponds to $$0x_1+-x_2+2x_3=1$$
* The third row corresponds to $$0x_1+0x_2+2x_3=2$$
* Therefore, there is no solution

{% hint style="warning" %}
Why is there no solution? Is it because $$2x_3$$ can't equal 1 and 2? Can't -x2 be zero?
{% endhint %}

![](<../../.gitbook/assets/image (605).png>)

### Example: Augmented Matrixes

For brevity, accuracy, and speed, the best way to handle thi sis using an augmented matrix.

$$
\begin{bmatrix}A &| & \vec{b} \end{bmatrix} = \begin{bmatrix}1 & 1 & 2 & | & 3 \\ -2 & 3 & 1 & | & 1 \\ 2 & 2 & 2 & | & 1 \end{bmatrix}
$$

![](<../../.gitbook/assets/image (608).png>)

* First, proceed to do column by column.
* Start in column 1 and identify the pivot.
* Define multipliers for rows below.

In our example, we have:

$$
l_{2,1} = \frac{\texttt{entry in row 1 column 1}}{\texttt{pivot in column 1, ie., entry in 1,1}} \implies \frac{-2}{1} \land l_{3,1} = \frac{2}{1}
$$

* Now, subtracting $$l_{i, 1}$$ copies of row 1 from row `i`
* This is allowed because the correspondance to systems of equations:

![](<../../.gitbook/assets/image (607).png>)

{% hint style="warning" %}
How did we get from the last step here?
{% endhint %}

![](<../../.gitbook/assets/image (609).png>)

### Relation to Chapter 1: Elimination is Matrix Multiplication

![](<../../.gitbook/assets/image (610).png>)

Then he wrote down: $$l_{2,1} = -2 \implies E_{2,1}=\begin{bmatrix}1 & 0 & 0 \\ 2 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}$$

* The value of 1,2 flips from negative to positive in the above matrix.

### Summary

* The process is looking at the multipliers (ie an augmented matrix) and multiplying it by \_\_.

$$
\begin{bmatrix} A & | & \vec{b} \end{bmatrix} \implies E_{21} \begin{bmatrix} A & | & \vec{b} \end{bmatrix} \implies E_{3,1} E_{2,1} \begin{bmatrix} A & | & \vec{b} \end{bmatrix} \implies E_{3,2} E_{3,1} E_{2,1} \begin{bmatrix} A & | & \vec{b} \end{bmatrix} \begin{bmatrix} V & | & \vec{0} \end{bmatrix}
$$

## 2.2: Elimination Matrices and Inverse Matrices

* Inverses are unique.
* Not every square matrix has an inverse.

I switched completely to handwritten notes. Find these here:

{% embed url="https://www.dropbox.com/s/rifd9429zlpfmqs/Chapter%202%20Matrix.pdf?dl=0" %}
