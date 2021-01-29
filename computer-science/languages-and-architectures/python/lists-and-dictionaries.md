---
description: >-
  I had a lot to learn and had to write a lot so it suck in my brain. It gets a
  new page.
---

# Lists, Dict, Set, Heaps

## Data Types

* We can check what type a variable is by calling `type()` on it.
* For example, `type("hello")` will return that it's the type string.

[Works cited: w3schools.com: Python Data Types](https://www.w3schools.com/python/python_datatypes.asp)

| Example | Data Type | Try it |
| :--- | :--- | :--- |
| x = str\("Hello World"\) | str | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_str2) |
| x = int\(20\) | int | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_int2) |
| x = float\(20.5\) | float | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_float2) |
| x = complex\(1j\) | complex | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_complex2) |
| x = list\(\("apple", "banana", "cherry"\)\) | list | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_list2) |
| x = tuple\(\("apple", "banana", "cherry"\)\) | tuple | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_tuple2) |
| x = range\(6\) | range | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_range2) |
| x = dict\(name="John", age=36\) | dict | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_dict2) |
| x = set\(\("apple", "banana", "cherry"\)\) | set | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_set2) |
| x = frozenset\(\("apple", "banana", "cherry"\)\) | frozenset | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_frozenset2) |
| x = bool\(5\) | bool | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_bool2) |
| x = bytes\(5\) | bytes | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_bytes2) |
| x = bytearray\(5\) | bytearray | [Try it »](https://www.w3schools.com/python/trypython.asp?filename=demo_type_bytearray2) |
| x = memoryview\(bytes\(5\)\) | memoryview | Try it » |

## Lists

* **Access**: `print(myList[-1])  # -1 refers to last element in the list.`
* **Append:** Use `yourNamedList.append(itemToAppend)` 
* **Append Another List:** Just use the `+` operator: `firstList + secondList`.
* **Count:** `trump_votes = votes.count('Trump')` ****will ****return a number. 
* **Del:** Removes an element from the list: 
* **Length \(Size\)**: `len(listVariable)`
* **Pop:** Removes the last index, but you can pass the index you want to remove as an argument.
* **Remove**: Removes a given item. Unlike pop, this lets you pass the object instead of the index. 
* **Slice:** You can slice a list to get a sublist. `sublist = letters[1:6]`
  * You can get the last 3 items of the list using: `sublist = letters[-3:]`
* **Sort** _does not return anything_ but sorts the existing list. You can sort a list using `existingList.sort()`
* **Sorted**  generates a new list without affecting the old one and uses the syntax `sorted(myList).` 
  * You can also sort in reverse order: `list1.sort(reverse=True).`

### [List Comprehensions](https://www.w3schools.com/python/python_lists_comprehension.asp)

Note: these examples were taken from my[ CodeCademy course.](https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-flow-data-iteration/modules/dspath-python-loops/cheatsheet)

Let’s say we have scraped a certain website and gotten these words:

```python
words = ["@coolguy35", "#nofilter", "@kewldawg54", "reply", "timestamp", "@matchamom", "follow", "#updog"]
```

We want to make a new list, called `usernames`, that has all of the strings in `words` with an `'@'` as the first character. We know we can do this with a for loop:

```python
words = ["@coolguy35", "#nofilter", "@kewldawg54", "reply", "timestamp", "@matchamom", "follow", "#updog"] 
usernames = []
for word in words: 
    if word[0] == '@':
        usernames.append(word)
    
>>> print(usernames)["@coolguy35", "@kewldawg54", "@matchamom"]
```

Python has a convenient shorthand to create lists like this with one line:

```python
usernames = [word for word in words if word[0] == '@']
```

This is called a _list comprehension._ It will produce the same output as the for loop did:

```python
["@coolguy35", "@kewldawg54", "@matchamom"]
```

This list comprehension:

1. Takes an element in `words`
2. Assigns that element to a variable called `word`
3. Checks if `word[0] == '@'`, and if so, it adds word to the new list, `usernames`. If not, nothing happens.
4. Repeats steps 1-3 for all of the strings in `words`

**Note:** if we hadn’t done any checking \(let’s say we had omitted `if word[0] == '@'`\), the new list would be just a copy of `words`

#### A second example: Filtering A List

```python
heights = [161, 164, 156, 144, 158, 170, 163, 163, 157] 
can_ride_coaster = [h for h in heights if h > 161] 
print(can_ride_coaster) # Returns numbers lareger than 161. 
```

#### [A third example](http://zetcode.com/python/listcomprehensions/): Change The Initial element

Note: taken from zetcode.

We have a list of temperatures in Celsius. We want to create a new list of temperatures expressed in Fahrenheit temperature.fahrenheit\_celsius.py

```python
#!/usr/bin/python3

celsius = [22, 28, 33, 42, 52]

fahr = [e * 9/5 + 32 for e in celsius]
print(fahr)
```

The example creates a new list of Fahrenheit temperatures calculated from a list of Celsius temperatures.

```python
fahr = [e * 9/5 + 32 for e in celsius]
```

The calculation is done in the third, expression part of the Python list comprehension.

{% code title="$ ./fahrenheit\_celsius.py " %}
```python
[71.6, 82.4, 91.4, 107.6, 125.6]
```
{% endcode %}

#### Fourth Example

Suppose we want to create empty list for each element in an existing list. We can do this with the following code.

```python
destinations = ["Paris, France", "Shanghai, China", "Los Angeles, USA", "São Paulo, Brazil", "Cario, Egypt"]
attractions = [[] for thing in destinations]

print(attractions)  # [[], [], [], [], []]
```



### Built In Functions

<table>
  <thead>
    <tr>
      <th style="text-align:left">Function</th>
      <th style="text-align:left">How to use it</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align:left">&lt;code&gt;&lt;/code&gt;<a href="https://www.programiz.com/python-programming/methods/built-in/range"><code>range()</code></a>&lt;code&gt;&lt;/code&gt;</td>
      <td
      style="text-align:left">
        <p><code>range(low_bound, upper_Bound, step)</code>
        </p>
        <ul>
          <li>Upper bound doesn&apos;t include upper bound. i.e. <code>range(10)</code> returns
            nums 0 to 9.</li>
          <li>Returns an immutable sequence.</li>
          <li>Steps can be positive or negative.</li>
          <li>It&apos;s a weird data type I don&apos;t understand.</li>
          <li>You can cast it to a list via:<code>list(range(start, stop, step)))</code>
          </li>
        </ul>
        </td>
    </tr>
    <tr>
      <td style="text-align:left">&lt;code&gt;&lt;/code&gt;<a href="https://www.programiz.com/python-programming/methods/built-in/zip"><code>zip(a, b, c)</code></a>&lt;code&gt;&lt;/code&gt;</td>
      <td
      style="text-align:left">
        <ul>
          <li>Zip takes iterables and aggregates them into a tuple.</li>
          <li>The iterables must be the same length. Any <em>extraneous values will be cut off</em>
          </li>
          <li>It casts to a <code>set()</code> or <code>list()</code>
          </li>
          <li>You can also unzip: <code>c, v =.zip(*results).</code>See the bottom of
            the link for a better explanation.</li>
        </ul>
        </td>
    </tr>
    <tr>
      <td style="text-align:left"><code>.index(element)</code>
      </td>
      <td style="text-align:left">
        <ul>
          <li>Gets the index given an. element.</li>
          <li><code>[&quot;foo&quot;, &quot;bar&quot;, &quot;baz&quot;].index(&quot;bar&quot;)</code> will
            return <code>1</code>.</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>

