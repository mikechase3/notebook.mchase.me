# BP Backwards Pass Backpropagation

Back propagation i based on two components:

1. Chain Rules
2. **Gradient Descent**

Both are built on-top of partial derivatives.&#x20;

<details>

<summary>What's this have to do with \theta?</summary>

In backpropagation, theta (θ) represents the weights and biases within a neural network. Finding these thetas is crucial for training the network to perform a specific task.

Here's how the concepts you mentioned tie in with finding thetas:

1. **Chain Rule:** Backpropagation utilizes the chain rule of calculus to efficiently compute the gradients of the error function (cost function) with respect to all the thetas in the network. The error function measures how well the network's predictions align with the desired outputs. By calculating these gradients, we determine how much each theta contributes to the overall error.
2. **Gradient Descent:** This optimization algorithm uses the gradients calculated with the chain rule to adjust the thetas in a direction that minimizes the error function. Imagine a landscape where the error function represents the height, and you want to find the lowest valley. Gradient descent guides the thetas downhill towards the minimum error.

Partial derivatives are the foundation for both the chain rule and gradient descent. They tell you how much a function (like the error function) changes with respect to a small change in a single theta. By chaining these partial derivatives together using the chain rule, we can efficiently calculate the overall impact of each theta on the error. Gradient descent then uses this information to iteratively update the thetas, moving them closer to the optimal values that minimize the error.

In essence, backpropagation employs the chain rule to calculate gradients and leverages gradient descent to find the optimal thetas that lead to the best performance for the neural network.

</details>

## Neural Network & Gradient Descent

We'll account for the bias in the last function? We'l get five equations in each layer.

<figure><img src="../../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

> So then you can go back to the neural network and see that it's built up on many functions of theta. y=F\_1=(\theta\_1, \theta\_2, \theta\_3) and it's a compacted process. You can see between two layer there's multiple functions. Then at the end you compute the ? to compute gradient descent.&#x20;

