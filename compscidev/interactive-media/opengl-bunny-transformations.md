---
description: Mix of python & C++.
---

# OpenGL Bunny Transformations



{% embed url="https://github.com/mikechase3/OpenGLCVBunnyPyEdition" %}

{% embed url="https://quizlet.com/890677132/opencv-f24_cps465-interactive-media-shen-flash-cards/" %}

{% embed url="https://quizlet.com/891983741/opengl-interactive-media-cps592-cps-465ish-flash-cards/?funnelUUID=91901382-c74d-4c94-aaff-282158607604" %}

## OpenGL Bunny Transformations

This project was initially intended to be implemented in C++, but due to complications with OpenCV and OpenGL installations, it was decided to use Python instead. Python's virtual environments provide a more manageable solution. For those interested in the C++ attempt, refer to the OpenGL Setup where OpenGL setup for Mac is discussed.

## Approach

The approach to this project is divided into several steps:

1. **Data Import**: The data from an .obj file is imported. The file is in plain text, so the String.split() and .startswith() methods, which are part of Python strings, are used for parsing. This process is encapsulated in a Data class.
2. **3D Object Display:** The 3D object is displayed using an OpenGL Python wrapper. The glColor3f() function is used to set colors, and glBegin() and glEnd() denote the beginnings and ends of glVertex()s to be shaded. A keyboard callback function is also implemented to toggle between solid and mesh views.
3. **Translation/Rotation Methods**: These methods are built without using OpenGL provided commands. Instead, OpenCV's Mat class is used to create matrices and homogeneous coordinates. These matrices are then multiplied to translate/rotate, and the display is updated using gluePostRedisplay() after mouse/keyboard actions.

### Parsing An `.obj` File to Extract Vertexes & Faces

After some deliberation I decided to wrap everything into a class like this:

```python

class Data:
    """
    Provides a way to interface to represent vertex data.
    Can be used by other libraries easily so i can use it between OpenCV/GL/NumPy if necessary.
    """
    def __init__(self, filename=None):
        self.vertices = []
        self.faces = []
        if filename:
            # Read the file
            with open(filename, 'r') as f:
              // Adds stuff to files.

    def __repr__(self):
        s = []
        // Adds stuff to that `s` list and prints it out.

    def __iter__(self):
        return iter(self.vertices + self.faces)

    # Getters/Adders for our data.
    # It's also an interactive interface for debugging.
    def add_vertex(self, vertex):
        if len(vertex) != 3:
            raise ValueError("A vertex must have three coordinates.")
        self.vertices.append(vertex)

    def add_face(self, face):
        if len(face) != 3:
            raise ValueError("A face must have three indices.")
        self.faces.append(face)

    def interactive_add_vertex(self):
        # An Interactive version...

    def interactive_add_face(self):
        face = input("Enter the indices for the face, separated by spaces: ").split()
        try:
            face = [int(x) for x in face]
            if len(face) != 3:
                raise ValueError("A face must have three indices.")
            self.add_face(face)
        except ValueError as e:
            print(f"Invalid input: {e}")
```

I considered using NumPy arrays, but since OpenCV is really a matrix calculator & Dr. Shen mentioned that I'm going to try & do my tranlsations/rotations with that. If I multiply by a 4x4 matrix, I can rotate 3D objects. I'll dive more into the math later.

### Displaying Vertexes and Faces with OpenGL

Next up, I'm going to create a class to encalsulate the bunny's vertexes and faces. I asked a large language model how to keep myself organized since I've never designed such a task before and it told me I should:

1. Create a bunny class
2. Use composition
3. Define rendering methodsd
4. Implement transformation methods
5. Add interaction methods
6. Provided initialization.

Therefore, I created a `Bunny` class in my script and wrote a `def __init__()` method which covers the first and last element.

I forgot what composition so I asked the LLM if that meant the same as inheritance. I'm not sure what I'd want to inherit from, but it turns out that a composition holds an instance of another class & deligates some behaviors back to the existing class. Therefore, it's not really inheritance but really just accessing public elements/methods in another class. In Python, there's no such things as public/private stuff that I know of in the builtins, so this is probably a sloppy way of doing things. The LLM says it's loosly coupled and a good practice so let's go with that and maybe I'll see why it's nice as I keep implementing it this way.

```python
class Bunny:
    def __init__(self, filename: str):
        self.data = Data(filename)

    def render(self):
        # Implement rendering logic using OpenGL
        pass

    def translate(self, x: float, y: float, z: float):
        # Implement translation logic
        pass

    def rotate(self, angle: float, axis: List[float]):
        # Implement rotation logic
        pass

    def scale(self, factor: float):
        # Implement scaling logic
        pass

    def handle_interaction(self):
        # Implement interaction handling logic
        pass
```

### Rotating with Quaternions & Translations

{% embed url="https://eater.net/quaternions" %}

Combine with this

## OpenGL Bunny Transformations

This project was initially intended to be implemented in C++, but due to complications with OpenCV and OpenGL installations, it was decided to use Python instead. Python's virtual environments provide a more manageable solution. For those interested in the C++ attempt, refer to the [OpenGL Setup](opengl-setup.md) where OpenGL setup for Mac is discussed.

### Approach

The approach to this project is divided into several steps:

1. **Data Import**: The data from an `.obj` file is imported. The file is in plain text, so the `String.split()` and `.startswith()` methods, which are part of Python strings, are used for parsing. This process is encapsulated in a Data class.
2. **3D Object Display**: The 3D object is displayed using an OpenGL Python wrapper. The `glColor3f()` function is used to set colors, and `glBegin()` and `glEnd()` denote the beginnings and ends of `glVertex()`s to be shaded. A keyboard callback function is also implemented to toggle between solid and mesh views.
3. **Translation/Rotation Methods**: These methods are built without using OpenGL provided commands. Instead, OpenCV's `Mat` class is used to create matrices and homogeneous coordinates. These matrices are then multiplied to translate/rotate, and the display is updated using `gluePostRedisplay()` after mouse/keyboard actions.

The progress so far is as follows:

* [x] Import data from file.
* [x] Display the bunny object on screen.
* [ ] Implement the ability to switch between solid & mesh views.
* [ ] Use OpenCV for matrix operations.
* [ ] Accurately translate/rotate the bunny object.
* [ ] Integrate basic settings for display size & perspective projection.
* [ ] Control mouse movement speed by appropriately scaling pixel changes to the rotation/translation in 3D space.

### Parsing An `.obj` File to Extract Vertices & Faces

The decision was made to encapsulate the parsing process into a class, `Data`. This class provides an interface to represent vertex data and can be used by other libraries such as OpenCV, GL, and NumPy if necessary.

The `Data` class includes methods for adding vertices and faces, both interactively and non-interactively cause I thought that'd be useful even though I've barely used it. It also includes a `__repr__` method for a string representation of the object, and a `__iter__` method to make the object iterable. Got Copilot to write the Unit Tests.

### Displaying Vertices and Faces with OpenGL

A `Bunny` class was created to encapsulate the bunny's vertices and faces. This class uses composition to hold an instance of the `Data` class and delegates some behaviors back to it. The `Bunny` class includes methods for rendering, translating, rotating, scaling, and handling interactions.

#### Rotating with Quaternions & Translations

For more information on rotating with quaternions and translations, refer to this [resource](https://eater.net/quaternions).

#### Naive Approaches

## Ability to Switch

Placeholders.
