# Exporting and Importing

## Exporting a Static Meshes from a DCC App

* Uses the FBX
* Enable: Smoothing groups, Triangulate, and Preserve Edge Orientation.
* Enable Animations in the setting if you have animations for a skeletal mesh.
* Disable everything else.

## Exporting Skeletal Meshes

* Export using the FBX file fromat
* Enable smoothing groups, triangulate, and preserve edge orientation.
* Enable Animation
* Check Deformations & Skins _\(or Morphs if you're exporting Morph targets\)_.

## 3D Mesh Import

![](../../../.gitbook/assets/image%20%28201%29.png)

* Use the Import button in the content browser.
* You may also drag & drop

## 3D Mesh Import Options

![](../../../.gitbook/assets/image%20%28199%29.png)

* The default settings are typically good enough.
* The l_ight UVs_ take the information and tries to lay it out so it all is between 0-1 UV space. Oftentimes, the results are not that great. You or the artist can set it up via DCC and import it that way. Pick what works best for your workflow.
* _Transform Vertex to Absolute:_ if this gets turned off, all of the collision points will be zeroed out and set to \(0,0,0\)
* _Disable Import Materials_: it's setup via Unreal 4. Makes sure that no other crap is used when testing. 
* _Disable Import Textures_: it's setup via Unreal 4. Makes sure no other crap is used when testing.
* _Toggle Skeletal Mesh_ as needed.,

## Re-Importing Assets

![Dragging and Dropping is Easiest](../../../.gitbook/assets/image%20%28200%29.png)

* Unreal Engine will automatically replace that asset and use it wherever it's been used before.

![](../../../.gitbook/assets/image%20%28198%29.png)

## Auto Re-Import

{% hint style="success" %}
This is useful!
{% endhint %}

This is useful if you keep files like Dropbox and sync between computers. 

### Specify a folder to listen to

![](../../../.gitbook/assets/image%20%28204%29.png)

* Got to edit -&gt; Editor preferences.
* View "Directories to monitor" and select shit.
* Click "Map Directory To" so that when things change, Unreal Engine will monitor changes.

## Full Scene Import From FBX



The Full-Scene FBX does a great job. 



## Exporting Assets from UE4

{% hint style="info" %}
Asset migration is the best if you have to move stuff from one project to another.
{% endhint %}

![](../../../.gitbook/assets/image%20%28203%29.png)

* You can export almost everything you imported into UE4.
* You can also migrate assets. 
* This works for textures, static meshes, and skeletal meshes

### Asset Migration

![](../../../.gitbook/assets/image%20%28202%29.png)

* In addition to the asset, this exports all the other assets that are associated with that mesh.

