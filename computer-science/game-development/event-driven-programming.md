# Event Driven Programming

## Problems with the Game Loop

* It only uses one frame.
* Everything runs 'on-tick'.
* Time.deltatime()

![](<../../.gitbook/assets/image (641) (1).png>)

## Event Driven Programming

* The idea is that you don't do any processing until an event tells you to do something.
* Libraries that come with the programming language take so much time.
* This guy is a C++ guru. There is a feature called "[templates](https://www.geeksforgeeks.org/template-metaprogramming-in-c/)"

## Template Metaprograms

* Works in compile time, not run-time.
* You force a program to run your program while you're compiling it.
* Luckily, we're not going to do that.&#x20;

## Embrace, Extend, Extinguish

* Microsoft's motto in a private email.
* Embrace: This is a fantstic technology. We should have it to Windows.
* Extend: add to the HTML or something with Microsoft-specific features.
* 98% of computers are running windows. All have Internet Explorer.
* Extinguish all the other web-browsers because they don't have the extension.
* Email retention policy. Your employer wants to say "sorry I can't give you those emails, we deleted them because of a policy that expires in 60 days. Don't tell the judge we have backups.

## Sun Microsystems: Java Sucks for Games

* Java: write once, run anywhere. All you have to have is a Java Virtual Machine, and everything will work.
* Now it's cross-platform.
* Microsoft said "Java is really good" and provided a great JVE runtime. Then, they extended the library with a bunch of new features and Microsoft sued. They're in the "extend" phase putting SUN out of business, and they won.
* Microsoft Java made C#. To be fair to Microsoft, C# is better because they learned from all the mistakes SUN made when they made Java.
* C# is better than Java at garbage collection because of [Mark and Seep](https://www.geeksforgeeks.org/mark-and-sweep-garbage-collection-algorithm/) garbage collection. Nothing can run at the same time either which is O(n). You don't control when the garbage collection runs, so Java is terrible for games.&#x20;
* If you need to do high-performance games, you don't want to use a virtual machine anyways.
* C# doesn't have an O(n) algorithm.
  * Every resource has a counter.
  * Every time you stop using a resource, it decrements the count.
  * It's predictable. You don't have to worry about when it gets to zero because that's when it does the cleanup.
  * C# won't disrupt any of the other cores. It doesn't stop the world and is predictable.

## C# Generational Garbage Collection

You can divide assets into 3 categories:

* Temporary:&#x20;
* Stage/Level:&#x20;
* Lifetime:&#x20;

You don't need to do garbage collection in the long category. Use a stack for short-lived things. Lifetime doesn't ever leave RAM, so all you have to do is worry about the stage/level.

Games don't have many things in the middle group. You're going to load lots of assets into long-term and the number of stage/level variable is so small that people just say "screw it". You game will use a little more memory and it won't be enough to justify having a garbage collector at all.

Java would break every single other problem if they changed it. If they changed it, they would break millions of programs in subtle and nasty ways until they're willing to break backwards compatibility.



## Why Teaching Game Development?

* When a fortune-100 company tells you what they want and cannot and find, but would pay millions of dollars.
* His company was succeeding. This started 13 months of negotiation in 1994. He was 25 and a multi-millionaire.



