# Introduction to C

## Key Features

* Has a low-level features of assembly languages
* Concise syntax
* They can directly access memory though pointer manipulation
* It's also a high programming language
  * Block structure
  * Weak type checking
  * Functions with some code encapsulation.

## Printf String Vulnerability

* If we don't format it as a string literal, there's a vulnerability

![](../../../.gitbook/assets/image%20%28259%29.png)

### Attacks

1. Crash the program by printing `%s%s%s%s...`
2. View the process memory:
   1. What's on the stack?
   2. View the memory at any location.
3. Overwrite arbitrary memory similar to common buffer overflows.
4. Through pure format strings.
5. Overwrite important program flags that control access privileges.

### The Fix

![](../../../.gitbook/assets/image%20%28258%29.png)

