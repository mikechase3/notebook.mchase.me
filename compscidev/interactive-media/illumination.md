# Illumination

## Illumination and Shading

* **Illumination** computes the color of each vertex.
* **Shading** computes the whole surface color. It's an interpolation process.
* This is a mdoel of how light interacts with materials.
* We discuss the common, heuristic shading models: flat, gouraud, and phong.
* Not physically based: work well in practice & are common on most graphics boards.

> **Physically based** rendering refers to a rendering approach that attempts to **simulate real-world light interactions** with materials accurately. It takes into account physical **properties such as the reflectance, transmittance, and distribution of light on different surfaces.**
>
> On the other hand, the shading models mentioned (flat, Gouraud, and Phong) are common heuristic models used in computer graphics that do not strictly adhere to physical accuracy. They approximate the lighting and shading effects on a surface in a **simplified manner**. Although these models may not accurately represent the physical behavior of light, they have been widely adopted and provide effective results in practice. Most graphics hardware and software include support for these shading models, making them common choices for real-time rendering applications.

## Diffuse Objects

> "Illumination and shading in computer graphics involve simulating how light interacts with materials. While physically based rendering aims for accurate simulations, there are commonly used non-physically based shading models: flat, Gouraud, and Phong.
>
> Flat shading computes the color of each vertex, resulting in a constant color across each polygon. Gouraud shading computes the color at each vertex based on the lighting conditions, then interpolates the colors across the polygon. Phong shading computes the surface color at each pixel by interpolating the vertex normals and using a more complex lighting calculation.
>
> These shading models, though not physically accurate, are widely used and implemented in most graphics hardware and software due to their practical effectiveness."
>
> \-Generative Pretrained Transformer

* For Matte objects swith no shininess
* Diffuse/Matte objects are called Lambertian
* Shading does not vary with viewpoint
  * Example: a piece of paper, chalk board
* Reflect light is scattered equally in all directions.

The final color of the vertex is diffuse(V) -> rgb1, ambient(V) -> rgb2, and phong(V)->rgb3. Each of these return a color and when we sum them up we compute the final color.&#x20;

{% hint style="info" %}
Today, we're focusing on diffuse only. Next lecture we'll do ambient and phong.
{% endhint %}

### Lambertian Surfaces

* Obeys Lambert's Law (from Physics)
* This means the color `c` of a surface is proportional to the _cosine of the angle_ between the surface normal & the direction of the light source.
* The color, c, of a Lambertian surface is proportional to the cosine of the angle between the surface normal, N, and the direction of the light source, L.

$$
c = k \cdot \cos(\theta)
$$

* (c) is the color of the surface
* (k) is a constant, representing the surface reflectance and light intensity
* (\theta) is the angle between the surface normal, N, and the direction of the light source, L
* `c` or Color here referes to the intensity & brightness of the surface, not the specific color values

> The equation "diffuse(V) = C.v \* C.l \* cos(\theta)" represents the diffuse reflection component for determining the color of a point, V, on a surface. Let's break down the components of this equation:
>
> * "diffuse(V)": This represents the diffuse reflection component of the point, V. Diffuse reflection refers to the scattering of light in various directions upon hitting a rough or matte surface.
> * "C.v": This represents the color of the surface at point V. It refers to the material's inherent color or reflectance properties.
> * "C.l": This represents the color of the light source. Different light sources can have different colors and intensities.
> * "cos(\theta)": This represents the cosine of the angle between the surface normal (a vector perpendicular to the surface) and the direction of the light source. The angle, (\theta), is important because it determines how much of the light is incident on the surface and how much is absorbed or reflected depending on the surface's orientation.
>
> Multiplying "C.v", "C.l", and "cos(\theta)" together combines the colors of the surface, light source, and the part of the light that is hitting the surface to determine the contribution of the diffuse reflection component to the overall color of point V.
>
> Essentially, this equation represents the interaction between the surface color, the color and intensity of the light source, and the angle at which light hits the surface, to calculate the diffuse reflection component responsible for determining the final color of the point V on the surface.
