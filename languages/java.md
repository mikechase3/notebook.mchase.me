# Java Collections Framework

## Overview

The collections framework includes a standard set of methods that make remembering the syntax for functions a million times easier. Also, you don't have to implement simple things yourself which saves you time and line space. 

> From [Geeks for Geeks](https://www.geeksforgeeks.org/collections-in-java-2/#_=_):
>
> 1. **Consistent API:** The API has a basic set of [interfaces](https://www.geeksforgeeks.org/interfaces-in-java/) like _Collection_, _Set_, _List_, or _Map_, all the classes \([ArrayList](https://www.geeksforgeeks.org/arraylist-in-java/), [LinkedList](https://www.geeksforgeeks.org/data-structures/linked-list/), Vector, etc\) that implement these interfaces have some common set of methods.
> 2. **Reduces programming effort:** A programmer doesn’t have to worry about the design of the Collection but rather he can focus on its best use in his program. Therefore, the basic concept of Object-oriented programming \(i.e.\) abstraction has been successfully implemented.
> 3. **Increases program speed and quality:** Increases performance by providing high-performance implementations of useful data structures and algorithms because in this case, the programmer need not think of the best implementation of a specific data structure. He can simply use the best implementation to drastically boost the performance of his algorithm/program.

![Source: Geeks for Geeks: Collections in Java 2](../.gitbook/assets/image%20%2887%29.png)

These functions are all available for any object extending collections:

## Interfaces Extending Collections

{% tabs %}
{% tab title="Collection" %}
#### [Iterable&lt;T&gt;](https://docs.oracle.com/javase/8/docs/api/java/lang/Iterable.html)

Collection extends [iterable](https://docs.oracle.com/javase/8/docs/api/java/lang/Iterable.html), and the entire framework depends on it. It lets you iterate through collections and it returns the Iterator iterator\(\);

#### Collection

Collection is the interface which implements iterable. It contains the following methods. \(For more information, see [Geeks for Geeks](https://www.geeksforgeeks.org/collections-in-java-2/#_=_), where I got this content\).



| METHOD | DESCRIPTION |
| :--- | :--- |
| [**add\(Object\)**](https://www.geeksforgeeks.org/collection-add-method-in-java-with-examples/) | This method is used to add an object to the collection. |
| [**addAll\(Collection c\)**](https://www.geeksforgeeks.org/collections-addall-method-in-java-with-examples/) | This method adds all the elements in the given collection to this collection. |
| [**clear\(\)**](https://www.geeksforgeeks.org/collection-clear-method-in-java-with-examples/) | This method removes all of the elements from this collection. |
| [**contains\(Object o\)**](https://www.geeksforgeeks.org/collection-contains-method-in-java-with-examples/) | This method returns true if the collection contains the specified element. |
| **containsAll\(Collection c\)** | This method returns true if the collection contains all of the elements in the given collection. |
| **equals\(Object o\)** | This method compares the specified object with this collection for equality. |
| **hashCode\(\)** | This method is used to return the hash code value for this collection. |
| [**isEmpty\(\)**](https://www.geeksforgeeks.org/collection-isempty-method-in-java-with-examples/) | This method returns true if this collection contains no elements. |
| **iterator\(\)** | This method returns an iterator over the elements in this collection. |
| [**max\(\)**](https://www.geeksforgeeks.org/collections-max-method-in-java-with-examples/) | This method is used to return the maximium value present in the collection. |
| **parallelStream\(\)** | This method returns a parallel Stream with this collection as its source. |
| **remove\(Object o\)** | This method is used to remove the given object from the collection. If there are duplicate values, then this method removes the first occurrence of the object. |
| **removeAll\(Collection c\)** | This method is used to remove all the objects mentioned in the given collection from the collection. |
| **removeIf\(Predicate filter\)** | This method is used to removes all the elements of this collection that satisfy the given [predicate](https://www.geeksforgeeks.org/mathematic-logic-predicates-quantifiers/). |
| **retainAll\(Collection c\)** | This method is used to retains only the elements in this collection that are contained in the specified collection. |
| **size\(\)** | This method is used to return the number of elements in the collection. |
| **spliterator\(\)** | This method is used to create a [Spliterator](https://www.geeksforgeeks.org/java-program-to-convert-iterator-to-spliterator/) over the elements in this collection. |
| **stream\(\)** | This method is used to return a sequential Stream with this collection as its source. |
| **toArray\(\)** | This method is used to return an array containing all of the elements in this collection. |
|  |  |
{% endtab %}

{% tab title="List" %}
List is a child of the collection interface. It stores lists:

```java
List <T> al = new ArrayList<> ();
List <T> ll = new LinkedList<> ();
List <T> v = new Vector<> ();
Where T is the type of the object
```

## Array Lists

It's like arrays, but they don't suck:

```java
// Java program to demonstrate the 
// working of ArrayList in Java 

import java.io.*; 
import java.util.*; 

class GFG { 
	public static void main(String[] args) 
	{ 

		// Declaring the ArrayList with 
		// initial size n 
		ArrayList<Integer> al 
			= new ArrayList<Integer>(); 

		// Appending new elements at 
		// the end of the list 
		for (int i = 1; i <= 5; i++) 
			al.add(i); 

		// Printing elements 
		System.out.println(al); 

		// Remove element at index 3 
		al.remove(3); 

		// Displaying the ArrayList 
		// after deletion 
		System.out.println(al); 

		// Printing elements one by one 
		for (int i = 0; i < al.size(); i++) 
			System.out.print(al.get(i) + " "); 
	} 
} 

```

#### Output:

```java
[1, 2, 3, 4, 5]
[1, 2, 3, 5]
1 2 3 5
```

### Linked Lists



It implements a LinkedList data structure:

```java
// Java program to demonstrate the 
// working of LinkedList in Java 

import java.io.*; 
import java.util.*; 

class GFG { 
	public static void main(String[] args) 
	{ 

		// Declaring the LinkedList 
		LinkedList<Integer> ll 
			= new LinkedList<Integer>(); 

		// Appending new elements at 
		// the end of the list 
		for (int i = 1; i <= 5; i++) 
			ll.add(i); 

		// Printing elements 
		System.out.println(ll); 

		// Remove element at index 3 
		ll.remove(3); 

		// Displaying the List 
		// after deletion 
		System.out.println(ll); 

		// Printing elements one by one 
		for (int i = 0; i < ll.size(); i++) 
			System.out.print(ll.get(i) + " "); 
	} 
} 

```

#### Output

```java
[1, 2, 3, 4, 5]
[1, 2, 3, 5]
1 2 3 5
```

## Stacks

#### What is it?

It's a stack, duh. 

#### Example

```java
// Java program to demonstrate the 
// working of a stack 

import java.util.*; 
public class GFG { 
	public static void main(String args[]) 
	{ 
		Stack<String> stack = new Stack<String>(); 
		stack.push("Geeks"); 
		stack.push("For"); 
		stack.push("Geeks"); 
		stack.push("Geeks"); 

		// Iterator for the stack 
		Iterator<String> itr 
			= stack.iterator(); 

		// Printing the stack 
		while (itr.hasNext()) { 
			System.out.print(itr.next() + " "); 
		} 

		System.out.println(); 

		stack.pop(); 

		// Iterator for the stack 
		itr 
			= stack.iterator(); 

		// Printing the stack 
		while (itr.hasNext()) { 
			System.out.print(itr.next() + " "); 
		} 
	} 
} 

```

#### Output

```java
Geeks For Geeks Geeks 
Geeks For Geeks
```

{% hint style="warning" %}
Stack is a subclass of Vector and a legacy class. It is thread safe which might be an overhead in an environment where thread safety is not needed. An alternate to Stack is to use [ArrayDequeue](https://www.geeksforgeeks.org/arraydeque-in-java/) which is not thread safe and faster array implementation.
{% endhint %}

## Vectors

#### What is it?

> [**Vector:**](https://www.geeksforgeeks.org/java-util-vector-class-java/) A vector provides us with dynamic arrays in Java. Though, it may be slower than standard arrays but can be helpful in programs where lots of manipulation in the array is needed. This is identical to ArrayList in terms of implementation. However, the primary difference between a vector and an ArrayList is that a Vector is synchronized and an ArrayList is non-synchronized. Let’s understand the Vector with an example:

#### How to use it:

```java
// Java program to demonstrate the 
// working of Vector in Java 

import java.io.*; 
import java.util.*; 

class GFG { 
	public static void main(String[] args) 
	{ 

		// Declaring the Vector 
		Vector<Integer> v 
			= new Vector<Integer>(); 

		// Appending new elements at 
		// the end of the list 
		for (int i = 1; i <= 5; i++) 
			v.add(i); 

		// Printing elements 
		System.out.println(v); 

		// Remove element at index 3 
		v.remove(3); 

		// Displaying the Vector 
		// after deletion 
		System.out.println(v); 

		// Printing elements one by one 
		for (int i = 0; i < v.size(); i++) 
			System.out.print(v.get(i) + " "); 
	} 
} 

```

#### Output

```java
[1, 2, 3, 4, 5]
[1, 2, 3, 5]
1 2 3 5
```
{% endtab %}

{% tab title="Queue/Deque" %}
## Queue

#### What is It?

```java
Queue <T> pq = new PriorityQueue<> ();
Queue <T> ad = new ArrayDeque<> ();
Where T is the type of the object.
```

#### Priority Queues Example:

```java
// Java program to demonstrate the working of 
// priority queue in Java 
import java.util.*; 

class GfG { 
	public static void main(String args[]) 
	{ 
		// Creating empty priority queue 
		PriorityQueue<Integer> pQueue 
			= new PriorityQueue<Integer>(); 

		// Adding items to the pQueue using add() 
		pQueue.add(10); 
		pQueue.add(20); 
		pQueue.add(15); 

		// Printing the top element of PriorityQueue 
		System.out.println(pQueue.peek()); 

		// Printing the top element and removing it 
		// from the PriorityQueue container 
		System.out.println(pQueue.poll()); 

		// Printing the top element again 
		System.out.println(pQueue.peek()); 
	} 
} 

```

#### Output

```java
10
10
15
```

## Deque

#### What is it?

> [**Deque Interface**](https://www.geeksforgeeks.org/deque-interface-java-example/)**:** This is a very slight variation of the [queue data structure](https://www.geeksforgeeks.org/queue-data-structure/). [Deque](https://www.geeksforgeeks.org/deque-set-1-introduction-applications/), also known as a double-ended queue, is a data structure where we can add and remove the elements from both the ends of the queue. This interface extends the queue interface. The class which implements this interface is [ArrayDeque](https://www.geeksforgeeks.org/arraydeque-in-java/). Since this class implements the deque, we can instantiate a deque object with this class. For example,

```java
Deque<T> ad = new ArrayDeque<> ();
Where T is the type of the object.
```

#### ArrayDeque Example

> [**ArrayDeque:**](https://www.geeksforgeeks.org/arraydeque-in-java/) ArrayDeque class which is implemented in the collection framework provides us with a way to apply resizable-array. This is a special kind of array that grows and allows users to add or remove an element from both sides of the queue. Array deques have no capacity restrictions and they grow as necessary to support usage. Lets understand ArrayDeque with an example:

```java
// Java program to demonstrate the 
// ArrayDeque class in Java 

import java.util.*; 
public class ArrayDequeDemo { 
	public static void main(String[] args) 
	{ 
		// Initializing an deque 
		ArrayDeque<Integer> de_que 
			= new ArrayDeque<Integer>(10); 

		// add() method to insert 
		de_que.add(10); 
		de_que.add(20); 
		de_que.add(30); 
		de_que.add(40); 
		de_que.add(50); 

		System.out.println(de_que); 

		// clear() method 
		de_que.clear(); 

		// addFirst() method to insert the 
		// elements at the head 
		de_que.addFirst(564); 
		de_que.addFirst(291); 

		// addLast() method to insert the 
		// elements at the tail 
		de_que.addLast(24); 
		de_que.addLast(14); 

		System.out.println(de_que); 
	} 
} 

```

#### Output

```java
[10, 20, 30, 40, 50]
[291, 564, 24, 14]
```
{% endtab %}

{% tab title="Sets" %}

{% endtab %}

{% tab title="" %}

{% endtab %}
{% endtabs %}



#### Further Reading & Works Cited

* [Geeks for Geeks: Java Collections](https://www.geeksforgeeks.org/collections-in-java-2/)

