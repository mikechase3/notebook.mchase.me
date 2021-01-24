# Classes and Inheritance

## Exceptions

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-classes/cheatsheet" %}



{% hint style="danger" %}
This content is copied/pasted from CodeCademy, I thought it was an awesome explanation. 

[https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-classes/cheatsheet](https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-classes/cheatsheet)
{% endhint %}

Exceptions

There’s one very important family of class definitions built in to the Python language. An _Exception_ is a class that inherits from Python’s `Exception` class.

We can validate this ourselves using the `issubclass()` function. `issubclass()` is a Python built-in function that takes two parameters. `issubclass()` returns `True` if the first argument is a subclass of the second argument. It returns `False` if the first class is not a subclass of the second. `issubclass()`raises a `TypeError` if either argument passed in is not a class.

```text
issubclass(ZeroDivisionError, Exception)# Returns True
```

Above, we checked whether `ZeroDivisionError`, the exception raised when attempting division by zero, is a subclass of `Exception`. It is, so `issubclass` returns `True`.

Why is it beneficial for exceptions to inherit from one another? Let’s consider an example where we create our own exceptions. What if we were creating software that tracks our kitchen appliances? We would be able to design a suite of exceptions for that need:

```text
class KitchenException(Exception):  """  Exception that gets thrown when a kitchen appliance isn't working  """ class MicrowaveException(KitchenException):  """  Exception for when the microwave stops working  """ class RefrigeratorException(KitchenException):  """  Exception for when the refrigerator stops working  """
```

In this code, we define three exceptions. First, we define a `KitchenException` that acts as the parent to our other, specific kitchen appliance exceptions. `KitchenException`subclasses `Exception`, so it behaves in the same way that regular `Exception`s do. Afterward we define `MicrowaveException` and `RefrigeratorException` as subclasses.

Since our exceptions are subclassed in this way, we can catch any of `KitchenException`‘s subclasses by catching `KitchenException`. For example:

```text
def get_food_from_fridge():  if refrigerator.cooling == False:    raise RefrigeratorException  else:    return food def heat_food(food):  if microwave.working == False:    raise MicrowaveException  else:    microwave.cook(food)    return food try:  food = get_food_from_fridge()  food = heat_food(food)except KitchenException:  food = order_takeout()
```

In the above example, we attempt to retrieve food from the fridge and heat it in the microwave. If either `RefrigeratorException`or `MicrowaveException` is raised, we opt to order takeout instead. We catch both `RefrigeratorException` and `MicrowaveException` in our try/except block because both are subclasses of `KitchenException`.



