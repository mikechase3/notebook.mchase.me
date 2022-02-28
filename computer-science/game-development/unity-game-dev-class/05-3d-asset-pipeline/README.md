# 05: 3D Asset Pipeline

### The Game Loop

* You don't want to write loops very often.
* Never run your game inside a loop.
* Instead, you want the game engine to be responding to user input more quickly.
* **Game Post-Mortem:** write an article about what went well and what went poorly. They are one of the most cherished/beloved traditions in gaming history. What goes wrong most often is the Asset Pipeline.
  * **What's an Asset:** Code, 2D images (textures), the manual for your game, the design document, and anything that is worth money/costs money to produce is called an asset.

### Comparing Game Engines

* In the 90s, prof used [Lithtech](https://en.wikipedia.org/wiki/LithTech). The James Bond & Aliens v. Predators were made using it.
* Game Engines are a library of code that you're going to use in your games so you don't have to write everything from scratch.
* The Unreal Engine has really emphasized large outdoor environments without walls.
* People made City Skylines in Unity (a Sim City) game that probably shouldn't have been made in it.&#x20;
* **You choose the game engine** based on what the engine emphasizes and does best and what it supports.
  * For example, what file types for 3D models are supported? How fast will it load?\Export it as a COLLADA model to import with Unity.

## Digital Asset Exchange

### Object Files (`.obj`)

* **Pros:** idk
* **Cons:** doesn't store animation data.
* Before, the OBJ format was the most popular, but it couldn't store any animation data. So typically, an artist would develop a 3D model and save it as a .obj.
* The animator took the `.obj` file, animated it, and saved it as something else.
* Changes needed to be made after animation, all animation data would be lost and the work would have to be re-done.
* In Assassin's Creed, they shipped the game with the wrong assets. Even in a game that was radically successful, they had problems with their asset pipeline.

### Collada (`.dae`)

* Collada stores all the animation data into [a giant XML document](http://cse.csusb.edu/tongyu/courses/cs520/notes/cs520b.pdf) (link takes you to a summary of specs).
* **Cons:** XML is inefficient, turns assets into really large files.
* **Pros:** there's a rule in the schema saying that even if one tool doesn't use some of the information, the program is not allowed to delete it.&#x20;
* **Bottom Line**: use collade files right up until the very end of your game.
* COLLADA format has a `.dae` extension, which stands for "digital asset exchange" manager.

## Example 3D Printing Pipeline

### Blender: Fixing the Units Bug

#### A "Known Problem"

* When SketchUp saves the collade file, it stores the information in the collade file.
* Blender just straight-up ignores this.
* The below subheadings explain how to fix this:

#### Join assets

![](<../../../../.gitbook/assets/Screenshot from 2022-02-28 00-43-49.png>)

* In your asset pipeline, you have to select all the little pieces and smush them together with an operation called `join` in `Object => join`.

#### Access Transform Information

![Press n to access the transform menu.](<../../../../.gitbook/assets/Screenshot from 2022-02-28 00-56-09.png>)



Prof Remarks:

> Prof: Now, I'm not going to teach you blender, but you might be wondering how I got this little popup which is absolutely essential. To do this, you just press `n`. Not `ctrl+n`, not `alt+n` not even `shift+n`. Just `n`. I'm pretty sure the people who created Blender had never used  a computer before because they followed none of the standard conventions for things like keyboard shortcuts. For example, how do you copy/paste things in blender?
>
> Student: Ctrl+C and Ctrl+S
>
> Prof: Wrong. You can't.
>
> Students: appalled.
>
> Prof: I'm not kidding. There's duplicate, which is kind-of like copy/paste.
>
> \<brief pause>&#x20;
>
> Prof: Anyway, so you can see that everything is off by a factor of about 100 here. It's even worse than that&#x20;

#### Converting Inches to Millimetres

![](<../../../../.gitbook/assets/Screenshot from 2022-02-28 00-59-41.png>)



* After you join all your assets into a `group`,&#x20;
* And then I'm going to go through and do 1/25.4 which turns out to be `0.03937`

> By the way - I have fixed that three times. The environment is written in Python. The script that reads in Collada files is a python file. I have fixed that three times and submitted it as a patch, and they have never yet incorporated it.

#### Cleanup (Simplify Model) Tool

![Example Cleanup of Prof's Model](<../../../../.gitbook/assets/Screenshot from 2022-02-28 01-18-52.png>)

* [Decimate](https://docs.blender.org/manual/en/latest/modeling/modifiers/generate/decimate.html) means "reduce by a 10th". he didn't use it, but seemed to suggest it's noteworthy.
* It reduces the complexity of files.
* **Clean Up => Merge by Distance**: it turns out you have a whole lot of coincident points. They're the same points, but they're being stored separately. If you don't merge all the points first, it'll separate the 'shared points' in some of the more buggy operations. It also makes it easier to render.
* **Clean Up => Degenerate Dissolve** some points and faces are 'degenerate' meaning they're not connected to anything.
* **Clean Up => Limited Dissolve**: looks for any triangles that are coplaner. It tries to represent the same thing with less triangles and does that.
* Object => Merge flat: fixes some issues in the end. I'm not sure why/how.

#### Modifiers

Modifiers are just little Python programs that you can run on your model.

**Decimate:** let you sacrifice triangles with lots of control over just how simplified it gets for the sake of simplifying things. It's a brilliant algorithm. _Note: this is a different tool than "Decimate Geometry"_

### CURA

* From blender, we can save a `.stl` model.
* CURA will slice this and turn it into [`gcode`](https://www.steckermachine.com/blog/g-code-and-m-code-programming).&#x20;
* Gcode is a very simple set of commands that moves the print head and tells it how to print the thing. You still have to&#x20;

### Saving Options

* STL: used for 3D Printing, used by CURA.
* Save to a .stl
* Save to a&#x20;

## Pipeline Lessons from a Game Developer

{% hint style="info" %}
See 1:05 in blender.
{% endhint %}

