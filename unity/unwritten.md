---
description: We'll make a driving simulator prototype.
---

# Player Control

## 1.1: Getting Started

### Learning Goals

| Goal | Explanation |
| :--- | :--- |
| Position Objects | Drag them into your hierarchy or the scene |
| Camera | Position it |
| Random | Create new project, import assets, add objects |
| Windows | Project, hierarchy inspector |
| Layout | Customize |
| Tools | What tools can we use  |

{% hint style="info" %}
Spelling hierarchy is super hard for Mike Chase
{% endhint %}

### Getting Organized

1. You'll want to store things in a folder.
2. Create a new project, using the drop down, and use the newest version.
3. When you create the project, it will create a sub-folder inside that folder. 

### Terminology

| Name | What it is |
| :--- | :--- |
| Project Window | Bottom. Stores environments and has lots of files. |
| Scene View | Shows the entire game world. Where you can right click and drag your mouse around.  |
| Course Library | All the different props we can use in our simulation |
| Hierarchy | Contains all your different things. |
| Inspector | Lets you change **components** within each object like the position or mesh renderer. |

### Basic Controls

| Shortcut |  |
| :--- | :--- |
| F | Focuses on whatever is selected in the thing.  |
| Alt + Left | Rotates around the scene.  |
| Alt + Right | Zooms in and out on the focused object. |

* WSAD keys to move around.

### Inspector Basics

#### Transforming

* Reset the position by hitting the gear option and clicking "reset."
* You can rename objects in the hierarchy or in the top of the inspector.

### Views

* Play Mode doesn't actuall change anything.
* Scene view is where you go to setup your objects and where they're placed.
* **Main Camera** lets you control where the player sees what they see in the game.
  * You also have to click the `ctrl` key while you select an arrow, right click, and drag to move in **whole units.**
* You can change the view at the top right of the scene view. Just click x, y, or z.
* Small circles are what help you rotate. Just click the smaller circles and rotate.

### Tools

| Tool | Shortcut | Usage |
| :--- | :--- | :--- |
| Hand | q | Just moves stuff. |
| Move | w | Moves |
| Rotate | e | Rotates objects. |
| Scale | r | Makes things bigger or smaller |
| Rect | t | Combines move, rotate, and scale into one. Useful for 2D |
| All | y | Combines, move, rotate, and scale. Useful for 3D. |

### Customize Interface Layout

* You can drag any `tabs` and put them wherever you want.
* You can drag them out too so that views are floating. 
* To save them, go back to where you'd see the defaults and then you can save your custom views. 

#### Presets

* There are presets on the top right. 

![](../.gitbook/assets/image%20%2842%29.png)

### 

### Summary

> New Functionality
>
> * Project set up with assets imported
> * Vehicle positioned at the start of the road
> * Obstacle positioned in front of the vehicle
> * Camera positioned behind vehicle
>
> New Concepts & Skills
>
> * Create a new project
> * Import assets
> * Add objects to the scene
> * Game vs Scene view
> * Project, Hierarchy, Inspector windows
> * Navigate 3D space
> * Move and Rotate tools
> * Customize the layout
>
> Next Lesson
>
> * We’ll really make this interactive by writing our first line of code in C\# to make the vehicle move and have it collide with other objects in the scene

## 1.2 Pedal To the Medal

### Learning Goals

> Overview: In this lesson you will make your driving simulator come alive. First you will write your very first lines of code in C\#, changing the vehicle’s position and allowing it to move forward. Next you will add physics components to your objects, allowing them to collide with one another. Lastly, you will learn how to duplicate objects in the hierarchy and position them along the road. 
>
> Project Outcome: You will have a moving vehicle with its own C\# script and a road full of objects, all of which may collide with each other using physics components.

### Introduction

* Objects are made up of components.
* We're going to write a C\# script to make the vehicle fly.

### Applying Scripts to Objects

#### Organization

* Nest our C\# scripts under **Assets -&gt; Scripts**
* Use CamelCase naming convention for all your classes.

{% hint style="danger" %}
Do not rename files on the fly. it won't update the name of the classes and everything will go wrong. Maybe. There's probably a better way to refactor, but I don't know how to do it yet.
{% endhint %}

#### Applying Scripts to Objects

1. Left drag a script from your asset
2. Drop your script onto the object.

{% hint style="info" %}
We can click the "Add Component" button in the inspector or drag scripts onto the inspector as well while you have an object selected.
{% endhint %}

### C\# First Line

* Visual Studio is the default IDE for Unity.

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour // INHERITS From MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}

```

#### What do we want to change?

![](../.gitbook/assets/image%20%2843%29.png)

We want our vehicle to move forward, so we can look at the parameter that's changing when our thing does what it wants.

#### Transforming Method

```csharp
void Update(){
    //We'll move the vehicle forward
    transform.Translate(0, 0, 1) // Moves the vehicle by 1 unit every refresh.
    transform.Translate(Vector3.forward) //Works better.
}
```

### Delta Time

* `Vector3.forward`stores 3 different times, or all three components of the vectors.
* When you multiply it by `Time.deltaTime`, you are really multiplying every single component by `deltaTime` which is simply $$\frac{Frames}{\texttt{Time it took to display}}$$ . Or something like that; I don't really know.
* Multiply everything by Delta Time because it increases consistency across all computer types.

Here's the best way we know of so far:

```csharp
    void Update()
    {
        //We'll move the vehicle forward.
        transform.Translate(Vector3.forward * Time.deltaTime * 5);
    }
```

### Rigid Bodies

This component lets you add basic physics into objects.

### Duplicate and Position Obstacles

| Shortcut | What Do It Do? |
| :--- | :--- |
| `CTRL + D` | Duplicates an object. |

### Summary

> New Functionality
>
> * Vehicle moves down the road at a constant speed
> * When the vehicle collides with obstacles, they fly into the air
>
> New Concepts & Skills
>
> * C\# Scripts
> * Start vs Update
> * Comments
> * Methods
> * Pass parameters
> * Time.deltaTime
> * Multiply \(\*\) operator
> * Components
> * Collider and RigidBody
>
> Next Lesson
>
> * We’ll add some code to our camera, so that it follows the player as they drive along the road.

## 1.3: High Speed Chase

