---
description: Functions, unpacking operators (*args, **kwargs), generators
---

# Functions, Lambdas, Unpacking, Generators

## Functions

### Summary of Function Arguments

> Summary from codecademy course I took:
>
> <pre class="language-python"><code class="lang-python"><strong># Pretend this is a restaurant
> </strong><strong>tables = {
> </strong>  1: {
>     'name': 'Jiho',
>     'vip_status': False,
>     'order': {
>       'drinks': 'Orange Juice, Apple Juice',
>       'food_items': 'Pancakes',
>       'total': [534.50, 20.0, 5]
>     }
>   },
>   2: {},
>   3: {},
>   4: {},
>   5: {},
>   6: {},
>   7: {},
> }
>
> def assign_table(table_number, name, vip_status=False): 
>   tables[table_number]['name'] = name
>   tables[table_number]['vip_status'] = vip_status
>   tables[table_number]['order'] = {}
>
> def assign_food_items(table_number, **order_items):
>   food = order_items.get('food')
>   drinks = order_items.get('drinks')
>   tables[table_number]['order']['food_items'] = food
>   tables[table_number]['order']['drinks'] = drinks
>
> def calculate_price_per_person(total, tip, split):
>     total_tip = total * (tip/100)
>     split_price = (total + total_tip) / split
>     print(split_price)
>
> </code></pre>





### Function Arguments

There are 3 types of arguments in functions:

1. Positional arguments (where order matters)
2. Keyword arguments (called by their name)
3. Default arguments (given as default values)

```python
# Imagine there's tables in a restaurant
tables = {
  1: ['Jiho', False],
  2: [],
  3: [],
  4: [],
  5: [],
  6: [],
  7: [],
}  Currently: # {1: ['Jiho', False], 2: [], 3: [], 4: [], 5: [], 6: [], 7: []}


def assign_table(table_number, name, vip_status=False):
  """Assigns a table to a customer"""
  tables[table_number] = [name, vip_status]

assign_table(6, 'Yoni', False)  # Positional arguments. Last one is redundant.
assign_table(4, "Karla")  # So we can just omit it. 
# Or use keywords to place them in any order.
assign_table(name="Martha", table_number=3, vip_status=True)

print(tables) 
# {1: ['Jiho', False], 2: [], 3: ['Martha', True], 4: ['Karla', False], 5: [], 6: ['Yoni', False], 7: []}
```

### \*args Unpacking Operator

The `print("hello", "world", "!")` takes an unlimited number of arguments and processes them using the unpacking operator.

<pre class="language-python"><code class="lang-python">def custom_print(*unlimited_args_here) -> Tuple[int, ...]:
    # print(unlimited_args_here)
    return unlimited_args_here  # in the form of a tuple. 
    
def shout_strings(*args):  # (Example from codecademy: intermediate python)
  for argument in args:
    print(argument.upper())
 
shout_strings('Working on', 'learning', 'argument unpacking!')

# Returns: 
<strong># WORKING ON
</strong># LEARNING
# ARGUMENT UNPACKING!
</code></pre>

### \*\*kwargs Keyword Args Dictionary

* type(\*\*kwargs) => Type\<Dictionary>

Example from Codecademy's intermediate Python course:

```python
def arbitrary_keyword_args(**kwargs):
  print(type(kwargs))
  print(kwargs)
  # See if there's an 'anything_goes' keyword arg and print it
  print(kwargs.get('anything_goes'))
 
arbitrary_keyword_args(this_arg='wowzers', anything_goes=101)
```

### Unpacking Other S\*\*\*

From Codecademy:

> The possibilities of using the `*` and `**` operators are endless. Observe some more clever use cases:
>
> *   Unpacking parts of an iterable
>
>     ```
>      a, *b, c = [3, 6, 9, 12, 15] print(b)
>     ```
>
>     Would output:
>
>     ```
>     [6, 9, 12]
>     ```
> *   Merging iterables
>
>     ```
>     my_tuple = (3, 6, 9)merged_tuple = (0, *my_tuple, 12)print(merged_tuple)
>     ```
>
>     Would output:
>
>     ```
>     (0, 3, 6, 9, 12)
>     ```
> *   Combining unpacking and packing
>
>     ```
>     num_collection = [3, 6, 9] def power_two(*nums):   for num in nums:    print(num**2) power_two(*num_collection)
>     ```
>
>     Would output:
>
>     ```
>     9 3681
>     ```
>
>
>
>

### Returning Multiple Values

We can return multiple values. It's so amazing!

```python
def get_boundaries(target, margin):
  low_limit = target-margin
  high_limit = margin+target
  return low_limit, high_limit

low_limit, high_limit = get_boundaries(100, 20)
```

###

### [Lambda Functions](https://www.youtube.com/watch?v=25ovCm9jKfA)

![Source: Socratica. My Favorite Beginner Python Series of 2020.](<../../../../.gitbook/assets/image (395).png>)

![Source: Socratica. My Favorite Beginner Python Series of 2020.](<../../../../.gitbook/assets/image (393).png>)

## Generators

* Generators are basically functions, but use the `yield` keyword instead of `return`
* When a generator is called again, the function picks up right where it left out
  * Functions by contrast will start at the beginning of the function.

{% embed url="https://www.youtube.com/watch?v=bD05uGo_sVI" %}

End of Functions
