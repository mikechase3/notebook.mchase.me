# Week 05: Microservices Architecture & Implementation with Express

## Traditional Application Development

### **N-Tier Layers**

1. Presentation
2. Business: \(business logic layer, domain layer\)
3. Data access layer

### Monolithic

![The three-tier monolithic design](../../../.gitbook/assets/image%20%28517%29.png)

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

![](../../../.gitbook/assets/image%20%28514%29.png)

* This is an application architecture and development approach to building **large applications** consisting of a collection of small, autonomous services.
* Each service is self-contained implementing a **single** business capability.
* This is more modern and companies are switching to it because it's easier to update/scale.

### Characteristics

* These are small, independent, and loosely coupled.
* A single small-team of developers can write and maintain a service.
  * Each service is a **separate codebase**, which can be managed by a small development team.
  * Services can be **deployed independently**
    * A team can update an existing service without rebuilding the entire app.
  * Services are responsible for persisting their **own data** or external state.
  * Services **communicate with each other** by using well-defined APIs.
  * Services don't need to share the same technology stack, libraries, or frameworks.

### History and Landscape

* "Micro Web Services" was introduced by Dr. Peter Rogers in a cloud-computing conference in 2005.
* The "Microservices" term was applied at an event for software architects in 2011.
* Currently, it's the prime candidate for maximizing the return for companies moving to the cloud.

### Drawbacks

* Complexity
* Development and testing
* Lack of "governance"
* Network congestion and latency
* Data integrity \(harder to control?\)
* Management
* Versioning
* Skillset: \(old timers aren't as hip to the new stuff?\)

{% hint style="info" %}
**Summary:** In a microservices architecture, each service should have a separate codebase and be managed by a small team. Each service should be responsible for its own data.
{% endhint %}

## How to Implement?

* We can use the express framework \(lab 2, part 2.c\)
* Remove the front-end UI so that this only returns a message.
* Add a new route to the application using `app.Method(path, handler)`
* Use functions and getters/setters. So everything is an interface of sorts.

![](../../../.gitbook/assets/image%20%28515%29.png)

## Cross-Origin Resource Sharing \(CORS\)

* This is a mechanism to allow cross-origin HTTP request/response.

### Usage Example

![](../../../.gitbook/assets/image%20%28516%29.png)

{% hint style="info" %}
**Check your understanding:** True/False: a microservice API allow CORS by default. _False._
{% endhint %}

## Microservice Testing

* We can run the microservice locally and test it using Google Cloud Shell.
* Each service must be accessible from within the network \(or publicly if it's a front-end computer users must interact with\).
* After deploying locally, deploy it on a server. 

## Sprint 1 Requirements

### Microservices 1

### Microserves 2

* **Input**: two fields of data
* Output: Generate
* Must NOT have a front-end UI.

## Works Cited and Further Reading

Links to the aforementioned publicly available sources are listed below.

* Phung, Phu. _Creative Cloud Applications_. Lecture 05. \(Primary\).
* Wu, Andy. _Taking the Cloud-Native Approach with Microservices_. 
* Microservices architecture style guide:  Microservices architecture style.
* Cloud Security Alliance. _Application Containers and Microservices_. "Best Practices in Impolemting a Secure Microservices Architecture" \(Feb 2020\).

{% embed url="https://cloud.google.com/files/Cloud-native-approach-with-microservices.pdf" %}

{% embed url="https://docs.microsoft.com/en-us/azure/architecture/guide/architecture-styles/" %}

{% embed url="https://cloudsecurityalliance.org/artifacts/best-practices-in-implementing-a-secure-microservices-architecture/" %}



