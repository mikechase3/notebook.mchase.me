---
description: Follows chapter 2 of the textbook.
---

# Week 05: Application Layer

## Web App

* Web pages consist of objects
* Objects can be HTML files, JPEG images, Java applets, an audio file, etc.
* Web pages consist of _base HTML-files_ which include several referenced objects.
* Each object is addressable by a _URL_.
  * Contains protocol
  * Host name
  * Path name

![](<../../.gitbook/assets/image (394).png>)

## HTTP Connections

![](<../../.gitbook/assets/image (393).png>)

### HTTP 1.0 vs 1.1

{% hint style="info" %}
If we use HTTP/1.1, we get 10 extra credit points onto part 3.
{% endhint %}

![](<../../.gitbook/assets/image (403).png>)

#### Symbols

| Symbol        | Meaning                         |
| ------------- | ------------------------------- |
| Fin           | Finished; close the connection. |
| Syn           |                                 |
| Acknowledge   |                                 |
| HTTP Get      |                                 |
| HTTP Response |                                 |
| RTT           |                                 |

#### Differences

* In socket 1.0, we need one socket for each connection call.
  * We need a socket for the _HEAD_ request
  * We also need another socket for the _GET_ request.
* In 1.1, you can send multiple requests on the same connection.
  * Only one socket for both the `HEAD` and `GET` request.

## Non-persistent URLs

* Suppose a user enters the URL www.someSchool.edu/someDepartment/home.
* Below lists the process

![](<../../.gitbook/assets/image (396).png>)

![](<../../.gitbook/assets/image (406).png>)

## Non-Persistent 1.0 HTTP: Response Time

![](<../../.gitbook/assets/image (402).png>)

**RTT**: The time for a small packet to travel from a client to server and back.

### Response Time

* One RTT to initiate TCP connection
  * The first two parts of the 3-way handshake
* One RTT for HTTP request and first few bytes of HTTP response to return
* File transmission time
* Total = 2RTT + Transmission Time

### HTTP 1.1

{% hint style="info" %}
I missed about 15 minutes of class here.
{% endhint %}

## Summary: HTTP Requests

![](<../../.gitbook/assets/image (404).png>)

## HTTP Response Codes

![](<../../.gitbook/assets/image (392).png>)















































## Works Cited

[Dr. Zhongmei Yao's Networking Class](https://academic.udayton.edu/zhongmeiyao/)





