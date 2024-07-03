# re Regular Expressions Package

{% embed url="https://docs.python.org/3/library/re.html" %}



## Match Class

## Pattern Class

### `split`

{% embed url="https://docs.python.org/3/library/re.html\#re.split" %}

\`\`

* The `split` function in `re`, aka `re.split()` is awesome because it lets you use multiple delimiters and accounts for whitespace around the delimiters.
* The result is a list of fields.

#### Usage

```python
>>> re.split(r'\W+', 'Words, words, words.')
['Words', 'words', 'words', '']
>>> re.split(r'(\W+)', 'Words, words, words.')
['Words', ', ', 'words', ', ', 'words', '.', '']
>>> re.split(r'\W+', 'Words, words, words.', 1)
['Words', 'words, words.']
>>> re.split('[a-f]+', '0a3B9', flags=re.IGNORECASE)
['0', '3', '9']
```

