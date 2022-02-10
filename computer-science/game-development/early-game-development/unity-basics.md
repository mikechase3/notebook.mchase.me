---
description: Crappy Unity Games
---

# Unity Basics

## Terminology

| Term                                                                | Definition                                       | Why                                                                                                                              |
| ------------------------------------------------------------------- | ------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------- |
| Mesh                                                                | Any set of triangles that get grouped together.  | Graphics cards are good at addition, subtraction, and multiplication of points, lines, and triangles. Unless you have a quad GPU |
| Ray Tracing                                                         |                                                  | Uses so much computational processing. We can get an approximation for phong shading.                                            |
| [Flat Shading](https://en.wikipedia.org/wiki/Shading#Flat\_shading) |                                                  | Works for 1 color.                                                                                                               |
| [Phong Shading](https://en.wikipedia.org/wiki/Phong\_shading)       |                                                  | It's really fast.                                                                                                                |
| Thrustem                                                            | A 3D pyramid shape showing what the camera sees. |                                                                                                                                  |

## Build Your Own Renderer

* The render runs on the graphics processor.
* Each game object can have it's own renderer.
* [https://learn.unity.com/tutorial/introduction-to-the-sprite-renderer#5f775a82edbc2a3309683d21](https://learn.unity.com/tutorial/introduction-to-the-sprite-renderer#5f775a82edbc2a3309683d21)

## Camera

* Where the camera is, is `0, 0, 0`. The center of the camera lens is the center of a 2D plane.
* The camera doesn't move. You actually are moving the whole world with respect to the camera.
* **GameObject-> Align with view** to&#x20;
