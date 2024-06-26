# Doc Conventions, PEP8, RSTs

{% embed url="https://www.python.org/dev/peps/pep-0008/#id34" %}

## Purpose

* Explain how to write code that's clean & easy to read.
* Below is a summary of the [PEP 8 Style Guide](https://www.python.org/dev/peps/pep-0008/).
* Write all python proejcts as if they were written by the same programmer.

## PEP

* Stands for _**Python Enhancement Proposal**_
* The most important for beginners is the informational PEP.
* PEPs describe commonly accepted guidelines.

### Length of Lines

* Don't use more than 79 lines.
* Shorter lines look better in code editors.

### Avoid Extra Spaces

* Avoid spaces in parentheses.

### Quotes

* You can use single or double quotes to define strings.
* Be consistent.
* If a string contains single or double quotes, you should use the other one to avoid backslashes.

#### Example

Good: `print("It's a good string!")`

Bad: `print('It\'s a bad string!')`

### Comments

* There should be _**one space after the hash mark**_
* There should be _**two spaces between code and hash marks**_.
* Indent your code to the same level as the statement it explains.
* Triple quotes are used for reserved for documentation strings (docstrings) for short.

```python
"""
    BAD.
    This is reserved for for documentation. Don't use these
    when you need to make comments.
"""

# Instead
# If you need to make short multi-line comments
# Use lots of hash symbols.
//Remember, don't use these for comments! #Syntax highlighter says "BAD!"
```



### [Docstrings](https://www.programiz.com/python-programming/docstrings) (See Programiz)

#### Example 1: Docstrings

```
def square(n):
    '''Takes in a number n, returns the square of n'''
    return n**2
```

Here, the string literal:

```
'''Takes in a number n, returns the square of n'''
```

Inside the triple quotation marks is the **docstring** of the function `square()` as it appears right after its definition.

**Note:** We can also use triple `"""` quotations to create docstrings.

#### Python \_\_doc\_\_ attribute

Whenever string literals are present just after the definition of a function, module, class or method, they are associated with the object as their `__doc__` attribute. We can later use this attribute to retrieve this docstring.

_Example 2: Printing docstring_

```
def square(n):
    '''Takes in a number n, returns the square of n'''
    return n**2

print(square.__doc__)
```

**Output**

```
Takes in a number n, returns the square of n
```

Here, the documentation of our `square()` function can be accessed using the `__doc__` attribute.

#### Using the help() Function for Docstrings

We can also use the `help()` function to read the docstrings associated with various objects.

_Example 7: Read Docstrings with the help() function:_

We can use the `help()` function on the class `Person` in **Example 6** as:

```
help(Person)
```

## Type Hints

### Type Hints for Built in Types

```python
from typing import List, Set, Dict, Tuple, Optional

# For simple built-in types, just use the name of the type
x: int = 1
x: float = 1.0
x: bool = True
x: str = "test"
x: bytes = b"test"

# For collections, the name of the type is capitalized, and the
# name of the type inside the collection is in brackets
x: List[int] = [1]
x: Set[int] = {6, 7}

# Same as above, but with type comment syntax
x = [1]  # type: List[int]

# For mappings, we need the types of both keys and values
x: Dict[str, float] = {'field': 2.0}

# For tuples of fixed size, we specify the types of all the elements
x: Tuple[int, str, float] = (3, "yes", 7.5)

# For tuples of variable size, we use one type and ellipsis
x: Tuple[int, ...] = (1, 2, 3)

# Use Optional[] for values that could be None
x: Optional[str] = some_function()
# Mypy understands a value can't be None in an if-statement
if x is not None:
    print(x.upper())
# If a value can never be None due to some invariants, use an assert
assert x is not None
print(x.upper())
```

### Type Hints & Functions

```python
from typing import Callable, Iterator, Union, Optional, List

# This is how you annotate a function definition
def stringify(num: int) -> str:
    return str(num)

# And here's how you specify multiple arguments
def plus(num1: int, num2: int) -> int:
    return num1 + num2

# Add default value for an argument after the type annotation
def f(num1: int, my_float: float = 3.5) -> float:
    return num1 + my_float

# This is how you annotate a callable (function) value
x: Callable[[int, float], float] = f

# A generator function that yields ints is secretly just a function that
# returns an iterator of ints, so that's how we annotate it
def g(n: int) -> Iterator[int]:
    i = 0
    while i < n:
        yield i
        i += 1

# You can of course split a function annotation over multiple lines
def send_email(address: Union[str, List[str]],
               sender: str,
               cc: Optional[List[str]],
               bcc: Optional[List[str]],
               subject='',
               body: Optional[List[str]] = None
               ) -> bool:
    ...

# An argument can be declared positional-only by giving it a name
# starting with two underscores:
def quux(__x: int) -> None:
    pass

quux(3)  # Fine
quux(__x=3)  # Error
```

## RST Files (versus .markdown)

* According to Alan Moore & others, RSTs are the preferred format instead of Markdown

#### Works Cited

I grabbed these from the [Mypy documentation](https://mypy.readthedocs.io/en/stable/cheat\_sheet\_py3.html). Check it out for more details.
