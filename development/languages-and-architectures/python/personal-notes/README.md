# Core

## Naming Conventions

{% embed url="https://www.python.org/dev/peps/pep-0008/#id34" %}

{% content-ref url="pep-8-style-guide.md" %}
[pep-8-style-guide.md](pep-8-style-guide.md)
{% endcontent-ref %}

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

* Use the type() function.
* `print(type(what_is_this_mysterious_variable))`



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

If we need to get a square root and cuberoot, then you can raise it to 0.5 or 1/3. If it needs to be exact, use numpy:

```python
import numpy as np 
arr1 = [1, 8, 27, 64] 
arr2 = np.cbrt(arr1) 
print(arr2)

# Output: [1. 2. 3. 4.]
```

### Compound Operators

> Naturally, similar assignment forms exist for the rest of arithmetic operations: `-=`, `*=`, `/=`, `//=`, `%=`, `**=`. Given the opportunity, use them to save time and effort.



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

## User Input

* The `input()` function reads a line from the user and returns it in a program as a string.

```python
new_list = [what_will_replace_i for i in some_list_or_range]
```

Let’s say we have scraped a certain website and gotten these words:

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

* Arguments passed in through the command line come in as a tuple.

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

## Data Types

* We can check what type a variable is by calling `type()` on it.
* For example, `type("hello")` will return that it's the type string.

[Works cited: w3schools.com: Python Data Types](https://www.w3schools.com/python/python\_datatypes.asp)

| Example                                      | Data Type  | Try it                                                                                     |
| -------------------------------------------- | ---------- | ------------------------------------------------------------------------------------------ |
| x = str("Hello World")                       | str        | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_str2)       |
| x = int(20)                                  | int        | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_int2)       |
| x = float(20.5)                              | float      | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_float2)     |
| x = complex(1j)                              | complex    | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_complex2)   |
| x = list(("apple", "banana", "cherry"))      | list       | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_list2)      |
| x = tuple(("apple", "banana", "cherry"))     | tuple      | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_tuple2)     |
| x = range(6)                                 | range      | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_range2)     |
| x = dict(name="John", age=36)                | dict       | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_dict2)      |
| x = set(("apple", "banana", "cherry"))       | set        | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_set2)       |
| x = frozenset(("apple", "banana", "cherry")) | frozenset  | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_frozenset2) |
| x = bool(5)                                  | bool       | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_bool2)      |
| x = bytes(5)                                 | bytes      | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_bytes2)     |
| x = bytearray(5)                             | bytearray  | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo\_type\_bytearray2) |
| x = memoryview(bytes(5))                     | memoryview | Try it »                                                                                   |

## Lists

* **Access**: `print(myList[-1]) # -1 refers to last element in the list.`
* **Append:** Use `yourNamedList.append(itemToAppend)`
* **Append Another List:** Just use the `+` operator: `firstList + secondList`.
* **Count:** `trump_votes = votes.count('Trump')` \*\*\*\* will \*\*\*\* return a number.
* **Del:** Removes an element from the list:
* **Length (Size)**: `len(listVariable)`
* **Pop:** Removes the last index, but you can pass the index you want to remove as an argument.
* **Remove**: Removes a given item. Unlike pop, this lets you pass the object instead of the index.
* **Slice:** You can slice a list to get a sublist. `sublist = letters[1:6]`
  * You can get the last 3 items of the list using: `sublist = letters[-3:]`
* **Sort** _does not return anything_ but sorts the existing list. You can sort a list using `existingList.sort()`
* **Sorted** generates a new list without affecting the old one and uses the syntax `sorted(myList).`
  * You can also sort in reverse order: `list1.sort(reverse=True).`

### [List Comprehensions](https://www.w3schools.com/python/python\_lists\_comprehension.asp)

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

**Note:** if we hadn’t done any checking (let’s say we had omitted `if word[0] == '@'`), the new list would be just a copy of `words`

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

{% code title="$ ./fahrenheit_celsius.py " %}
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

