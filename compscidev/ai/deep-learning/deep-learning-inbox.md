---
description: Will sort these out later.
---

# Deep Learning Inbox

## Neural Networks

### Pre-Readings

{% embed url="https://www.youtube.com/watch?v=jhrrw8Iuus0&list=PLkDaE6sCZn6FNC6YRfRQc_FbeQrF8BwGI&index=42" %}



### Class Notes From 2024-APR-11

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-16 at 14.34.11@2x.png" alt=""><figcaption></figcaption></figure>

### Quiz

<figure><img src="../../../.gitbook/assets/image.png" alt="" width="375"><figcaption></figcaption></figure>

Given an image of a neural network, be able to know:

1. What are the dimensions of of input data for classification? _Three._
2. How many output of actions or classes are there? _Two._
3. How many layers are involved for this neural netowrk? _Three_.
4. How many parameters do you need to learn through training? _Parameters are edges or the arrows. Therefore, 12 I think? Maybe 16?_

$$
a_{1}^{(1)} = g(\theta_{10}^1 x_0 + \theta_{11}^1 x_1+ \theta_{12}^1x_2 + \theta_{13}^1x_3)
$$

Here, $$a_i^{(j)}$$ is the activation of unit `i` in layer `j`. $$\theta^{(j)}$$ is a matrix of weights controlling function mapping from layer `j` to layer `j+1`.&#x20;

$$
a_{2}^{(2)} = g(\theta_{20}^1 x_0 + \theta_{21}^1 x_1+ \theta_{22}^1x_2 + \theta_{23}^1x_3)
$$



### **Network Architecture:**

* **Layers:** The network has 3 layers:
  * Input layer: 4 nodes (including a bias node)
  * Hidden layer: 4 nodes (including a bias node)
  * Output layer: 1 node
* **Activation Function:** The output layer uses an activation function denoted by `g`.

### **Variables:**

* **a\_i^j:** Activation of unit `i` in layer `j`. Here, `i` refers to the specific node within the layer (1 to number of nodes in that layer), and `j` refers to the layer number (1 for input, 2 for hidden, etc.).
* **x\_i:** Input to node `i` in the input layer (i = 0 to number of input nodes excluding bias).
* **θ^j:** Weight matrix for connections between layer `j` and layer `j + 1`. This matrix has dimensions (number of nodes in layer `j+1`) x (number of nodes in layer `j`).

### **Equations:**

* **a\_1^{(1)} = g(θ\_{10}^1 x\_0 + θ\_{11}^1 x\_1 + θ\_{12}^1 x\_2 + θ\_{13}^1 x\_3):** This equation represents the activation of the first node (i = 1) in the hidden layer (j = 1). It calculates the weighted sum of the inputs to this node:
  * `x_0` to `x_3` are the inputs to the node from the input layer (including the bias term `x_0`).
  * `θ_{10}^1` to `θ_{13}^1` are the corresponding weights in the first row of the weight matrix `θ^1`.
  * The weighted sum is then passed through the activation function `g` to get the final activation `a_1^{(1)}`.
* There's three more of them.&#x20;

### **Improvements:**

* **Clarity:** Specifying the dimensions of the weight matrix helps understand how it connects layers.
* **Completeness:** Mentioning the activation function used in the output layer would provide a more complete picture.

## Activation Functions

We're going to implement it by hand and understand how data goes through layers. The training process is more complex.&#x20;

* `g(x)` = relu(x) = max(0,x).&#x20;

### NumPy Activation

Let's do a manual implementation to see how neural networks work.

```

# Create some 3D Input Data
x = np.array([5, 2, 4])
print(x)
x = np.random.rand(3, 1)  # A better way; 3 rows / 1 columns. 
print(x)

```

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-16 at 15.11.08@2x.png" alt="" width="313"><figcaption></figcaption></figure>

Now everything is column wise.&#x20;

```python
import numpy as np

# Create some 3D Input Data
x = np.random.rand(3, 1)
print(type(x))
print(x)

# We want to use theta1 and theata2 to map into a final value.
def sigmoid():
    """
    An Activation Function.
    Sigmoid: 1/(1+e^(-x)

    """
    return 1.0/(1.0 + np.exp(x))

def relu(x):
    """
    return
    """
    return np.max(0, x)
```

