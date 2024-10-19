# Software Project Management Midterm
View [here][1] and please… for the love of love, ignore everything below. Didn’t think I’d need to send accommodations but it’s been a doozy and girlfriend has been quite sick today and so have I.



## Digital Twin - Manufacturing, An AR/VR Simulation for Aircraft Maintenance Routine

### Deliverable 1: Review of the Subject Area: AR/VR Training Simulation for Aircraft Maintenance
(Disclaimer - due to time constraints, I had an LLM clean this up. My original is in appendix b)

Suppose there may exist a part that is manufactured and flown in an aircraft for testing during the manufacturing process. In aerospace, parts are often tested in aircraft due to their critical role in mission success and the safety of personnel involved.

#### Importance of Training in Aircraft Maintenance
Safety and regulatory compliance are paramount concerns when training aircraft maintenance crews, alongside the significant financial investment involved. Proper training ensures that maintenance crews can effectively perform checks and repairs, thereby reducing the risk of accidents or equipment failures.

Aerospace components tend to be expensive, and sourcing "damaged" parts for training purposes is also costly; therefore, it's impractical to evaluate a technician's ability to identify damage by physically degrading aircraft parts. As a result, simulations and training modules become a practical and efficient solution.

Moreover, adherence to aviation standards and regulations necessitates thorough knowledge checks related to maintenance procedures, emphasizing the importance of comprehensive training.

#### VR/AR in Training
Virtual and Augmented Reality provide innovative ways to simulate equipment failures without causing actual damage. These technologies enable realistic maintenance checks that incorporate simulated malfunctions and issues.

VR and AR excel in geospatial environments, facilitating inspections and maintenance routines that mimic real-world conditions. This hands-on approach is more effective than traditional manuals, significantly enhancing training realism. Consequently, trainees can learn more quickly and effectively through interactive simulations.

#### How Aircraft Checks Work
Different types of checks are performed on airplanes at varying frequencies, each critical to maintaining airworthy conditions. Line checks must be conducted every 24-60 hours of accumulated flight time, where inspections of wheels, brakes, and fluid levels occur prior to takeoff. Since they are not very time-consuming, we’ll be focusing on line-checks and A-checks, which must be conducted every 400-600 flight hours or after 200-300 flights for interior/exterior damage and functionality of core parts. Other checks exist, but are increasingly complex. 


#### Requested Features from Customer
We are tasked to conduct propeller checks, tire inspections, brake checks, fuel system checks, and walk-around checks in VR. Here’s a list of tasks to pull from. Current best practices primarily involve reviewing documentation and completing written tests. VR Maintenance Training would include step-by-step guides for each maintenance task. Error management mechanisms would provide hints and corrective feedback for trainees. Time tracking and performance evaluation tools would encourage self-assessment and improvement.

#### Specific Tests
In our VR simulation for aircraft maintenance training, we will incorporate critical checks focused on propellers, tires, brakes, fuel systems, and overall walk-around inspections. The simulation will guide users through specific tasks such as inspecting propeller spinners and blades for damage, checking tire tread depth and pressure, and assessing brake pad conditions and functionality. Users will also examine fuel lines for leaks and measure fuel quality, as well as perform comprehensive walk-around checks that include verifying structural integrity and the condition of sensors, flight surfaces, safety equipment, and lighting systems. Each task will include interactive, step-by-step instructions, allowing trainees to learn and practice these essential maintenance routines in a realistic VR environment, ensuring they can confidently perform these checks in real-world scenarios.

#### Expected Outcomes
The implementation of AR/VR technologies is expected to enhance the learning curve for technicians, making them more adept and confident in their roles. These training solutions will ensure accuracy in maintenance practices, leading to increased preparedness for real-world scenarios. Overall, VR/AR training is anticipated to expedite learning times, allowing technicians to become proficient more efficiently than traditional methods.

Here is a table of proposed technical tasks for the VR development of the aircraft maintenance training simulation:

