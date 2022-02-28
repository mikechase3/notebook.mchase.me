---
description: We'll make a driving simulator prototype.
---

# Player Control

## 1.1: Getting Started

### Learning Goals

| Goal             | Explanation                                    |
| ---------------- | ---------------------------------------------- |
| Position Objects | Drag them into your hierarchy or the scene     |
| Camera           | Position it                                    |
| Random           | Create new project, import assets, add objects |
| Windows          | Project, hierarchy inspector                   |
| Layout           | Customize                                      |
| Tools            | What tools can we use                          |

{% hint style="info" %}
Spelling hierarchy is super hard for Mike Chase
{% endhint %}

### Getting Organized

1. You'll want to store things in a folder.
2. Create a new project, using the drop down, and use the newest version.
3. When you create the project, it will create a sub-folder inside that folder.&#x20;

### Terminology

| Name           | What it is                                                                            |
| -------------- | ------------------------------------------------------------------------------------- |
| Project Window | Bottom. Stores environments and has lots of files.                                    |
| Scene View     | Shows the entire game world. Where you can right click and drag your mouse around.    |
| Course Library | All the different props we can use in our simulation                                  |
| Hierarchy      | Contains all your different things.                                                   |
| Inspector      | Lets you change **components** within each object like the position or mesh renderer. |

### Basic Controls

| Shortcut    |                                                |
| ----------- | ---------------------------------------------- |
| F           | Focuses on whatever is selected in the thing.  |
| Alt + Left  | Rotates around the scene.                      |
| Alt + Right | Zooms in and out on the focused object.        |

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

| Tool   | Shortcut | Usage                                                    |
| ------ | -------- | -------------------------------------------------------- |
| Hand   | q        | Just moves stuff.                                        |
| Move   | w        | Moves                                                    |
| Rotate | e        | Rotates objects.                                         |
| Scale  | r        | Makes things bigger or smaller                           |
| Rect   | t        | Combines move, rotate, and scale into one. Useful for 2D |
| All    | y        | Combines, move, rotate, and scale. Useful for 3D.        |

### Customize Interface Layout

* You can drag any `tabs` and put them wherever you want.
* You can drag them out too so that views are floating.&#x20;
* To save them, go back to where you'd see the defaults and then you can save your custom views.&#x20;

#### Presets

* There are presets on the top right.&#x20;

![](<../../../../.gitbook/assets/image (42).png>)

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
> * We’ll really make this interactive by writing our first line of code in C# to make the vehicle move and have it collide with other objects in the scene

## 1.2 Pedal To the Medal

### Learning Goals

> Overview: In this lesson you will make your driving simulator come alive. First you will write your very first lines of code in C#, changing the vehicle’s position and allowing it to move forward. Next you will add physics components to your objects, allowing them to collide with one another. Lastly, you will learn how to duplicate objects in the hierarchy and position them along the road.&#x20;
>
> Project Outcome: You will have a moving vehicle with its own C# script and a road full of objects, all of which may collide with each other using physics components.

### Introduction

* Objects are made up of components.
* We're going to write a C# script to make the vehicle fly.

### Applying Scripts to Objects

#### Organization

* Nest our C# scripts under **Assets -> Scripts**
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

### C# First Line

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

![](<../../../../.gitbook/assets/image (43).png>)

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

| Shortcut   | What Do It Do?        |
| ---------- | --------------------- |
| `CTRL + D` | Duplicates an object. |

### Summary

> New Functionality
>
> * Vehicle moves down the road at a constant speed
> * When the vehicle collides with obstacles, they fly into the air
>
> New Concepts & Skills
>
> * C# Scripts
> * Start vs Update
> * Comments
> * Methods
> * Pass parameters
> * Time.deltaTime
> * Multiply (\*) operator
> * Components
> * Collider and RigidBody
>
> Next Lesson
>
> * We’ll add some code to our camera, so that it follows the player as they drive along the road.

## 1.3: High Speed Chase

### Variables

#### Initializing Floats