| Function                                                                                | How to use it                                                                                                                                                                                                                                                                                                                                                                              |
| --------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| ``[`range()`](https://www.programiz.com/python-programming/methods/built-in/range)``    | <p><code>range(low_bound, upper_Bound, step)</code></p><ul><li>Upper bound doesn't include upper bound. i.e. <code>range(10)</code> returns nums 0 to 9.</li><li>Returns an immutable sequence.</li><li>Steps can be positive or negative.</li><li>It's a weird data type I don't understand.</li><li>You can cast it to a list via:<code>list(range(start, stop, step)))</code></li></ul> |
| ``[`zip(a, b, c)`](https://www.programiz.com/python-programming/methods/built-in/zip)`` | <ul><li>Zip takes iterables and aggregates them into a tuple.</li><li>The iterables must be the same length. Any <em>extraneous values will be cut off</em></li><li>It casts to a <code>set()</code> or <code>list()</code></li><li>You can also unzip: <code>c, v =.zip(*results).</code>See the bottom of the link for a better explanation.</li></ul>                                   |
| `.index(element)`                                                                       | <ul><li>Gets the index given an. element.</li><li><code>["foo", "bar", "baz"].index("bar")</code> will return <code>1</code>.</li></ul>                                                                                                                                                                                                                                                    |

## Dictionaries

* **General Syntax:** `my_dictionary = {key: value, key: value}`
* Keys must be immutable. Aka no lists.

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-dictionaries/cheatsheet" %}

### Add a Key

We can add multiple keys to a dictionary by using the `.update()` method.

```python
locations = {}
locations['Paris'] = 100 
locations.update({"London": 75})
locations.update({"New York": 83, "Vancouver" : 110})

print(locations)
# {'Paris': 100, 'London': 75, 'New York': 83, 'Vancouver': 110}
```

#### Adding via defaultdict

* An easy way to start making a list is to use the `defaultdict` module.

```python
from collections import defaultdict

d = defaultdict(list)  # or set.
d['a'].append(1)
d['a'].append(2)
d['b'].append(4)
```

* _Warning:_ it will create dictionary enteries for keys accessed later on, even if they are not currently in the dictionary. If you don't want this behavior, you can call `d.setdefault()` on an ordinary dictionary. (Beazley Jones 12).

{% hint style="info" %}
This doesn't make sense to me.
{% endhint %}

### Get a Key

* The get method is best way to grab keys because you avoid an error if a key does not exist when using the `some_dictionary[key]` method.

```python
building_heights.get("Shanghai Tower", "default_val")  # use the .get() method.
```

You can also specify a value to return if the key doesn’t exist. For example, we might want to return a building height of 0 if our desired building is not in the dictionary:

```python
>>> building_heights.get('Shanghai Tower', 0)
632
>>> building_heights.get('Mt Olympus', 0)
0
>>> building_heights.get('Kilimanjaro', 'No Value')
'No Value'
```

### Overwriting Values

```python
menu = {"oatmeal": 3, "avocado toast": 6, "carrot juice": 5, "blueberry muffin": 2}
menu["oatmeal"] = 5  # Alternatively use .update()
print(menu) 
# {"oatmeal": 5, "avocado toast": 6, "carrot juice": 5, "blueberry muffin": 2}
```

### Replacing the Key

```python
mydict["new_key"] = mydict.pop("old_key")
```

### Deleting a Key

* Use the `dictionary.pop(key, defaultValueIfKeyDoesntExist)`

```python
>>> raffle
{223842: "Teddy Bear", 872921: "Concert Tickets", 412123: "Necklace", 298787: "Pasta Maker"}
>>> raffle.pop(100000, "No Prize")
"No Prize"
```

### Two Lists -> Key

Let’s say we have two lists that we want to combine into a dictionary, like a list of students and a list of their heights, in inches:

```python
names = ['Jenny', 'Alexus', 'Sam', 'Grace']
heights = [61, 70, 67, 64]
```

Python allows you to create a dictionary using a list comprehension, with this syntax:

```python
students = {key:value for key, value in zip(names, heights)}
# students is now {'Jenny': 61, 'Alexus': 70, 'Sam': 67, 'Grace': 64}
```

Remember that `zip()` combines two lists into a zipped list of pairs. This list comprehension:

1. Takes a pair from the zipped list of pairs from `names` and `heights`
2. Names the elements in the pair `key` (the one originally from the `names` list) and `value` (the one originally from the `heights` list)
3. Creates a `key` : `value` item in the `students` dictionary
4. Repeats steps 1-3 for the entire list of pairs

Here's another example:

```python
drinks = ["espresso", "chai", "decaf", "drip"]
caffeine = [64, 40, 0, 120]

zipped_drinks = zip(drinks, caffeine)
drinks_to_caffeine = {drinks:caffeine for drinks, caffeine in zipped_drinks}
print(drinks_to_caffeine)
```

_Works Cited: Direct text from Codecademy -> Python3 -> List Comprehensions to Dictionaries_

### Get All Keys, Values, or Items (as a list)

#### Keys

* To get all keys you can just cast a dictionary to a list: `list(my_dictionary)`
* Alternatiely, dictionaries have a `.keys()` method which will produce an iterable `<class 'dict_keys'>` of keys:

```python
for student in university.keys():
    print(student)  # Will print out all students, assuming they are keys.
```

#### Values

* There is also a `.values()` method that produces an iterable of values.
* You can get all the values as a list by casting it via `list(test_scores.values())`

#### Items

* Use the `.items()` function to iterate through the items.

```python
biggest_brands = {"Apple": 184, "Google": 141.7, "Microsoft": 80, "Coca-Cola": 69.7, "Amazon": 64.8}
 
for company, value in biggest_brands.items():  # Key, Value in dictionary.ITEMS()
  print(company + " has a value of " + str(value) + " billion dollars. ")
```

{% hint style="info" %}
Getting the smallest item is always quickest using heaps because it's O(log N) operations.
{% endhint %}

* `heap[0]` is always the smallest item in a heap.
* Subsequent items can easily be found using the `heapq.heappop()` method.
* To find the single smallest number, it's faster to use `min()` and `max()`.

_Source: Beazley, Jones Python Cookbook 3ed. See page 7._

### OrderedDict

* Ordered dictionaries maintain order when iterating.
* It preserves the original insertion order of data.

```python
from collections import OrderedDict

fav_movies = OrderedDict()
fav_movies["Back to the Future"] = "I loved the car"
fav_movies["Race to Witch Mountain"] = "Had a crush on the actress"

for movie in fav_movies:
    print(movie, fav_movie[key])

# Returns
# Back to the Future I loved the car
# Race to Witch Mountain Crush on the actress
```

## Sets

* Sets are basically dictionaries, but just without keys and values. Just include values.
* Defined using `{something, something_else}`

## Heaps

* Use these if you have to implement some sort-of priority queue.
* My favorite resource is 1.5 from _The Python Cookbook (below)._

{% embed url="https://learning.oreilly.com/library/view/python-cookbook-3rd/9781449357337/ch01.html" %}

{% embed url="https://docs.python.org/3/library/heapq.html" %}

{% embed url="https://docs.python.org/3/library/heapq.html" %}

## Resources

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-classes/cheatsheet" %}
This content is directly from CodeCademy. Check them out!
{% endembed %}

## Classes

```python
# Define
class Facade:
  pass

# Instantiate
facade_1 = Facade()
```

### Constructors

> There are several methods that we can define in a Python class that have special behavior. These methods are sometimes called “magic,” because they behave differently from regular methods. Another popular term is _dunder methods_, so-named because they have two underscores (double-underscore abbreviated to “dunder”) on either side of them. (Source: Codecademy)

Use `def __init()__:` within the class to make a constructor.

### Attribute Functions

* You can examine an object's attributes at runtime by using `dir(ur_object)`

> ```python
> class NoCustomAttributes:
>   pass
>  
> attributeless = NoCustomAttributes()
>  
> try:
>   attributeless.fake_attribute
> except AttributeError:
>   print("This text gets printed!")
>  
> # prints "This text gets printed!"
> ```
>
> What if we aren’t sure if an object has an attribute or not?
>
> * `hasattr()` will return `True` if an object has a given attribute and `False` otherwise.
> * If we want to get the actual value of the attribute, `getattr()` is a Python function that will return the value of a given object and attribute.
> * In this function, we can also supply a third argument that will be the default if the object does not have the given attribute.
>
> The syntax and parameters for these functions look like this:
>
> `hasattr(object, “attribute”)` has two parameters:
>
> * _object_ : the object we are testing to see if it has a certain attribute
> * _attribute_ : name of attribute we want to see if it exists
>
> `getattr(object, “attribute”, default)` has three parameters (one of which is optional):
>
> * _object_ : the object whose attribute we want to evaluate
> * _attribute_ : name of attribute we want to evaluate
> * _default_ : the value that is returned if the attribute does not exist (note: this parameter is **optional**)
>
> ```python
> can_we_count_it = [{'s': False}, "sassafrass", 18, ["a", "c", "s", "d", "s"]]
>
> for obj in can_we_count_it:
>   if hasattr(obj, "count"):
>     print(str(type(obj)) + " has the count attribute!")
>       
> # <class 'str'> has the count attribute!
> # <class 'list'> has the count attribute!
> ```
>
> _(Source: Codecademy, Python Programming Course)_

### Superclass

* You can inherit the methods and variables from the superclass by calling `super()`. Make sure you have the **() at the end!!!!!**



## Dunder Methods

### Initialization

```python
class guest:
  DRINKING_AGE = 21  # Class Variable. 
  
  def __init__(self, name, dob):  # name/age/dob are instance vars.
    self.name = "Michael"
    self.dob = dob
  def can_drink():
    if datetime.date.today() - self.dob > 7930: return True # I forgot syntax.

g = Guest("Michael", datetime.date(1995, 7, 24))
```

### String Representation: \_\_repr\_\_()

* To have a default string representation of an object, use `__repr(self)__:`

```python
class Employee():
  def __init__(self, name):
    self.name = name
 
  def __repr__(self):
    return self.name
 
argus = Employee("Argus Filch")
print(argus)
# prints "Argus Filch"
```

### Adding with \_\_add\_\_()

```python
class Atom:
  def __init__(self, label):
    self.label = label

  def __add__(self, other):
    return Molecule([self, other])
    
class Molecule:
  def __init__(self, atoms):
    if type(atoms) is list:
	    self.atoms = atoms
      
sodium = Atom("Na")
chlorine = Atom("Cl")
salt = Molecule([sodium, chlorine])
# salt = sodium + chlorine
```

### \_\_Iter()\_\_

```python
class UserGroup:
  def __init__(self, users, permissions):
    self.user_list = users
    self.permissions = permissions
 
  def __iter__(self):
    return iter(self.user_list)
 
  def __len__(self):
    return len(self.user_list)
 
  def __contains__(self, user):
    return user in self.user_list
```

* `__iter__`, the iterator, we use the `iter()` function to turn the list `self.user_list` into an _iterator_ so we can use `for user in user_group` syntax. For more information on iterators, review [Python’s documentation of Iterator Types](https://docs.python.org/3/library/stdtypes.html#typeiter).

### \_\_len()\_\_

```python
class UserGroup:
  def __init__(self, users, permissions):
    self.user_list = users
    self.permissions = permissions
 
  def __iter__(self):
    return iter(self.user_list)
 
  def __len__(self):
    return len(self.user_list)
 
  def __contains__(self, user):
    return user in self.user_list
```

* `__len__`, the length method, so when we call `len(user_group)` it will return the length of the underlying `self.user_list` list.

### \_\_contains()\_\_

```python
class UserGroup:
  def __init__(self, users, permissions):
    self.user_list = users
    self.permissions = permissions
 
  def __iter__(self):
    return iter(self.user_list)
 
  def __len__(self):
    return len(self.user_list)
 
  def __contains__(self, user):
    return user in self.user_list
```

* `__contains__`, the check for containment, allows us to use `user in user_group` syntax to check if a `User` exists in the `user_list` we have.

## Exceptions

There’s one very important family of class definitions built in to the Python language. An _Exception_ is a class that inherits from Python’s `Exception` class.

We can validate this ourselves using the `issubclass()` function. `issubclass()` is a Python built-in function that takes two parameters. `issubclass()` returns `True` if the first argument is a subclass of the second argument. It returns `False` if the first class is not a subclass of the second. `issubclass()`raises a `TypeError` if either argument passed in is not a class.

```python
issubclass(ZeroDivisionError, Exception) # Returns True
```

Above, we checked whether `ZeroDivisionError`, the exception raised when attempting division by zero, is a subclass of `Exception`. It is, so `issubclass` returns `True`.

Why is it beneficial for exceptions to inherit from one another? Let’s consider an example where we create our own exceptions. What if we were creating software that tracks our kitchen appliances? We would be able to design a suite of exceptions for example:

```python
class KitchenException(Exception):
  """
  Exception that gets thrown when a kitchen appliance isn't working
  """
 
class MicrowaveException(KitchenException):
  """
  Exception for when the microwave stops working
  """
 
class RefrigeratorException(KitchenException):
  """
  Exception for when the refrigerator stops working
  """
```

In this code, we define three exceptions. First, we define a `KitchenException` that acts as the parent to our other, specific kitchen appliance exceptions. `KitchenException`subclasses `Exception`, so it behaves in the same way that regular `Exception`s do. Afterward we define `MicrowaveException` and `RefrigeratorException` as subclasses.

Since our exceptions are subclassed in this way, we can catch any of `KitchenException`‘s subclasses by catching `KitchenException`. For example:

```python
def get_food_from_fridge():
  if refrigerator.cooling == False:
    raise RefrigeratorException
  else:
    return food
 
def heat_food(food):
  if microwave.working == False:
    raise MicrowaveException
  else:
    microwave.cook(food)
    return food
 
try:
  food = get_food_from_fridge()
  food = heat_food(food)
except KitchenException:
  food = order_takeout()
```

In the above example, we attempt to retrieve food from the fridge and heat it in the microwave. If either `RefrigeratorException`or `MicrowaveException` is raised, we opt to order takeout instead. We catch both `RefrigeratorException` and `MicrowaveException` in our try/except block because both are subclasses of `KitchenException`.

## Working with Modules

And how to create your own.

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-modules/cheatsheet" %}

#### Import a Class

```python
from your_file import YourClass
```

#### Importing a Function

```python
from your_file import your_function  # Imports the function so you can use it.
```
