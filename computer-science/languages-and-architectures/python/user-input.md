# User input

## Reading Input from a user

* The `input()` function reads a line from the user and returns it in a program as a string.

```python
user_name = input()
print("Hello, " + user_name) #You don't need to cast this, already str.
```

## Specify Clear Messages

* State clearly the type of input we expect from our user.
* The `input()` function takes an optional argument, a message.

```python
user_name = input("Please, enter your name: ")
print("Hello, " + user_name)

# The user will see this:
Please, enter your name: Sauron
Hello, Sauron
```

## Important Details

* If the user doesn't enter any input, the program will not execute any further.
* All input is always type `str`. You have to cast it if you want anything else:
* An error will appear if the user enters a value that cannot be converted.

```python
print("What's your favorite number?")
value = int(input()) # now, the value keeps an integer number. 
```

