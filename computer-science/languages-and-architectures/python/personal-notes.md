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

## Documentation & Type Hints

### Comments

```python
//This is me being an idiot. #Thank God for syntax highlighting. 
```

### [Docstrings](https://www.programiz.com/python-programming/docstrings) \(See Programiz\)

#### Example 1: Docstrings

```text
def square(n):
    '''Takes in a number n, returns the square of n'''
    return n**2
```

Here, the string literal:

```text
'''Takes in a number n, returns the square of n'''
```

Inside the triple quotation marks is the **docstring** of the function `square()` as it appears right after its definition.

**Note:** We can also use triple `"""` quotations to create docstrings.

#### Python \_\_doc\_\_ attribute

Whenever string literals are present just after the definition of a function, module, class or method, they are associated with the object as their `__doc__` attribute. We can later use this attribute to retrieve this docstring.

_Example 2: Printing docstring_

```text
def square(n):
    '''Takes in a number n, returns the square of n'''
    return n**2

print(square.__doc__)
```

**Output**

```text
Takes in a number n, returns the square of n
```

Here, the documentation of our `square()` function can be accessed using the `__doc__` attribute.

#### Using the help\(\) Function for Docstrings

We can also use the `help()` function to read the docstrings associated with various objects.

_Example 7: Read Docstrings with the help\(\) function:_

We can use the `help()` function on the class `Person` in **Example 6** as:

```text
help(Person)
```

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



#### Works Cited

I grabbed these from the [Mypy documentation](https://mypy.readthedocs.io/en/stable/cheat_sheet_py3.html). Check it out for more details. 

## Math

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

### Compound Operators

> Naturally, similar assignment forms exist for the rest of arithmetic operations: `-=`, `*=`, `/=`, `//=`, `%=`, `**=`. Given the opportunity, use them to save time and effort.

## Strings

### Slicing

#### Get the last few characters

```python
favorite_fruit = 'blueberry'
print(favorite_fruit[-1])
# => 'y'
 
print(favorite_fruit[-2])
# => 'r'
 
print(favorite_fruit[-3:])
# => 'rry'
```



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

### I**n keyword**

* `in` checks if one string is part of another string.

```python
print("e" in "blueberry")
# => True
print("a" in "blueberry")
# => False
```

### String Methods

* `.upper()`, `.title()`, and `.lower()` adjust the casing of your string.
* `.split()` takes a string and creates a list of substrings.
* `.join()` takes a list of strings and creates a string.
* `.strip()` cleans off whitespace, or other noise from the beginning and end of a string.
* `.replace()` replaces all instances of a character/string in a string with another character/string.
* `.find()` searches a string for a character/string and returns the index value that character/string is found at.
* `.format()` allows you to interpolate a string with variables.

Checkout Codecademy's [cheat sheet](https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-strings/cheatsheet) for this topic. Scroll down on that page & you'll see the methods.

![Codecademy&apos;s Summary of String Methods](../../../.gitbook/assets/image%20%281%29.png)

#### String Format

You can insert keywords to make your code more legible.: 

```python
def favorite_song_statement(song, artist):
    return "My favorite song is {song_label} by {artist_label}.".format(song_label=song, artist_label=artist)
```

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

### Assigning Default Values

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

### [Lambda Functions](https://www.youtube.com/watch?v=25ovCm9jKfA)

![Source: Socratica. My Favorite Beginner Python Series of 2020.](../../../.gitbook/assets/image%20%2816%29.png)

![Source: Socratica. My Favorite Beginner Python Series of 2020.](../../../.gitbook/assets/image%20%2818%29.png)

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

## Lists

* **Access**: `print(myList[-1])  # -1 refers to last element in the list.`
* **Append:** Use `yourNamedList.append(itemToAppend)` 
* **Append Another List:** Just use the `+` operator: `firstList + secondList`.
* **Count:** `trump_votes = votes.count('Trump')` ****will ****return a number. 
* **Del:** Removes an element from the list: 
* **Length \(Size\)**: `len(listVariable)`
* **Pop:** Removes the last index, but you can pass the index you want to remove as an argument.
* **Remove**: Removes a given item. Unlike pop, this lets you pass the object instead of the index. 
* **Slice:** You can slice a list to get a sublist. `sublist = letters[1:6]`
  * You can get the last 3 items of the list using: `sublist = letters[-3:]`
* **Sort** _does not return anything_ but sorts the existing list. You can sort a list using `existingList.sort()`
* **Sorted**  generates a new list without affecting the old one and uses the syntax `sorted(myList).` 
  * You can also sort in reverse order: `list1.sort(reverse=True).`

### [List Comprehensions](https://www.w3schools.com/python/python_lists_comprehension.asp)

Note: these examples were taken from my[ CodeCademy course.](https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-flow-data-iteration/modules/dspath-python-loops/cheatsheet)

Let’s say we have scraped a certain website and gotten these words:

```python
words = ["@coolguy35", "#nofilter", "@kewldawg54", "reply", "timestamp", "@matchamom", "follow", "#updog"]
```

We want to make a new list, called `usernames`, that has all of the strings in `words` with an `'@'` as the first character. We know we can do this with a for loop:

```python
words = ["@coolguy35", "#nofilter", "@kewldawg54", "reply", "timestamp", "@matchamom", "follow", "#updog"] 
usernames = []
for word in words: 
    if word[0] == '@':
        usernames.append(word)
    
>>> print(usernames)["@coolguy35", "@kewldawg54", "@matchamom"]
```

Python has a convenient shorthand to create lists like this with one line:

```python
usernames = [word for word in words if word[0] == '@']
```

This is called a _list comprehension._ It will produce the same output as the for loop did:

```python
["@coolguy35", "@kewldawg54", "@matchamom"]
```

This list comprehension:

1. Takes an element in `words`
2. Assigns that element to a variable called `word`
3. Checks if `word[0] == '@'`, and if so, it adds word to the new list, `usernames`. If not, nothing happens.
4. Repeats steps 1-3 for all of the strings in `words`

**Note:** if we hadn’t done any checking \(let’s say we had omitted `if word[0] == '@'`\), the new list would be just a copy of `words`

#### A second example: Filtering A List

```python
heights = [161, 164, 156, 144, 158, 170, 163, 163, 157] 
can_ride_coaster = [h for h in heights if h > 161] 
print(can_ride_coaster) # Returns numbers lareger than 161. 
```

#### [A third example](http://zetcode.com/python/listcomprehensions/): Change The Initial element

Note: taken from zetcode.

We have a list of temperatures in Celsius. We want to create a new list of temperatures expressed in Fahrenheit temperature.fahrenheit\_celsius.py

```python
#!/usr/bin/python3

celsius = [22, 28, 33, 42, 52]

fahr = [e * 9/5 + 32 for e in celsius]
print(fahr)
```

The example creates a new list of Fahrenheit temperatures calculated from a list of Celsius temperatures.

```python
fahr = [e * 9/5 + 32 for e in celsius]
```

The calculation is done in the third, expression part of the Python list comprehension.

{% code title="$ ./fahrenheit\_celsius.py " %}
```python
[71.6, 82.4, 91.4, 107.6, 125.6]
```
{% endcode %}

#### Fourth Example

Suppose we want to create empty list for each element in an existing list. We can do this with the following code.

```python
destinations = ["Paris, France", "Shanghai, China", "Los Angeles, USA", "São Paulo, Brazil", "Cario, Egypt"]
attractions = [[] for thing in destinations]

print(attractions)  # [[], [], [], [], []]
```



### Built In Functions

<table>
  <thead>
    <tr>
      <th style="text-align:left">Function</th>
      <th style="text-align:left">How to use it</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align:left">&lt;code&gt;&lt;/code&gt;<a href="https://www.programiz.com/python-programming/methods/built-in/range"><code>range()</code></a>&lt;code&gt;&lt;/code&gt;</td>
      <td
      style="text-align:left">
        <p><code>range(low_bound, upper_Bound, step)</code>
        </p>
        <ul>
          <li>Upper bound doesn&apos;t include upper bound. i.e. <code>range(10)</code> returns
            nums 0 to 9.</li>
          <li>Returns an immutable sequence.</li>
          <li>Steps can be positive or negative.</li>
          <li>It&apos;s a weird data type I don&apos;t understand.</li>
          <li>You can cast it to a list via:<code>list(range(start, stop, step)))</code>
          </li>
        </ul>
        </td>
    </tr>
    <tr>
      <td style="text-align:left">&lt;code&gt;&lt;/code&gt;<a href="https://www.programiz.com/python-programming/methods/built-in/zip"><code>zip(a, b, c)</code></a>&lt;code&gt;&lt;/code&gt;</td>
      <td
      style="text-align:left">
        <ul>
          <li>Zip takes iterables and aggregates them into a tuple.</li>
          <li>The iterables must be the same length. Any <em>extraneous values will be cut off</em>
          </li>
          <li>It casts to a <code>set()</code> or <code>list()</code>
          </li>
          <li>You can also unzip: <code>c, v =.zip(*results).</code>See the bottom of
            the link for a better explanation.</li>
        </ul>
        </td>
    </tr>
    <tr>
      <td style="text-align:left"><code>.index(element)</code>
      </td>
      <td style="text-align:left">
        <ul>
          <li>Gets the index given an. element.</li>
          <li><code>[&quot;foo&quot;, &quot;bar&quot;, &quot;baz&quot;].index(&quot;bar&quot;)</code> will
            return <code>1</code>.</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>

