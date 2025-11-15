# C Programming Security

## Lab 2 Outline

{% embed url="https://accounts.google.com/signin/continue?sarp=1&continue=https%3A%2F%2Fdocs.google.com%2Fdocument%2Fu%2F1%2Fd%2F1q0g8MZFUP9XE1BfQnMdHioaMMbkkFqThkVlBZSDEnr0%2Fedit%3Fusp%3Dsharing&plt=AKgnsbuylbKj6vaHtHdjZc5jkq535i3_mUdZeJ4Ph37OYhbZWFC7H7h0TmC_RIdpnWzA6ymUkLaeXUQdEdC1Xg2-5NMNV7wUKn8whx8cIG7zONMiw4ua90kcTxeflYu_m27f7QlWQ5HU&PersistentCookie=1&scc=0&service=wise" %}

## Languages and Direct Memory Access

![](<../../../../.gitbook/assets/image (376) (1) (1).png>)

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

![](<../../../../.gitbook/assets/image (417).png>)

### Attacks

1. Crash the program by printing `%s%s%s%s...`
2. View the process memory:
   1. What's on the stack?
   2. View the memory at any location.
3. Overwrite arbitrary memory similar to common buffer overflows.
4. Through pure format strings.
5. Overwrite important program flags that control access privileges.

### The Fix

![](<../../../../.gitbook/assets/image (418).png>)

## Insecure Functions

* Avoid using vulnerable functions in which no bounds are checked.
  * strcpy, strcat, sprintf, scanf, sscanf, gets, read,
* Use equivalent safe functions which restrict the scope of stuff that can go wrong.

![Source: Dr. Phu Phung's Software Security Course. 2021.](<../../../../.gitbook/assets/image (419).png>)

![Source: Dr. Phu Phung's Software Security. 2021.](<../../../../.gitbook/assets/image (420).png>)

## Your Responsibilities
