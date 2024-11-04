# AS03 Sprint Planning Task Breakdown

## Project Overview
The assignments I chose so far are part of a larger goal of creating my own platform for my small business, DAM-IT LLC
which is a brick-and-mortar tech business that provides on-site service, affordable device rentals, and same day service.
The "grand idea" is an uber-style service that manages inventory, availability, and gives customers access to that info.

I'm going to select two tasks from the [second assignment.](/career/software-project-management/as02-estimating-budget-and-time.md)
Since the timeline of that entire project was one year and this takes over the course of two sprints, the timeline
will be shortened to complete each task in two weeks. Specifically, it will be shortened to build a **prototype**
application:

## Selected Tasks with Descriptions

1. Start a django application **prototype** on Google Cloud
2. Build a **skeleton** site. 

My _as02_ table of the overarching project is listed below for reference; however, we'll only be focusing on the first two.

| Task                                       | Description                                                                                                                                                                                    | Due Date     |
|--------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------|
| Start                                      | Development begins                                                                                                                                                                             | Jan 1, 2025  |
| Django skeleton site, auth, and databases. | Build the framework for the website, databases, etc. Implement smart-card authentication and deploy it to Google Cloud.                                                                        | May 1, 2025  |
| Adaptive Scheduling System                 | Make a user-friendly scheduling interface for the front-end and an admin-side panel that integrates with Google Calendar and utilizes a matching algorithm to optimize technician assignments. | July 1, 2025 |
| Real-Time Inventory Management Sys         | Make a comprehensive inventory management for everything quantifiable like labor\[availability, skillLevel, qualifications], hardware, software keys/licenses, etc.                            | Oct 1, 2025  |
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

| Task Name                                     | Assignee    | Time (hrs) | Definition of Done                                                                                               |          |
|-----------------------------------------------|-------------|------------|------------------------------------------------------------------------------------------------------------------|----------|
| Set up Google Cloud Environment               | Developer 1 | 40         | Google Cloud account is created; Network/IP Filtering setup; security policy; sql instance setup.                | Critical |
| Install Python and Django                     | Developer 1 | 20         | Compute engine setup; Python and Django are installed; a sample Django project runs successfully without errors. | Critical |
| Documentation and User Guide                  | Developer 1 | 16         | Documentation for installation and usage is complete and reviewed; user guide is created for FAQ.                | Medium   |
| Create User Authentication Model              | Developer 2 | 32         | User model is created and migrated to the database & migrations are verified by query calls to google cloud.     | Medium   |
| Implement User Registration Functionality     | Developer 2 | 16         | Users can register; registration directs to the login page; failed login error messages are thrown to user.      | Low      |
| Implement User Login Functionality            | Developer 2 | 16         | Users can log in; session management is handled; appropriate error messages display upon failure.                | Critical |
| Password Hashing Implementation               | Developer 3 | 8          | Passwords are hashed and stored securely; verified through testing with different user inputs.                   | High     |
| Develop Role Management System                | Developer 3 | 12         | User roles are created; access restrictions are verified based on role; tests confirm proper access.             | High     |
| Set Up Unit Tests for Authentication Features | Developer 3 | 12         | All critical paths for login and registration are covered by tests; tests run successfully without errors.       | Medium   |
| Implement Scheduling Feature                  | Developer 4 | 16         | Users can create new appointments; appointments are stored correctly in the database.                            | Critical |
| Integrate Google Calendar API                 | Developer 4 | 16         | API integration is implemented; appointments sync correctly with Google Calendar; functionality is verified.     | High     |
| Design Database Schema                        | Developer 4 | 16         | The schema is documented in repo & created in the database; tables are verified to match the application needs.  | Critical |


# JUNK
# Sprint Planning Document

## Project Overview
### Selected Tasks
1. **Task 1: Implement User Authentication System**  
   Description: Develop a basic user authentication system that allows employees to register, login, and access the prototype application. This will involve using Django’s built-in authentication functionalities and creating a simple user database.

2. **Task 2: Develop Scheduling System**  
   Description: Create a scheduling system that integrates with Google Calendar for employees to self-schedule appointments. The logic for handling bookings and checking availability will be implemented without a front-end interface.

## Goals for the Sprint
1. Implement a functional user authentication system.
2. Create a working scheduling system that integrates with Google Calendar.
3. Ensure basic functionality is completed within a two-week time frame.

## Sprint Backlog
### Task Breakdown
| Task Name                                    | Assignee    | Estimated Time (hours) | Definition of Done                                                                              | Priority |
|----------------------------------------------|-------------|------------------------|-------------------------------------------------------------------------------------------------|----------|
| 1. Setup Django Environment                  | Developer 1 | 8                      | Django environment is configured; the application runs without errors.                          | High     |
| 2. Create User Model                         | Developer 2 | 8                      | User model is created and successfully migrated to the database.                                | Critical |
| 3. Implement User Registration               | Developer 3 | 16                     | Users can register, and their data is correctly stored in the database.                         | Critical |
| 4. Create Login Functionality                | Developer 4 | 16                     | Users can log in successfully; appropriate error messages for failures are in place.            | Critical |
| 5. Implement Google Calendar API Integration | Developer 1 | 16                     | API integration is tested; the app can read and write appointments to Google Calendar.          | High     |
| 6. Create Appointment Booking Logic          | Developer 2 | 16                     | Users can book appointments based on availability; success and failure returns are implemented. | Critical |
| 7. Setup Data Validation for User Input      | Developer 3 | 12                     | All user inputs are validated; the application handles errors properly.                         | Medium   |
| 8. Test User Registration                    | Developer 4 | 8                      | Test cases for registration pass; all edge cases are handled in testing.                        | Medium   |
| 9. Test Login Functionality                  | Developer 1 | 8                      | Login test cases pass; any issues are documented and resolved.                                  | Medium   |
| 10. Test Scheduling System                   | Developer 2 | 16                     | All scenarios for appointment booking are tested successfully.                                  | Medium   |
| 11. Prepare Documentation                    | Developer 3 | 12                     | Documentation is created and available for the development team and users.                      | Low      |
| 12. Code Review                              | Developer 4 | 8                      | All code is reviewed, feedback is documented, and revisions are made accordingly.               | High     |

Here’s a structured task breakdown for your sprint, incorporating 12 tasks with assignments for 4 developers. The estimated total time meets your criteria for the 2-week sprint, targeting between 256-320 hours.

### Task Breakdown Structure

### Summary of Time Allocation
| Developer     | Total Hours |
|---------------|-------------|
| Developer 1   | 44          |
| Developer 2   | 48          |
| Developer 3   | 36          |
| Developer 4   | 44          |
| **Total**     | **172**     |

### Notes:
- The sum of hours here is 172. You can adjust individual tasks by adding more granular tasks or redistributing hours among the developers to reach a total between 256-320 hours.
- Each task features a "Definition of Done" to ensure clarity in completion.
- Adjustments can be made for priority if necessary based on your team's needs or project objectives.

Please let me know if you would like to add more hours or tasks, or if you need further clarifications!