---
description: Apr 29 2024
---

# Cheat Sheet

Mostly AI Generated from my notes:

## **Supervised Learning**

* Learns from labeled data (input-output pairs)
* Goal: Predict outputs for unseen data
* Examples: Classification (spam filter), Regression (stock prediction)

## **Unsupervised Learning**

* Learns from unlabeled data (no predefined outputs)
* Goal: Discover hidden patterns in data
* Examples: Clustering (customer segmentation), Dimensionality reduction

## **Reinforcement Learning (RL)**

* Agent interacts with environment through actions
* Receives rewards for good actions, penalties for bad ones
* Goal: Learn optimal policy to maximize rewards
* **Differs from MDP (Markov Decision Process):**
  * MDP is a framework for modeling decision-making problems.
  * RL uses MDPs to define the environment but learns the policy through interaction.

### _A Search Algorithm_\*

* Heuristic function (h(x)) estimates cost to reach goal from state x
* Admissible: h(x) never overestimates true cost
* f(x) = g(x) + h(x) = total cost so far + estimated cost to goal
* Expands states with lowest f(x) values

```
function A_Star_Search(start, goal):
  openSet = set containing start
  cameFrom = empty dictionary

  gScore[start] = 0
  fScore[start] = gScore[start] + heuristic(start, goal)

  while openSet is not empty:
    current = min(openSet, key=fScore.get)  # Node with lowest fScore
    if current == goal:
      return reconstruct_path(cameFrom, current)  # Path found!

    openSet.remove(current)

    for neighbor in get_neighbors(current):
      tentative_gScore = gScore[current] + distance_between(current, neighbor)
      if neighbor not in openSet or tentative_gScore < gScore[neighbor]:
        cameFrom[neighbor] = current
        gScore[neighbor] = tentative_gScore
        fScore[neighbor] = gScore[neighbor] + heuristic(neighbor, goal)
        openSet.add(neighbor)

  return "Path not found"  # No path found

function reconstruct_path(cameFrom, current):
  path = [current]
  while current in cameFrom:
    current = cameFrom[current]
    path.append(current)
  return path.reverse()  # Reverse to get path from start to goal
```

This pseudocode defines functions for A\* search:

* `A_Star_Search` takes the starting node and goal node as input.
* It uses sets and dictionaries to track explored nodes and their scores.
* `fScore` combines the cost from the start (`gScore`) with an estimate to reach the goal (`heuristic`).
* The loop iterates through nodes with the lowest `fScore`.
* It expands neighbors, updating scores and cameFrom dictionary for path reconstruction.
* `reconstruct_path` backtracks from the goal to the start using the `cameFrom` information.

**Unsupervised Learning vs. MDP Tree**

* Unsupervised learning doesn't involve states or actions.
* MDP Tree: represents states and transitions in an RL problem.
  * Features:
    * Root: Starting state
    * Edges: Transitions between states
    * No height definition (tree can grow indefinitely)

**State & Q-Values/Trees**

* State: Represents a situation in the environment.
* Q-value (Q(s,a)): Expected future reward starting from state s, taking action a.
* Q-learning: An RL algorithm that learns Q-values.
  * Q-Trees: Can be used to represent and update Q-values for all states and actions.
  * Edges don't represent transitions (unlike MDP Tree). They may connect related states for efficiency.

**Finding the Next Action (Bellman Equation & Policy Iteration)**

* Bellman Equation: Iteratively updates Q-values based on rewards.
* Policy Iteration & Value Iteration: RL algorithms to find optimal policies.
  * **Policy Iteration:** Evaluates current policy, improves it based on Q-values.
  * **Value Iteration:** Directly computes optimal Q-values, then extracts the policy.

**Model-based vs. Model-free RL**

* Model-based: Learns a model of the environment (transitions, rewards) for planning.
* Model-free: Learns directly from interaction, without an explicit model.

**Monte Carlo vs. Temporal-Difference (TD) Learning**

* Monte Carlo: Estimates Q-values by averaging rewards from complete episodes.
* TD Learning: Updates Q-values based on immediate rewards and estimated future rewards.
  * (e.g., SARSA, Q-learning)

**Epsilon-Greedy (ϵ-greedy) Exploration**

* With probability ϵ, explore by choosing a random action.
* With probability (1-ϵ), choose the action with the highest estimated reward (exploitation).

**Deep Reinforcement Learning**

* Uses neural networks to represent policies and Q-values.
* **Forward Pass:** Calculates activations through network layers.
* **Activation Functions:** Introduce non-linearity (e.g., ReLU, sigmoid).
* **Backpropagation:** Updates network weights to minimize errors.
