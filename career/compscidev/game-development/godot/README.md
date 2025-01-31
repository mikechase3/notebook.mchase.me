# Godot

## Installing

They go from TI-4080 to potato. All of these can be changed on the fly.&#x20;

<figure><img src="../../../.gitbook/assets/CleanShot 2024-08-23 at 09.47.06@2x.png" alt="" width="375"><figcaption></figcaption></figure>

## Recommended Styling

* Use Allman, not K\&R stuff.



<figure><img src="../../../.gitbook/assets/CleanShot 2024-08-23 at 09.49.57@2x.png" alt=""><figcaption></figcaption></figure>

## Editor Window

* Hey - when you get an image & construct a tree", it's called a **SCENE**.&#x20;
* When a group of nodes is collected into a tree, it's called a scene.

## Scenes & Scripts & Signals

* **Scripts** get attached to scenes.
* **export** key word in particular makes it so that a variable defined in the script shows up in the inspector tab.&#x20;
* **Signaling:** it's connected to each node & we see if there's a&#x20;
  * **Callbacks**: this is the software equivalent of a hardware interrupt.
  * We teach freshmen there's an infinite while loop & there's a condition that'll stop it.
  * In practice, there's a polling rate.
  * Every time that process is called, it's going to check a variable.
  * We can use the `awake` node.&#x20;
  * **Signaling** does sideways or up. Why can we directly call things down.&#x20;
    * You don't want to render the entire scene again.
    * When you're working down, you know exactly what was in that scene.
    * You never want your descendants dealing with things outside of the scope. This gives you the braces scop.
* **Dollar Signs** let you access things under you.&#x20;
* This is a _rule of thumb_.  This works 95% of the time.
