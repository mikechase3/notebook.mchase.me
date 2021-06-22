# Week 05: Microservices Architecture & Implementation with Express

## Traditional Application Development

### **N-Tier Layers**

1. Presentation
2. Business: \(business logic layer, domain layer\)
3. Data access layer

### Monolithic

![The three-tier monolithic design](../../.gitbook/assets/image%20%28514%29.png)

#### What is a monolithic design?

* The app is built as a single deployable unit.
* Normally runs as a single process and hosted on a resource-intensive computing platform called the _server_.
* Developed with object-oriented principles

#### Issues with monolithic architecture in the cloud

* Fault isolation cannot be contained.
  * There is no physical separation between different areas of the system.
  * There's no way to guarantee any new release will only affect the areas they are targeted for.
* It's hard to scale properly
  * Scaling it requires lots of resources.
  * You must deploy additional instances of the entire app and setup load balancers or buy a VM with more computing power.
* Deployments are cumbersome and time-consuming
  * Minor changes to a single component or adding a new feature require a full process of rebuilding/regression testing/deploying the enitre monolith agin.
* Limited to a particular techology stack.
  * Requires a long-term commitment to a particular technology stack.
  * It's hard to adopt or change the technology.
  * I think this means that it goes too quickly?

{% hint style="info" %}
**Check your understanding:** In a monolithic application architecture, what are the common three layers? _Answer: view layer, business logic layer, and the data layer._
{% endhint %}

## Microservices

* This is an application architecture and development approach to building **large applications** consisting of a collection of small, autonomous services.
* Each service is self-contained implementing a **single** business capability.

## Works Cited and Further Reading

Links to the aforementioned publicly available sources are listed below.

* Phung, Phu. _Creative Cloud Applications_. Lecture 05. \(Primary\).
* Wu, Andy. _Taking the Cloud-Native Approach with Microservices_. 
* Microservices architecture style guide:  Microservices architecture style.
* Cloud Security Alliance. _Application Containers and Microservices_. "Best Practices in Impolemting a Secure Microservices Architecture" \(Feb 2020\).

{% embed url="https://cloud.google.com/files/Cloud-native-approach-with-microservices.pdf" %}

{% embed url="https://docs.microsoft.com/en-us/azure/architecture/guide/architecture-styles/" %}

{% embed url="https://cloudsecurityalliance.org/artifacts/best-practices-in-implementing-a-secure-microservices-architecture/" %}



