---
description: 'Purpoose: build better 3D Meshes'
---

# Static Meshes

## System Units

* Use _**centimeters**_ as the default unit of measurement.
* 1 unreal unit is equal to 1 centimeter.
* Make sure to set DCC

## Triangle Counts

![](<../../../../.gitbook/assets/image (178).png>)

Keep your triangle count low!

### Tips

1. Don't model small details
2. Constantly check your triangle count
3. You can display millions of triangles, it just takes some planning.

### Checking Triangles in UE4

* The triangles and vertices can be counted within the static mesh editor.
* It helps you create models that are beautiful, but also performance.

## Material ID's

* Material IDs determine which material gets applied to them.
* If an object has multiple material IDs, it needs to be rendered multiple times.
* If an object has 5 material IDs, it will need to be rendered 5 times.&#x20;

**Summary**: Each material ID you add costs more to render.

## Pivot Points

Pivot points describe the center point. It's where 0, 0, 0 is.

![An example of a terrible pivot point.](<../../../../.gitbook/assets/image (182).png>)

$$
(\text{bad pivot placement} \implies \text{artist hours}) \lor (\text{correct placement} \implies \text{efficient placement})
$$

## Light Maps

![Left: Light map. Right: shadow map.](<../../../../.gitbook/assets/image (183).png>)

Light maps are used to store complex light and shadow information inside of a texture.

* Textures are extraordinarily cheap and good at storing complex lighting calculations.
* This way, we get this information almost at zero cost during run-time.
* You pack information into R, G, and B information.

Now that we know what light maps are and what they're used for, we'll talk about some of the caveats.&#x20;

![](<../../../../.gitbook/assets/image (176).png>)

1. Light maps require every object be laid out in the 0 to 1 UV Space. _The 0 to 1 is the square space._
2. The items need to occupy their own space on the 3D Atlas.

{% hint style="info" %}
There is more information in 15:00, but it was too specific for what I need.
{% endhint %}

## Collision Meshes

#### Use

1. Recognize when an object hits something in the world
2. Make sure players can walk on the surfaces they're standing on.

### Creating via DCC

* We need to name the collision with a specific identifier: `UCX_(FuillName)_VersionNumber` so Unreal engine knows it's collision geometry.

### Creating via Unreal Engine

#### Create a box around specific parts.

![](<../../../../.gitbook/assets/image (185).png>)

1. Click Collision and add a box.&#x20;
2. Move it around the colliding object.

![Transform the box so it rotates within the leg.](<../../../../.gitbook/assets/image (175).png>)

### Convex Decomposition

![Convex Decomposition hugs objects really well.](<../../../../.gitbook/assets/image (174).png>)

* Allows you to create complex collisions for organic collisions.  `Window -> Convex Decomposition`

## Limiting Overdraw

![](<../../../../.gitbook/assets/image (181).png>)

* By manipulating the shape of your plane, you can eliminate unneeded calculations.
* Remove some vertices so you don't have to render a ton more pixels.&#x20;

## Level of Detail (LOD)

![Files contain different LODs within the same file.](<../../../../.gitbook/assets/image (180).png>)

It's an exact same copy of your mesh, but with less triangles, pixels, and vertices.

### Importing into Unreal engine

* Instead of importing all, you have to selected `advanced -> Import Mesh LODs`.

### Automatically Creating LODs (34:30)

* Unreal Engine can do some of the basics for you if you don't create them automatically.

![](<../../../../.gitbook/assets/image (179).png>)





## Further Exploration

* Auto-desk 3D Max is popular software to use.
