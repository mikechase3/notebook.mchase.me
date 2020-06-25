# Java Review

1/14/20-1/28/20 \# Title \#\# Lecture Focus \(Classes/Objects, Memory, Inheritance, Interfaces\) \#\#\# Major Sub-Topics \#\#\#\# Questions, Examples, More \#\#\#\#\# More if necessary.

## Classes and Objects

### String Objects

* String reference variables hold the address of the object, not the object itself.

  \`\`\`java

  String s = new String\(\);

  S = "hi";

  String s2 = s; //Copies the address and reference stored in s to s2.

```text
Now s and s2 reference the same object.
```java
//Construct a copy of object, assign its address to s3
String s3 = new String(s);
```

Now s3 points to a new object with the same value.

* In Java, unlike other objects, Strings are immutable _menaing once they’ve been constructed, their contents never change_.

  \`\`\`java

  S2 = s.toUppercase\(\); //a newly created String "HI"

  S3 = s.concat\("**"\); //s3 -&gt; a newly created String "Hi**"

```text
### Default Values of Variables
- *instance variables* are declared inside a class but not within a method.* - Instance variables will have default values (ie. 0 or null).
- ***Local variables*** are declared within a method.
    - They do not get a default value.
    - THe compiler will complain if you try to use a local variable before it’s initialized.
#### Exercises
`public int getCoinValue(Stirng coinName){...}`
- coinName is a local variable.
- The parameter can be used within the method.
#### Initial Values Exercises
```java
public class Vehicle{
    Private String type;
    Private int numAxels
    Public Vehicle(){...}
```

* _type_ will be initialized to null.
* numAxels will be initialized to _0_.

### Passing by Value

* When using primitive variables, we make a **copy** of number ‘7’ \(or whatever the primitive data type is\), not the address to RAM.
* Java is pass-by-value, which means _pass by copy._

_what happens if the **argument** we want to pass is an **object** instead of a primitive?_

* We are passing the address of the string, instead of the string itself.
* There are no copies.

  _What happens if we pass an **array** into a method?_

* Arrays are objects. An array variable stores the addresses where the array are located in memory.

  \`\`\`java

  / **This practice problem adds up all the numbers in an array** /

  public static double sum\(double\[\] numbers\){

    double sum;

    For element:numbers{

  ```text
    sum = sum + element;
  ```

    }

    Return sum;

```text
- Java passes *everything by value*. When an argument is an array variable, the *address* of the array object is copied to the parameter in the method.
- For objects, the address is passed.

