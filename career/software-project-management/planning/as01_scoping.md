# AS01 Scoping

## AS01 Scoping Slide

<figure><img src="../../../.gitbook/assets/CleanShot 2024-09-03 at 12.23.18@2x.png" alt=""><figcaption><p>Project Scope Visual</p></figcaption></figure>

## Q/A

### What are you trying to Do?

DAM-IT is a company I recently started to service equipment, perform software/hardware consulting, and rent equipment to students. I aim to develop a Django-based web application, integrating scheduling, customer management, and inventory functionalities. The system will streamline operations for IT support services, equipment rentals, and customer interactions (CRM). Eventually, I'd like to design the roadmap for creating kiloton and swiftUI application.

### How is it Done Today & Limits of Current Solution

DAM-IT's process and operations is rather inefficient. It currently uses a Google Sites page which requires manual entry/updating. Scheduling is managed by Google Calendar, which integrates well with existing workflows for blocking out my personal time; however, it looks slightly unprofessional and does not easily coordinate with my website in real-time (though there might be an API?) After a phone call requested through google calendar's iFrame, I perform a free call and request their deposit after which I manually add it to my calendar. Prices for subsequent repairs (e.g. more than three per week) increase the price.

### Innovation - New Approach

My proposal is to integrate a custom backend, customer database, and real-time inventory tracking. By implementing a custom backend, I can have the site automatically update booking prices as appointments are created and my availability fills up. The introduction of mobile apps using SwiftUI and Android's native UI features & connecting it to the centralized database hasn't been done.

### Impact

Upon success, I will have a customer database I can use to send blast emails to like a mailing list. By tying in their history, I can offer promotional pricing to certain/repeat customers like offering coupons for certain products they might be interested in. A dynamically generated website using information pulled from database information will decrease manual labor hours if scaled. Mobile apps and web apps will allow students to request/reserve equipment and services tied to their accounts for self-service work, payments, etc. If this is successful, I'll advertise myself as a cloud engineer and offer newer (and more lucrative) services because of my ability to add value to other small businesses.&#x20;

## Goals

1. **Implement a comprehensive customer database:** this will store detailed information about customers, including their contact details, past interactions, service requests, and preferences. This will allow for personalized service, enabling me to maintain notes on each customer, build stronger connections, and establish trust. With a more central place for customer information (versus excel), our our team will improve the quality of service, tailor our repsonses based on past interactions, and ensure consistent follow-up which is essential for customer retention and satisfaction.
2. **Develop a Scalable and Modular Web Application for Scheduling & Inventory Management**: the web application will integrate with Google Calendar for seamless scheduling and include real-time inventory management. This will automate the booking process, reduce manual errors, and allow customers to easily see available time slots and equipment. This will further reduce my administrative workload, freeing up time to focus on core services like actually fixing computers and delivering more equipment. It will also enhance the customer experience by providing them with easy access to booking and equipment availability, making the process mroe efficient and user friendly.
3. **Launch Native Mobile Applications to Enhance User Interaction**: a less important goal would be to use native iOS and Android app UIs to for customers to browse available services, book appointments, and manage rentas directly from their mobile devices. This self-service capability aligns with the preferences of our target audience, primarily college students. Not only will it make our services more accessible/convenient, but it can increase engagement and customer satisfaction while driving down costs in the long-run. Mobile apps offer a more immersive, professional experience which will help differentiate us from our competitors.&#x20;
4. **Position as a Cloud Engineer and Expand Service Offerings**: completing this project will demonstrate my ability to design, deploy, and manage web applications using coud techonlogies. This expertise will enable me to offer specialized IT support and cloud services to help small businesses optimize operations via custom solutions similar to mine. The diversification in services will open higher revenue streams and allow me to cater to a broader client base, including businesses looking for reliable/scalable cloud services.



## Drafts & Duplicate Info

### Requirements

* Answer Questions:
  * What am I trying to do?

Goals:

* Plan DAM-IT blue-sky-dea services.
* Utilize _The Helmeier Catechism_: questions to articulate goals & risks.
* High-level, don't think about cost or time yet.

Requirements:

* Answer questions.
* For each goal, explain how it relates to project.
* 3 total goals w/ how end-user interacts with my software.
* Make a 1-slide PPT showcasing project.

### Project Overview

**Project Objective**: Project Objective: Develop a Django-based web application for DAM-IT, integrating scheduling, customer management, and inventory functionalities. This system will streamline operations for IT support services, equipment rentals, and customer interactions. Eventually, the goal is to expand the functionality to mobile apps using SwiftUI and Android native components.

### Current System

* Website: DAM-IT.TECH currently redirects to a Google Sites page.
* Scheduling: managed via Google Calendar, which integrates well with existing workflows for blocking personal time while displaying available slots for customer bookings.
* Payment & Booking: initial customer interaction happens over the phone, where bookings are confirmed and a $25 deposit is collected. Subsequent prices are tiered, increasing for $10 for each additional booking until capacity is reached.

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

### What's New:

Integration of Native UI Elements: By using SwiftUI and Android native components, the apps will leverage the platform's built-in UI frameworks, resulting in a more responsive and consistent user experience. Scalable and Modular Design: Starting with essential functionalities and scaling as needed allows for manageable growth and adaptability. Open-Source Contribution: While there are many CRM solutions available, contributing a tailored, modular solution for small service-based businesses could meet niche needs not fully covered by larger systems like Odoo. Market Impact:

Target Audience: Primarily college students, a demographic that prefers self-service options and app-based interactions. By offering a user-friendly app, DAM-IT aims to increase its customer base and improve service efficiency. Operational Efficiency: Automation of booking, payments, and customer management will reduce the manual workload, allowing more focus on delivering high-quality IT services.

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

Attract more college students through app-based service booking. Reduce operational workload with automation. Provide a model for small service-based businesses.
