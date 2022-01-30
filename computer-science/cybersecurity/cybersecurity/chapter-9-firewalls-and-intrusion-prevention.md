# Chapter 9: Firewalls and Intrusion Prevention

## 9.1: Purpose

* The firewall works as a perimeter defense system.
* It forces all traffic through a single point to be examined, modified, or blocked.

## 9.2: Characteristics

* All traffic from inside to outside and vice-versa must pass through.
* The firewall itself must be immune to penetration.
* Only authorized traffic as defined by the local security policy will be allowed to pass.

### Firewall Access Policy: Things We Control

* What type of traffic and to whom has the power to get through?
* IP addresses
* Application protocols
* User Identity
* Network Identity

## 9.3: Types of Firewalls

1. Single Bastian inline firewall
2. Packet filtering
3. Application Level
4. Circuit-level proxy

## 9.4: Firewall Basing

## 9.5: Firewall Location and Configurations

## 9.6: Intrusion Prevention Systems

### Host-Based IPS (HIPS)

Checks modification of privelege resources, buffer overflow exploits, access to email contact lists, etc.

### Network Based IPS

* Modifies and discards TCP packets.
* Limits the rate at which certain packets can be sent if they're suspicious.

#### Methods

1. Pattern Matching
2. Stateful matching
3. Protocol anomaly
4. Traffic anomaly
5. Statistical anomaly.

### Distributed or Hybrid IPS: Digital Immune System

{% hint style="info" %}
What is this?
{% endhint %}

### Snort Inline

{% embed url="https://snort.org" %}

* Snort is a packet monitoring system.
* It also has intrusion prevention capabilities.&#x20;

## 9.7: Unified Threat Management Products

![](<../../../.gitbook/assets/image (640) (1) (1).png>)

## 9.8: Review

## 9.9: Homework

1. We're going to be developing rules for the internal/external firewall. A list of policies are listed. For the very first one, here's how it would look like.

| Policy | Direction | Source Address |           | Protocol | Action |
| ------ | --------- | -------------- | --------- | -------- | ------ |
| 1      | Both      | External       | DMZ Email | SMPT     | Permit |
|        |           |                |           |          |        |
|        |           |                |           |          |        |
|        |           |                |           |          |        |

* This will be due next Tuesday.&#x20;
