# PEP 8 Style Guide

{% embed url="https://www.python.org/dev/peps/pep-0008/#id34" %}



## Purpose

* Explain how to write code that's clean & easy to read.
* Below is a summary of the [PEP 8 Style Guide](https://www.python.org/dev/peps/pep-0008/).
* Write all python proejcts as if they were written by the same programmer.

## PEP

* Stands for _**Python Enhancement Proposal**_
* The most important for beginners is the informational PEP.
* PEPs describe commonly accepted guidelines.

### Length of Lines

* Don't use more than 79 lines.
* Shorter lines look better in code editors.

### Avoid Extra Spaces

* Avoid spaces in parentheses.

### Quotes

* You can use single or double quotes to define strings.
* Be consistent.
* If a string contains single or double quotes, you should use the other one to avoid backslashes.

#### Example

Good: `print("It's a good string!")`

Bad: `print('It\'s a bad string!')`

### Comments

* There should be _**one space after the hash mark**_
* There should be _**two spaces between code and hash marks**_.
* Indent your code to the same level as the statement it explains.
* Triple quotes are used for reserved for documentation strings (docstrings) for short.

```python
"""
    BAD.
    This is reserved for for documentation. Don't use these
    when you need to make comments.
"""

# Instead
# If you need to make short multi-line comments
# Use lots of hash symbols.
```

