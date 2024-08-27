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

* Chain rule is used to compute the gradients of the error function with respect to all the weights and biases (theta) in the network.
* Gradient descent is an algorithm that uses the gradients calculated with the chain rule to adjust the thetas in a direction that minimizes the error function.

We'll account for the bias in the last function? We'l get five equations in each layer.

<figure><img src="../../../.gitbook/assets/image (2) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

> So then you can go back to the neural network and see that it's built up on many functions of theta. y=F\_1=(\theta\_1, \theta\_2, \theta\_3) and it's a compacted process. You can see between two layer there's multiple functions. Then at the end you compute the ? to compute gradient descent.&#x20;

I'm getting lost here:

<figure><img src="../../../.gitbook/assets/image (2) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

Can we use matrix products to represent this? Yes, we can & we can write it as two matrix products

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

## Further Reading TODOs

\
Sure, here are some videos you can watch to understand the math behind backpropagation and the variables you'll encounter:

**Wondrium**

* Neural Networks and Deep Learning by deeplearning.tv (\[Wondrium Neural Networks and Deep Learning course]) This course is a great introduction to neural networks and covers backpropagation in detail. It will explain what a^1, a^2, a^3, theta^1, theta^2, theta^3, and deltaY are and how they are used in the backpropagation algorithm. The course also explains the chain rule and gradient descent, which are fundamental concepts for understanding backpropagation.
  * Chapter 4, 5 specifically. Maybe 1, 9 for help. 23 is extra.

**O'Reilly**

* Hands-On Machine Learning with Scikit-Learn, Keras & TensorFlow by Aurélien Géron (\[O'Reilly Hands-On Machine Learning with Scikit-Learn, Keras & TensorFlow]) This course is a more hands-on introduction to machine learning, but it also covers backpropagation. The course will explain the concepts of activation functions, loss functions, and optimization algorithms, all of which are important for understanding backpropagation.

**YouTube**

* 3Blue1Brown: Neural Networks (\[YouTube 3Blue1Brown Neural Networks]) This is a great explainer video from 3Blue1Brown that gives a high-level overview of neural networks and backpropagation. The video won't go into the deep math, but it will help you get a basic understanding of the concepts.

**List of Variables**

Here's a list of variables you might see in the context of backpropagation:

* **a^i**: The activation of unit i in layer l. For example, a^1 might represent the activation of the first unit in the first layer.
* **theta^jl**: The weights connecting layer l to layer l+1. For example, theta^12 might represent the weights between the first and second layers.
* **deltaY**: The difference between the actual output of the network and the desired output. This is also known as the error.
* **delta^l**: The error term for layer l. This is used to calculate the gradients of the error function with respect to the weights and biases in that layer.
* **eta**: The learning rate, which controls how much the weights and biases are updated in each iteration of gradient descent.
