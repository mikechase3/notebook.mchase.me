# Golang

{% embed url="https://learning.oreilly.com/library/view/head-first-go/9781491969540/ch03.html" %}



## Syntax Basis

* Declare on the first line `package main` or else your code won’t run.
* Runes are `chars`.
* There are lots of stupid data types. `int` has `int64` and `int32` and `int8` and probably more and you can’t use comparison operators using them because they are diferent types. You have to cast an `int64` to an `int` to compare them and I don’t know what that does.
  * Same goes for floats.
* **Go Commands**
  * `go fmt` formats your source file automatically and indents things.
  * `go build` compiles your code to an executable.
  * `go run` compiles it without saving the executable.

## Conditionals, Loops, Functions

* Call methods using the import hethod. Like `import time`
* You have to declare `func main(){...}` because it’s the first thing Go will run.
* Here’s an example of calling a method: `var now time.Time = time.Now()`
  * It is a type of ‘time’ even though I thought there were no objects.
  * It gets the time from the time function.
  * Go can sort-of be object oriented. [http://play.golang.org/p/LGB-2j707c](http://play.golang.org/p/LGB-2j707c)
* Functions can return multiple things.
  * To discard a resut, assign it to `_`. 
* For loops have no parenthesis:
  * `for x :=4; x <=6; x++{...}`
  * Initializer \(`x :=4`\) and post statements \(`x++`\) are optional.
  * Break and continue work like any other language.
* 
