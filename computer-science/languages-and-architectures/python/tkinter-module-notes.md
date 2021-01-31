---
description: Personal notes and examples all about tkinter.
---

# Modules

## Working with Modules

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-modules/cheatsheet" %}



#### Import a Class

```python
from your_file import YourClass
```

#### Importing a Function

```python
from your_file import your_function  # Imports the function so you can use it.
```

## AWS

{% embed url="https://aws.amazon.com/getting-started/hands-on/build-modern-app-fargate-lambda-dynamodb-python/" %}





## DateTime

* `from datetime import datetime`
* Print the current time: `datetime.now()`
* Get the date: `datetime.date()`
* Get the time: `datetime.time()`
* Set a date & time: 

  ```text
  any_variable = datetime(year, month, day[, hour[, minute[, second[, microsecond[,tzinfo]]]]])
  ```

#### DateTime Arithmetic 

We can subtract dates from each other to see how much time has elapsed.

```python
datetime(2018, 1, 1) - datetime(2017, 1, 1)  # Returns 'datetime.timedelta(days=365)
datetime.now() - datetime(1999, 6, 3)  # Returns how old Mike Chase is.
```

### Strptime: Strings to datetime objects

Oftentimes, we'll get the information in the form of a string. We can use `datetime.strptime()` to tell it how we've formatted the date and time in our string.

```python
parsed_date = "Jan 16, 2018"  # Converting to datetime using the reference below.
actual_date = datetime.strptime(parsed_date, '%b, %d, %Y')  # Tells python how this is formatted.
# Now it's in a datetime object.
```

{% embed url="https://strftime.org/" %}

### Strftime: Datetime objects to strings

This creates a string from a datetime. It's very similar to `strptime` but just in reverse

```python
date_string = datetime.strftime(datetime.now(), '%b %d, %Y')
# Returns: 'Jan 17, 2020'
```



## Decimal

* `random.choice()` takes a list as an argument and picks one.
* `random.randint()` takes 2 numbers as arguments and returns an int between the two.
* **Purpose**: Perform decimal arithmetic more accurately.
* **Import**: `from decimal import Decimal`
* **Usage:** 

```python
from decimal import Decimal
 
cost_of_gum = Decimal('0.10')
cost_of_gumdrop = Decimal('0.35')
 
cost_of_transaction = cost_of_gum + cost_of_gumdrop
# Returns 0.45 instead of 0.44999999999999996
```

## MatPlotLib

* `from matplotlib import pyplot as plt` will import what we need to graph stuff.
* Plot using `p.plot(a: list[int], b: list[int])`
* Lastly, show the plot using `plt.show()`
* You might need [seaborn](https://pypi.org/project/seaborn/), `pip install seaborn` which is a library for making statistical graphics in Python.

If all goes to plan, you'll see a plot produced with the dataset.

![](../../../.gitbook/assets/image%20%2867%29.png)

## Pipenv

{% embed url="https://www.youtube.com/watch?time\_continue=256&v=BVr-6Ki96XM&feature=emb\_title" %}

* It's really difficult to maintain lots of different versions of lots of different libraries by yourself.
* Therefore, developers made virtual environments. It's a local environment that defines different versions of python, libraries, and dependencies _specific to one project in a directory_.

### Setup

* Install: `pip install --user pipenv`
* By putting a directory in PATH, it'll allow you to just type `pipenv` so you can use it in any directory.
* If you add `/Users/mikechase3/Library/Python/3.7/bin` to `~/.bash_profile`, you can access it anywhere.
  * Type into your bash profile: `export PATH="/Users/{yourusername}/Library/Python/3.7/bin:$PATH"`
* Now, your computer will recognize `pipenv` as a command on a mac.
  * I don't believe it actually works. You have to edit [~/zshrc](https://stackoverflow.com/a/58786420/4777844) instead.
  * On windows, see 09:15 on the video.

### Shell

* `pipenv shell` lets you access the shell within the virtual environment.

## Random

* Use `r.sample(range(numbers_to_produce: int), 12))` to generate a list of 12 random numbers.

## STL Tools

* Convert python code to generate STL geometry from text, LaTeX, numpy arrays, and pictures.

{% embed url="https://github.com/thearn/stl\_tools" %}



## TKinter

### Comprehensive Guide

{% embed url="https://users.tricity.wsu.edu/~bobl/cpts481/tkinter\_nmt.pdf" %}



### Dropdown Menus

{% embed url="https://www.youtube.com/watch?v=PSm-tq5M-Dc&t=329s" %}







