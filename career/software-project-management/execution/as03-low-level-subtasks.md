# AS03 Sprint Planning Task Breakdown

## Project Overview
The assignments I chose so far are part of a larger goal of creating my own
platform for my small business, DAM-IT LLC
which is a brick-and-mortar tech business that provides on-site service, affordable device rentals, and same day service.
The "grand idea" is an uber-style service that manages inventory, availability, and gives customers access to that info.

I'm going to select two tasks from the [second assignment.][1]
Since the timeline of that entire project was one year and this takes over the course of two sprints, the timeline
will be shortened to complete each task in two weeks. Specifically, it will be shortened to build a **prototype**
application:

## Selected Tasks with Descriptions

1. Start a django application **prototype** on Google Cloud
2. Build a **skeleton** site. 

My _as02_ table of the overarching project is listed below for reference; however, we'll only be focusing on the first two.

| Task                                       | Description                                                                                                                                                                                    | Due Date     |
| ------------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ |
| Start                                      | Development begins                                                                                                                                                                             | Jan 1, 2025  |
| Django skeleton site, auth, and databases. | Build the framework for the website, databases, etc. Implement smart-card authentication and deploy it to Google Cloud.                                                                        | May 1, 2025  |
| Adaptive Scheduling System                 | Make a user-friendly scheduling interface for the front-end and an admin-side panel that integrates with Google Calendar and utilizes a matching algorithm to optimize technician assignments. | July 1, 2025 |
| Real-Time Inventory Management Sys         | Make a comprehensive inventory management for everything quantifiable like labor\\[availability, skillLevel, qualifications], hardware, software keys/licenses, etc.                           | Oct 1, 2025  |
| Cross-platform mobile applications         | Develop iOS and Android apps allowing users to interact with scheduling systems, inventory systems, and make payments to confirm reservations.                                                 | Jan 1, 2026  |


### Task 1: Implementing User Authentication System
In the first sprint, we'll handle the task of setting up a django server on Google Cloud and implementing basic authentication.
The user authentication will allow employees to register and login to the app. They will be labeled as customers,
employees, or administrators so customers/employees can't see sensitive information about other clients or details.
Simple & static web pages will exist and be displayed depending on which type of user accesses URLs.


### Task 2: Implementing a Scheduling System
The scheduling system will be designed to allow student employees maximum flexibility of their working hours. 
Customers will be able to self-schedule appointments through the internal application w/ a front-facing interface,
and they will be matched to qualified technicians by checking their qualifications (via tags) and the employee's
availability by examining their Google Calendar entries, preventing scheduling conflicts in real time.

## Sprint
### Goals for Tasks One & Two
The goal of the sprint is to accomplish the two tasks above. The overarching goals are:
1. Setup the Google Cloud Environment by making a compute instance and installing python & django library.
2. Design and implement a database schema to support user roles, management, and scheduling.
3. Implement a user authentication system w/ Django pages & the user database using the builtin django login mechanisms, 
but securing it using password hashing, salting, and separating users into roles of customer, employee, and superuser.
4. Develop the scheduling system allowing customers to specify needs & match them with technicians based on
the employee's qualifications and their Google Calendar using G-Cal API calls.

### Sprint Backlog

| Task Name                                 | Assignee    | Time (hrs) | Definition of Done                                                                                               |          |
| ----------------------------------------- | ----------- | ---------- | ---------------------------------------------------------------------------------------------------------------- | -------- |
| Set up Google Cloud Environment           | Developer 1 | 40         | Google Cloud account is created; Network/IP Filtering setup; security policy; sql instance setup.                | Critical |
| Install Python and Django                 | Developer 1 | 20         | Compute engine setup; Python and Django are installed; a sample Django project runs successfully without errors. | Critical |
| Documentation and User Guide              | Developer 1 | 16         | Documentation for installation and usage is complete and reviewed; user guide is created for FAQ.                | Medium   |
| Create User Authentication Model          | Developer 2 | 40         | User model is created and migrated to the database & migrations are verified by query calls to google cloud.     | Critical |
| Implement User Registration Functionality | Developer 2 | 8          | Users can register; registration passwords get hashed/salted; failed login error messages are thrown to user.    | Low      |
| Implement User Login Functionality        | Developer 2 | 16         | Users can log in; session management is handled; Create Prototype HTML Pages for differnet roles.                | Critical |
| Password Hashing Implementation           | Developer 3 | 8          | Passwords are hashed and stored securely in DB.                                                                  | High     |
| Develop Role Management System            | Developer 3 | 48         | Improve security of access control mechanisms for different roles                                                | High     |
| Research & Implement Security Measures    | Developer 3 | 16         | URL paths for login and registration are verified and tests for security measures are extensively documented.    | Medium   |
| Implement Scheduling Feature              | Developer 4 | 20         | Users can create new appointments; appointments are stored correctly in the database.                            | Critical |
| Implement Google Calendar API Integration | Developer 4 | 40         | API integration is implemented; appointments sync correctly with Google Calendar; functionality is verified.     | High     |
| Design Database Schema                    | Developer 4 | 16         | The schema is documented in repo & created in the database; tables are verified to match the application needs.  | Critical |

Here's how their hours stack up:
* Dev1: 64hrs
* Dev2: 64hrs
* Dev3: 72hrs
* Dev4: 76hrs

Following this sprint is one developing the inventory management system for equipment. Following that or perhaps concurrently, mobile development begins.

[1]:	/career/software-project-management/as02-estimating-budget-and-time.md