# Chapter 07: DoS Attacks

## 7.1 DoS Attacks Introduction

* It exhausts some resource on the system resulting it not being available.
  * Disk space
  * CPU resources.

### **Nature of Attacks**

#### **Network Bandwidth**

* Relates to the capacity of the network links connecting a server to the internet.
* For most organizations, this is their connection to their ISP.

#### System Resources

* Aims to overload or crash the network handling software.

#### Application Resources

* Typically involves a number of valid requests, each of which consumes significant resources.
* Limits the ability of the server to respond to requests from other users.

### Classic DoS Attacks

* The aim is to overwhelm the capacity of the network connection to the target organization.
* Traffic can be handled by high capacity links on the path, but packs are discarded as capacity decreases.

### Source Address Spoofing

#### Forged/Spoofed Source Addresses

* It makes attacking systems harder to identify.
* Attacker generates 

### SYN Spoofing Attack

![Retrieved from Dr. Baldwin&apos;s Slides.](../../.gitbook/assets/image%20%28594%29.png)

* It's trying to fill up a table such that you make a bunch of sessions the system wants to keep a track of, but the table is **filled up with illegitimate sessions.**



## 7.2 Flooding Attacks

### ICMP Flooding

* Uses ICMP \(Internet Control Message Protocol\) echo request packets.
* You basically overwhelm the network with a bunch of ping requests

### UDP Flood

* Here, you don't establish a connection or enter into a system table.
* You just bombard it to a particular port and the driver can't handle everything coming in.

### TCP SYN Flood

* Sends TCP packets to the target system.
* Total volume of packets is the aim of the attack rather than the system code.



## 7.3: Distributed DoS Attacks

* Use of multiple systems to generate attacks.
* The attacker uses a falw in the OS or in a common application to gain access and install their programs on them, becoming a zombie for a bigger botnet.
* Large collections of systems under the control of one attacker's can be created to form a botnet.



## 7.4: Application Based Bandwidth Attacks

### SIP Flood

![When one INVITE request is sent, it uses 5 times the resources on the receiving end.](../../.gitbook/assets/image%20%28593%29.png)

* SIP is used to establish VoIP \(voice over IP\) sessions. 
* It bombards SIP proxy servers with `INVITE` requests.
* **Consumes considerable resources via a single invite** both on proxy and network servicing `INVITE`.
  * You get a 5-for-1. Where one request does 5 times the work for one botnet request.
* This DDoS affects the server, network, and user agents.

### HTTP Based Attacks

#### HTTP Flood

* The attack bombards web server with HTTP requests.
* Consumes considerable resources.
* Spidering/Web crawlers.
* Bots starting from a given HTTP link and following all links on the provided web site in a recursive way.

#### Slowloris

* Attempts to monopolize by sending legit HTTP requests that never are completed.
* It doesn't ever complete the request, sending it... but just super slow.
* It eventually consume's a web servers connection capacity.

## Works Cited

* Stallings, William, and Lawrie Brown. _Computer Security_. Available from: VitalSource Bookshelf, \(3rd Edition\). Pearson Education \(US\), 2014. 

