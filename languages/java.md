# Java

## Collection Framework Interface

The collections framework includes a standard set of methods that make remembering the syntax for functions a million times easier. Also, you don't have to implement simple things yourself which saves you time and line space. 

> From [Geeks for Geeks](https://www.geeksforgeeks.org/collections-in-java-2/#_=_):
>
> 1. **Consistent API:** The API has a basic set of [interfaces](https://www.geeksforgeeks.org/interfaces-in-java/) like _Collection_, _Set_, _List_, or _Map_, all the classes \([ArrayList](https://www.geeksforgeeks.org/arraylist-in-java/), [LinkedList](https://www.geeksforgeeks.org/data-structures/linked-list/), Vector, etc\) that implement these interfaces have some common set of methods.
> 2. **Reduces programming effort:** A programmer doesn’t have to worry about the design of the Collection but rather he can focus on its best use in his program. Therefore, the basic concept of Object-oriented programming \(i.e.\) abstraction has been successfully implemented.
> 3. **Increases program speed and quality:** Increases performance by providing high-performance implementations of useful data structures and algorithms because in this case, the programmer need not think of the best implementation of a specific data structure. He can simply use the best implementation to drastically boost the performance of his algorithm/program.

![Source: Geeks for Geeks: Collections in Java 2](../.gitbook/assets/image%20%2887%29.png)



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

#### Further Reading & Works Cited

* [Geeks for Geeks: Java Collections](https://www.geeksforgeeks.org/collections-in-java-2/)

