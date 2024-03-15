# Machine Learning

## What is Machine Learning?

* A subset of artificial intelligence
* It uses historical data to make better decisions
* It makes predictions, optimize utility functions, extract hidden patterns in structures

### Use Cases

* Fraudulent transactions
  * Mine data with fradulant transactions
  * Train a model to flag them.
* Predictive content loading
* Target marketing: choosing marketing campaigns & cross-selling items.
* Matching managers and resumes
* Customer service: routing customer email.
* Product Category
  * Items containing "Jeans" are propably apparrel.

### Methods and systems

1. Predict
2. Extract
3. Summarize
4. Optimize an action given a cost function and observed data.
5. Adapt based on observed data.

### Types of Machine Learning Problems

1. Unsupervised:
   1. Patterns are found without any help because the labels are not known.
   2. The model constructs patterns without any pre-trained data.
   3. The model discovers groupings and clusters.
   4. i.e: _Customers who buy product A, also tend to buy product B._
2. Supervised:
   1. Inputs to the model are known and the model learns to generalize the output to these examples.
   2. Teacher's classifications must be present.
   3. Classification: Color, True/False
   4. Regression: Often a number
3. Reinforcement (Clasiffication and regression)

## Smart Applications

### Machine Learning Questions

* **User**: Will they use your product
* **Order**: Is this fradulant?

### Challenges To Building Smart Applications

* Requires high levels of expertise
* Finding the right technology that scales to customers
* Time to operationalize so your product application is effective.

### Machine Learning Platforms on AWS

* Amazon Machine Learning
  * Supports supervised learning approaches.
  * **Binary Classificatio**n: predicts the answer to a yes/no question. _Is this email spam or not?_
  * **Multiclass Classification**: predicts the correct category from a list. _Is this a movie or clothing? Which product is most interesting to this customer?_
  * **Regression**: predicts the value of a numeric variable. _For this product, how many units will sell? How many days beore the user stops using the application?_
* Amazon EMR
* Spark & SparkML

### How to build a Smart Application

1. Train Model
2. Evaluate and Optimize
3. Retrieve Predictions
