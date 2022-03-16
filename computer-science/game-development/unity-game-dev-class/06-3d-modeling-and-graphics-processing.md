# 06: 3D Modeling & Graphics Processing

## Fused Multiply Add

{% embed url="https://www.quora.com/How-does-Fused-Multiply-Add-FMA-work-and-what-is-its-importance-in-computing" %}

* Graphics card are really good at multiplying/adding.
* ****[**Fused Multiply-Add**](https://www.quora.com/How-does-Fused-Multiply-Add-FMA-work-and-what-is-its-importance-in-computing)**:** (A+B)\*(C+D)
  * Important for computing dot products.

### Specular and Diffuse Reflection

* **Diffuse** lighting comes from the light to the surface.
* **Specular** light reflects only certain wavelengths off the surface.

Checkout this tool:

{% embed url="https://www.olympus-lifescience.com/en/microscope-resource/primer/java/reflection/specular#:~:text=The%20reflection%20of%20light%20can,as%20illustrated%20in%20Figure%201)." %}

### Dot and Cross Products

![](<../../../.gitbook/assets/image (659).png>)

* Dot product of two vectors gives you a fused multiply add.
* A vector is a direction and a magnitude.
* Dot product is the percentage of one vector in another vector.

## Lighting

{% embed url="https://learnopengl.com/Lighting/Basic-Lighting" %}

* **Shaders**: programs that run on the GPU.
* Ambient light: comes from all directions
* Diffuse light: comes in parallel rays
* Specular: light reflecting off shiny things.

### Vectors

* You can express a light with two vectors of an object an a light source.&#x20;
* The light is the cross-product between the light and the object.
* If the angle between the vector and surface is 90 degrees, there's no light. If the ray and light is perpendicular, more light is shown.

### Smooth Shading

{% embed url="https://courses.washington.edu/arch481/1.Tapestry%20Reader/4.Rendering/4.Shading/3.Smoothing.html" %}

### Normal Maps

![](<../../../.gitbook/assets/image (643).png>)

* The red, green, and blue colors correspond to the x, y, and z&#x20;
* It changes the simulation of light or how it bounces off.&#x20;
* [Per-pixel lighting ](https://en.wikipedia.org/wiki/Per-pixel\_lighting#:\~:text=Then%2C%20the%20data%20is%20passed,scene%20on%20the%20pixel%20level.)is the standard now.

### Decimating

The decimate tool takes a complex shape.&#x20;

* Artists like to have 5M vertices
* You don't want to run this.
* Calculate the lighting map from the complex model.
* Load the decimated model.
* This has the effect of making a model have very few triangles, but look complex through their lighting map.&#x20;

##
