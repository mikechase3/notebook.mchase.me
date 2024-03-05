# Strings

## Strings

### Slicing

#### Get the last few characters

```python
favorite_fruit = 'blueberry'
 
print(favorite_fruit[-2])
# => 'r'
 
print(favorite_fruit[-3:])
# => 'rry'
```

### Concatenation

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
"""
```

### Eval()

* Use eval() to have python evaluate a regular expression.

### I**n keyword**

* `in` checks if one string is part of another string.

```python
print("e" in "blueberry")
# => True
print("a" in "blueberry")
# => False
```

### String Methods

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-strings/cheatsheet" %}

* `.upper()`, `.title()`, and `.lower()` adjust the casing of your string.
* `.split()` takes a string and creates a list of substrings.
* `.join()` takes a list of strings and creates a string.
* `.strip()` cleans off whitespace, or other noise from the beginning and end of a string.
* `.replace()` replaces all instances of a character/string in a string with another character/string.
* `.find()` searches a string for a character/string and returns the index value that character/string is found at.
* `.format()` allows you to interpolate a string with variables.

Checkout Codecademy's [cheat sheet](https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-strings/cheatsheet) for this topic. Scroll down on that page & you'll see the methods.

![Codecademy's Summary of String Methods](<../../../../../../.gitbook/assets/image (392).png>)

#### String Format

You can insert keywords to make your code more legible.:

```python
def favorite_song_statement(song, artist):
    return "My favorite song is {song_label} by {artist_label}.".format(song_label=song, artist_label=artist)
```

Words
