# 02: Mesh Editing

**Applying Scales**: Object => Apply => Scale to make your new object's scale have `{1,1,1}`.

### Smooth Shading

![](<../../.gitbook/assets/image (643).png>)

* `<Select Object> => Context Menu =>  Shade Smooth`: You can make objects appear to be smooth without affecting it's geometry.&#x20;
* You can confirm whether something is high or low poly by looking at the _silhouette_.

![Search Results: Google / Oxford Languages ©2022 ](<../../.gitbook/assets/image (653).png>)

### Subdivision Surface

Notice that even though we turned on smooth surface, the silhouette is still jagged:

![Jagged silhouette on donut](<../../.gitbook/assets/image (646).png>)

The "subsurf" modifier adds exponential amounts of detail. This makes it look nicer, but slows down render times.

![Modifier Panel => Add => Subdivision Surface](<../../.gitbook/assets/image (658).png>)

To fix the rough silhouette, you'll use the `subdivision surface` tool. This is in the `modifier panel` ![](<../../.gitbook/assets/image (656).png>)

![](<../../.gitbook/assets/image (648).png>)

## Changing Display Modifier Visibility

* Modifiers make blender slow.
* To temporarily skip rendering:
  * In viewport: left button
  * In renderer: right camera-looking button.
* Press `1` to edit vertices individually.
* You can drag out each vertex individually
* You can select multiple vertices by holding `shift`.

## Proportional Editing ![](<../../.gitbook/assets/image (651).png>)

### Edit Mode #`1`

![You can control the proportion between each vertex. Default is smooth.](<../../.gitbook/assets/image (638).png>)

* There are several ways to manipulate the&#x20;
* To edit the influence radius, hold the left mouse button down while performing the transform operation and scroll up/down on the mouse.

{% embed url="https://blender.stackexchange.com/questions/255660/how-to-change-radius-for-proportional-editing-using-industry-compatible-keyboard/255662#255662" %}
Spent an hour figuring this out :turtle:
{% endembed %}

You can also proportion size here:

![](<../../.gitbook/assets/image (654).png>)

