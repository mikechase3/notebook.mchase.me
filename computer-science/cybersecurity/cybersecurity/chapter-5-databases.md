# Chapter 5: Databases

{% hint style="info" %}
Chapters 5.1-5.7 only.
{% endhint %}

## 5.1: Need for Database Security

* We want to use the same uniform language to access a database.
* **DBMS**: a suite of programs that help in maintaining/restructuring the database.

## 5.2: DBMS

![](<../../../.gitbook/assets/image (714).png>)

* You're defining the data stored in databases.
* It'll be process and put into database description tables.

## 5.3: Relational Databases

There are 3 different types

* Object-oriented databases
* Relational Databases
* Flat-File: basically a Microsoft excel document or a CSV.

## 5.4: SQL Injection Attacks & Types

{% hint style="info" %}
Read this!
{% endhint %}

* **User Input**: attackers inject SQL commands by crafting user input on websites.
* **Server variables**: change some of the values replaced into the HTTP and network headers. (e.g. manipulate the URL).
* **Second Order Injection**: you can use macros and it'll constitute a malicious command that you want. You get these from different places in the system, so it's a lot harder to attack.
* **Cookies**: put the malicious input in a cookie that has the content you want.
* **Physical user input**: outside the realm of web requests.

### Inband Attacks

* It uses the same communications channel for injecting SQL code and retrieving results.
* **Tautology**: inject code into one or more conditional statements so it always evaluates to true.

## 5.5: Database Access Controls

## 5.6: Inference

## 5.7: Database Encryption

* It's the last layer of defense: firewalls, authentication, general access control systems, DB access control systems, and then database encryption.
* **Disadvantages**: key management. It makes the database inflexible because you have to decrypt stuff as you're searching it.

## Homewrok

1. IDK
2. The user inputs a single quote.&#x20;
3. Analyze a grant operation sequence and tell me what happens when B revokes access rights from C. Redraw the diagram based on what priveleges are still in-place after that occurs.
4. Has to do with role-based access control. What is the appropriate access for each role?
