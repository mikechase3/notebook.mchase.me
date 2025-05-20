# Single Value Decomposition

## The Main Idea

* Remember: $$A=U \Sigma V^T$$
* We use it to factor non-square matrices and do fun things like find determinants on that after they get turned into square matrices through voodoo multiplication.
* It breaks down like this:

$$
A = \begin{bmatrix}\vec{u_1} & \vec{u_2}\end{bmatrix} \begin{bmatrix} \sigma_1 & 0 \\ 0 & \sigma_{2} \end{bmatrix} \begin{bmatrix} \vec{v}_1^T \\ \vec{v}_2^T\end{bmatrix}
$$

* Orthogonal \* diagonal \* orthogonal.

## Example

This process works on any size mxn matrix, but for now, let's say we have a matrix:

$$
A = \begin{bmatrix}2 & 2 \\ 1 & 1 \end{bmatrix}
$$

and there's a question on the test that says "find the singular value decomposition", you'll want to break it up into something that looks like this:

$$
A = \begin{bmatrix}\vec{u_1} & \vec{u_2}\end{bmatrix} \begin{bmatrix} \sigma_1 & 0 \\ 0 & \sigma_{2} \end{bmatrix} \begin{bmatrix} \vec{v}_1^T \\ \vec{v}_2^T\end{bmatrix}
$$

#### Step 1: Find A'A

The first thing we'll want to do is calculate A'A.

### Video Walkthrough

## Other Resources

{% embed url="https://ocw.mit.edu/courses/mathematics/18-06sc-linear-algebra-fall-2011/positive-definite-matrices-and-applications/singular-value-decomposition/MIT18_06SCF11_Ses3.5sum.pdf" %}

{% embed url="https://www.youtube.com/watch?index=63&list=PL221E2BBF13BECF6C&v=TX_vooSnhm8" %}

## Example

{% embed url="https://www.youtube.com/watch?index=64&list=PL221E2BBF13BECF6C&v=pSbafxDHdgE" %}

![](<../../../.gitbook/assets/CleanShot 2021-12-02 at 12.45.48@2x.jpg>)
