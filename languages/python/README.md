---
description: >-
  This page contains my personal notes that probably won't be useful to anyone
  but me. It's purely so I don't mix up languages. Checkout the sub-pages for
  better content!
---

# Python

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

## \#Comments

```python
#This is a Python comment
//This is me being an idiot. #Thank God for syntax highlighting. 
```

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

