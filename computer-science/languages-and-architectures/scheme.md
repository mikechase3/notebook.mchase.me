# Scheme

## The Best Resource

{% embed url="https://www.scheme.com/tspl4/" %}

## Setup

* Dr.Racket is the ID E we will use.
* Racket is a dialect of scheme, so the syntax contains the Scheme syntax.

## Data Types

* **Characters:** `\#a` is a character.

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