### Deliverable 2: Table of Technical Tasks

| **Technical Task**                    | **Description**                                                                                                                                                               |
| ------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **1. Requirements Gathering**         | PM will collaborate with subject matter experts to review documents, establish a course of action, and check in with customers throughout the year.                           |
| **2. Environment Design**             | Have a developer work with an artist to create a virtual environment that mimics a realistic aircraft maintenance workshop, including a workbench, tools, and aircraft model. |
| **3. Simulation Mechanics Design**    | Get a dev to design the interaction mechanics. They need to pickup/interact with tools, execute the line check, and manage errors.                                            |
| **4. Step-by-Step Instruction Logic** | Implement a system that provides step-by-step  visual guidance through the HUD for each maintenance task within the simulation.                                               |
| **5. Error Management System**        | Incorporate a feedback mechanism that allows users to receive hints or corrective measures when they make mistakes during tasks.                                              |
| **6. Performance Tracking**           | Develop something like a csv/report to track user performance metrics such as completion time, accuracy of tasks, and hint usage during maintenance checks.                   |
| **7. User Interface Design**          | Create a user interface that includes menus for task selection, performance review, and other available content for both students and instructors.                            |
| **8. Deployment**                     | Prepare the VR simulation for deployment on specified platforms, including desktop computers and Oculus Quest Headsets.                                                       |

### Deliverable 3: Gantt chart
So. I found some nice software to make my Gantt chart and this is going to be a problem because it’s unreadable. Here’s an export in a different way but I’ll resubmit and pass a link because this is still quite bad.

|       |              |                                     |             |                      |           |              |
| ----- | ------------ | ----------------------------------- | ----------- | -------------------- | --------- | ------------ |
| \\#   | Traits       | Title                               | Given Work  | Given Earliest Start | Resources | Predecessors |
| **1** | **Is Group** | **Project Management**              | **45 days** |                      |           |              |
| 2     |              | Customer Meeting                    | 5 days      |                      |           |              |
| 3     |              | Create Project Plans                | 5 days      |                      |           | 2            |
| 4     |              | Collaborate with SME                | 5 days      |                      |           | 3            |
| 5     |              | Document requirements and feedback  | 20 days     |                      |           | 3            |
| 6     |              | More collaboration with SME         | 5 days      |                      |           | 5            |
| 7     |              | Finalize Requirements               | 5 days      |                      |           | 6            |
| **8** | **Is Group** | **Environment Design**              | **40 days** |                      |           | **1**        |
| 9     |              | Gather reference materials          | 10 days     |                      |           |              |
| 10    |              | Collaborate with artist for concept | 20 days     |                      |           | 9            |
| 11    |              | Sim Mechanics Design                | 50 days     |                      |           | 10           |
| 12    |              | Procedure Programming               | 50 days     |                      |           | 11           |
| 13    |              | Error Management Sys                | 15 days     |                      |           | 12           |
| 14    |              | Performance Tracking Sys            | 15 days     |                      |           | 13           |
| 15    |              | Make User Interface and HUD         | 20 days     |                      |           | 14           |
| 16    |              | Deployment                          | 30 days     |                      |           | 15           |
| 17    |              | Buffer Time                         | 20 days     |                      |           |              |


### Deliverable 4: Charts!

 

## Appendices
### Appendix A: Understanding the Assignment

There's a list of plans. Pick one topic area and do a project plan. Then do the following:

* [ x] &#x20;Write a 1-2 page review of the subject matter. Include major competitors, technical background of the area, history of the topic, and current best practices.&#x20;
* [ x] Create a table that lists proposed technical tasks for the project. Give a two-sentence explanation of the task with at least eight technical tasks.
* [x] Graphically created a task list containing major and subtasks within a Gantt chart.&#x20;
  - [ x] Include selected _completion_ or due dates .&#x20;
