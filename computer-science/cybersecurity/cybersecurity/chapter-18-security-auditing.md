# Chapter 18: Security Auditing

## 18.1: Security Auditing Architecture

![Source: Stalling et. al](<../../../.gitbook/assets/image (642) (1) (1) (1) (1).png>)

### Security Audit and Alarms Model

* Events are reported in the _audit log_.
* When you ned access to a privilege command, it can trigger an audit message.
* Even if you didn't write things into your program, the operating system might still put it in a log if it needs things like elevated privileges.

### Security Auditing Functions

![Src: stallings et. al](<../../../.gitbook/assets/image (639) (1).png>)

* Security auditing is broken down into 6 areas. Each has specific functions.

### Requirements

![Source: stalling et. al](<../../../.gitbook/assets/image (643) (1) (1) (1).png>)

### Implementing Guidelines

1. Agree on the requirements with management
2. Agree on the scope of the checks.
3. Make sure the auditor only has read-only access to software/data.
4. Copy these system files so they can be examined somewhere else.
5. Have the resources available to do the audit
6. If you're going to have additional processing, have resources to do that. Whatever auditors do, that needs to be recorded too. Maybe security auditors are the bad guys.



## 18.2: Security Audit Trail

### What to Collect

* An audit of the auditing software.&#x20;
* Access to the system itself.
* Remote access.

### Physical Access Audit Trails

* When prof needs a master key, he has to go into a box, swipe into it, put in a pin, and the key has a locator attached to it to make sure you put the physical master key back.
*



## Works Cited

* Stallings, William Brown, Lawrie _Computer Security Principles and Practice_
* Baldwin, Rusty _Fundamentals of Cyber Security_ Fall 2021. 21 Oct 2021.
