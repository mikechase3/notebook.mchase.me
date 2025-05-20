# R Mean, Median, and Mode

## Calculating Mean

### Ex 1: Sum These Four Numbers

* Objective: sum the numbers 29, 49, 42, 43 and save the answer in the variable `total`. Print `total`

#### Solution

My first attempt was to reference the [cheat sheet](https://isidore.udayton.edu/access/lessonbuilder/item/29574372/group/d6082308-ebf3-4045-9a06-a4d7a6611751/Lessons/base-r.pdf) and use a for-loop like so.

````r
---
title: "Mean in R"
output: html_notebook
---
```{r}
data = c(29, 49, 42, 43)

total = 0
for (i in data){
  total = total + i
}
print(total)
```
````

However, the _simplest_ solution is save it to a variable & print.

```
total <- 29 + 49 + 42 + 43
```

### Ex 2: Average the 4 numbers

_Tags: string concatenation, length of arrays, length()_

* Review [string concatenation](https://www.math.ucla.edu/\~anderson/rw1001/library/base/html/paste.html) in base r.&#x20;
* Syntax: `print(paste("The total is: ", toString(total)))`

Here's one way. Not the shortest, but it works:

````
# Get the sum
data = c(29, 49, 42, 43)

total = 0
for (i in data){
  total = total + i
}
print(paste("The total is: ", toString(total)))

# Now find average
mean_value = total / length(data)
print(paste("The mean value is: ", toString(mean_value)))

```
````

### Ex 3: Use Built-In Function

We can use `mean(<array of integers>)` to have R calculate the mean for us:

```
ages <- c(24, 16, 30, 10, 12, 28, 38, 2, 4, 36)
example_average <- mean(ages)
print(example_average)  # Returns 20, the resulting average of this array
```

