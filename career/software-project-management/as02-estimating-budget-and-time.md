# AS02 Estimating Budget and Time
Assume (or rather imagine) that DAM-IT, the Digital Assistance and Mobile Integration team 
was actually profitable and had $1M. First of all, I wouldn't know what to do with it, but
I'd probably have to hire people because I'm not producing that kind of output.
But if I were to get as big as Microcenter I can see spending about $1M/year in labor costs
and hiring about eight developers with a combined worth of $1.5M.

See [DAM-IT.TECH](dam-it.tech) for more info on the context/vision.

I'm writing this very last-minue because I have to do a poster for AFRL Discover ASAP.
Sorry it's to a much lower quality than I would've liked.

## Task List
### Authorization and Django Backend
First, build the django web app backend. To do this, we'll need a method of user authentication.
Because I don't trust my employees (or anyone) I'm going to make SmartCards and load my private keys
and integrate private/public keys into the django app to authorize them. Let's call this the **AUTH**
phase. Subtasks might include:
- [ ] Write a skeleton HTML document, buttons, and a bit of forum functionality. 
- [ ] Install a django test server locally.
- [ ] Create user databases and a prototype website for review/refinement/etc.
- [ ] Setup a Google Cloud Platform account w/ Compute and Database support.
- [ ] Move django site to an apache web server on Google Cloud Platform (henceforth GCP)
- [ ] Migrate existing user authorization database to GCP.

Let's start everything on Jan 1st, 2025, and this part will be due on May 1 2025.

### **Scheduling System**: realistically, I need a scheduling system that'll sorta integrate
with my own Google Calendar so I don't need to hire a secretary and I can let people self-schedule.
I expect I'll have multiple people staffed to help repair stuff and do house calls.
So let's say I have a system that you pick a date/time on and it'll look at everyone's
calendars to determine their availability for appointments. I forget which algorithm does the
scheduling but it'd be like the stable matching problem. Customer puts in their availability and
they're matched/assigned to a tech and the issue gets assigned on Gitlab all automatically. Subtasks:

- [ ] Build the front-end site. (Some HTML/CSS/JS. Nothing too fancy. Should only take a few weeks or so)
- [ ] Built the back-end for the scheduling system.
- [ ] Make component that'll handle all Google API calls like reading/writing/auth their accounts.
- [ ] Write & attach the front-end for the scheduling system.
- [ ] Implement a payment provider that'll take credit cards to "hold someone's spot"

Let's say this'll be due July 1, 2025 and I'll hire a full-stack or two to do all the API stuff.


### Task 3: Build the inventory management system
Inventories are important to track and better optimize what we need at different locations.
My office is at The Hub, but space is more expensive so I also have a storage unit for
older things like 2.5" HDDs because everyone wants a SSD now. Here's my vision:

- [ ] Make a tKinter app using Python with some basic front end to see fields like "count", "name"...
- [ ] Setup the SQL database.
- [ ] Make tKinter app talk to the SQL database.
- [ ] Get website to pull available inventory from SQL database that's publicly visible.

### Develop iOS and Android Apps
This'll take a bit to do:
- [ ] Write the front-end iOS app.
- [ ] Write the back-end of the iOS app (function calls to SQL DB)
- [ ] Write the front-end of the Android app.
- [ ] Write the back-end of the Android app.

### Table
Easy. Four easy steps. I'll get two developers who know the built-ins. How do I make tables again?
I have to do this in markdown because I'm working on base and it's easier to use terminal
than try and load websites on computers. I wonder how I'll do the gantt chart that'll be hard.

| Task              | Roles                         | Labor (hrs) | Due   | Cost              |
| ------------------|-------------------------------|-------------|-------|-------------------|
| Django Stuff      | FullStack, Cloud Egr          | 160*4*2=1280| May1  | $75/hr+$100/hr    |


Number of hours per each role. Show why/how my task is allocated & due dates.

## Gantt Chart

* Show the full breakdown of each task & their due-dates, across every month of the project.
* Put lines down for each month.
* Include milestones.

## Proposed Budget Plot

By month, show the breakdown. CUMULATIVE.
