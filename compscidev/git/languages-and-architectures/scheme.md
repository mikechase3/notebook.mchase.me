# Racket

## Works Cited

I closely follow along with the following book. If something in my notes doesn't make sense, you can look it up in here for a better explanation.

{% embed url="https://learning.oreilly.com/library/view/racket-programming-the/9781098128449/xhtml/ch01.xhtml" %}
Racket Programming the Fun Way
{% endembed %}

You might find the documentation helpful as well:

{% embed url="https://www.scheme.com/tspl4/" %}

## Setup

* Dr.Racket is the IDE we will use.
* Racket is a dialect of scheme, so the syntax contains the Scheme syntax.

## Data Types

### Primitives

* **Characters:** `\#a` is a character.
* Integers, floats, `pi` cover some of the numbers.
* To prevent an unbound identifier from being evaluated, prefix it with an apostrophe

```scheme
> alpha
. . alpha: undefined;
  cannot reference an identifier before its definition
  
> 'alpha  ; The apostrophe tells Scheme: 'don't evaluate this'
'alpha
```

### Lists & Quotes

Lists and quotes are nearly the same; however, lists will get evaluated while quotes return the list exactly as it was entered.

#### Lists Example

> Lists typically begin with an open parenthesis, (, followed by a list of space-separated items and end with a closed parenthesis, )
>
> ```
> > (list 1 (list "two" "three") 4 5)
> ```
>
> which prints as
>
> ```scheme
> '(1 ("two" "three") 4 5)  ; The apostrophe shows it's literal
> ```

#### Quotes Example

> ```scheme
> > (quote (3 1 4 pi))
> '(3 1 4 pi)
>
> > (list 3 1 4 pi)
> '(3 1 4 3.141592653589793)
> ```

#### Lists are S-Expressions

S expressions are defined to be one of two cases

1. An atom (or a really simple type)
2. In the form `(x . y)` where x and y are other s-expressions.

That form in the 2nd category is called a _pair_.

The picture below shows how S-expressions form binary trees where non-leaf nodes have 2 child nodes. (Photo from [Racket Programming the Fun Way](https://nostarch.com/racket-programming-fun-way))

![S-Expressions are Binary Trees](https://learning.oreilly.com/library/view/racket-programming-the/9781098128449/images/01fig01.jpg)

#### Cons Cells and List Structure

* The **cons** function creates a pair. i.e: `(cons 1 2)` returns `'1 . 2'`

![Each group makes up \`cons\` pair.](<../../../.gitbook/assets/image (455).png>)

> Cons cells can be created directly by using the cons function. Note that the cons function does not necessarily create a list. For example
>
> ```
> > (cons 1 2)
> '(1 . 2)
> ```
>
> produces a pair but _not_ a list. However, if we use an empty list as our second s-expression
>
> ```
> > (cons 1 '())
> '(1)
> ```
>
> we produce a list with just one element.

## Flow Control

### If/Then/Else

```scheme
> (if (and (<= x 3) (>= x 2))  ; Test Expression
    "x is in range"  ; Then-expression 
    "x is Not in the range")  ; else expression.
```

### Conditional Expressions

Example

```scheme
(cond {conditional_clause...})

con-clause = [test-expr then-body ...+] | [else then-body ...+]
```

#### Example: Grade Translation

```scheme
#lang racket

(define grade
  (lambda (x)
    (cond
    [(>= x 90) "A"]
    [(>= x 80) "B"]  ; Else if this holds... B
    [(>= x 70) "C"]  ; Else if th is holds... C
    [(>= x 60) "D"]
    [else "F"])))

(grade 90); err
```

#### Example: Divisibility

```scheme
#lang racket

(define divisible
  (lambda (x y)
    (if (integer? (/ x y))
        "Yes"  ; If condition is true.
        "No")))  ; Else

(divisible 10 2)
```

#### Built-Ins

You can also just call `(modulo 2 3)` or `(remainder 2 3)`

## Recursion

#### Example: Factorial

```scheme
(define fact
    (lambda (n)
        (if (= n 0)
            1  ; Base case 
            (* n (fact (- n 1))))))  ; Recursive call n-1
(fact 5)
```

#### Example: Display all Elements in a List

```scheme
#lang racket

(define disp
    (lambda (node)
        (if (equal? '() node) ; If node is already at the end of the list. 
            "end" 
            (begin  ; Using begin to sequence multiple expressions
                (display (car node))
                (newline)  ; Takes no arguments, moves to new line.
                (disp (cdr node))))))  ; List reference moves to the next one.
            
(disp '(w a t e r m e l o n))
```

#### Example: Linear Search in a List

```scheme
(define search
    (lambda (node x)
        (if (equal? '() node)
            (display "The given value is not found")
            (begin
                (if (equal? x (car node))
                    (display "The given value is in the list")
                    (search (cdr node) x))))))
(search '(a b c d) 'c)  ; 'c' is a symbol, so make sure to put a quote before it.
```