## Dictionaries

* **General Syntax:** `my_dictionary = {key: value, key: value}` 
* Keys must be immutable. Aka no lists.

{% embed url="https://www.codecademy.com/learn/paths/computer-science/tracks/cspath-python-objects/modules/cspath-python-dictionaries/cheatsheet" %}

### Add a Key

We can add multiple keys to a dictionary by using the `.update()` method. 

```python
locations = {}
locations['Paris'] = 100 
locations.update({"London": 75})
locations.update({"New York": 83, "Vancouver" : 110})

print(locations)
# {'Paris': 100, 'London': 75, 'New York': 83, 'Vancouver': 110}
```

#### Adding via defaultdict

* An easy way to start making a list is to use the `defaultdict` module.

```python
from collections import defaultdict

d = defaultdict(list)  # or set.
d['a'].append(1)
d['a'].append(2)
d['b'].append(4)
```

* _Warning:_ it will create dictionary enteries for keys accessed later on, even if they are not currently in the dictionary. If you don't want this behavior, you can call `d.setdefault()` on an ordinary dictionary. \(Beazley Jones 12\).

{% hint style="info" %}
This doesn't make sense to me.
{% endhint %}

### Get a Key

* The get method is best way to grab keys because you avoid an error if a key does not exist when using the `some_dictionary[key]` method.

