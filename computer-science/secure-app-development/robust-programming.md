---
description: Lecture 14
---

# Robust Programming

## Introduction
* Robust programming is making your program more **resistant to crashing.**
* Secure apps must also be robust. Otherwise it might crash.

## Robust Programming Principles
1. Be Paranoid: Assume all inputs are attacks.
2. Assume Stupidity
3. Don't hand out dangerous implementations
4. Assume all conditions can happen

Source: *Robust Programming Principles (Bishop/Elliot 2011)

### Examples in C
* Make sure that you include a buffersize when using `strncpy`. 
* Make srue you use an `exit(0)` to terminate invalid programs.

### Summary
* Programming robustly provides the basis for adding security elements to the program.
* But without robust programming, secure programming will never achieve the desired effect.