## User Input

* The `input()` function reads a line from the user and returns it in a program as a string.

```python
user_name = input()
print("Hello, " + user_name) #You don't need to cast this, already str.
```

### Specify Clear Messages

* State clearly the type of input we expect from our user.
* The `input()` function takes an optional argument, a message.

```python
user_name = input("Please, enter your name: ")
print("Hello, " + user_name)

# The user will see this:
Please, enter your name: Sauron
Hello, Sauron
```

### Type Check

You can check that a value works by typecasting it or using the type function to check if the type is equal to the expected type; however, the latter isn't recommended because of a corner case of "4" and "4.0" and the user won't know better. If you choose the ladder, just use an 'or' to make sure that it's a float/int and cast it over to what it needs to be. Actually, that's probably best now that I. think about it.

* If the user doesn't enter any input, the program will not execute any further.
* All input is always type `str`. You have to cast it if you want anything else:
* _An error will appear_ if the user enters a value that cannot be converted.

```python
print("What's your favorite number?")
value = int(input()) # now, the value keeps an integer number. 
```

## Command Line Arguments

Below is a snippet of something I wrote when I had to figure this out the first time.

```python
def main(): # function, method are the same
    host = "www.google.com"

    # Check Command Line Input to make sure some stuff was entered.
    print("Number of arguments: " + str(len(sys.argv)) + " arguments")
    if (1 == len(sys.argv)):
        print("You didn't specify a host name, so we're using Google")
    else:
        host = sys.argv.__getitem__(1)
        print("The host you specified was: " + host)
    print("===============================================\nNow commencing Dr. Yao's Code... \n")
```



