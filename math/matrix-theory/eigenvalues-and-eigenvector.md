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
0= \texttt{det}(\begin{bmatrix} 1 & 2 & 3 \\ 0 & 1 & -2 \\ 0 & 1 & 4\end{bmatrix} - \lambda \begin{bmatrix} 1 & 0 & 0 \\ 0 & 1 & 0\\ 0 &  0 & 1 \end{bmatrix})
$$

This simplifies to:

$$
0= \texttt{det}(\begin{bmatrix} 1 & 2 & 3 \\ 0 & 1 & -2 \\ 0 & 1 & 4\end{bmatrix} - \lambda \begin{bmatrix} 1  & 0 & 0  \\ 0&1& 0 \\ 0 & 0 & 1 \end{bmatrix})
$$

And furthermore:
