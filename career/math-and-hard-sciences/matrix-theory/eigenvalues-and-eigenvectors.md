# Eigenvalues and Eigenvectors

## Formulas

| Name              | Usage                                                    | Formula                                                          |
| ----------------- | -------------------------------------------------------- | ---------------------------------------------------------------- |
| Eigenvalues       | Find eigenvalue                                          | $$0=det(A-\lambda I_n)$$                                         |
| Eigenvectors      | Find the eigenvector given a lambda that you solved for. | $$A \vec{v} = \lambda \vec{v} \Leftrightarrow A- \lambda I_n=0$$ |
| P-D Factorization |                                                          | $$A=P D P^{-1}$$                                                 |

## Example

{% embed url="https://www.youtube.com/watch?index=46&list=PL221E2BBF13BECF6C&v=mVeuZzJdd1w" %}

**Question:** Given the invertible matrix $$A= \begin{bmatrix} 1 & 2 & 3 \\ 0 & 1 & -2 \\ 0 & 1 & 4 \end{bmatrix}$$, find the eigenvalues and eigenvectors of $$A^2,A^{-1}-I_n$$.

### Find the Eigenvalues

Use the eigenvalues formula $$0=\texttt{det}(A - \lambda I_n)$$and substitute in the matrix A and identity matrix to get

$$
0= \texttt{det}(\begin{bmatrix} 1 & 2 & 3 \\ 0 & 1 & -2 \\ 0 & 1 & 4\end{bmatrix} - \lambda \begin{bmatrix} 1 & 0 & 0 \\ 0&1& 0 \\ 0 & 0 & 1 \end{bmatrix}) \Rightarrow \texttt{det}(\begin{bmatrix} 1- \lambda & 2 & 3 \\ 0 & 1- \lambda & -2 \\ 0 & 1 & 4 - \lambda \end{bmatrix})
$$

To find the determinant of a 3x3 matrix, use the formula you have to use cofactors, but I think you only have to do it once for some reason:

$$
0=(1-\lambda) \ast \texttt{det} \begin{bmatrix} 1 - \lambda & -2 \\ 1 & 4 - \lambda \end{bmatrix}
$$

$$
ightarrow 0=(1 - \lambda)(\lambda^2 -5 \lambda + 6) \Rightarrow 0=(1-\lambda) (\lambda-2) (\lambda-3) \Rightarrow \lambda = 1, 2, 3
$$

{% hint style="info" %}
In summary, just use the formula, set it equal to zero, and solve for lambda.
{% endhint %}

### Find the Eigenvectors

* Do this process for each eigenvector.

![](<../../../.gitbook/assets/CleanShot 2021-12-02 at 12.40.39@2x.jpg>)

### 2nd Example to Find Eigenvectors

> _**Problem Statement**_: find an eigenvector of the matrix $$A= \begin{bmatrix} -63 & 195 & 0 \\ -20 & 62 & 0 \\ 40 & -118 & 3 \end{bmatrix}$$corresponding to the eigenvalue $$\lambda = -3$$.

![](<../../../.gitbook/assets/CleanShot 2021-12-02 at 12.41.16@2x.jpg>)

![Your final answer would say that the eigenvectors are: .](<../../../.gitbook/assets/CleanShot 2021-12-02 at 12.41.45@2x.jpg>)
