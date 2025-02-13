# Chapter 04: Access Control

Skipped class for 4.1-4.5.

## 4.6: Attribute-Based Access Control (ABAC)

* You define authorizations expressing conditions on properties of both the resource/subject.
* Association
  * Subject attributes: a user
  * Object attributes: a file
  * Environment attributes: the operational/situational environment which information access occurs.

#### Strengths

* It's flexible/expressive.

#### Weaknesses

* Performance impact of evaluating predicates on both resource & user properties.

### ABAC Logical Architecture

![](<../../../../.gitbook/assets/CleanShot 2021-10-12 at 09.48.19@2x.jpg>)

### ABAC Policies

#### Trust Chains

* It's very inefficient.
* You have to have a lot more 'trust' here to implement this.

![](<../../../../.gitbook/assets/CleanShot 2021-10-12 at 09.51.35@2x.jpg>)

## 4.7: ICAM: Identity, Credential, and Access Management

### What is it?

* Developed by the US government.
* Outside entities need access to our systems. How do we know we can trust people who are on their systems?
* This was designed to create trusted digital identities so individuals and their identities can be established.
* Bind those identities to credentials that serve as a proxy for access transactions.

### Identity Management

* This is concenred with assigning attributes to a digital identity and connecting that digital identity to an individual.
* The goal is to access a trustworthy digital identity independent of a specific app or context.

### Access Management

There are 3 elements you need for enterprise-wide access control facilities.

* Resource management:
* Privilege management:
* Policy management:

## 4.8: Trust Frameworks Identity Federation

1. How do we trust identities of individuals from external organizations who need access to your systems?
2. How do you vouch for identities of individuals in your organization when they need to collaborate with external organizations.

Solutions: contracts and TOS agreements.

![](<../../../../.gitbook/assets/CleanShot 2021-10-12 at 10.05.38@2x.jpg>)

### Open Identity Trust Framework

* **OpenID** is a standard allowing users to be authenticated by certain cooperating sites using a 3rd party service.
* **OIDF** (Open ID Foundation) is a non-profit promoting and protecting OpenID technologies.
* **ICF** (Information card foundation): companies trying to advance ecosystems.
* **OITF**: open identity trust framework
* **OIX** (Open identity exchange corporation): they do evaluations.
* **AXN**: An independent service provider ensuring you can exchange these using trusted sources.

#### Roles within Framework

![](<../../../../.gitbook/assets/CleanShot 2021-10-12 at 10.11.57@2x.jpg>)

## Homework

#### 4A

* Part B: User -> o, w, r -> object
* Part C: are they equivalent? Are they exactly equivalent?

#### 4B

* Even though they are both the same files, the permissions mean different thing whether it's a file or directory.
* The data structure is called an **inode**. Read, write, execute.
* If the file is in a directory of 7, 3, 0, this can cause a problem in that this combination of directory mode and file mode can allow the contents of the file to be changed either directly or indirectly.
* We have to figure out what's allowed in the directory permissions, and how can we use that to change what is in the file?
* If you look at the file on the board, only the owner has write access. The intent is that only the owner can change it; however, with the directory set this way, it's possible for someone other than the owner to change it.
* Our task is to figure out how.

#### 4D

* DAC: Discressionary access control.
