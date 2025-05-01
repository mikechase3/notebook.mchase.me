# Bipedal Walker
{% embed url="https://github.com/mikechase3/OptimalWalkingProblem" %}
## Background Knowledge
* **Reinforcement Learning (RL):**  Algorithms that allow an agent to learn by interacting with an environment and receiving rewards.
* **Temporal Difference (TD) Learning:**  RL method that learns by adjusting predictions based on the difference between expected and actual rewards.
* **SARSA:**  A TD algorithm updating Q-values based on (State, Action, Reward, next State, next Action).
* **Q-values:**  Represent the expected future rewards of taking a specific action from a given state. 

## Progress Made
* **Environment Setup:**  Successfully installed dependencies and configured the PyCharm project.
* **State Representation:**  Implemented a `State` class to represent the crawler's angles.
* **Action Selection:**  Implemented the `chooseAction` function using the ε-greedy policy.
* **Core TD Learning:**  Started implementing the SARSA algorithm in the `onTDLearning` function.

## Challenges and Future Work

* **Major Challenges:**  Initially had difficulty calculating correct state indices and ensuring Q-value updates use integer division. Debugging helped resolve these issues.
* **Negative Indices:**  Need to address the issue where the crawler tries to access negative indices, preventing correct Q-value updates.
* **Debugging and Refinement:**  Continued debugging and testing of the SARSA implementation is required, and will need to visualize the crawler's behavior.

## Additional Notes
{% embed url="https://quizlet.com/891442364/ai-cps-48x-f24-shen-monte-carlo-flash-cards/?funnelUUID=906ee232-b50a-4529-9d1c-94006f3e7038" %}

* I used Gym's Bipedal Walker environment initially to understand the concepts.

<figure><img src="../../../../.gitbook/assets/CleanShot%202024-04-28%20at%2022.18.36.gif" alt=""><figcaption></figcaption></figure>

* [x] &#x20;It compiles!
* [x] self.steps repeatedly lets the agent learn multiple episodes & generate random trajectories for each episode.

<figure><img src="../../../../.gitbook/assets/CleanShot%202024-04-28%20at%2022.08.52.png" alt=""><figcaption></figcaption></figure>

* [ ] Correctly updates the Qvalue for each state by finding the right state and action index within the 2D list.
  * [x] Done, but major bugs
  * [ ] Crawler tries to access negative indices that are nonexistant.&#x20;
  * [ ] Therefore, Q-values do not get updated.

<figure><img src="../../../../.gitbook/assets/CleanShot%202024-04-28%20at%2022.12.17.png" alt=""><figcaption></figcaption></figure>

* [x] &#x20;Correctly implement the e-greedy algorithm for chooseAction()

<figure><img src="../../../../.gitbook/assets/CleanShot%202024-04-28%20at%2022.14.17.png" alt=""><figcaption></figcaption></figure>

* [x] &#x20;Provide a document with what's implemented & not.



# Draft & Scrap Notes

