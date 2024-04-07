# OpenGL Bunny Transformations

We're supposed to implement this in C++, but life is too short and installing OpenCV breaks OpenGL so I wrote this in Python where I can use virtual environments.  If you're interested in seeing my C++ attempt, see [OpenGL Setup](opengl-setup.md) where I get GL for mac setup.

## Approach

1. Import the data from an `.obj` file. Since it's in plain text, we'll parse them using `String.split()` and `.startswith()` methods I think are part of [python strings.](../git/languages-and-architectures/python/corepython/strings/) I wrapped all this into a Data class.
2. Display the 3D object through an OpenGL python wrapper. I'll use `glColor3f()` to set colors and `glBegin()` and `glEnd()` to denote the beginnings/ends of `glVertex()`s to be shaded. I'll also implement a keyboard callback function to toggle between solid & mesh views if I can. Initially without illumination/shading it'll look flat but we'll fix that too.
3. Build translation/rotation methods without using OpenGL provided commands. Instead, we'll use OpenCV's `Mat` clas to create matrices & homogenous (uniform) coordinates. We'll multiply to translate/rotate matrices and ensure proper updating of the display using `gluePostRedisplay()` after mouse/keyboard actions.&#x20;

* [ ] Successfully display the bunny object on screen
* [ ] Implemdnt the ability to switch between solid & mesh views
* [ ] Use OpenCV for matrix operations
* [ ] Accurately translate/rotate the bunny object.
* [ ] Consider integrating basic settings for display size & perspective projection
* [ ] Control mouse movement speed by appropriately scaling pixel changes to the rotation/translation in 3D space.

## Parsing An `.obj` File to Extract Vertexes & Faces

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

## Displaying Vertexes and Faces with OpenGL

Next up, I'm going to create a class to encalsulate the bunny's vertexes and faces. I asked a large language model how to keep myself organized since I've never designed such a task before and it told me I should:

1. Create a bunny class
2. Use composition
3. Define rendering methodsd
4. Implement transformation methods
5. Add interaction methods
6. Provided initialization.&#x20;

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



## Rotating with Quaternions & Translations

{% embed url="https://eater.net/quaternions" %}

