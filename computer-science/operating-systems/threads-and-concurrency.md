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

## Benefits of Multithreading

* **Parallelization**: speeds up programs. We can process much faster than if a single thread on a single CPU had to calculate the entire input matrix.
* Threads can either execute completely different portions of the program or operate on different portions of the code that correspond to specific functions.
* By specializing different threads to run different tasks or different portions of the program, we can differentiate how we manage those threads. So, for instance, we can give higher priority to those threads that handle more important tasks or more important customers.
* Another important benefit of partitioning what exactly the operations are executed by each thread, and on each CPU, comes from the fact that performance is dependent on how much state can be present in the processor cache.
* **Specialization**: **hotter cache**. We end up executing with a hotter cache which translates to faster performance.
* **Efficiency**: lower memory management requirement and cheaper IPC.

### Disk I/O

* Multithreading is even applicable to single-processors with single-cores.
* As long as the amount of idle time is less than twice the amount of time it costs to context switch, the OS should switch to minimize idling time.

![](<../../.gitbook/assets/image (523).png>)

* Here: threads here help us hide the latency of I/O operations.

### Apps and OS Benefits

* By multithreading the operating system's kernel, we allow the operating system to support multiple execution contexts.&#x20;
* This is particularly important so the OS can support multiple execution contexts.
* Obviously better for multi-core processors.&#x20;

## Thread Mechanisms

{% hint style="danger" %}
Slides won't match up with the content here. Week 2-1 is all note above, but we did a surface-level brief of the topics below. Week 2-2 covers the mutex in more depth, so the notes below come from multiple time-stamps across the two videos.&#x20;
{% endhint %}

### Mutual Exclusion Mechanism

### Mutex Basics

From Week 2-2.&#x20;

* **Mutexes** should be used whenever we access data/resources shared among threads.
* We say a thread is trying to **acquire the lock** when attempting to get exclusive access to the shared resource.
* **Condition variables** handle the inter-thread communication in Birrel threading systems.&#x20;

<figure><img src="../../.gitbook/assets/image (557).png" alt=""><figcaption></figcaption></figure>



### **Thread Creation & Data Structure**

To identify threads & keep track of resource usage, we need:

1. Thread identifier
2. Register values (PC, SP, stack of the thread, any other OS data/attributes)

### Creating & Managing Threads

We create forks by the `Fork` call. The fork call is composed of `procs`, a procedure that the created thread will start executing, and the `args` for such procedures.

### FORK Call

<figure><img src="../../.gitbook/assets/image (646).png" alt="" width="375"><figcaption></figcaption></figure>

Fork works by:

1. Creating a new thread that'll execute the procedure with the arguments.
2. Thread T0 calls a fork a new thread & T1 is created
3. $$T_0 \land T_1$$ (parent & new) threads execute concurrently.
   1. $$T_0$$ executes the next operation after the fork call.&#x20;
   2. $$T_1$$executes with the first instruction in proc with the specified arguments.
   3. When T1 finishes, it'll store results in a location accessible to other threads/parent.
4. **Join** is called by the parent: `join(<thread id>)`. &#x20;
   1. Further instructions are blocked until the child completes.



### Nondeterministic Code

Sometimes, we don't have a clear result. In the case below, the list could come out to be two different orders.

<figure><img src="../../.gitbook/assets/image (588).png" alt=""><figcaption><p>This example shows how we create threads in code.</p></figcaption></figure>

{% hint style="info" %}
Don't confuse this `Fork` code with the one in [process mgmt.](ProcessManagement.md)
{% endhint %}

* **Fork**: doesn't create a new process this time, but instead a thread passing along the thread data structure.

### Join Mechanism

* Provides a place for the child to store its result.
* Frees the resources the child used.



### Mutex Data Structure

<figure><img src="../../.gitbook/assets/image (589).png" alt=""><figcaption></figcaption></figure>

* **Status**: The data structure should contain information about whether it's locked or not.
* **List\[Blocked]**: threads and awaiting the mutex to be free.
* Owner: what thread has the lock?

**Critical section** refers to code within the mutex-locked section.

**Condition variables** should be used in conjunction with mutexes to control the behavior of concurrent threads.

### Reader/Writer Problem

* We can't read from memory, perform an operation, and write to it all at the same time.
* **Naieve**: lock the whole function & be super restrictive.
* We can also have an enum sorta thing with `Free`, `Reading`, and `Writing` state.
  * Free: resource counter = 0
  * Reading: resource counter > 0 (equal to the number of readers)
  * Writing: resource counter = -1 (there is exactly one writer currently accessing the resoe)

### Common Pitfalls

* Keep track of mutex & condition variables that are specially used with a given shared resource.
* Forgetting to use the lock() and unlock() commands.
* Not generating a warner that there's a locked construct.
* It's desirable to use a single mutex to access a single resource.
* **Deadlocks**: situations where competing threads are waiting on each other to complete but none of them ever do.

In practice, we force everyone to first get the mutex for A and then the lock for B, deadlocks won't occur?

### Multithreading Models

A kernel level thread has to launch a user-level thread.

### Every User Thread Gets a Kernel Thread

* **Pros**: better synchornization because OS has more opportunities to schedule?
* **Cons**: more process control blocks & context switching is expensive.

### All User-Level Threads Supported by One Kernel Level Thread

* Everything will be done at the user-level thread library: scheduling, synchronization, etc.
* Not limited by the specific limits and policies that are available in the kernel.
* No system calls?

### Many to Many

* The coordination between the kernel-level thread management & user-level thread management is required.

## Scope of Multithreading

* **Process Scope** is a user-level thread library that's linked to the process manages all the threads that are **within that single process only.**
* **System Scope**: all the threads compete for the CPU. It's also known as globbal scheduling because the kernel decides which kernel-level thread is to be scheduled into the CPU.

## User & Kernel Threads
