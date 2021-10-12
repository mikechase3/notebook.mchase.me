# NP Completeness (L21)

## Complexity Theory

![Different problems have different amounts of difficulty.](<../../../.gitbook/assets/image (132).png>)

* An entire field in one lecture.
* We're going to show that Super Mario Bros is NP Complete.
* This is all about reductions and converting one problem into another.

![](<../../../.gitbook/assets/image (130).png>)

This expands out to cover NP:

![](<../../../.gitbook/assets/image (110) (1) (1).png>)

### Polynomial Time (P)

* P is the set of all problems that can be solved in polynomial time.
* **Polynomial:** $$n^{\text{some constant}}$$ 

### Exponential Time (EXP)

![We try to bring anything exponential into polynomial time as much as possible](<../../../.gitbook/assets/image (129).png>)

* EXP is the set of all problems you can solve in exponential time.
* Exponential means $$2^{n^\text{some constant}}$$ 

### Recursive (R)

* Describes problems that are solvable in a finite time.
* Most problems are not solvable.

### Nondeterministic Polynomial (NP)

![](<../../../.gitbook/assets/image (133).png>)

* _**NP **_describes a set of decision problems:
  * Solvable in polynomial time via a _lucky _algorithm.
  * _**Lucky**: Lucky algorithms make guesses. It just needs to try 1 problem because it's really lucky and always guesses the right choice. _
* _**NP decision**_ problems are solvable in _**nondeterministic**_ _**polynomial**_ time.
  * Polynomial:  $$n^{\text{some constant}}$$ 
  * _**Nondeterminstic: **_in O(1) time, you can _guess_ among polynomial number of choices. If the computer guesses a yes answer, then we get such a guess.
  * _**Decision**_: The output is yes or no.

{% hint style="info" %}
When the answer is YES, you can prove it and check that proof in polynomial time. Your proof is the sequence you choose.
{% endhint %}

#### Nondeterministic Model

![](<../../../.gitbook/assets/image (128).png>)

* An algorithm that makes guesses and then says _yes_ or _no_.
* You give it a list of choices, and somehow, a choice is made (by magic, it just chooses)
* The guesses are guaranteed to lead to a _yes_ answer if possible.

### NP Complete

![](<../../../.gitbook/assets/image (134).png>)

* _**NP-Complete**_ if $$\exists x: (x \in \text{NP} \land x \implies \text{NP-Hard}) \implies \text{NP-Complete})$$ 
  * Problem X is NP-Complete if X is in NP and X is _NP-Hard_
  * _You are exactly as hard as NP. No harder and no easier._
