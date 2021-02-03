# Scheme

## The Best Resource

{% embed url="https://www.scheme.com/tspl4/" %}

## Setup

* Dr.Racket is the ID E we will use.
* Racket is a dialect of scheme, so the syntax contains the Scheme syntax.

## Flow Control

#### If/Then/Else

```scheme
> (if (and (<= x 3) (>= x 2))  ; Test Expression
    "x is in range"  ; Then-expression 
    "x is Not in the range")  ; else expression.
```

#### Conditional Expressions

Example

```scheme
(cond {conditional_clause...})

con-clause = [test-expr then-body ...+] | [else then-body ...+]


```

Example: Grade Translation

```scheme
(define grade
  (lambda (x)
    (cond
    [(>= grade 90) "A"]
    [(>= grade 80) "B"]  ; Else if this holds... B
    [(>= grade 70) "C"]  ; Else if th is holds... C
    [(>= grade 60) "D"]
    [else "F"])))

(grade 90); err
```

Example: Divisible?

```scheme
#lang racket

(define divisible
  (lambda (x y)
    (if (integer? (/ x y))
        "Yes"  ; If condition is true.
        "No")))  ; Else

(divisible 10 2)
```

