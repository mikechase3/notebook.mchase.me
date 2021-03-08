# C

* This is the best resource. Don't even read my notes, just go [here](https://www.programiz.com/c-programming/c-keywords-identifier). 
* The ads are a little intrusive, but not bad.
* They have an app for 'C' on iOS and probably Android. Also Python and probably everything. It's the same app, just with different documentation.

## Introductory Stuff



### Keywords and Identifiers
* Checkout the resource I used to build this section in my notebook [here](https://www.programiz.com/c-programming/c-keywords-identifier)
* The alphabet is all uppercase, lowercase, digits, and some special cahracters. 
* Also blank space, newline, horizontal tabs, carriage return, and form feed.
* There are some keywords. Try not to use them. [Keywords](https://www.programiz.com/c-programming/c-keywords-identifier)

#### Identifiers
* These are names given to things like variables and functions.
* They must be unique.
* First character of an identifier must be a letter or an `_`.


### Variables and Constants
* Don't make the identifiers longer than 31 characters.
* No symbols besides `_`.

#### Literals
* ints, floats, and chars are what you'd expect.
* **Escape Sequences** include `\b` for backspace. `\f` for form feed, `\0` is for the null character.
* `"this is string"`
* `""` is a null string constant.
* `"x"` is a string constant with one character. Not a char.
* `'x'` is a char because it has single quotation marks.

#### Constants
* `const double PI = 3.14` uses the `const` keyword.
* Also use capital letters.
* Alternatively, you can use the `#define` preprocessor directives. It's a [Macro](https://www.programiz.com/c-programming/c-preprocessor-macros).


### Data Types
* `int`s are usually 4 bytes. `long`s are 8. There's also `long long int` which I think is kind-of funny.
* `char` is 1 byte.
* `double` is 8 bytes. `long double` is usually 12 or 16.
* Check the size of a varaible using the `sizeof(<a variable already defined>)`. (Note: requires `include <stdio.h>`
* Arrays, pointers, and structs are called *derived types*.


## Structures

* Sometimes referred to as aggregates.
* In object-oriented programs, they're called _data fields_.


```c
struct card{
    char FirstName[20]
    char lastName[20]
    double hourlySalary;
    struct employee2 *ePtr;  // Can include a variable to the same structure.
```



