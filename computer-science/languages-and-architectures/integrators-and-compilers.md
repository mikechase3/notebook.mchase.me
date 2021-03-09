---
description: CPS 352 Equivalent.
---

# Concepts & Implementations

## Concepts and Implementations of Languages

* Office hours are by appointment only.
* Ask the difference between abstract types and static methods.
* Homework: read chapter 1.

{% tabs %}
{% tab title="Schedule" %}


![](../../.gitbook/assets/image%20%2881%29.png)
{% endtab %}

{% tab title="Topics" %}
### What we'll Study

* Compiled vs. Interpreted Languages
  * What are the advantages/disadvantages?
* Formal languages & grammar
  * How to define syntax.
  * What is the right way to write a statement?
* Scanning and Parsing \(Semantics\)
  * How to recognize some statements
  * How do you integrate statements?
  * How can we execute a statement?
* Binding & Scope
  * How do we define variables?
* Types
  * How do we associate those variables with types?
* Local binding & Conditional Evaluation?
  * How can we evaluate expressions?
* Functions and closures
  * How can we explain and integrate sub-procedures?
* Functional Programming \(Scheme\)
{% endtab %}

{% tab title="Languages We\'ll Learn" %}
### Languages We'll Learn

1. Fortran 77
2. C & C++
3. Java
4. Python
5. **Racket**, a functional language of scheme. It has an open source IDE called Dr. Racket
{% endtab %}
{% endtabs %}



## Languages Introduction

### Comparing Programming Languages

{% tabs %}
{% tab title="Pure" %}
#### What is Pure Interpretation

* The source code is run directly by an interpreter.

#### Advantages

* No translation is required before running
* Easy debugging
* Easy transplanting

#### Disadvantages

* More resource costly.
* Slow Execution

#### Examples

* Python
* Matlab

![](../../.gitbook/assets/image%20%28195%29%20%281%29.png)
{% endtab %}

{% tab title="Hybrid" %}
#### What is it?

* A tradeoff between pure compiled languages and pure interpreted languages.
* It uses a virtual machine.

#### Advantages

* Good efficiency.
* Easy transplanting: _runs on different operating systems easily. Doesn't require recompiling._

#### Disadvantages

* More costly than pure compiled languages.
* Debugging is slightly easier than compiled languages, but not as good as pure languages.
* A translation to intermediate code is required before running.

#### Examples

* Java
* .NET languages

![](../../.gitbook/assets/image%20%2870%29.png)
{% endtab %}

{% tab title="Compiled" %}
#### What are they?

#### Advantages

#### Disadvantages

#### Examples

* C/C++
{% endtab %}
{% endtabs %}

### Programming paradigms

{% tabs %}
{% tab title="Procedual" %}
#### Characteristics

* FORTRAN, Pascal, C.

#### Advantages

#### Disadvantages

#### Examples

* FORTRAN, Pascal, C.
{% endtab %}

{% tab title="Object Oriented" %}
#### Characteristics

#### Advantages

#### Disadvantages

#### Examples

* Smalltalk \(Academia\)
* C++ / Java
{% endtab %}

{% tab title="Functional" %}
#### Characteristics

* **Languages**: LISP, Scheme, Haskell, Racket \(dialect of Scheme\).
* The design tries to minimize the syntax content _e.g. no main method, class keyword, virtual, static to make your program very simple and concise._
* When you remove these, it makes your program harder to read.
* Most of these programs look like math formulas but their definitions are \(too\) simple and concise. 

#### Advantages

* Less syntax.
* Concise.

#### Disadvantages

* Everything looks like math formulas.
* No english-looking language.
* Hard to read.
* Scheme is an exception, but loops are typically handled with recursions because in formal mathematics, loops are handled by recursion.

#### Examples

![Recursively computing a factorial in Scheme](../../.gitbook/assets/image%20%28217%29%20%281%29%20%281%29%20%281%29.png)

* All expressions using scheme use prefix notation: `if( (= n 0)`  checks whether n is equal to zero or not.
  * If it's true, return 1. _We see it's really simple. It's just_  `1` _which eliminates so much syntax._
  * The second line is the 'else' condition. 
* In scheme, the nested structures use parenthesis. 
{% endtab %}

{% tab title="Logic" %}


#### Characteristics

* All of the statements are logic formulas.
* Languages: Prolog, ASP, CLP

#### Advantages

* Less syntax

#### Disadvantages

* Really only used in academia.

#### Examples

![](../../.gitbook/assets/image%20%28215%29.png)

* The first line is the base case.
* The second line and indented lines describe the recursive call.
* `F1` is like a return value. 
{% endtab %}

{% tab title="Scripting or Domain-Specific" %}
#### Characteristics

#### Advantages

#### Disadvantages

#### Examples

* JavaScript, PHP, Python, Flash. 
{% endtab %}
{% endtabs %}

### Parsing Programs

* We can define high priorities for division and multiplication and low priorities for addition and subtraction.
* We can evaluate expressions so `+-` is an illegal operator.
* We can also have programs throw errors, such that `int i = 3.0` is illegal without typecasting.
* Parsers must recognize when `+` is used for concatenation or adding integers depending on the context.
  * Different contexts have different roles. 
* When do we pass by reference and when do we make copies?

## Syntax and Semantics

![Chomsky Hierarchy](../../.gitbook/assets/image%20%28379%29.png)

### Applications of Regular Languages

* **Identifiers:** are naming rules for variables, functions, and classes.
  * Two identifiers can have the same name if they are both out of scope.
  * Variables must start with a letter and must only contain numbers/underscores.
* **Formats of constants:** integers, floating-point numbers, characters, strings
  * We can put a `+/-` in front of an integer.
  * You can also use scientific notation in many languages.
  * The finite automata used to read these formats is included within the language.
* **Keywords:** 
  * Easiest because there's not transitive/kleans closure.
  * There is only one word that you can define in a regular language.

### Translating a Finite Automaton to an Algorithm

![](../../.gitbook/assets/image%20%28383%29.png)

* Input: a word or string of characters.
* Output: true if the word belongs ot the regular language described by the automation, otherwise false.
* Simulating the FA \(finite automata\) according to the given word. If the run terminates in a final state, then returning ttrue. Otherwise return false.
* We assume that the FA is deterministic since an NFA can always be equivalently translated to a DFA.

### Lexical Analyzer using a Type-3 Grammar

1. Translating the type-3 grammar to a regular expression.
2. Constructing a finite automaton which exactly accepts the language defined by the regular expression.
3. Translating the finite automaton to an algorithm
4. Implementing the algorithm

![](../../.gitbook/assets/image%20%28380%29.png)

### What is Grammar?

* Grammar is used to formally define a syntactic structure, or a language
* Grammar has a finite set of rewrite rules defined in the form A-&gt;B. For any rule A-&gt;B, we say that B is derived from A.
* A, B are sequences of pre-defined symbols which are called terminals \(an alphabet\) and nonterminals \(variables\).
* Has a start symbol which can be a terminal or nonterminal.
* A word `w` is generated by a grammar. If there is a finite step derivation $$S \implies E_1 \implies E_2 \implies w$$ such that `s` is the start symbol and all derivations follow the rewriting rules.
* It is denoted as a tuple \(V, S, Σ, P\)

### Regular Grammar \(Type-3 Grammar\)

If and only if a grammar is regular:

![](../../.gitbook/assets/image%20%28381%29.png)

## 

## Works Cited

* [Chen, Xin. Concepts and Implementations of Programming Languages. Lecture 3](https://udayton.edu/directory/artssciences/computerscience/chen-xin.php)



