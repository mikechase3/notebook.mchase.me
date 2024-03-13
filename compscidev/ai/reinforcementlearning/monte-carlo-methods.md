# Monte Carlo Methods

## Problem Setup

* Environment: where the agent operates. It's composed of:
  * States
  * Actions
  * Rewards
  * Transition Probabilities
* **Policy**: the strategy/behavior of the agent defining how it selects actions in each state.
* **Model-Free**: doesn't require explicit knowledge of the transition probabilities and rewards of the environment/model.

## Algorithm Overview

### Initializing Value Function Estimate `V(s)` for all states.

* The value of a state indicates how good it is for the agent to be in that state under a given policy.
* Higher values imply that being in that state is more beneficial for the agent in terms of obtaining future rewards.
* In the context of a 4x4 grid where a robot is traversing different cells, each cell could indeed be considered a state. So if we have a 4x4 grid there's 16 states corresponding to each cel.
* Initializing the vslaue involves settingan initial estimate for how good it is to be in that state.&#x20;
  * Common practice: random or all states have an initial value of zero
* In deterministic environments, the state would correspond directly to the position of the robot & there would be no uncertainty about the next state given the chosen action.
* In stochastic (probability/randomness) environments, there's some uncertainty about the outcome of actions which can lead to different states with certain probabilities.
  * Said differently, even though there's a probability asssociated with each action, the resulting state after taking an action might not be deterministic.&#x20;

### Generate Episodes

Run a for-loop of episode iterations until a sufficient number is generated.

* Initialize the episode by starting in some initial state.
* Follow the policy to select actions in each state until the episode terminates.
* Record the states, actions, and rewards encoutnered in the episode.

### Update the Value Function

For each state visited in the episode, we'll update the value estimate `V(s)` by averaging the returns obtained from all visits to that state.&#x20;

### Policy Improvement

Update the policy based on the updated value function estimates (e.g. using a policy improvement algorithm like policy iteration).

## Equations

**Return (G):**

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-13 at 19.04.43@2x.png" alt=""><figcaption></figcaption></figure>

* The return $$G_t$$ is the total discounted reward obtained in an episode. It is calculated as the sum of discounted rewards from the current time step $$tt$$ until the end of the episode: $$Gt=Rt+1+γRt+2+γ2Rt+3+…+γT−t−1RTGt​=Rt+1​+γRt+2​+γ2Rt+3​+…+γT−t−1RT​$$ where $$RtRt​$$ is the reward obtained at time step $$tt$$, $$γγ$$ is the discount factor (a value between 0 and 1), and $$TT$$ is the time step at which the episode terminates.

**Value Function Update:**

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-13 at 19.04.27@2x.png" alt=""><figcaption></figcaption></figure>

* After each episode, the value function estimate $$V(s)$$ for a state $$s$$ is updated using the following equation:  where $$N(s)$$ is the number of times state $$ss$$ has been visited, and $$G$$ is the return obtained in the episode.

## Further Reading

{% embed url="https://en.wikipedia.org/wiki/Monte_Carlo_method" %}

{% embed url="https://www.youtube.com/watch?v=BfS2H1y6tzQ" %}

