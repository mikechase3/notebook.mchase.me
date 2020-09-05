# Annotation: Types and Functions

## Function Return Types



```python
def greeting(name: str) -> str:
    return 'Hello ' + name
```

## Specifying Variable Types

[Source: Python Docs](https://docs.python.org/3/library/typing.html)

```python
from typing import List
Vector = List[float]

def scale(scalar: float, vector: Vector) -> Vector:
    return [scalar * num for num in vector]

# typechecks; a list of floats qualifies as a Vector.
new_vector = scale(2.0, [1.0, -4.2, 5.4])
```



