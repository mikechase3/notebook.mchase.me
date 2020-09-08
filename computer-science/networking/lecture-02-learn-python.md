---
description: Learn Python Basics
---

# Lecture 02: Learn Python

## TP Socket Class

### Constructor

```python
def __init__(self):
    self.sock = None
    self.host = ""  # The remote host's name
    print("create an object of TCPsocket"
    
    
```

### Create a TCP Socket

```python
# Create a TCP Socket
def createSocket(self):
    try:
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("Created a TCP socket!")
    except socket.error as e:
        print("Failed to create a TCP socket{}".format(e))
        self.sock = None
```

* The `SOCK_STREAM` parameter means it will be a TCP Socket
* The `AF_INET` parameter means it follows IPV4 \(or IPV6\) protocols.
* The `socket` function fo the socket class creates a new socket.

### Connect to the TCP Remote Server

* Download Data
* If you want to connect to the remote server, you need to know:
  * The IP Address
  * Port Number

```python

def connect(self, ip, port):
    if self.sock is None or ip is None:
       return
    try:
       self.sock.connect((ip, port)) .# Server address is defined by IP/Port
       print("Successfully connect to host", ip)
    except socket.error as e:
       print("Failed to connect: {}".format(e))
       self.sock.close()
       self.sock = None
```

### Port Numbers

* Typically the port number is 80.
* The URL will tell us the port number.

### DNS Resolve

* This function determines a remote server's IP Address given a domain name.
* Finds the address of a remote server

```python
def getIP(self, hostname):
    self.host = hostname
    try:
        ip = socket.gethostbyname(hostname) # IP is a local variable to get IP
    except socket.gaierror:
        print("Failed to gethostbyname"
        return None
    return ip
```

### Calling From Main

1. Make sure to import the class from a different file using `from some_file import some_class`.
2. Then assign a variable to the class to instantiate it.

```python
def main():
    mysocket = TCPsocket()  # Create an object of TCP socket
    mysocket.createSocket()
    host = "www.google.com"
    ip = mysocket.getIP(host)  # Host to IP
    port = 80
    mysocket.connect(ip, port)
```



