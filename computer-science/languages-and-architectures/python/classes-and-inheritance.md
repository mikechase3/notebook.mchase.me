# Classes, Inheritance, Exceptions

## Resources

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-classes/cheatsheet" caption="This content is directly from CodeCademy. Check them out!" %}



## Classes

```python
# Define
class Facade:
  pass

# Instantiate
facade_1 = Facade()
```

### Constructors

> There are several methods that we can define in a Python class that have special behavior. These methods are sometimes called “magic,” because they behave differently from regular methods. Another popular term is _dunder methods_, so-named because they have two underscores \(double-underscore abbreviated to “dunder”\) on either side of them. \(Source: Codecademy\)

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
> *  `hasattr()` will return `True` if an object has a given attribute and `False` otherwise. 
> * If we want to get the actual value of the attribute, `getattr()` is a Python function that will return the value of a given object and attribute. 
> * In this function, we can also supply a third argument that will be the default if the object does not have the given attribute.
>
>
>
> The syntax and parameters for these functions look like this:
>
> `hasattr(object, “attribute”)` has two parameters:
>
> * _object_ : the object we are testing to see if it has a certain attribute
> * _attribute_ : name of attribute we want to see if it exists
>
> `getattr(object, “attribute”, default)` has three parameters \(one of which is optional\):
>
> * _object_ : the object whose attribute we want to evaluate
> * _attribute_ : name of attribute we want to evaluate
> * _default_ : the value that is returned if the attribute does not exist \(note: this parameter is **optional**\)
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
> _\(Source: Codecademy, Python Programming Course\)_

### Superclass

* You can inherit the methods and variables from the superclass by calling `super()`. Make sure you have the **\(\) at the end!!!!!**

\*\*\*\*

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

### String Representation: \_\_repr\_\_\(\)

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

### Adding with \_\_add\_\_\(\)

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

### \_\_Iter\(\)\_\_

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

### \_\_len\(\)\_\_

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

### \_\_contains\(\)\_\_

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



