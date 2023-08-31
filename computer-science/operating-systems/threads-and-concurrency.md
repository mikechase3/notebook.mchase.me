---
description: Week 2 CPS 536 by Dr. E FALL23
---

# Threads and Concurrency

## External Sources

This first one is optional & serves as some motivation.

{% embed url="https://www.youtube.com/watch?v=3RvkfuXUv1c&t=521s" %}

This is more useful:

{% embed url="https://www.youtube.com/watch?v=7ENFeb-J75k&t=1s" %}

## Defining Threads

What are they? How are they different from processes? What data structures are used to implement and manage these? We use the paper "An Introduction to Programming with Threads."

**Threads** execute a unit of work on behalf of a process. We're executing the process in terms of smaller units each of which is called a thread.

* Threads can be **concurrent**. Those threads can execute concurrently across multiple cores.

### Thread Resources & Under-The-Hood

<figure><img src="../../.gitbook/assets/image (521).png" alt=""><figcaption></figcaption></figure>

### Benefits of Multithreading

* **Parallelization**: we can process much faster than if a single thread on a single CPU had to calculate the entire input matrix.
* Threads can either execute completely different portions of the program or operate on different portions of the code that correspond to specific functions.
* By specializing different threads to run different tasks or different portions of the program, we can differentiate how we manage those threads. So, for instance, we can give higher priority to those threads that handle more important tasks or more important customers.
* Another important benefit of partitioning what exactly the operations are executed by each thread, and on each CPU, comes from the fact that performance is dependent on how much state can be present in the processor cache.&#x20;
* **Specialization**: we end up executing with a hotter cache which translates to faster performance.

### Single CPU Use Cases

As long as the amount of idle time is less than twice the amount of time it costs to context switch, the OS should switch to minimize idling time.&#x20;

![](<../../.gitbook/assets/image (523).png>)

* Here: threads here help us hide the latency of I/O operations.

### Apps and OS Benefits

By multithreading the operating system's kernel, we allow the operating system to support multiple execution contexts. This is particularly important so the OS can support multiple execution contexts.

## Thread Mechanisms

<figure><img src="../../.gitbook/assets/image (557).png" alt=""><figcaption></figcaption></figure>

### **Data Structure**

To identify threads & keep track of resource usage, we need:

1. Thread identifier
2. Register values (PC, SP, stack of the thread, any other OS data/attributes)

### Thread Creation

<figure><img src="../../.gitbook/assets/image (588).png" alt=""><figcaption><p>This example shows how we create threads in code.</p></figcaption></figure>

{% hint style="info" %}
Don't confuse this `Fork` code with the one in [process mgmt.](ProcessManagement.md)
{% endhint %}

* **Fork**: doesn't create a new process this time, but instead a thread passing along the thread data structure.

<figure><img src="../../.gitbook/assets/image (558).png" alt=""><figcaption></figcaption></figure>

### Mechanism of Storing Results

IDK how this is implemented. Maybe just a consideration?

### Join Mechanism

* Provides a place for the child to store its result.
* Frees the resources the child used.

## Mutex

### Mutex Data Structure

<figure><img src="../../.gitbook/assets/image (589).png" alt=""><figcaption></figcaption></figure>

* **Status**: The data structure should contain information about whether it's locked or not.
* **List\[Blocked]**: threads and awaiting the mutex to be free.
* Owner: what thread has the lock?

**Critical section** refers to code within the mutex-locked section.&#x20;

**Condition variables** should be used in conjunction with mutexes to control the behavior of concurrent threads.&#x20;

### Reader/Writer Problem

* We can't read from memory, perform an operation, and write to it all at the same time.
* **Naieve**: lock the whole function & be super restrictive.
* We can also have an enum sorta thing with `Free`, `Reading`, and `Writing` state.
  * Free: resource counter = 0
  * Reading: resource counter  > 0 (equal to the number of readers)
  * Writing: resource counter = -1 (there is exactly one writer currently accessing the resoe)

### Common Pitfalls

* Keep track of mutex & condition variables that are specially used with a given shared resource.
* Forgetting to use the lock() and unlock() commands.&#x20;
* Not generating a warner that there's a locked construct.
* It's desirable to use a single mutex to access a single resource.
* **Deadlocks**: situations where competing threads  are waiting on each other to complete but none of them ever do.

In practice, we force everyone to first get the mutex for A and then the lock for B, deadlocks won't occur?

## Multithreading Models

A kernel level thread has to launch a user-level thread.&#x20;

### Every User Thread Gets a Kernel Thread

* **Pros**: better synchornization because OS has more opportunities to schedule?
* **Cons**: more process control blocks & context switching is expensive.

### All User-Level Threads Supported by One Kernel Level Thread

* Everything will be done at the user-level thread library: scheduling, synchronization, etc.
* Not limited by the specific limits and policies that are available in the kernel.
* No system calls?

### Many to Many

* The coordination between the kernel-level thread management & user-level thread management is required.&#x20;

## Scope of Multithreading

* **Process Scope** is a user-level thread library that's linked to the process manages all the threads that are **within that single process only.**&#x20;
* **System Scope**: all the threads compete for the CPU. It's also known as globbal scheduling because the kernel decides which kernel-level thread is to be scheduled into the CPU.





