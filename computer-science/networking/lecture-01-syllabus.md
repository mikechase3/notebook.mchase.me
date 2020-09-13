# Lecture 01 Syllabus

## Instructor

![Dr. Yao has two daughters.](../../.gitbook/assets/image%20%28224%29.png)

* 2 Daughters
* She likes running

## Grading

* 5% for participation
* 20% for quizzes. They are open note and open book.
* 20% for programming assignments: the implementation and reports
* 25% Closed-book Midterm Exam
* 30% Closed-book Final.

## Overview

| Dates | Topic | Reading |
| :--- | :--- | :--- |
| August 25 | Introduction & Assignment 1 | Chapter 1 |
| September 15 | Application Layer | Chapter 2 |
| September 29 | _**Assignment 1, Chapters 1-2 Quiz.**_ | All Reading |
|  |  |  |

## Assignment 1

### Purpose

* Take the python name
* Take the file
* Open it and return a bunch of information.
* Check if it's a _unique_ host or not. _**Make sure the host is unique!**_
* Check if the IP Address is unique. _**Make sure it's unique!**_
* Connect on robots. 
* Load the web page from the URL.
* Parse the next URL.
  * Check the host name
  * Check the IP
  * Download it from the web host.

### Part 2

* Use a loop to process 100 URLs.
* Given a URL, build a request.
  * Use a socket to send the request to a remote server.
  * After we send this _GET_ request, you'll get a reply.
* `RECV` function call receives data and stores it into a string.
  * You can parse the string and do some nice data analysis.

### Part 3: Multithreading

* Call 1M URLs using 3500 threads.
* Use `Mutek` to lock and unlock threads.
* Create 3500 threads to process.
* Use `mutex` to lock and unlock threads.

### Implementations

* Use a _**Queue**_ to store all the URLs.
* Parse the URL.











