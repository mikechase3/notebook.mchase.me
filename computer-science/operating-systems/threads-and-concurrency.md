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

