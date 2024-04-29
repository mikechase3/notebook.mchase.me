# OpenGL Bunny Shading

Our task:

* [ ] Finish the block "else if" in `functions.h` around lines 130-146.
* [ ] Implement the equation:

$$
color(v) = C_rC_l max(\vec{l} \cdot \vec{n}, 0)  + C_rC_a + C_l C_p \cdot max(\vec{r} \vec{v}, 0)
$$

.

## **Assignment Summary**

You are tasked with creating a realistic 3D rendering of a bunny object using different illumination models to simulate various material appearances. Key components of the assignment include:

* **Understanding Illumination Models:** Familiarize yourself with the diffuse, ambient, and Phong illumination models and how they influence light and material interaction.
* **Shading Implementation:** Apply flat shading, where each triangle on the bunny object has a consistent color. Compute colors based on the chosen illumination models
* **Material Simulation:** Create different material effects (plaster, china, gold) by modifying the parameters of the illumination models, particularly the Phong parameters.

**Goals**

1. **Data Structure Proficiency:**
   * Refine your `data.h` file to ensure correct cross-product calculations, which are essential for determining surface normals.
   * Accurately compute view, light, and normal vectors for correct lighting representation.
2. **Illumination Model Implementation:**
   * Implement the ambient illumination model in `functions.h`. Pay attention to its simple behavior as a constant light contribution.
   * In `functions.h`, precisely implement the diffuse illumination model, ensuring it correctly considers the angle between the surface normal and light direction.
   * Carefully implement the Phong illumination model in `functions.h`, as it's the most complex. Ensure it accurately simulates specular highlights.
3. **Visual Output and Control:**
   * Successfully implement keyboard controls:
     * "0": Display the bunny with no shading.
     * "1": Display with diffuse and ambient terms (plaster-like look).
     * "2": Display with all three illumination terms (simulating materials like china or metal).
     * "M" or "m": Display only the mesh lines.

**Additional Tips**

* **Start Early:** Break down the assignment into smaller tasks, and begin with the easier components to build momentum.
* **Test Incrementally:** As you implement each illumination model component, test and visualize the results immediately to catch errors quickly.
* **Experiment with Material Parameters:** Play with different values within the Phong model to achieve diverse and interesting material effects.