{% embed url="https://gymnasium.farama.org/_images/bipedal_walker.gif" fullWidth="false" %}
Bipedal Walker Gym Environment | Source: [https://www.gymlibrary.dev/environments/box2d/bipedal\_walker/](https://www.gymlibrary.dev/environments/box2d/bipedal\_walker/)
{% endembed %}


This is a gymnasium environment, but it's basically what we're doing, but we're using Dr. Shen's proprietary environment instead. Let's first try it with Gym:

## Pycharm Project Setup

I took Pycharm and opened up the folder as my project.&#x20;

<figure><img src="../../../../.gitbook/assets/CleanShot%202024-04-17%20at%2019.54.54.png" alt=""><figcaption></figcaption></figure>

Something they never teach you about is how to setup interperters which I found confusing at first. Apparently, environments are fragile in code and while Python is easier than most languages, there are dependency conflicts when working with outdated code. To fix this, we have virtual environments of which there's pipenv and conda as the major ones. Anyways, if something is going wrong, the beginning of the arrow will let you add a new virtual environment interpreter and the IDE will use that.&#x20;

<figure><img src="../../../../.gitbook/assets/CleanShot%202024-04-17%20at%2020.06.46.png" alt=""><figcaption></figcaption></figure>

{% embed url="https://gymnasium.farama.org/environments/box2d/bipedal_walker/" %}

<figure><img src="../../../../.gitbook/assets/CleanShot%202024-04-17%20at%2020.06.46%20(1).png" alt=""><figcaption></figcaption></figure>

In ye older days, you could import it right from the context menu.&#x20;

<figure><img src="../../../../.gitbook/assets/CleanShot%202024-04-17%20at%2020.15.43.png" alt=""><figcaption></figcaption></figure>

But now they want you to use the package manager

<figure><img src="../../../../.gitbook/assets/CleanShot%202024-04-17%20at%2020.16.51.png" alt=""><figcaption></figcaption></figure>

You can verify this works successfully by opening up the python console right above it & typing `import numpy` into the interperter prompt (e.g. `>>>`). If you don't see that, type python3, unless you're using conda than you've got to activate it somehow but I'm doing a pipenv & it works for now. If you don't get any error when running import numpy, you're good to go.

## Understanding the Environment

This is an AI chat to help me do a few things...

### Understanding the Assignment

* **Temporal Difference (TD) Learning:** The key idea is to learn by adjusting predictions based on the difference between the predicted reward for a state and the actual reward received along with the estimated reward for the next state. In essence, it learns by refining its expectations with experience.
* **Q-Values:** Represent the expected future rewards of taking a specific action from a given state. The goal of TD Learning is to find the optimal Q-values for each state-action pair.
* **SARSA:** This a TD algorithm where you'll update your Q values based on:
  * **S**tate (current state)
  * **A**ction (action taken in the current state)
  * **R**eward (reward received after taking the action)
  * \*\*S'\*\*tate (the next state the agent ends up in)
  * \*\*A'\*\*ction (the action chosen in the next state, based on policy)

### Understanding the Design

1. **State:** Represents a combination of `angle1` and `angle2`.
2. **Qvalue:** A 2D array storing Q-values for each state-action pair.
3. **chooseAction():** Selects an action based on the ε-greedy policy, potentially updates the angle1 and angle2
4. **onTDLearning():** The core of the TD SARSA algorithm, updates Q-values based on rewards and state transitions.
5. **Crawler (From Crawler.py):** The simulated bot whose state is being modeled and controlled by the RL algorithm.

```
                        Bot Movement and State Representation                        
                                                                                     
     ┌───────┐                              ┌─────────┐                              
     │Crawler│                              │RLearning│                              
     └───┬───┘                              └────┬────┘                              
         │Request current state (angle1, angle2) │                                   
         │──────────────────────────────────────>│                                   
         │                                       │                                   
         │                                       ────┐                               
         │                                           │ Calculate state indices (r, c)
         │                                       <───┘                               
         │                                       │                                   
         │         Send updated angles           │                                   
         │<──────────────────────────────────────│                                   
         │                                       │                                   
         ────┐                                   │                                   
             │ Update internal angles            │                                   
         <───┘                                   │                                   
     ┌───┴───┐                              ┌────┴────┐                              
     │Crawler│                              │RLearning│                              
     └───────┘                              └─────────┘                              
```

* This diagram shows how the `Crawler` object interacts with the `RLearning` component.
* The `Crawler` provides its current angles.
* The `RLearning` module maps these angles to a discrete state representation (using row and column indices).
* New angles might be calculated by `RLearning` (e.g, if the `play_mode` is on) and sent back to the `Crawler` to update its position.

```
                        TD SARSA Q-Value Update                   
                                                                  
     ┌─────────┐                                         ┌───────┐
     │RLearning│                                         │Crawler│
     └────┬────┘                                         └───┬───┘
          ────┐                                              │    
              │ chooseAction()                               │    
          <───┘                                              │    
          │                                                  │    
          ────┐                                              │    
              │ Get current state (r, c) and action index    │    
          <───┘                                              │    
          │                                                  │    
          │      Execute action, get new state, reward       │    
          │─────────────────────────────────────────────────>│    
          │                                                  │    
          ────┐                                              │    
              │ Calculate next state (r', c')                │    
          <───┘                                              │    
          │                                                  │    
          ────┐                                              │    
              │ Update Qvalue[r][c] based on TD SARSA formula│    
          <───┘                                              │    
     ┌────┴────┐                                         ┌───┴───┐
     │RLearning│                                         │Crawler│
     └─────────┘                                         └───────┘
```

* This focuses on the internal logic within the `onTDLearning()` function.
* `chooseAction()` selects an action using the ε-greedy approach.
* The `Crawler` executes the action, leading to a new state and a reward.
* The key step is the Q-value update, which uses the immediate reward, the Q-value of the next state-action pair, and the discount factor (gamma).

### Decision Pipeline

I looked up how a robot makes a decision and learn from it (a bit more formally perhaps):

1. **Action Selection (chooseAction function)**
   * Implement an ε-greedy policy here. This means:
     * Most of the time (1-ε probability) choose the action with the highest Q-value in the current state.
     * Sometimes (ε probability) choose a random action for exploration purposes.
2. **Learning (onTDLearning function)**
   * The core TD SARSA update will occur here. Here's the general flow inside this function:
     * Initialize a random starting state.
     * For a certain number of iterations (`self.steps`):
       * Choose an action based on the ε-greedy policy (using your `chooseAction` function).
       * Take the action, observe the next state, and receive an immediate reward.
       * Choose the next action (also using ε-greedy policy).
       *   Update the Q-value for the current state-action pair using the TD update rule:

           ```
           Q(S, A)  <-  Q(S, A) + alpha * [R + gamma * Q(S', A') - Q(S, A)]
           ```
       * Move to the next state and repeat.
3. **State Representation**
   * The state is represented by the angles (`angle1`, `angle2`). You'll need to map these angles to discrete indices for your `Qvalue` array.
4. **Reward Calculation**
   * Reward seems to be based on the agent's horizontal distance traveled. You'll compute this on reaching a new location.

**Suggested Coding Tips**

* **Start with `chooseAction`:** It's more straightforward to implement, and then you can use that function within your `onTDLearning` function.
* **Data Structures:** Think about how to access and update your `Qvalue` array efficiently given the discretized `angle1` and `angle2` values.
* **Debugging:** Print values of states, actions, rewards, and Q-values at different steps to help you visualize the process and spot errors.

### Misc

Just gonna copy/paste my chat here:

<details>

<summary>More Background Knowledge</summary>

<img src="../../../../.gitbook/assets/CleanShot%202024-04-18%20at%2023.06.10@2x.png" alt="" data-size="original">

</details>


