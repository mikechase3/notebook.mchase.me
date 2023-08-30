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

