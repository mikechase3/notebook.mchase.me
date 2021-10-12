---
description: Learn Python Basics
---

# Lecture 02: Python, GET, HEAD Requests

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
* The `AF_INET` parameter means it follows IPV4 (or IPV6) protocols.
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



## AS 1 Problem Solving

1. Crawl one web page
2. Add a loop to crawl 100 web pages.

## URL Format

The general URL format is given by:

```
scheme://[user:pass@]host[:port][/path][?query][#fragment]
```

* `user`: Username
* `pass`: Depreciated password.
* `:port`: The port number in the URL
* `/path`: Helps us find where the path is.
* `?query`: What information do we want to receive
* `#fragment`: Not sure

{% hint style="danger" %}
What is fragment and query for? What are examples?
{% endhint %}

## GET Request

* Use the `GET` request to get the entire HTML file.

```python
string request = "GET /" + path + query + " HTTP/1.0\n User-agent: UDCScrawler/1.0\n Host: " +...
```

1. The type of request.
2. Second, specify the path.
3. Specify the protocol
4. Specify the version number
5. Type in the `User-agent: udaytoncrawler/1.0` as whatever user agent you want.
6. End the line using an escape character.
7. Use the field name `Host: `for some reason. 
8. Type the actual host name.
9. Use a `\n` to start a new line.
10. Close the request by saying `Connection: close.`

## HEAD Request

* Use the `HEAD` request to only receive the header.
* Format it the same as the `GET` request

```python
string request = "GET /" + path + query + " HTTP/1.0\nUser-agent: UDCScrawler/1.0\nHost: " +...
```

## URL Parser

```python
def parse(self, string):  # String is a URL
    self.query = ''  # Default query is an empty string
    self.path = '/'  # The default path.
    self.port = '80'  $ default port.
    self.host = ''  # The host is always defined for valid URLs.
    
    index = string.find('\n')
    if index != -1:
    string = string[0:index]  # remove the line break that is in the end.
    
    # remove 'http://' or 'https://' if it is present in the given URL.
    index = string.find '://')
    if index != 1:
        string = string[index + 3:]
        
    # Remove fragment from url
    index = string.find('#')
    if index != -1:  # if it found a fragment
        string = string[:index]  # Strip fragment
        
    # Remove user:pass@ if it exists.
    
    
```

## Works Cited

[Dr. Zhongmei Yao's Networking Class](https://academic.udayton.edu/zhongmeiyao/)
