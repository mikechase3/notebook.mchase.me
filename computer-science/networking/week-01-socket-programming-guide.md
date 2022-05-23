# Socket Programming In Python

## Note

* I'm summarizing a summary to force me to go through the information
* Just read it again [here](https://realpython.com/python-sockets/).&#x20;
* [Source: Real Python's Socket Guide](https://realpython.com/python-sockets/)

## Background

* Sockets originated with ARPANET in 1971
* It became an API, written in C I think.
* The most common types of scoket apps are client-server applications
  * One side is a server
  * The client connects to it.
* We're using the API for _Internet Sockets_, AKA Berkeley or BSD (Berkeley Software Distribution)

## Socket API Overview

* Python's [socket module](https://docs.python.org/3/library/socket.html) provides an interface to Berkeley socket's API.
* Python also has classes making low-level socket functions easier.
  * Not covered in this tutorial.
  * See the [socketserver ](https://docs.python.org/3/library/socketserver.html)module, a framework for network servers.

| Method        | Functionality |
| ------------- | ------------- |
| socket()      |               |
| bind()        |               |
| listen()      |               |
| accept()      |               |
| connect()     |               |
| connect\_ex() |               |
| send()        |               |
| recv()        |               |
| close()       |               |

## TCP Sockets

### Why use TCP?

* TCP stands for _Transmission Control Protocol_
  * It's the default protocol and what we'll usually want to use.
* We should use TCP because:
  * **It's reliable**: packets are detected and retransmitted.
  * **Has in-order data delivery**: your application reads information in the order it was written by the sender.

### What else exists?

* User Data Protocol (UDP) sockets are not reliable.
* Data read by the receiver can be out-of-=order from what the sender writes.
* TCP lets you implement stuff without worrying about the details.

### TCP Socket Flow

![](<../../.gitbook/assets/image (182).png>)

| Method     | Functionality                                                                             |
| ---------- | ----------------------------------------------------------------------------------------- |
| `listen()` | Listens for connections from clients. When a client connects, the server calls `accept()` |
| `accept()` | Completes a connection when the `listen()` function finds something.                      |
|            |                                                                                           |

## Works Cited

* [Real Python's Python Sockets](https://realpython.com/python-sockets/)









