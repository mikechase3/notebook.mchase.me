# User input

## Reading Input from a user

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

### Important Details

* If the user doesn't enter any input, the program will not execute any further.
* All input is always type `str`. You have to cast it if you want anything else:
* An error will appear if the user enters a value that cannot be converted.

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