### Recap on Classes and Objects
- Let’s define class `Node` for creating a linked list.
    - Instance variables are `public` by default unless they are declared as `private`.
    - They do have initial values (0 for `int`, `null` for `strings`.
```java
public class Node{
    String item //public
    Node next; //null

    Node n1 = new Node();
    Node n2 = new Node();
    Node n3 = new Node();
    N1.item = "Hi";
    N2.item = "CPS";
    N3.item = "350";

    private void pointToEachOthersAddresses(){
        N1.next = n2;
        N2.next = n3; //Get 3's address and put it into n2's next node.
=============
Container 1
-------------
Pointer
==============
```

* Random: API stands for _Application Programming INterface_

_Q: Can you define class LinkedLIst so that we can write methods for implementing stackAPI?_

* A **linkedList** is made of **Node objects**
* We can declare **Node** as a **separate** public class:

  ```java
  public class Node{
    String item; // public
    Node next; // null.
  ```

#### Question

* Use the node class in the LinkedLIst

## Memory Allocation in Java

Stacks and heaps are parts of the main memory.

* Java stores program data in two separate pools of memories: the stack and the heap.
* All **objects live on the heap**
* The stack is where method invocations and local variables live.

  **Programs vs. Process**

* **Program**: an executable file stores on the system: `calculator.exe`
* **Process**: an executing instance of a program. 
  * Always stored in the main memory.
  * You can have multiple instances of the Calculator program.

    **Memory Allocation**

    **Address Space**
* Address space: space is allocated for the program/process. No other process can use that space.
* One process cannot even see another’s address space.

  \`\`\`java

  Process A:

    Stack // the name of this part of the space.

    \(Allocated space\)

    Heap //THe name of the portions in the space

    Data //

    Text

  Process B:

    Stack

    \(Extra allocated space\) //This way, the stack can grow or shrink.

    Heap //You may see a run out of heap space runtime error too. Heaps use the extra allocated space.

    Data

    Text

```text
#### Methods are Stacked
```java
public static void main (String[] args){
    DoStuff();

Public static void doStuff(){
    Boolean b = true;
    Go(4);

Public static void go (int x) {
    Int z = x+24;
    //more code here.

The stack looks like:
Go()
DoStuff()
Main() //The program finishes when main is popped off the stack.
```

#### Exercise

```java
public class StackRef{
    Public void foof(){
        Barf();
    }
    Public void barf(){ //Stored in a stack with 8 bytes.
        //create a duck object, the object is stored on the heap where the object lives.
        Duck d = new Duck(); //Stored on the stack.
```

* Only the reference variable _the address of the object_ goes on the stack. The object itself still goes on the heap.

  **Instance Variables**

  Instance variables live on the heap inside the object they belong to.

  ```java
  public class CellPhone{
    Private int x; //Occupies 4 bytes
    Private long y; //Occupies 8 bytes.
  ```

What if instance variables are object references?

```java
public class CellPHone{
    Private Antenna ant = new Antenna (); //ant is an instance variable which lives inside the object.
}
```

#### Summary

* **local variables** including **parameters** live on the stack **only when** the method they belong to is pushed on the stack.
  * It does not matter if the local variable is a primitive or reference variable.
* **Instance variables** live on the **heap** inside the **object** they belong to.
  * //More here.

    **Lifetime of an Object**

    ```java
    Book b = new Book(); //object 1
    Book c = new Book(); //object 2.
    ```

    An object is alive on the heap **as long as** there’s a reference to it.

    ```java
    b = c; //refer to the same object 2
    ```
* When it doesn’t have any pointers attached to it, then it’s **eligible for garbage collection**.
* The JVM _\(java virtual machine\)_ will do the cleaning.

  **Destroying Objects**

* We can abandon them and the _garbage collector_ will reclaim the memory the objects were using.

  **Efficient Solutions**

* The references goes out of scope, permanently

  ```java
  void go(){
   Life z = new Life(); //Reference variable dies at the end of method.
  }
  ```

* Explicitly **assign** the reference variable to **null**.

  ```java
  Life z = new Life();
  Z = null;
  ```

* The reference is assigned another object: \(double check this code\).

  ```java
  Life z= new Life();
  Z = new Life;
  ```

  **Question: when implementing a Queue in a LinkedList, can you replace the head address to traverse a LinkedList or will it be garbage collected?**

## Inheritance

!\[\]\[image-1\]

* Instead of looping through an entire list, use a tail so you can reference the very end.

  **Extends**

* We can create a new class called **HeadTailList** that **inherits** the fields and methods of `LinkedList,` and then write our own `insertEnd()` in the new class

  ```java
  public class HeadTailList extends LinkedList{ //A subclass of LinkedList
    //The head and size fields are inherited from LinkedList
    Private Node tail; //Add a new field
    Public HeadTailList(){
        //LinkedList() constructor is called automatically here
        Tail = null;
    }
    //Methods
  ```

* A **subclass** inherits all fields and methods of its superclass.
* A subclass can modify or augment **superclass** in at least three ways
  * It can declare new fields
  * It can declare new methods
  * It can **override** old methods with new implementations

    **Using Multiple Constructors**

    What happens if we have multiple constructors?
* The zero-parameter constructor in the superclass is always called by default by subclass constructor.
* Calling the constructor in the parent class
* Use the `super` keyword.
  * `super.insertFront(item)` will call the super method from the parent class.

    **Exercise**

    This method will add something to the front of the list. %%Help: might be wrong

    ```java
    public class HeadTailList extends LinkedList{
    //Node, head, and size fields are inherited from LinkedList

    Public void insertFront(String item){ //This is what I did and it might be wrong?
      Node nodeToAdd;
      nodeToAdd.item = item;
      nodeToAdd.next = head;
      head = nodeToAdd;
    ```

This method will add something to the end of the list. %%Help: you mentioned subclasses/superclasses here, how were they used? I’m confused at what I can call and when.

```java
public void insertEnd(String item){ //Assumes the case handles multiple
    Node nodeToAddToEnd = new Node(); //Creates the object.
    //If the list has multiple items{
        nodeToAddToEnd.item = item;
        nodeToAddToEnd.next = null;
        tail = nodeToAddToEnd;
    //If the list has one item{
    if (size.isEmpty()){ //Don't use the size.?

    }
```

### Review of Inheritance

* A subclass inherits all fields and methods of its superclass. It can declare new fields & methods.
* We can use the `super` keyword to call a method or constructor from a parent class.

  **Interfaces**

* Interfaces are very similar to abstract classes.
* You can only extend one parent class, so if you need to extend from multiple parents, you can implement many interfaces \(as many as you want\).
* Uses the keyword `implements <interface>, <another interface>, <even more>` in the class.

  ```java
    public class LinkedList extends List implements Comparable, Iterator{ ...}
  ```

  **Abstract classes**

* An abstract class is a class whose sole purpose is to be extended for multiple classes to share.

  ```java
    public abstract class List{ //Use the abstract keyword to implement 
        //Variables
        Protected int size;
        Public abstract void insertFront(String item); //An abstract method ensures that every non-abstract subclass will implement this method.
  ```

* If you want to create a new abstract object, it’s not allowed in Java.
* You can have a reference variable containing a variable in an abstract class \(even though it’s not part of the object.

  **Dynamic Method Lookup**

  Dynamic lookup is ::Help: insert more here::

* Every object of a subclass _is_ an object of the _super_Class \(with less fields/methods\). The reverse is not true.
* Any subclass object can be assigned to a superclass variable, which is called _**polymorphism**_

  ```java
    LinkedList l = new HeadTailList();
  ```

* We can pass superclass object or any subclass object at runtime.

  **Exercise**

  Refer to the PowerPoint, I’m going to write what I think the output will be. This is useless. ::TODO:Figure this out::

  ```java
  I should go see her or her TA during the office hours to re-learn interfaces and inheritance.
  ```

#### Aside: Assignment 1 Discussion

```java
public void enque(T item){
    If (size == queue.length){ //You have to see if the Array if full. If it's equal, you used all the spots in the array.
        resizeArray(queue.length);
    }
    Q[back] = item //The back's initial is zero. It decreases back by 1?
    Back ++;
    Back = back % Q.length; //Divide the current back the the current array size. If it's zero, it points to an item at element zero.
    Size++;
}

Public T dequeue(){
    If(isEmpty()){
            Throw new java.util.NoSuchElementException();
    }
    T value = Q[front]; //The index front pointing to the front item. Since it's not empty, you can get it and save it in the value.
    Front++ //so front moves to the next element
    Front = front % Q.length; //You have to do the modulus calculation if the index in the front move to the beginning item.
    Size--;
    Return value;
}

Private void resizeArray(int oldSize){
    newSize = 2*oldSize;
    T[] newQ = new T[newSize]; //New Queue is the new array.
    For (int i = 0; i < oldSize; i++){
        NewQ[i] = oldQ[front];
        Front ++;
```

* After you resize, the front will be the beginning of the new array.
* The back will be where the array ends.

## Genetic Components

What if we want a stack of apples?

### Generic Stack

* If we use the keyword `object`, this can be any class name.
* When we use objects, this causes bugs.
* All the items on the `stack` should be the same type, so **tighter type** was made.

  **Tighter Type**

  \`\`\`java

  public class ListStack //Type is a placeholder for the type of items in the data structure.

```text
- The Type surrounded by angle brackets `<>` is a placeholder for an actual type of object.
    - Type can be replaced with any other name: `E, T, TYPE, AnyType`
    - It can be any _non-primitive_ type you specify (_any class type, any interface type, or any array type_).
```java
//In Main
ListStack<String> s = new ListStack<String>();
s.push("Hi");
s.push(10); //ERROR.
```

* We can only use concrete class types, not primitive types when doing this. 

  **Practice: Array Implementation Using a Generic Stack**

  There are two approaches. You can either re-index every time you add a new item into the array or you have a counter pointing to the next spot for the new item.

  \`\`\`java

  public class ArrayStack{

    private Type\[\] s; //generic array

    private int top = 0; //next empty spot

    private int capacity = 10; 

//Make a constructor public ArrayStack\(\){ s = new Object\[capacity\]; //not a good idea s = new Type\[capacity\]; //Won't run; generic array creation is not allowed in Java. s = \(Type\[\]\) new Object\[capactiy\] //Typecast Object =&gt; Type.

```text
public boolean isEmpty(){
    return top == 0;
}

public void push(Type item){
    if (arrayIsFull()){
        resizeArray();
    if (isEmpty){ 


public Type pop() throws NoSuchElementException{
    toPop = s[rear]
    if (isEmpty()){
        throw new NoSuchElementException();
    Type x = s[top];
        s[top+1] = null; //Not needed because array is same size. Setting to null is wasted time.
        top --;
        return x;
    }
```

\`\`\`

* This code is incomplete
* As a workaround, create an array of objects and then insert type cast to preserve type.
* If nothing is pointing to the new array, the array that was referenced by s is eligible for garbage collection.

  **Autoboxing**

* Each primitive type has a wrapper object type
* Autoboxing is an _automatic cast_

\[image-1\]: assets/DraggedImage.png

