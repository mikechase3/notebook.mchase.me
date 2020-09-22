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

![](../../.gitbook/assets/image%20%28391%29.png)

## HTTP Connections

![](../../.gitbook/assets/image%20%28390%29.png)

### HTTP 1.0 vs 1.1

{% hint style="info" %}
If we use HTTP/1.1, we get 10 extra credit points onto part 3.
{% endhint %}

![](../../.gitbook/assets/image%20%28393%29.png)

#### Symbols

| Symbol | Meaning |
| :--- | :--- |
| Fin | Finished; close the connection. |
| Syn |  |
| Acknowledge |  |
| HTTP Get |  |
| HTTP Response |  |
| RTT |  |

#### Differences

* In socket 1.0, we need one socket for each connection call.
  * We need a socket for the _HEAD_ request
  * We also need another socket for the _GET_ request.
* In 1.1, you can send multiple requests on the same connection.
  * Only one socket for both the `HEAD` and `GET` request.

## Non-persistent URLs

* Suppose a user enters the URL www.someSchool.edu/someDepartment/home.
* Below lists the process

![](../../.gitbook/assets/image%20%28392%29.png)

![](../../.gitbook/assets/image%20%28394%29.png)

## Non-Persistent HTTP: Response Time













































## Works Cited

[Dr. Zhongmei Yao's Networking Class](https://academic.udayton.edu/zhongmeiyao/)







