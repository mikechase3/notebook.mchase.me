# Memory Management

## MMS Goals

Here, we'll discuss a more detailed description of OS memory management.

1. Manage the physical resources (DRAM)
2. We also want to 'decouple' physical from virtual memory because it has various benefits.
3. Allocate memory: determine what's brought from disk & how to store it.
4. Arbitrate: translate & validate memory based on the process ID, if we're in superuser mode, if memory exists at address, etc.

## How does the OS Support Memory Management

1. Decoupling virtual to physical addresses
2. Segmentation: arbitrate using segment registers.

## How does Hardware support Memory Management?

1. **MMU**s are Memory-Management Units that'll generate **faults** for illegal access or when referenced memory must be pulled from a disk.
2. **Designated registers**: support memory management through page-based registers which point to currently active page tables. Segment based registers indicate the base address of a segment if we use that system.
3. **Cache**: will contain a \*\*translation lookaside buffer
4. **Address Translation** is performed by page table lookups.

### Address Translation

The memory management unit translates virtual to physical addresses, but what's the underlying abstract mechanisms?

The whole thing is like a librarian managing books in a library but the terminology is slightly off:

* The books represent physical pages of virtual memory.
* The shelves represent physical memory .
* The librarian maintains an index of which book is on which shelf, similar to how the OS maintains the page table.
* When someone request a book, they provide its title (the virtual address), and the librarian looks up its location in the index (the page table) and retrieves it from the shelf (the physical memory).
* When there's not enough space on any shelf for a new book, then some books must be removed from their shelves and placed into storage (paging out)

## Page Tables

* Virtual memory is a technique allowing a program to use more memory than what's available in the system.
* The OS divides virtual memory into _fixed-sized blocks_ called **pages**.
* Each page is mapped to a corresponding block of physical memory called a page frame.
* The mapping between pages <--> page frames is maintained in a data structure called a **page table**.

### Virtual Addresses

Virtual addresses consist of the **virtual page number** and the **offset.**

* **Virtual Page Number**: used to index into the page table to obtain the corresponding **frame number**.
* {Offset} + {Base Address} => **Physical Address**

### MMU Return Values

* **Memory Vals**: The first access to a newly allocated page frame is called a **first touch**. Hopefully it'll just read the values off RAM into the CPU or caches.
* **Page faults** are triggered when programs access pages that aren't in physical memory.
  * Why is it not in memory? Pheraps it's on the HDD in which case it has to...
  * **Page in**: which is also called page swapping (from HDD to RAM)

## Inverted Page Tables

So what's the difference between a regular page table and an inverted one? That's what I'd like to know, but I don't have an answer yet.

## Potentially Useful Rabbitholes I have Yet to Go Down

Multilevel Paging & Inverted Page Table.

{% embed url="https://www.youtube.com/watch?v=7EcniI__vjA" %}

{% embed url="https://www.youtube.com/watch?v=8kBPRrHOTwg" %}

## Extra Rabbitholes I Went Down

These are not really in the scope of my class. It's more hardware/electrical in nature.

### What is virtual memory

A medium-quality discussion:

{% embed url="https://www.youtube.com/watch?v=5lFnKYCZT5o" %}

### How Dynamic Memory Works

{% embed url="https://www.youtube.com/watch?v=0A1e8eceIsY" %}

### Memory

This is more hardware-focused whereas CPS 536 is abstract, but it helps explains why we're learning those abstractions in class. Important discussed **terms**: gated latches, multiplexors.

{% embed url="https://www.youtube.com/watch?v=fpnE6UAfbtU&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo&index=7" %}

### Memory Part 2 Ish

This crash course discusses **terms:**

{% embed url="https://www.youtube.com/watch?v=TQCr9RV7twk&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo&index=20" %}

### The SAGE system. US DoD:

Worlds biggest punch card machine.

{% embed url="https://www.youtube.com/watch?v=06drBN8nlWg" %}

{% embed url="https://www.youtube.com/watch?v=Yc945sNB0uA" %}
