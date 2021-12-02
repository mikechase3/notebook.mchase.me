# Eigenvalues and Eigenvector

## Formulas

| Name         | Usage                                                             | Formula                                            |
| ------------ | ----------------------------------------------------------------- | -------------------------------------------------- |
| Eigenvectors | An eigenvector $$\vec{v}$$ lies along the same line as A times x. | $$A\vec{v} = \lambda\vec{v}$$ (lambda is a scalar) |
| Eigenvalues  | Find eigenvalue                                                   | $$0=det(A-\lambda I_n)$$                           |
|              |                                                                   |                                                    |



## Example

**Question:** Given the invertible matrix $$A= \begin{bmatrix} 1 & 2 & 3 \\ 0 & 1 & -2 \\ 0 & 1 & 4 \end{bmatrix}$$, find the eigenvalues and eigenvectors of $$A^2,A^{-1}-I_n$$.

### Find the Eigenvalues

Use the eigenvalues formula $$0=\texttt{det}(A - \lambda I_n)$$and substitute in the matrix A and identity matrix to get

$$
0= \texttt{det}(\begin{bmatrix} 1 & 2 & 3 \\ 0 & 1 & -2 \\ 0 & 1 & 4\end{bmatrix} - \lambda \begin{bmatrix} 1  & 0 & 0  \\ 0&1& 0 \\ 0 & 0 & 1 \end{bmatrix}) \Rightarrow \texttt{det}(\begin{bmatrix} 1- \lambda & 2 & 3 \\ 0 & 1- \lambda & -2 \\ 0 & 1 & 4 - \lambda \end{bmatrix})
$$

To find the determinant of a 3x3 matrix, use the formula you have to use cofactors. For the first eigenvalue,&#x20;

$$
(1-\lambda) \ast \texttt{det} \begin{bmatrix} 1 - \lambda & -2 \\ 1 & 4 - \lambda \end{bmatrix} \Rightarrow (1 - \lambda)(\lambda^2 -5 \lambda + 6) \Rightarrow (1-\lambda) (\lambda-2) (\lambda-3) \Rightarrow \lambda = 1, 2, 3
$$