* Bonus: [Mario is computationally hard](https://arxiv.org/abs/1203.1895).

### NP Hard

* _**NP-Hard**_ if every problem $$Y\in \text{NP}$$ reduces to X.
* In English, NP hard means that it's at least as hard as every problem in NP.
  * If $$P \neq \text{NP} \implies x \notin P$$ 
    * Aka: Your problem is not polynomial solvable.
  * \[Reduction from problem A to problem B] = \[polynomial-time algorithm converting A inputs into equivalent _(same yes/no answer)_ B inputs]
    * Equivalent means it has the same yes/no answer.
    * _**Reduction**_: Polytime algorithm converting A inputs -> equivalent B inputs.
    * If B has a polynomial time algorithm, than so does A because you can just convert A into B and then solve B.
    * This works for nondeterministic algorithms.
  * If I can solve B, then I can solve A, so B is at least as hard as A.
* Tetris is _NP-hard_, meaning "as hard as" every problem in NP.

![](<../../../.gitbook/assets/image (106).png>)

{% hint style="warning" %}
* What is NP? 
  * Not polynomial?
  * Did I define it right?
* How do I know if something is in NP?
* How do I know if NP is hard?
* What is the definition of a _problem _in this case? 
  * Like a function? 
  * Like binary search is a problem that's O(log(n))?
* What do the handwritten notes mean?
{% endhint %}

### How to Prove X is NP-Complete

#### Purpose

Look, I don't need to look for algorithms anymore because my problem is too hard because it's as hard as everything in NP.

{% hint style="warning" %}
What is problem y and what is problem x?

They're both problems. What's the difference?
{% endhint %}

![](<../../../.gitbook/assets/image (107).png>)

### Exptime

![](<../../../.gitbook/assets/image (136).png>)

* Exptime contains problems that are not solvable in P.

### Summary of Complexities

That are useful for me to know thus far:

![](<../../../.gitbook/assets/image (135).png>)

## Reductions: $$A \implies B$$ 

Convert your problem into a problem you already know how to solve instead of solving it from scratch.

![](<../../../.gitbook/assets/image (127).png>)

### Dijkstra's Example 

* Suppose your friend gives you a problem for unweighted Shortest paths.
* How do you solve unweighted paths? Do BFS if you're smart.
* But suppose someone gave you dijkstra's code and goes "how do you do it?" Just set all the weights to 1.
  * Weighted -> Unweighted. //Just set all the weights to 1.



## 3 SAT (Satisfiability)

![SAT is the king of NP. SAT is able to completely represent every other problem in NP. That makes SAT NP Complete.](<../../../.gitbook/assets/image (126).png>)

### Problem

* I'm given a formula which is an AND of ORs. Each OR clause only has 3 things in it. 
  * The things are called _literals._
    * _Literals_ is either a variable _x_i _or it's the negation of a variable, _not x_i_.
  * _**Clauses**_ are groups of 3 things.
* _**Question: **_Can you set the variables: (x\_1, x\_2, x\_3...) such that the **formula comes out true?**

![3 SAT Problem](<../../../.gitbook/assets/image (109).png>)

* I have to satisfy the first clause in one of 3 ways. One of the first set should be true, and something in the 2nd clause needs to be true, and so on.
  * We don't know a polynomial time algorithm, there probably isn't one.
  * BUT, there is a polynomial time nondeterministic algorithm.
  * So this problem is in NP because...
    * If I have lucky guesses, I'm going to guess whether x\_1 is true or false.
    * So I have true choices, then I'm going to ask my machine to make the right choice.
    * Then I'll guess x\_2. Each guess operation take O(1) time, so you do it for every variable.
    * Then I'm going to check if I satisfy the formula.
* If the whole thing comes out as true, I'll return yes. If not, it will come out no.
  * If there is some way to satisfy the formula, I'll return yes.
  * If there is no way to satisfy for the formula, then this nondeterministic algorithm will return no.

![](<../../../.gitbook/assets/image (105).png>)

### Guessing

* You can always arrange for your guessing to be at the beginning.
* Then do some regular polynomial time checking, a deterministic checking.

#### Verification Formula

* It's easy to verify...
  * Your friend thinks that there's a way to set it up so that it's true.
  * This is called a satisfying assignment.
  * Then you're like "I don't believe you."
  * And your friend is like "no no no, this is true, I can prove it."
    * If your friend tells you what the x_i's are, then you can quickly check that the solutions are valid.
    * But you can only do this for 'yes' answers.
  * At the least, _**you can check your answers in polynomial time**_.
* If your friend say no, this is not satisfiable...
  * You have to check all the assignment separately.
  * Your friend cannot prove this to you.

### Summary

* NP = {Decision problems with polynomial size certificates & polynomial time verifiers for YES inputs}
  * This is an equivalent definition of NP.
  * You can call these guesses that it's a certificate of yes.
  * Then you have a regular polynomial time algorithm. That given that certificate, it will verify and prove that the answer is yes.
  * That certificate has to be polynomial size.
    * You can't guess something that's exponential size in this model.

{% hint style="warning" %}
What is a certificate? What is a verifier? These don't make sense.
{% endhint %}

### Proving NP Completeness of Your Algorithms

#### Step 1: Show $$x \in \text{NP}$$ 

![Showing that our problems are in SAT means our problem is in NP.](<../../../.gitbook/assets/image (125).png>)

* Recall: We can do this by using:
  * A nondeterministic algorithm
  * Certificate + verifier.
* We defined the certificate
* We provide a verification algorithm that checks if everything is true or not.
* Now we can conclude $$\text{problem } x \in \text{NP}$$ 

#### Step 2: Reductions

* Reduce from known NP-complete problem Y to x.
* The definition says you should reduce every problem in y to x.
  * That's tedious because there are lots of problems.
  * I'd like to do it just for one.
  * If I reduce sorting, it says my problem is at least as hard as sorting.
  * But if I start from an NP-Complete problem, I know that by definition, every problem in NP can be reduced to that problem.

{% hint style="warning" %}
I don't understand reductions or these definitions very well.
{% endhint %}

#### Proof Your Own Algorithms Summary

![Choose a problem and reduce it down to prove something is NP Complete](<../../../.gitbook/assets/image (118) (1) (1) (1).png>)

* Cook proved (through a pain in the a\*\*) that the 3SAT problem is NP complete.
* Now, you just have to pick your favorite problem, and reduce from any known problem (like 3SAT) to your problem that you're trying to prove is NP Hard.
* Bonus: [proof](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-045j-automata-computability-and-complexity-spring-2011/lecture-notes/MIT6\_045JS11\_lec16.pdf) of 3SAT in 6.045

## Super Mario Bros

![Super Mario Bros is a 3SAT Problem (see works cited).](<../../../.gitbook/assets/image (124).png>)

### Generalized Problem

* We're going to reduce 3SAT to Super Mario Brothers, but we have an arbitrary screen size. My entire level will be in one big screen and forget about the side scrolling example.
* We're are tasked to determine: **can you get to the end of this level?**

### 3SAT Reduction

![](<../../../.gitbook/assets/image (121).png>)

{% hint style="info" %}
See a full explanation [here](https://www.youtube.com/watch?v=oS8m9fSk-Wk\&list=PLlwsleWT767dnN25K_QgvdKkovK_t4K6-\&index=8\&t=36s).
{% endhint %}



## Further Examples

![](<../../../.gitbook/assets/image (122).png>)



## Works Cited

Erik Demaine, and Srini Devadas. _6.006 Introduction to Algorithms. _Fall 2011. Massachusetts Institute of Technology: MIT OpenCourseWare, [https://ocw.mit.edu](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011). License: [Creative Commons BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/). Lecture 23.

Erik Demaine, Srini Devadas, and Nancy Lynch. _6.046J Design and Analysis of Algorithms. _Spring 2015. Massachusetts Institute of Technology: MIT OpenCourseWare, [https://ocw.mit.edu](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-design-and-analysis-of-algorithms-spring-2015). License: [Creative Commons BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/). Lecture 16.

Chang, Cory. [_P vs. NP - An Introduction_](https://www.youtube.com/watch?v=OY41QYPI8cw)_. _Undefined Behavior.

Chang, Cory. [_What Makes Mario NP-Hard? (Polynomial Reductions)_](https://www.youtube.com/watch?v=oS8m9fSk-Wk\&list=PLlwsleWT767dnN25K_QgvdKkovK_t4K6-\&index=8\&t=36s)_. _Undefined Behavior.

\
