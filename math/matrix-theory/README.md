# Linear Algebra and Matrix Theory/Apps

## Decompositions

#### Legend (Appendix-3)

| Letter               | Meaning                                            | Usage Examples |
| -------------------- | -------------------------------------------------- | -------------- |
| L                    | An $$n \times n$$ matrix with 1's on the diagonal. |                |
| U                    |                                                    |                |
| Q (Orthogonal)       |                                                    |                |
| S (Symmetric)        |                                                    |                |
| $$\land$$ (Diagonal) |                                                    |                |
| X                    |                                                    |                |

### Decompositions

| Mathematical Form    | English Translation                                                                                                                                                                                                     | Usage                                                                                                                                                                                     |
| -------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| A=LU                 |                                                                                                                                                                                                                         |                                                                                                                                                                                           |
| A=QR                 |                                                                                                                                                                                                                         |                                                                                                                                                                                           |
| $$S=Q \land Q^T$$    |                                                                                                                                                                                                                         |                                                                                                                                                                                           |
| $$A=X \land X^{-1}$$ |                                                                                                                                                                                                                         |                                                                                                                                                                                           |
| $$A=QS$$             |                                                                                                                                                                                                                         |                                                                                                                                                                                           |
| $$A=U \Sigma V^T$$   | Singular value decomposition. Looks like $$A = \begin{bmatrix}\vec{u_1} & \vec{u_2}\end{bmatrix} \begin{bmatrix} \sigma_1 & 0 \\ 0 & \sigma_{2} \end{bmatrix} \begin{bmatrix} \vec{v}_1^T \\ \vec{v}_2^T\end{bmatrix}$$ | <ul><li><span class="math">\sigma_1, \sigma_2,...</span> are "singular values"</li><li>The u's are the "left singular vector".</li><li>The v's are the "right singular vectors"</li></ul> |

## Matrix Factorizations (A5)

| Math                                                                                                                                                                             | English | Usage |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------- | ----- |
| A=CR                                                                                                                                                                             |         |       |
| A=CMR\*                                                                                                                                                                          |         |       |
| A=LU                                                                                                                                                                             |         |       |
| A=LDU                                                                                                                                                                            |         |       |
| PA=LU                                                                                                                                                                            |         |       |
| $$S=C^TC$$                                                                                                                                                                       |         |       |
| A=QR                                                                                                                                                                             |         |       |
| $$A=X \land X^{-1}$$                                                                                                                                                             |         |       |
| $$S=Q \land Q^T$$                                                                                                                                                                |         |       |
| $$A=BJB^{-1}$$                                                                                                                                                                   |         |       |
| $$A=U \Sigma V^T$$                                                                                                                                                               |         |       |
| $$A^+ = V \Sigma^+ U^T$$                                                                                                                                                         |         |       |
| $$A=QS$$                                                                                                                                                                         |         |       |
| $$A=U \land U^{-1}$$                                                                                                                                                             |         |       |
| $$A=QTQ^{-1}$$                                                                                                                                                                   |         |       |
| $$F_n= \begin{bmatrix} I & D \\ I & -D \end{bmatrix} \begin{bmatrix} F_{n/2} & \\ &F_{n/2} \end{bmatrix} \begin{bmatrix} \texttt{even-odd} \\ \text{permutation} \end{bmatrix}$$ |         |       |
