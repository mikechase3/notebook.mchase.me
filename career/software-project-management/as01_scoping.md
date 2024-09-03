# AS01 Scoping

## Final Deliverable
### Questions & Answers
* **What I'm doing**: 




## Requirements
* Answer Questions:
  * What am I trying to do? 
  * 

Goals: 
* Plan DAM-IT blue-sky-dea services.
* Utilize *The Helmeier Catechism*: questions to articulate goals & risks. 
* High-level, don't think about cost or time yet.

Requirements:
* Answer questions. 
* For each goal, explain how it relates to project.
* 3 total goals w/ how end-user interacts with my software.
* Make a 1-slide PPT showcasing project.

**DRAFT BELOW**

## Project Overview
**Project Objective**: Project Objective: 
Develop a Django-based web application for DAM-IT, integrating scheduling, customer management, and inventory functionalities. 
This system will streamline operations for IT support services, equipment rentals, and customer interactions. 
Eventually, the goal is to expand the functionality to mobile apps using SwiftUI and Android native components.

### Current System
* Website: DAM-IT.TECH currently redirects to a Google Sites page.
* Scheduling: managed via Google Calendar, which integrates well with existing workflows for blocking personal time
while displaying available slots for customer bookings.
* Payment & Booking: initial customer interaction happens over the phone, where bookings
are confirmed and a $25 deposit is collected. Subsequent prices are tiered, increasing for $10 for each additional
booking until capacity is reached.

### Proposed System
#### Django Web Application:
* Appointment System: Embed a Google Calendar iframe for initial consultation bookings. Implement a custom back-end for managing follow-up bookings with tiered pricing to optimize workload.
* Customer Database: A component to store customer details, past interactions, and service requests. This will facilitate tracking customer history and improve service efficiency.
* Inventory Management: Implement or integrate an open-source inventory system to manage rental equipment, prices, and availability in real-time.

#### Mobile App Development:
* SwiftUI-Based iOS App: A native iOS application using SwiftUI to offer seamless interaction with the Django backend. The app will allow users to browse available equipment, book services, and potentially handle payments.
* Android App: A native Android application mirroring the iOS app functionality, using Android's native UI components for a responsive and intuitive user experience.

#### Learning Objectives and Open-Source Considerations:
* Integration and Customization: The project serves as a learning platform for integrating Google Calendar API and building custom CRM solutions with Django.
* Publishing Open Source: If successful, components developed could be released as open-source tools, potentially filling gaps in existing CRM and inventory management solutions.
* Comparison with Existing Solutions: Systems like Uber offer advanced booking capabilities, similar to the envisioned setup. Odoo provides an open-source ERP/CRM system that covers a range of business needs, but the goal here is to create something more lightweight and tailored to small IT service providers.

 
#### What's New:

Integration of Native UI Elements: By using SwiftUI and Android native components, the apps will leverage the platform's built-in UI frameworks, resulting in a more responsive and consistent user experience.
Scalable and Modular Design: Starting with essential functionalities and scaling as needed allows for manageable growth and adaptability.
Open-Source Contribution: While there are many CRM solutions available, contributing a tailored, modular solution for small service-based businesses could meet niche needs not fully covered by larger systems like Odoo.
Market Impact:

Target Audience: Primarily college students, a demographic that prefers self-service options and app-based interactions. By offering a user-friendly app, DAM-IT aims to increase its customer base and improve service efficiency.
Operational Efficiency: Automation of booking, payments, and customer management will reduce the manual workload, allowing more focus on delivering high-quality IT services.

## Overview Presentation Slide
DAM-IT Tech Project: Streamlined IT Service Management

### Objectives:

* Develop a custom Django web app for scheduling, customer management, and inventory.
* Create native iOS and Android apps to enhance user experience and operational efficiency.

#### Current State:
* Website on Google Sites, linked to DAM-IT.TECH.
* Google Calendar for scheduling initial consultations.
* Manual process for follow-up bookings and payments.

#### Proposed Solution:
* Web App: Google Calendar integration, customer database, real-time inventory management.
* Mobile Apps: Native iOS and Android apps using SwiftUI and Android components for intuitive UI.

#### Innovation:

* Use of Native UI Components: Ensures a consistent and responsive user experience.
* Scalable and Modular Design: Facilitates growth and adaptability.
* Open-Source Potential: Contribution to CRM solutions tailored for small businesses.

#### Impact:

Attract more college students through app-based service booking.
Reduce operational workload with automation.
Provide a model for small service-based businesses.
