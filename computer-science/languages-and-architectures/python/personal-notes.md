# Personal Notes

## Naming Conventions

* Variables are lowercase.
* Classes are uppercase.

### Variables

Python likes to name things with underscores, not camelCase.

```python
# Define the release and runtime integer variables below:
year = 1999
runtime_of_crap = 2
```

### Reveal Variable Type

* Use the type\(\) function.
* `print(type(what_is_this_mysterious_variable))`

### Classes

* Class names are upper case.

## Comments

* Type hints are super nice and will be checked by mypy if you install the package.\#This is a Python comment

```python
//This is me being an idiot. #Thank God for syntax highlighting. 
```

* You should also use type hints because it'll help you.

### Built in Types

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

#### Works Cited

I grabbed these from the [Mypy documentation](https://mypy.readthedocs.io/en/stable/cheat_sheet_py3.html). Check it out for more details. 

## Math 🎲

### Exponents

Instead of `Math.pow(3, 2)` we have the `**` operator. 🔥

```python
# This keeps track of how many squares you need in quilts.

# Calculation of squares for:
# 6x6 quilt
print(6**2) #This is 6^2
# 7x7 quilt
print(7**2)
# 8x8 quilt
print(8**2)
# How many squares for 6 people to have 6 quilts each that are 6x6?
print(6**4) #6^4
```

## Strings

### Concatenation

{% hint style="warning" %}
This one always gets me.
{% endhint %}

You can't add non-strings to strings.

```python
print("Hello" + 3) //Error.

print("Hello "+ (str) (3) //Hello 3

--
#Example: source codecademy
birthday_string = "I am "
age = 10
birthday_string_2 = " years old today!"

# Concatenating an integer with strings is possible if we turn the integer into a string first
full_birthday_string = birthday_string + str(age) + birthday_string_2

# Prints "I am 10 years old today!"
print(full_birthday_string)

# If we just want to print an integer 
# we can pass a variable as an argument to 
# print() regardless of whether 
# it is a string.

# This also prints "I am 10 years old today!"
print(birthday_string, age, birthday_string_2)
```

### Multi-Line Strings

It's just like swift.

```python
my_sad_poem = """
Roses are red
Violets are blue.
I like learning python.
But I wish I was doing it with you.

(Didn't realize what I said until after I wrote it)
(Please submit inquires at me@mchase.me)
(I should make a dating website for myself).
(Instead of hello cupid it'll be like hello Mike Chase)

(and I'll be lonely forever)

(But I'll know a lot of Python).

And COBOL. You know how lonely I am?
I know some COBOL. That's how lonely I am.

You know...
Maybe it's time for a girlfriend.

I always say I don't have time for one.
But I also spend time learning COBOL.

I've never been so useful and useless at the same time.

Am I projecting? Sorry.
"""
```

### Eval\(\)

* Use eval\(\) to have python evaluate a regular expression.

## Functions

### Returning Multiple Values

We can return multiple values. It's so amazing!

```python
def get_boundaries(target, margin):
  low_limit = target-margin
  high_limit = margin+target
  return low_limit, high_limit

low_limit, high_limit = get_boundaries(100, 20)
```

### Default Values

* When specifying parameters, you can assign default values.
* Here, if nothing is passed, `num_repeats` is assigned to 10 by default

```python
def repeat_stuff(stuff, num_repeats=10):
  return stuff*num_repeats
repeat_stuff("Row ", 3) #repeats 3 times because we specified that. 
lyrics = repeat_stuff("Row ", 3) + "Your Boat. "
song = repeat_stuff(lyrics)

print(song) #Repeats 10 times because it uses the default value.
```

## Expressions

### Booleans

{% hint style="warning" %}
Use capital letters for `True` and `False`. 
{% endhint %}

```python
statement_one = True

statement_two = False

statement_three = True
```

## Error Handling

* You "raise" errors instead of throwing them.
* You except errors instead of catching them.
* Trying is still the same as Java.

```python
def raises_value_error():
  try:
    raise ValueError
  except ValueError:
    print("You raised a ValueError!")
raises_value_error()
```

## Data Types

[Works cited: w3schools.com: Python Data Types](https://www.w3schools.com/python/python_datatypes.asp)

| Example | Data Type | Try it |
| :--- | :--- | :--- |
| x = str\("Hello World"\) | str | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_str2) |
| x = int\(20\) | int | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_int2) |
| x = float\(20.5\) | float | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_float2) |
| x = complex\(1j\) | complex | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_complex2) |
| x = list\(\("apple", "banana", "cherry"\)\) | list | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_list2) |
| x = tuple\(\("apple", "banana", "cherry"\)\) | tuple | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_tuple2) |
| x = range\(6\) | range | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_range2) |
| x = dict\(name="John", age=36\) | dict | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_dict2) |
| x = set\(\("apple", "banana", "cherry"\)\) | set | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_set2) |
| x = frozenset\(\("apple", "banana", "cherry"\)\) | frozenset | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_frozenset2) |
| x = bool\(5\) | bool | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_bool2) |
| x = bytes\(5\) | bytes | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_bytes2) |
| x = bytearray\(5\) | bytearray | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_bytearray2) |
| x = memoryview\(bytes\(5\)\) | memoryview | Try it » |

### Lists

| Function | Example |
| :--- | :--- |
| Declare a list | my\_list:  |


