# Illumination w/ Diffuse, Ambience, Phong

## Illumination and Shading

* **Illumination** computes the color of each vertex.
* **Shading** computes the whole surface color. It's an interpolation process.
* This is a model of how light interacts with materials.
* We discuss the common, heuristic shading models: flat, gouraud, and phong.
* Not physically based: work well in practice & are common on most graphics boards.

> **Physically based** rendering refers to a rendering approach that attempts to **simulate real-world light interactions** with materials accurately. It takes into account physical **properties such as the reflectance, transmittance, and distribution of light on different surfaces.**
>
> On the other hand, the shading models mentioned (flat, Gouraud, and Phong) are common heuristic models used in computer graphics that do not strictly adhere to physical accuracy. They approximate the lighting and shading effects on a surface in a **simplified manner**. Although these models may not accurately represent the physical behavior of light, they have been widely adopted and provide effective results in practice. Most graphics hardware and software include support for these shading models, making them common choices for real-time rendering applications.

<figure><img src="../../.gitbook/assets/image (703).png" alt=""><figcaption></figcaption></figure>

## Diffuse Objects

Diffusion is how light direction interacts with surface normal. The vector starts from V pointing towards the light source.

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
>
>

### Equations for Defining a Lighting Model

<figure><img src="../../.gitbook/assets/image (705).png" alt=""><figcaption></figcaption></figure>

### Calculating Dot Products of Normalized Vectors

<figure><img src="../../.gitbook/assets/image (706).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (712).png" alt=""><figcaption></figcaption></figure>

## Ambience

<figure><img src="../../.gitbook/assets/image (715).png" alt=""><figcaption></figcaption></figure>

## Phong

<figure><img src="../../.gitbook/assets/image (714).png" alt=""><figcaption></figcaption></figure>

### Phong Illumination

* Adding two vectors forms the resultant vector.
* Subtracting a vector is the same as adding the negative of the vector. This flips the direction of the vector.
* Multiplying a vector by a number scales the vector. The direction stays the same but the magnitude is multiplied by the number.

<figure><img src="../../.gitbook/assets/image (716).png" alt=""><figcaption></figcaption></figure>

### Components of Phong

* Ambient light: This provides a general low-level of illumination.
* Diffuse light: This determines how much ambient light is reflected by the surface.
* Specular light: This creates highlights on shiny surfaces.

<figure><img src="../../.gitbook/assets/image (719).png" alt=""><figcaption></figcaption></figure>

#### Finding s

$$
\vec{s} = \vec{l} - \vec{m} \implies \vec{l} - \vec{n} \cdot(\vec{n} \cdot \vec{l})
$$

So now we pull from the $$\vec{r}$$ and sub it into this somehow:

<figure><img src="../../.gitbook/assets/image (720).png" alt="" width="188"><figcaption></figcaption></figure>

This last line represents our final result for `def compute_reflection`.

## Quiz

The problem given is that there is a point P(300, 240, 200) in a 3D space and its color is RGB(0.1, 0.5, 0.1). There is only one light source in the capturing environment, which locates at (300, 270, 190). The light color is RGB (0.9, 0.9, 0.9). We also know the point P is from a surface with its normal is (0, 1, 0). We need to find the final color of this point, assuming the specular color is RGB(1.0, 1.0, 1.0), and the exponent is 5.

The solution involves using the illumination equation which models three components: ambient, diffuse reflections, and specular reflections.

<figure><img src="../../.gitbook/assets/image (721).png" alt=""><figcaption></figcaption></figure>

## Programming Tips

### Normalizing

<figure><img src="../../.gitbook/assets/image (722).png" alt=""><figcaption></figcaption></figure>

Then make a calculate reflected vector part:

<figure><img src="../../.gitbook/assets/image (723).png" alt=""><figcaption></figcaption></figure>

Not sure what we're doing now; here's what he wrote.

<figure><img src="../../.gitbook/assets/image (725).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/CleanShot 2024-04-18 at 12.53.52@2x.png" alt=""><figcaption></figcaption></figure>

It's better if we show something like this visually. Multiply down the diagonals:

<figure><img src="../../.gitbook/assets/image (727).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (729).png" alt=""><figcaption></figcaption></figure>

### Calculating Normal Vectors

<figure><img src="../../.gitbook/assets/image (730).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (733).png" alt=""><figcaption></figcaption></figure>

## Multiple Lighting Sources

How do we reflect several lights? We'd acount for additional lights by computing the dot products with each light & sum them up.

<figure><img src="../../.gitbook/assets/image (734).png" alt=""><figcaption></figcaption></figure>

### Dealing with Shadows

* Goal: If a point is visible from a light, illuminate it. If not, don't.
* Introduce a visibility term S\_i for each point, light pair.&#x20;
* $$S_i$$=0 if the point isn't visible. S\_i = 1 if it is visible.

$$
c=c_rc_a + \sum_{i=1}^nS_ic_{l_i}(c_r max(0, n \cdot l_i) + c_p \texttt{ max} (0,v \cdot r_i)^p)
$$

Make sure you clamp all colors at 1.&#x20;

### Computing Normal for Multiple Connected Vertexes?

Let's say you have a triangle. How do you compute the normal? We can generate two vectors & find the normal. But then, that normal- it's the safe normal for this triangle. It shares the same number?&#x20;

* For each vertex, find all polygons that contain the vertex. For vertex v\_0 these are polygons p\_1, p\_2, p\_3, and p\_4.
* Take the average of the polygon normals.
* This gives the normal n\_v0 at the vertex.
* Repeat this for each vertex.&#x20;

So this is a new question, what if we have multiple faces? Ps are the faces, but if four faces share a point. Then sum up the vectors I think.

For example, what is the normal of n`* \vec(v_4)` and `n(v_2)`.&#x20;

### ![](<../../.gitbook/assets/image (737).png>)

###
