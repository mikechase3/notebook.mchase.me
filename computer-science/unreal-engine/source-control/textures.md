---
description: 'Purpose: Build better 3D Textures'
---

# Textures

## Textures

### Naming Conventions

* Naming conventions lets others more easily find your owrk.
* `SM_Rock_00` for Statick Mesh for a Rock version 00.
* `T_Rock_00_BC` for Base Color Textures for a Rock version 00.
* `SKM_RockBunch_00` for Skeletal Mesh for Rocks version 00.

### Texture Creation

* Textures resolutions should always be a **power of 2**.
  * 2, 4, 8, 16, 32..
  * It helps with Unreal Engine's built-in optimization.
* Textures do not have to be square, just a power of 2.
  * This way, mip-maps are generated. 
  * You can adjust LOD bias.
  * When the camera is far away, things that aren't a power of 2 will never be scaled down, making it inefficient.

![The texture on the left uses &quot;streaming&quot; and performs well. The texture on the right will not.](../../../.gitbook/assets/image%20%28167%29.png)

### Alpha Information

* Use a separate alpha over an embedded alpha.
* The information stored in an embedded alpha will cost twice as much.
* A separate alpha will let you independently control the alpha and base color separately.

### RGB Mask Packing

* A way to cut down textures and memory used in your project.
* Stores different textures in the red, green, blue, or alpha
  * You will only get black and white information
  * Make sure to disable sRGB.
* Used in VFX

### Saving Textures

* PNG: Embed alpha support
* PSD: Embed ALpha Support
* TGA: Embed Alpha support.
* BMP, Floa, PCX, IPG, EXR, DDS, and HDR are supported.
  * You do not have to fllow the power of 2 in the HDR texture type.

### MIP Mapping

MIP Maps allow you to use less memory when the resolution doesn't matter. For example, if you are super far away from a group of stones, Unreal Engine won't load the full resolution of your stones.

![](../../../.gitbook/assets/image%20%28166%29.png)

* MIP Maps describe a chain of resolutions.

#### MIP Map Filtering

![](../../../.gitbook/assets/image%20%28171%29.png)

* MIP Map filtering lets you sharpen or blur for some specific problems like shimmering.

### Texture Groups

* They help how your textures are going to be used and displayed.
* Texture groups control how big or small textures are going to be shown.
  * Also magnifications among others.
  * Controls the maximum and minimum size.
* If your project is running out of texture memory, you can change the LODBias to reduce memory use with reduced texture sizes.
  * If not, you can you can change the LODBias without having to export, scale, and re-import textures.

### Texture Compression

* Disable sRGB on masks and normal maps.
* Compress without alpha should be disabled.
* Use the default compression settings.

