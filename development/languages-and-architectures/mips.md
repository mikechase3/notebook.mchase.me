# MIPS

\\#\\#Day \\#\\##Heading \\#\\###Subheading

## See Notability for missing information

Summarize this later.

## Jan 23, 2020

### Branch is equal `beq`

`beq` means _Branch is equal_ Example: `beq $2, $4, loop //the loop is a target address`

#### BEQ Example Program

```java
beq $2, $4, loop /At register 100
Add $5, $3, $7 //At register 104
Add $6, $6, $7 //108
Loop: add $5, $3, $8 //Instructions at 112.
```

&#x20;This is what’s happening in the computer.&#x20;

#### Review of formats

* R-format
*   I-format

    **Branch not equal `bne`**

    Goes to the loop if the branch is not equal.

    Example: `Ben $2, $4, loop`
* If two is not equal to 4, go to the loop.

### Jump

*   It is unconditional.

    `j`: Always jump, no condition.

    ```java
    j //loop, stored at location 100.
    Add //stored at location 104
    Lw //108
    add //112
    Loops: add //116; not sure if "loops" is a part of the code.
    ```

#### Review of Architecture (using J-Format)

The J-format is nice because it only contains op-code. Everything else is space for your code (I think). Bullets below needs review for accuracy.

* Each instruction takes 4 bytes.
* Memory stores 8 bytes.
* The register file stores 32 bits
* Your code used to be limited because of the way things were setup.
*   Also the compilers limited how large your cod was. (Not these days).

    **Comparing Things**

    **Set Less Than (SLT)**

    The following command compares 4 to 5.

    ```java
    slt $2, $4, $5 //destination, register 1, register 2
    ```
* Follows R-format.
* Sets the destination register to 1 or 0 based on the contents of the register.
*   The destination is set to `0` if false, and `1` if true.

    **Branch Greater Than (BGT)**
*   Pseudo code that _doesn’t exist_

    Below is a pseudo instruction. These are on the green sheet.&#x20;

    ```java
    bgt $4, $5, loop //Will jump to the loop if $4 > $5.
    ```

    **Branch Grater or Equal (BGE)**
*   Pseudo code that also doesn’t exist.

    **Coding Challenge**

    Write the code that is equal to this _branch grater than_ method using other methods.

```java
slt $2, $5, $4 //set register 2 to 0 if $5>$4 Maybe?
Bne $2, $0, loop//if the contents of register 2 is not equal to register 0, go to the loop.
```

### Homework

* Review: branch less than, branch greater than, ble, bge, li, move. These are pseudo instructions.&#x20;
* Li means load immediate.`add i into register 2, add register 0 with 5. Means add i, $2, $0, 5.`
* move $5, $6: `add $5, $6, $0 //add 0 to register 6.`

## Jan 28, 2020

### Reviewing Arrays

Write the following code similar to the homework.

```java
while (j<5){
    A[i] = A[j+1];
    j = j+1;
    i = i+1;
}
```

&#x20;Continuing from above

```java
li $1, 0, --i //Load immediate, same as handwritten in box.
li $t2, 0, --j
li $3, 5
slt $s1, $t2, $t3
beq $5, $0, end.
add $t5, $t2, $t2 //
add $t5, $t5, $t5//Equal to 4j
add $t6, $t5, $s2 //t6 is now your index.
lw $t7 4, ($t6) //Reference 03

//Now we have to do i and multiply i by 4.
add $t8, $t1, $t1
add $t8, $t8, $t8 //4i?
add $t9, $t8, $s2
sw $t7, 0 ($t0)
addi $t2, $t2, 1
j loop

endi.
```

### How to write Functions

Let’s say you have a function that returns `number * 4`. The name is `mfowr`. 1. The first thing Is to put the parameter in the register.&#x20;

**Move**

**move** moves one register to another.

* It’s pseudocode.
*   It means the same as `addi $v0, $t, 0`

    **jr**

    `jr` returns the register address `$ra`

    **jal**

    `jal` stands for jump and link and is used to call a function.

### Stack Space & Memory

&#x20;1\. We call A. 2. A says `jal B`. Once it goes there, it puts `600` into A. 3. The next value of `A` is now `124`. 4. Then you call C and it’s overwritten by `224`. 5. Then you go to `D` and it does a `jr $ra` (jump/return address). 6. It jumps back to `316`. 7. It’s supposed to go to `240` but it doesn’t (see red line). 8. If it was a recursive function, we would over-fill our register, but we have more memory.&#x20;

## Jan 30, 2020; On Section 2.8

We started off with a fake quiz that I did all myself, but took forever. I made progress, so that’s good.

### Review of Instructions

**move** is pseudo instructions that move one register to another. **jr** is the

#### Practice Problem (See p.98)

Write the following function in assembly:

```java
int leafExample(int g, int h, int i, int j){ //Assume $a0, $a1, $a2, $a3
    Int f; //f is stored into -> s1.
    P = (g+h)-(i+j);
    Return f;
}
```

* There are some global variables you don’t want to mess with.
*   We save them by storing things into temporary variables.

    \`\`\`java

    add $t0, $a0, $a1

    Add $t1, $a2, $a3

    Sub $s1, $t0, $t1

    Move $V0, $s1 #//Move is pseudo code.

    //I'm confused at the rest. Might not be in order. He drew arrows.

$addi, 4sp, $sp, -4 Sw $s1, 0 ($sp) Jr $ra lw $s1, $sp, 4 Jr $ra

````
Then store the temporary variables into the stack too so your program never gets screwed up.
```java
addi, $sp, $sp, -12
Sw $s1, 0, ($sp)
Sw $t0, 4, ($sp)
Sw $t1, 8, ($sp)
Add $t0, $a0, $a1
Add $t1, $a2, $a3
Sub $s1, $t0, $t1
Move $V0, $s1
Lw $t1, 8, ($sp)
Lw $t0, 4, ($sp)
Lw $t0, 4, ($sp)
Addi $sp, $sp, 12
Jr $ra
````

*   Anytime you assign something to an `S` register like `$s3`, you have to save it by using `sw $s1, 0 ($sp)`.

    **Recursive Functions**

    See p.101: _Compiling a recursive C procedure, showing nested procedure linking_ from the book.

    ```java
    int fact (int n){ //n gets stored at $a0
      If (n<1) return (1):
          Else return (n * fact(n-1));
    }
    ```
* Write this in assembly. The stack will have lots of things.
*   Assume n = 3.

    \`\`\`java

    fact: addi, $sp, $sp, -8 //Fact is the name of the function. Store two numbers.

    Sw $a0, 0 ($sp)

    Sw $ra, 4 ($sp)

    Li $t0, 1 //Load immediate.

    Slt $t1, $a0, t0 //Compare. If less, than put flag it by making $t1 = 1.

    Beq $t1, $s0, else

Else addi $3, 0, Li $V0, 1 //Stores 1 in the return variable. Jr $ra //Return 1.

\`\`\`

## Feb 4, 2020

&#x20;We have a quiz on Thursday.

## February 6, 2020

### System Call

`syscall` will print out things to the console. System call services.&#x20;

## February 18, 2020

### The Adder

The adder is like a black box. It takes inputs a, b, and c. Then it sums it and carries out any overflow value. C out means carry out.
