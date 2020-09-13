# Lecture 04

## Assignment 1

![](../../.gitbook/assets/image%20%28225%29.png)

1. Open the text file and insert the URLs to the _**Queue**_
2. While the Queue is not empty
   1. Extract the URL from the queue. Parse it.
   2. Using a set in python, determine if the URL & host name are unique.
   3. Check if the IP address is unique or not.
3. If the IP address is unique, then crawl it.
   1. Connect to the server given it's IP address and Port.
   2. Send a HEAD request for robots.txt
   3. Receive the reply and read the status code
      1. Stop reading if the code is 200.
      2. Otherwise create a TCP socket
      3. Connect to the same server
      4. Send a GET request
      5. Receive a reply
      6. Close the socket.
   4. Close the socket.

### Checking if Hosts and URLs are Unique

* Use the `set` in Python 3.
* Sets are mutable.

```python
# Python program to demonstrate sets.

# Same as {"a", "b", "c"}
my_set= set(["a", "b", "c"])
print(my_set)

# Adding an element to the set
my_set.add("d")
print(my_set)
```

### Multi-threading Program

Next time, we're going to write a program spanning multiple threads. The runtime will be significantly decreased when parsing 1M programs. 

![](../../.gitbook/assets/image%20%28227%29.png)

### Upper Bound

Declare a maximum variable.

{% code title="tcpsocket.py" %}
```python
#  Constants used in tcpsocket.py
BUF_Size= 2048
TIMEOUT = 10
TOTAL_BYTES = 96000000
```
{% endcode %}

Now track how much data is received.

{% code title="tcpsocket.py" %}
```python
...
try:
    while True:  # Use a loop to receive data until we receive all of it.
        data = self.sock.recv(BUF_SIZE)  # returned chunk of data with max
        if data == b'': # If empty byytes
            break
        else:
            reply += data  # append to reply
            bytesRecd += len(data)
        if bytesRecd > TOTAL_BYTES:
            break
    except socket.error as e:
...
```
{% endcode %}

## Python Data Types

* All variables in Python are **reference variables**.
* Strings are immutable. 
* Bytes are immutable.

### Working with Strings

* Do not append strings to each other. It's terrible practice because you have to construct so many string objects which exist on the heap.
* Instead, use a list because they are mutable.

```python
list_build = []  # Empty list
for data in container:
    list_build.append(str(data))
s = "".join(list_build)  # Allocate3 a single string to put data in.
```

### Appending to a sequence



## Mutability of Types

![](../../.gitbook/assets/image%20%28226%29.png)







