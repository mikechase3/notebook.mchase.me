# Week 04: Internet & Network Edge & Core

## Assignment 1 Part 3

### FIFO List

![](<../../.gitbook/assets/image (237).png>)

We'll want to implement a Python list.

* In Python, every variable is a reference variable, meaning the reference variables are always objects.
* When we add things to the queue.

### Main Method

In the main method, we'll want to make 5 unique threads. 

{% hint style="info" %}
Review Dr. Yao's clip. Lecture 06 at 17:00
{% endhint %}



## What is the Internet: An Overview

The internet is a massive network of networks. They are loosely hirearchical.

### Computing Devices

* Millions of connected computing devices
* Hosts are end systems
* They run _network applications._
* PC, server, wireless laptop

### Communication Links

* Fiber, copper, radio, satellite
* Transmission rate: bandwidth.

### Routers

* Forward packets & other packets of data

### Protocols

* They control the sending & receiving of messages.
* _Examples: TCP, IP, HTTP,, Ethernet_

### Internet Standards

* RFC: Request for comments
  * When you design your own protocol, you have to follow internet standards
* IETF: Internet engineering task force.

## Protocols

![Protocols are standards of doing business.](<../../.gitbook/assets/image (236).png>)

Protocols define format, order of messages sent and received among network entities, and actions taken on those message transmission like receipt.

## Network Structure

![Access Networks are connected via hierarchical structures. ](<../../.gitbook/assets/image (246).png>)

Access networks are connected to regional networks (ie Dayton) which are connected to global networks run by ISPs.

* A **network edge** means that the the device is not in the center (like some router or ISP)
* **Hosts: **clients and servers often in data centers
* **Access Networks** connect the client servers to the internet
  * Physical media
  * Wired, wireless communication links.
  * We have so many parts of the local area network.

![](<../../.gitbook/assets/image (238).png>)



## Access Networks 

### Digital Subscriber Lines (DSL)

* 24MBps downstream
* \~2MBps upstream.

### Cable Networks

![](<../../.gitbook/assets/image (245).png>)

### Hybrid Fiber Coax

* Asymmetric, up to 30Mbps downstream and 2Mbps upstream transmission rate.
* Network of cable, fiber attaches homes to ISP router.

### Enterprise Networks

![](<../../.gitbook/assets/image (242).png>)

* Institutional link to the ISP

### Wireless Access Networks

* Watch Netflix and drive at the same time.

## Packet Transmission Delay

* (L bits) divided by R bits/second.

## The Network Core

* Routing algorithms try to find the shortest path from the source to the destination

![](<../../.gitbook/assets/image (244).png>)

### Circuit Switching

![](<../../.gitbook/assets/image (240).png>)

* Commonly used in traditional telephone networks
* End to end resources are reserved for the call between the source & destination

### Frequency Division Multiplexing (FDM) vs Time Division Multiplexing (TDM)



![](<../../.gitbook/assets/image (248).png>)

{% hint style="danger" %}
What's the difference?
{% endhint %}



### Packet Switching

* We divide messages into packets.

![](<../../.gitbook/assets/image (249).png>)

* **Transmission Delay**: 
* **Store and forward**: 

#### I need help

{% hint style="warning" %}
What does the math, L, and R mean? 
{% endhint %}

![](<../../.gitbook/assets/image (235).png>)

## Team Quiz

#### What is the difference between a host and an end system? List several different types of end systems.

#### What is the structure of the Internet?

#### What is a network protocol?

#### How does packet switching work?









## Works Cited

[Dr. Zhongmei Yao's Networking Class](https://academic.udayton.edu/zhongmeiyao/)
