# Datetime Package

## DateTime

* `from datetime import datetime`
* Print the current time: `datetime.now()`
* Get the date: `datetime.date()`
* Get the time: `datetime.time()`
*   Set a date & time:

    ```
    any_variable = datetime(year, month, day[, hour[, minute[, second[, microsecond[,tzinfo]]]]])
    ```

#### DateTime Arithmetic

We can subtract dates from each other to see how much time has elapsed.

```python
datetime(2018, 1, 1) - datetime(2017, 1, 1)  # Returns 'datetime.timedelta(days=365)
datetime.now() - datetime(1999, 6, 3)  # Returns how old Mike Chase is.
```

### Strptime: Strings to datetime objects

Oftentimes, we'll get the information in the form of a string. We can use `datetime.strptime()` to tell it how we've formatted the date and time in our string.

```python
parsed_date = "Jan 16, 2018"  # Converting to datetime using the reference below.
actual_date = datetime.strptime(parsed_date, '%b, %d, %Y')  # Tells python how this is formatted.
# Now it's in a datetime object.
```

{% embed url="https://strftime.org/" %}

### Strftime: Datetime objects to strings

This creates a string from a datetime. It's very similar to `strptime` but just in reverse

```python
date_string = datetime.strftime(datetime.now(), '%b %d, %Y')
# Returns: 'Jan 17, 2020'
```
