---
description: >-
  Create blueprints and tour the Blueprint Editor Interface. Create and assign
  vars from my blueprint panel and place them into the level.
---

# Creating Blueprints & Editor UI

## Creating New Blueprint Classes

* **Add:** In the content browser: `Add New` -> `Blueprint Class`  -> `Actor`
* There are all types of classes to inherit from, but the generic `actor` class works most of the time.

## Blueprint Editor UI

### Components Panel

![](<../../../.gitbook/assets/image (211).png>)

* Each of these components have some built-in functionality

### Toolbar

![](<../../../.gitbook/assets/image (209).png>)

* Compile your blueprints before testing them
* Save them.
* `Class Settings` gives you the ability to define class-specific settings
* `Class Defaults` lets you control the defaults for variables. You can access variables from the class defaults..
* `Simulation` lets you see your blueprint running.
* `Debug Filter` helps you debug blueprints.&#x20;
  * The dropdown lets you _choose a specific instance._

### Details

![](<../../../.gitbook/assets/image (206).png>)

* Controls all the _properties_ for each component you add.

## Viewport Panel

* Nothing new here.

## Construction Strip

![](<../../../.gitbook/assets/image (210).png>)

* Allows you to setup customized parameters for your blueprints
  * Called _**pre-faps**_
* Lets people change the values of things without the code.
  * It updates inside of the editor.
  * Seems like an interface?
* Fires at run-time when the game begins.

## Event Graph

![](<../../../.gitbook/assets/image (213).png>)

* Used for updating blueprints at run time.
* Most of your scripting is done here.

## My Blueprint Panel

![](<../../../.gitbook/assets/image (212).png>)

* Graphs
* Functions
  * Create Them
  * See the functions you created
  * Override them
* Macros
  * Streamline the way blueprints are setup
* Variables
  * View variables
* Event Dispatchers&#x20;
  * Used to communicate between different blueprints.

## Advanced Assets

![](<../../../.gitbook/assets/image (207).png>)

* Under the create assets menu, you can create more things.
* **Blueprint Function Library:** a collection of functions you can access from other blueprints
* **Blueprints Interface**: communicating between different blueprints
* **Blueprints Macro Library**: A collection of macros to use in other blueprints.
* **Enumeration:** Lets you have different states. A list of states.
  * For example: state of character like `alive` or `dead` or `hurt`.
  * Used within blueprints.
* **Structure**: A collection of different variable types.
  * If you had a character with an inventory, you could have a pickup structure.
    * Contains the name of the pickup, a sound effect, and everything within one structure even though they're different variable types.

## Converting Objects to Blueprint Class

If you're working in the editor, you can group a bunch of components together and make them in a blueprint. It gives you a different approach if you want to build everything in the level first.&#x20;

![](<../../../.gitbook/assets/image (208).png>)

* You can create several components in the level.
* Use `CTRL` to select a group of objects.
* Go to `Blueprints` in the toolbar and select `Convert Selected Components to Blueprint Class`.

