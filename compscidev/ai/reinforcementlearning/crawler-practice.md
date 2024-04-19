# Bipedal Walker



{% embed url="https://gymnasium.farama.org/_images/bipedal_walker.gif" fullWidth="false" %}
Bipedal Walker Gym Environment | Source: [https://www.gymlibrary.dev/environments/box2d/bipedal\_walker/](https://www.gymlibrary.dev/environments/box2d/bipedal\_walker/)
{% endembed %}

{% embed url="https://quizlet.com/891442364/ai-cps-48x-f24-shen-monte-carlo-flash-cards/?funnelUUID=906ee232-b50a-4529-9d1c-94006f3e7038" %}

This is a gymnasium environment, but it's basically what we're doing, but we're using Shen's proprietary environment instead. Let's see what happens.

## Pycharm Project Setup

I took Pycharm and opened up the folder as my project.&#x20;

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-17 at 19.54.54.png" alt=""><figcaption></figcaption></figure>

Something they never teach you about is how to setup interperters which I found confusing at first. Apparently, environments are fragile in code and while Python is easier than most languages, there are dependency conflicts when working with outdated code. To fix this, we have virtual environments of which there's pipenv and conda as the major ones. Anyways, if something is going wrong, the beginning of the arrow will let you add a new virtual environment interpreter and the IDE will use that.&#x20;

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-17 at 20.06.46.png" alt=""><figcaption></figcaption></figure>

{% embed url="https://gymnasium.farama.org/environments/box2d/bipedal_walker/" %}

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-17 at 20.06.46 (1).png" alt=""><figcaption></figcaption></figure>

In ye older days, you could import it right from the context menu.&#x20;

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-17 at 20.15.43.png" alt=""><figcaption></figcaption></figure>

But now they want you to use the package manager

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-17 at 20.16.51.png" alt=""><figcaption></figcaption></figure>

You can verify this works successfully by opening up the python console right above it & typing `import numpy` into the interperter prompt (e.g. `>>>`). If you don't see that, type python3, unless you're using conda than you've got to activate it somehow but I'm doing a pipenv & it works for now. If you don't get any error when running import numpy, you're good to go.

### CV2 Issues

I'm guessing that PyCharm's solution to installing packages is seeing if `pip install <whatYouTypeIn>` is a registered package and `cv2` apparently isn't.&#x20;

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-17 at 20.23.24.png" alt=""><figcaption></figcaption></figure>

If you get this error too, you've got to install `opencv-python` like so:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-04-17 at 20.28.27.png" alt=""><figcaption></figcaption></figure>

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

<img src="../../../.gitbook/assets/CleanShot 2024-04-18 at 23.06.10@2x.png" alt="" data-size="original">

</details>

.
