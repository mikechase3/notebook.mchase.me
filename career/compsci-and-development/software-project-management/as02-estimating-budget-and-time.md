---
description: Software Proj Mgmt, Homework 2 Detailed Estimations
---

# AS02 Estimating Budget and Time

Assume (or rather imagine) that DAM-IT, the Digital Assistance and Mobile Integration team was actually profitable and had $1M. First of all, I wouldn't know what to do with it, but I'd probably have to hire people because I'm not producing that kind of output. But if I were to get as big as Microcenter I can see spending about $1M/year in labor costs and hiring about eight developers with a combined worth of $1.5M.

See [DAM-IT.TECH](../../software-project-management/dam-it.tech) for more info on the context/vision.

I'm writing this very last-minue because I have to do a poster for AFRL Discover ASAP. Sorry it's to a much lower quality than I would've liked.

## Task List

### Authorization and Django Backend

First, build the django web app backend. To do this, we'll need a method of user authentication. Because I don't trust my employees (or anyone) I'm going to make SmartCards and load my private keys and integrate private/public keys into the django app to authorize them. Let's call this the **AUTH** phase. Subtasks might include:

* [ ] Write a skeleton HTML document, buttons, and a bit of forum functionality.
* [ ] Install a django test server locally.
* [ ] Setup smart-card authentication by viewing existing libraries and testing functionality.&#x20;
* [ ] Create user databases and a prototype website for review/refinement/etc.
* [ ] Setup a Google Cloud Platform account w/ Compute and Database support.
* [ ] Move django site to an apache web server on Google Cloud Platform (henceforth GCP)
* [ ] Migrate existing user authorization database to GCP.

Let's start everything on Jan 1st, 2025, and this part will be due on May 1 2025.

### **Scheduling System**: realistically, I need a scheduling system that'll sorta integrate

with my own Google Calendar so I don't need to hire a secretary and I can let people self-schedule. I expect I'll have multiple people staffed to help repair stuff and do house calls. So let's say I have a system that you pick a date/time on and it'll look at everyone's calendars to determine their availability for appointments. I forget which algorithm does the scheduling but it'd be like the stable matching problem. Customer puts in their availability and they're matched/assigned to a tech and the issue gets assigned on Gitlab all automatically. Subtasks:

* [ ] Build the front-end site. (Some HTML/CSS/JS. Nothing too fancy. Should only take a few weeks or so)
* [ ] Built the back-end for the scheduling system.
* [ ] Make component that'll handle all Google API calls like reading/writing/auth their accounts.
* [ ] Write & attach the front-end for the scheduling system.
* [ ] Implement a payment provider that'll take credit cards to "hold someone's spot"

Let's say this'll be due July 1, 2025 and I'll hire a full-stack or two to do all the API stuff.

### Task 3: Build the inventory management system

Inventories are important to track and better optimize what we need at different locations. My office is at The Hub, but space is more expensive so I also have a storage unit for older things like 2.5" HDDs because everyone wants a SSD now. Here's my vision:

* [ ] Make a tKinter app using Python with some basic front end to see fields like "count", "name"...
* [ ] Setup the SQL database.
* [ ] Make tKinter app talk to the SQL database.
* [ ] Get website to pull available inventory from SQL database that's publicly visible.

### Task 4: Develop iOS and Android Apps

This'll take a bit to do:

* [ ] Write the front-end iOS app.
* [ ] Write the back-end of the iOS app (function calls to SQL DB)
* [ ] Write the front-end of the Android app.
* [ ] Write the back-end of the Android app.

### Summary

For my sanity & to make things a bit more concise, consider this table:

<table><thead><tr><th>Task</th><th width="312">Description</th><th>Due-Date</th></tr></thead><tbody><tr><td>Start</td><td>Development begins</td><td>Jan 1, 2025</td></tr><tr><td>Django skeleton site, auth, and databases.</td><td>Build the framework for the website, databases, etc. Implement smart-card authentication and deploy it to Google Cloud.</td><td>May 1, 2025</td></tr><tr><td>Adaptive Scheduling System</td><td>Make a user-friendly scheduling interface for the front-end and an admin-side panel that integrates with Google Calendar and utilizes a matching algorithm to optimize technician assignments.</td><td>July 1, 2025</td></tr><tr><td>Real-Time Inventory Management Sys</td><td>Make a comprehensive inventory management for everything quantifiable like labor[availability, skillLevel, qualifications], hardware, software keys/licenses, etc.</td><td>October 1, 2025</td></tr><tr><td>Cross-platform mobile applications</td><td>Develop iOS and Android apps allowing users to interact with scheduling systems, inventory systems, and make payments to confirm reservations.</td><td>January 1, 2026</td></tr></tbody></table>



## Labor Breakdown

<table><thead><tr><th width="177">Task</th><th>Backend Dev</th><th>Frontend Dev</th><th>Cloud Egr</th><th>App Developer</th></tr></thead><tbody><tr><td>#1: site, auth, django</td><td>320</td><td>140</td><td>160</td><td>10</td></tr><tr><td>#2: scheduling system</td><td>240</td><td>140</td><td>80</td><td>10</td></tr><tr><td>#3: Inventory Management Sys</td><td>240</td><td>140</td><td>20</td><td>20</td></tr><tr><td>#4: cross platform app</td><td>80</td><td>80</td><td>160</td><td>320</td></tr><tr><td>Hourly Rate</td><td>$70/hr (880hr)</td><td>$50/hr (500)</td><td>$70/hr (420)</td><td>$70/hr (360)</td></tr><tr><td>Total Cost</td><td>$61,600</td><td>$25,000</td><td>$29,400</td><td>$25,200</td></tr></tbody></table>



## Gantt Chart

* Show the full breakdown of each task & their due-dates, across every month of the project.
* Put lines down for each month.
* Include milestones.

### PlantUML

I went to plantUML's docs on gantt charts and spent way too much time reading the docs to make this:

```java
@startgantt
projectscale monthly
Project starts the 1st of january 2025

[Django Auth] as [Task1] requires 120 days
[Schedule] as [Task2] requires 60 days 
[Inventory Sys] as [Task3] requires 90 days
[Mobile Apps] as [Task4] requires 90 days

[Task2] starts at [Task1]'s end
[Task3] starts at [Task2]'s end
[Task4] starts at [Task3]'s end

@endgantt

```



<figure><img src="../../../.gitbook/assets/image (2) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

After learning some syntax and spending literally 45m on this tiny chart, I tried putting some subtasks into Chat GPT and having it write the UML code, but it always gets the syntax wrong and wasn't very helpful. Since subtasks weren't required for this project, I'm going to skip over them in this graph.&#x20;

## Proposed Budget Plot

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

{% hint style="warning" %}
Actual cost estimate is $150, far from the $1M budget given in this assignment.&#x20;
{% endhint %}