```csharp
public float speed = 5.0f #The f makes it a float instead of a double. 
```

{% hint style="info" %}
Make sure it's public! That way, unity can interface with it.
{% endhint %}

### Data Types

* We can get references to our different objects like our `FollowPlayer` method.&#x20;
* We can drag our objects (like `Vehicle`) into our `Player` class request in Unity.
  * Then, we can call a method of that object like `playerObject.transform.position;`

### Using the GameObjects class

Things like obstacles or vehicles in our project are GameObjects and we can get references directly to our different game objects like our player from our camera.

#### Declaration of the object

```csharp
public class FollowPlayer : MonoBehaviour { 

    //Data Variables
    public GameObject player;
```

#### Accessing that object

Just use a dot operator to the object you are referencing.

```csharp
// Update is called once per frame
void Update(){
    transform.position = player.transform.position;
}
```

### Camera Offset and Adding Vectors

Our player position is providing a `Vector3`, we can offset the position by creating another `Vector3` and adding two vectors together.

```csharp
void Update(){
    //Offset the camer behind the player by adding to the player's position.
    transform.position = player.transform.position + new Vector3(0, 5, -7);
}
```

#### Better Method

It's better to assign this new vector to a private variable. This is kind-of obvious, but it makes our code cleaner to change values at the class level instead of hard coding.

```csharp
public class FollowPlayer : MonoBehaviour{
    // Class Variables
    public GameObject player; //Gets input from the actual player.
    private Vector3 offset= new Vector3(0, 5, -7) //Camera offset from player.
    
    // Class Methods
    void Update(){
        transform.position = player.transform.position + offset;
```

### Playmode Tint Color

You can do a blueout tint to make sure you do not change your program while in play-mode. This is done by adding a Playmode tint in the preferences. You can access them here.

`Edit` > `Preferences` > `Colors` >&#x20;

My color is b\*\*\*\*\*d amber `#FFCC88` because it brings back theater memories. That's a technical term. You can thank the theater industry for that. Same with the audio industry. They have poor naming like `dead cats` to cover microphones. It's a skin that covers a microphone so the wind does not get picked up by the microphone. If you're my future employer searching my website for profanity... I promise I'm not an evil person. Please hire me.

## 1.4 User Input

### Turning Our Car

1. Make a public `turnspeed` variable to the class as a float.
2. Make the car transform when we move that variable by saying (in the update method) `transform.Translate(Vector3.`right`* Time.deltaTime * turnSpeed);`

#### Code For Turning

```csharp
//using lotsOfKeywords
public class PlayerController : MonoBehaviour
{
    //Member Variables
    public float speed = 5.0f;
    public float turnSpeed = 0.1f;


    // Update is called once per frame
    void Update()
    {
        //We'll move the vehicle forward.
        transform.Translate(Vector3.forward * Time.deltaTime * speed);
        transform.Translate(Vector3.right * Time.deltaTime * turnSpeed);
    }
}

```

### Keyboard Input

Unity does a lot of things that make our lives easy.

#### Input Manager

![](<../../../../.gitbook/assets/image (52).png>)

The input manager maps keyboard input to things we can write in our code

* Jumping, firing, horizontal, vertical axes, sensitivity, etc.&#x20;

#### In Our Code

Unity provides a class called `Input` with a bunch of methods. The one we're going to use is `Input.getAxis()` which will return a string.&#x20;

![](<../../../../.gitbook/assets/image (49).png>)

{% hint style="success" %}
When you add to a vector position, it knows which direction you're facing. So when we say Vector3.forward, it won't change the car's position relative to the ground, but the car's position relative to the car. We don't have to calculate any fancy vector formulas to calculate velocity in a certain direction into the separate x and y components. It's not based on global coordinates.&#x20;
{% endhint %}



![You can change from local to global here!](<../../../../.gitbook/assets/image (59).png>)



### Rotation

Currently, when we press the left arrow key, we slide to the left and slide to the right. But like, directly to the left and right. The car doesn't rotate which is very abnormal
