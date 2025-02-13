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

![Retrieved from Dr. Baldwin's Slides.](<../../../../.gitbook/assets/image (601).png>)

* It's trying to fill up a table such that you make a bunch of sessions the system wants to keep a track of, but the table is **filled up with illegitimate sessions.**

## 7.2 Flooding Attacks

### ICMP Flooding

* Uses ICMP (Internet Control Message Protocol) echo request packets.
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

![When one INVITE request is sent, it uses 5 times the resources on the receiving end.](<../../../../.gitbook/assets/image (602).png>)

* SIP is used to establish VoIP (voice over IP) sessions.
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

## 7.5: Reflection and Amplification Attacks

### Reflection

Port 7 is an ICMP echo port which is carried out by using a spoofed address.

![](<../../../../.gitbook/assets/image (611).png>)

### Amplification Attacks

* Has a bunch of zombies make reflector attacks using spoofed addresses.
* This way, the target is flooded with attacks.

## 7.6: DoS Attack Defenses

* These attacks can't be prevented entirely.
* High traffic volumes may be legitimate
  * High publicity about a specific site
  * Activity on a popular site.

### DoS Attack Prevention

| Idea                                                  | Execution                                                                                                                                                                                                                                                                                                                                                                                                                               |
| ----------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Block spoofed source addresses                        | <ul><li>Send a request to the suspected spoofed address.</li><li><p>The response if received should be consistent with the previously received packet.</p><ul><li>If what you receive/send should have the same number of hops.</li><li>If what you send has more hops, assume the original packet sent isn't legitimate.</li></ul></li></ul>                                                                                           |
| Reverse path forwarding (RPF)                         | Verifies the interface a packet was received on is on the same interface a path to the claimed source will use. If not, drop it.                                                                                                                                                                                                                                                                                                        |
| Use modified TCP connection handling code             | Cryptographically encode critical information in a cookie sent as the server's initial sequence number. If the cookie doesn't come back correctly, drop it.                                                                                                                                                                                                                                                                             |
| Block IP directed broadcasts                          | Within the IP protocol, there are certain services that'll send something to every server on the network. You can just refuse to forward any broadcast packets on.                                                                                                                                                                                                                                                                      |
| Block suspicious service/port combinations.           | If you get an incoming service on a strange port, it's probably not legitimate.                                                                                                                                                                                                                                                                                                                                                         |
| Manage application attacks with some site of captcha. | You'll know you're responding to a captcha if you put up a puzzle that they have to solve.                                                                                                                                                                                                                                                                                                                                              |
| Use mirrored/replicated servers.                      | If you are able to bring on legitamate servers, you can dynamically adjust to your traffic level. If you're getting DoSsed, you can service the legit attacks while figuring out how to discard illegitimate attacks. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. Illegitimate. |

## 7.7: Responses

* Have a good **incident response plan**.
* Antispoofing, directed broadcast, and rate limiting filters should be implemented.
* Ideally have network monitors and IDS to detect and notify abnormal traffic patterns.

### Responding to DoS Attacks

* Identify the type of attack.
* Have your ISP trace packet flow back to the source.
* Implement a contingency plan; new servers with different addresses.
* Update an incident response plan with lessions you've learned.

## Works Cited

* Stallings, William, and Lawrie Brown. _Computer Security_. Available from: VitalSource Bookshelf, (3rd Edition). Pearson Education (US), 2014.\\
