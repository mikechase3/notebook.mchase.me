# Classes and Inheritance

## Resources

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-classes/cheatsheet" caption="This content is directly from CodeCademy. Check them out!" %}

## Exceptions

There’s one very important family of class definitions built in to the Python language. An _Exception_ is a class that inherits from Python’s `Exception` class.

We can validate this ourselves using the `issubclass()` function. `issubclass()` is a Python built-in function that takes two parameters. `issubclass()` returns `True` if the first argument is a subclass of the second argument. It returns `False` if the first class is not a subclass of the second. `issubclass()`raises a `TypeError` if either argument passed in is not a class.

```text
issubclass(ZeroDivisionError, Exception)# Returns True
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

## Classes

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-classes/cheatsheet" caption="Checkout Codecademy\'s \'Classes Cheatsheet\' where I learned and sourced this section." %}

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



