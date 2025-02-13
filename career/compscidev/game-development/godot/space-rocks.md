# Space Rocks

## Overview

* Uses a RigidBody2D
* We'll implement custom input actions.

## Input Maps

* These are systems/frameworks that assigns game actions to specific inputs, such. as buttons, keys, or joystick movements, allowing the player to interact with the game.
* It essentially translates player input from devices like controllers, keyboards, or mice into commands that the game understands and executes.
* **Key Components**: input devices, actions, bindings, customizability.
  * **Input Devices:** mice, flight controllers, touchscrens, motion.
  * **Actions:** specific game related functions like "jump", "shoot", "move forward"
  * **Bindings:** the actual mapping between input devices & game actions.
  * **Customizability:** putting crouch on the mouse will decrease others accuracy, so people will put it there.

## Creating an Input Map

Project -> Project Settings

<figure><img src="../../../../.gitbook/assets/CleanShot 2024-10-02 at 09.41.39.gif" alt=""><figcaption></figcaption></figure>

### Creating New Input Actions

* We need: `rotate_left`, `rotate_right`, `thrust`, and `shoot`.&#x20;
* You get a popup window after doing all of this.

<figure><img src="../../../../.gitbook/assets/CleanShot 2024-10-02 at 09.45.37@2x.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../.gitbook/assets/CleanShot 2024-10-02 at 09.47.06.gif" alt=""><figcaption></figcaption></figure>

### Analog Mappings

* There's a sine wave, but instead of it having a negative value, the **resstance** ends up giving us somewhere between a minimum/maximum value (zero and one).
* Versus digital, it's on or off.  Zero or one.
* If you have a gamepad or other controller connected to your computer, you can add its inputs to the actions in the same way.
* Using an analog joystic would require changes to the project code for example.&#x20;

## Rigid Body Physics

* **Collision Detection**: when two objects in the game space intersect or come into contact.
* **Collision Response**: the reactionary response to when a collision is detected.

1. `StaticBody2D`: these do not need to be affected by physics or gravity, such as walls, floors, or other environment elements that should not move during gameplay.
2. `RigidBody2D` is the physics body that provides simulated physics. _You don't control it, but it controls gravity._
3. `CharacterBody2D`: is a type of body that provides collision detection but no physics. All movement must be implemented in code.

### RigidBody2D

There are two types of properties for RigidBody2D nodes that can be customized.&#x20;

<figure><img src="../../../../.gitbook/assets/CleanShot 2024-10-02 at 09.56.11@2x.png" alt=""><figcaption></figcaption></figure>

### Advanced Settings: Linear/Angular Dampening

<figure><img src="../../../../.gitbook/assets/CleanShot 2024-10-02 at 09.58.30@2x.png" alt=""><figcaption></figcaption></figure>

.

