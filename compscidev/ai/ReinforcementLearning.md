# Reinforcement Learning Notes
Shen wants us to implement policy iteration. 

## Basic Idea
1. Receive feedback in the form of *rewards*
2. Agent’s utility is defined by the reward function
3. Must learn to act as to *maximize expected rewards*
4. All learning is based on observed samples of outcomes. 

Unlike deep learning, this involves receiving/learning based on new data. If we communicate with the model a lot, it’s reinforcement learning. 

> Who will receive feedback?
The agent receives feedback.

## On Utility
When we get a house, we’ll utilize electricity, water, and gas. Unlike bills we have to pay, within the context of *AI*, it refers to the value collected through the interaction between the agent and the environment.

In Markov decision process, we receive feedback.

## Details
* It’s made up of a set of states s \in S
* A set of actions (per state) is represented by `A`
* A model `T(s, a, s')`
* A reward function `R(s, a, s')`
* Still looking for a policy `pi(s)`
New Twist: we don’t know `T` or `R`.
* i.e. we don’t know which states are good
* We don’t know what the actions do
* We must manually try actions & states out to learn. 

## Offline/Online
* We already know the probability?
* **Online learning**: is for reinforcement learning. The only way we learn is by trying it. 
* We don’t really think before we do. 

Sample = Trajectory:
* An agent take practice in the environment by taking a sequence of actions until it stops the current practice.

## Example
l