* [ ] Create a table displaying staff & their total hour breakdown/cost.
  - [ ] Total hour breakdown
  - [ ] Cost across the whole project.&#x20;
* [ ] Create a monthly line graph to visualize and predict how expenses are distributed over time, with each month representing the x-axis (independent variable) and the total cost as the y-axis (dependent variable).
  - [ ] Plot a budget as y=$budget
  - [ ] Add axes, a title, axes titles, legend.

#### Requirements

* [ ] Proposal budget must be between $400K-$500K.&#x20;
* [ ] Scope is 2024JAN01-2024DEC31
* [ ] Mock budget over the level of effort required to complete each deliverable.&#x20;
* [ ] Use the mock budget attached.
* [ ] 12 point times new roman font with 1" margins with excel spreadsheets and charts attached in the document and as separate attachments.&#x20;

#### Draft Snippets
TODO: remove
#### Review -  Digital Twin Simulation Stealth Spray Painting
Specifically: create a digital twin VR/AR tool which offers a way for manufacturing plants to safely train their employees.

Here's some scenarios I could choose from:

1. Digital twin of spray-painting process of stealth parts and material properties of the paints. Components are 1) real-time data acquisition of putting sensors on paint cans and analyzing which layers, angles, and power settings get used during the process. The physics and material properties of the paint & the ergonomics of how employees should position themselves and move while painting are important. **Components:** a real time data acquisition uses sensors on spray-painting equipment to gather data on factors like pressure, speed, and paint flow. The VR training module will let trainees interact with the digital twin with scenairos that mimic real-life conditions, allowing those users to practice without the risk of waste or injury. Then there's a feedback system that AI can use to provide instant feedback based on the trainee's actions, allowing for cusomized training experiences.&#x20;

### Appendix B: Original Review of Projects
I used an LLM to clean this up, but left my original:

>  Suppose there may exist a part that is manufactured
>   and flown around in a plane for testing during the manufacturing process.
>  In aerospace, parts are often tested in aircrafts for due to how vital
>   they are to a mission and people's lives.
> 
> #### Importance of Training in Aircraft Maintenance
> Safety and regulatory compliance are of concern when training 
> aircraft maintneance crews (and the money/investment). 
> Proper training ensures that the maintenance crews can effectively
> perofrm check and repairs, reducing the risk of accidents or
> equipment failure.
> 
> Plane parts are expensive, and finding "broken" parts for training
> are still considerably expensive, so it's not feasible to test
> if someone recognizes damages by physically damaging parts of a plane.
> Therefore, the simulation and training is practical.
> 
> Still, there is regulatory compliance and aviation standards/regulations
> which requires these thorough knowledge checks of maintenance procedures.
> 
> #### VR/AR in Training
> Virtual and Augmented Reality offer ways to "break" equipment
> without breaking it in real-life.
> 
> Allows aircraft maintenance checks to be possible & include broken stuff.
> 
> Works well in geospatial environments such as performing inspections.
> Makes training more realistic than training manuals because it's'
> more hands-on approach. Faster to learn this way and better.
> 
> #### How Airplane Checks Work
> There are different types of checks on airplanes at different frequencis.
> Line checks must be conducted every 24-60hrs of accumulated flight time.
> Wheels, breaks, and fluid levels are inspected every time before takeoff.
> 
> A checks are every 400-600hrs of or 200-300 flights and focus on
> interior or exterior damage and function. B checks follow, then C, and D.
> 
> #### Requested Features from Customer
> * Suppose current best practices are to read documentaiton and take a test.
> * VR Maintenance Training would incorporate a step-by-step guide. 
> * Error management: provide hints and corrective measures.
> * Time Tracking and Performance Evaluation would promote
> self assessment and improvement.
> #### Future Impact
> *  Expected to enhance learning curve for technicians
> *  Ensures accuracy and increases preparedness
> *  Expedites learning times. 

[1]:	https://notebook.mchase.me/career/software-project-management/large-scale-software-development/software-project-management-midterm