```python
building_heights.get("Shanghai Tower", "default_val")  # use the .get() method.
```

You can also specify a value to return if the key doesn’t exist. For example, we might want to return a building height of 0 if our desired building is not in the dictionary:

```python
>>> building_heights.get('Shanghai Tower', 0)
632
>>> building_heights.get('Mt Olympus', 0)
0
>>> building_heights.get('Kilimanjaro', 'No Value')
'No Value'
```

### Overwriting Values

```python
menu = {"oatmeal": 3, "avocado toast": 6, "carrot juice": 5, "blueberry muffin": 2}
menu["oatmeal"] = 5  # Alternatively use .update()
print(menu) 
# {"oatmeal": 5, "avocado toast": 6, "carrot juice": 5, "blueberry muffin": 2}
```

### Replacing the Key

```python
mydict["new_key"] = mydict.pop("old_key")
```

### Deleting a Key

* Use the `dictionary.pop(key, defaultValueIfKeyDoesntExist)`

```python
>>> raffle
{223842: "Teddy Bear", 872921: "Concert Tickets", 412123: "Necklace", 298787: "Pasta Maker"}
>>> raffle.pop(100000, "No Prize")
"No Prize"
```

### Two Lists -&gt; Key

Let’s say we have two lists that we want to combine into a dictionary, like a list of students and a list of their heights, in inches:

```python
names = ['Jenny', 'Alexus', 'Sam', 'Grace']
heights = [61, 70, 67, 64]
```

Python allows you to create a dictionary using a list comprehension, with this syntax:

```python
students = {key:value for key, value in zip(names, heights)}
# students is now {'Jenny': 61, 'Alexus': 70, 'Sam': 67, 'Grace': 64}
```

Remember that `zip()` combines two lists into a zipped list of pairs. This list comprehension:

1. Takes a pair from the zipped list of pairs from `names` and `heights`
2. Names the elements in the pair `key` \(the one originally from the `names` list\) and `value` \(the one originally from the `heights` list\)
3. Creates a `key` : `value` item in the `students` dictionary
4. Repeats steps 1-3 for the entire list of pairs

Here's another example:

```python
drinks = ["espresso", "chai", "decaf", "drip"]
caffeine = [64, 40, 0, 120]

zipped_drinks = zip(drinks, caffeine)
drinks_to_caffeine = {drinks:caffeine for drinks, caffeine in zipped_drinks}
print(drinks_to_caffeine)
```

_Works Cited: Direct text from Codecademy -&gt; Python3 -&gt; List Comprehensions to Dictionaries_

### Get All Keys, Values, or Items \(as a list\)

#### Keys

* To get all keys you can just cast a dictionary to a list: `list(my_dictionary)`
* Alternatiely, dictionaries have a `.keys()` method which will produce an iterable `<class 'dict_keys'>` of keys:

```python
for student in university.keys():
    print(student)  # Will print out all students, assuming they are keys.
```

#### Values

* There is also a `.values()` method that produces an iterable of values.
* You can get all the values as a list by casting it via `list(test_scores.values())`

#### Items

* Use the `.items()` function to iterate through the items.

```python
biggest_brands = {"Apple": 184, "Google": 141.7, "Microsoft": 80, "Coca-Cola": 69.7, "Amazon": 64.8}
 
for company, value in biggest_brands.items():  # Key, Value in dictionary.ITEMS()
  print(company + " has a value of " + str(value) + " billion dollars. ")
```

### OrderedDict

* Ordered dictionaries maintain order when iterating.
* It preserves the original insertion order of data. 

```python
from collections import OrderedDict

fav_movies = OrderedDict()
fav_movies["Back to the Future"] = "I loved the car"
fav_movies["Race to Witch Mountain"] = "Had a crush on the actress"

for movie in fav_movies:
    print(movie, fav_movie[key])

# Returns
# Back to the Future I loved the car
# Race to Witch Mountain Crush on the actress
```

## Sets

* Sets are basically dictionaries, but just without keys and values. Just include values.
* Defined using `{something, something_else}`

## Heaps

* Use these if you have to implement some sort-of priority queue.
* My favorite resource is 1.5 from _The Python Cookbook \(below\)._

{% embed url="https://learning.oreilly.com/library/view/python-cookbook-3rd/9781449357337/ch01.html" %}

{% embed url="https://docs.python.org/3/library/heapq.html" %}

{% embed url="https://docs.python.org/3/library/heapq.html" %}



