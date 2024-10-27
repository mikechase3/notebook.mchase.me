---
description: >-
  Digital Twin - Manufacturing, An AR/VR Simulation for Aircraft Maintenance
  Routine
---

# Software Project Management Midterm

{% hint style="info" %}
Available as a PDF [here](softProjMgmtMidtermPdf.pdf)
{% endhint %}

## Digital Twin - Manufacturing, An AR/VR Simulation for Aircraft Maintenance Routine

### Deliverable 1: Review of the Subject Area: AR/VR Training Simulation for Aircraft Maintenance

{% hint style="warning" %}
Due to time constraints, I wrote bullet points and had an LLM word this more professionally. You may examine my original work in appendix B.
{% endhint %}

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

### Deliverable 2: Table of Technical Tasks & Work Breakdown Structure

<table><thead><tr><th width="93">#</th><th width="174">Technical Task</th><th>Description</th></tr></thead><tbody><tr><td>1</td><td><strong>1. Requirements Gathering</strong></td><td>PM will collaborate with the Subject-Matter Expert (SME) to understand the technical details of the Cessna's maintenance routines, including tire inspections. A sequence diagram will be created that the SME approves to ensure developer understanding.</td></tr><tr><td>1.1</td><td>Identify Common Errors</td><td>Research common errors during maintenance, such as loose nuts on the landing gear. This will help replicate these scenarios in the simulation for trainees to identify and correct.</td></tr><tr><td>2</td><td><strong>2. Environment and Asset Design</strong></td><td>Develop a realistic virtual environment that mimics an aircraft maintenance workshop, focusing on detailed models like the Cessna aircraft and its various components. This includes creating intricate assets such as the aircraft tires and workbench components.</td></tr><tr><td>3</td><td><strong>3. Designing Simulation Game Mechanics</strong></td><td>Design the interaction mechanics that allow users to interact with virtual tools and perform tasks. Implement methods for picking up items and reading clipboard instructions effectively.</td></tr><tr><td>3.1</td><td>Implement Tool Interactions</td><td>Create mechanics for users to grasp tools, such as a wrench, and visualize required movements through on-screen arrows to guide their actions in VR. This involves determining how tool manipulation will function within the simulation.</td></tr><tr><td>4</td><td><strong>4. Step-by-Step Instruction Logic</strong></td><td>Collaborate with the SME to review the sequence diagram and finalize the visual guidance system. Together with developers, outline how tool collisions will work in the simulation.</td></tr><tr><td>4.1</td><td>Define Collision Mechanics</td><td>Work with developers to determine whether tools snap to corners or if specific rotational parameters are needed for interaction. This step is crucial for creating a realistic user experience.</td></tr><tr><td>5</td><td><strong>5. Error Management System</strong></td><td>Develop a feedback system that alerts users to mistakes and provides corrective hints during maintenance tasks. Work on embedding this feedback mechanism within the simulation.</td></tr><tr><td>6</td><td><strong>6. Performance Tracking</strong></td><td>Design and implement a reporting system that tracks user performance metrics, including task completion times and accuracy. Ensure data is collected effectively for analysis.</td></tr><tr><td>7</td><td><strong>7. User Interface Design</strong></td><td>Develop the user interface for the simulation, including buttons for starting the game, navigation menus, and displaying the HUD with performance metrics. Include final polishing touches before deployment.</td></tr><tr><td>8</td><td><strong>8. Deployment</strong></td><td>Prepare the VR simulation for deployment by optimizing assets, reducing polygon counts for smooth performance on devices like Oculus Quest 2. Publish the app on the research website and Oculus stores.</td></tr></tbody></table>

### Deliverable 3: Gantt chart

{% hint style="warning" %}
TODO: include subtasks
{% endhint %}

{% hint style="info" %}
See appendix C for a digital approach I tried, but ended up being too time-consuming.
{% endhint %}

<figure><img src="../../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

### Deliverable 4: Labor Breakdowns

Note - 3D Pay rate salaries are from Indeed.

<figure><img src="../../../.gitbook/assets/CleanShot 2024-10-20 at 16.07.54.png" alt=""><figcaption></figcaption></figure>

#### In Plaintext for Readability

<table><thead><tr><th width="87">Null</th><th width="261">Task</th><th width="68">Len (Mo)</th><th width="87">PM</th><th width="87">JuniorDev1</th><th width="87">JuniorDev2</th><th width="87">JuniorDev3</th><th width="87">SeniorDev1</th><th width="87">SeniorDev2</th><th width="87">SME</th><th width="87">Modeler1</th><th width="87">Modeler2</th><th width="100">Total Hours</th><th width="100">Cost Per Task</th></tr></thead><tbody><tr><td>$</td><td>Hourly Rate</td><td>N/A</td><td>50</td><td>35</td><td>35</td><td>35</td><td>80</td><td>80</td><td>120</td><td>35</td><td>35</td><td>N/A</td><td>N/A</td></tr><tr><td>1</td><td>Requirements Gathering</td><td>1</td><td>160</td><td>40</td><td>40</td><td>0</td><td>40</td><td>40</td><td>80</td><td>0</td><td>0</td><td>400</td><td>$ 26,800.00</td></tr><tr><td>2</td><td>Environment and Core Asset Design</td><td>4</td><td>160</td><td>0</td><td>0</td><td>0</td><td>20</td><td>20</td><td>40</td><td>640</td><td>640</td><td>1520</td><td>$ 60,800.00</td></tr><tr><td>3</td><td>Simulation Mechanics</td><td>5</td><td>200</td><td>800</td><td>800</td><td>0</td><td>100</td><td>100</td><td>200</td><td>100</td><td>100</td><td>2400</td><td>$ 113,000.00</td></tr><tr><td>4</td><td>UI/HUD Design</td><td>3</td><td>120</td><td>480</td><td>480</td><td>0</td><td>60</td><td>60</td><td>60</td><td>120</td><td>0</td><td>1380</td><td>$ 60,600.00</td></tr><tr><td>5</td><td>Implement Procedure Instructions</td><td>3</td><td>120</td><td>480</td><td>480</td><td>0</td><td>480</td><td>120</td><td>240</td><td>240</td><td>0</td><td>2160</td><td>$ 124,800.00</td></tr><tr><td>6</td><td>User Feedback and Error Handling</td><td>1</td><td>40</td><td>80</td><td>80</td><td>0</td><td>160</td><td>40</td><td>40</td><td>80</td><td>0</td><td>520</td><td>$ 31,200.00</td></tr><tr><td>7</td><td>Performance Tracking</td><td>1</td><td>80</td><td>80</td><td>80</td><td>0</td><td>20</td><td>20</td><td>40</td><td>80</td><td>0</td><td>400</td><td>$ 20,400.00</td></tr><tr><td>8</td><td>Polishing and Deployment</td><td>1</td><td>80</td><td>40</td><td>40</td><td>0</td><td>80</td><td>80</td><td>40</td><td>160</td><td>0</td><td>520</td><td>$ 30,000.00</td></tr><tr><td>SUM</td><td>Total Hours Per Role</td><td></td><td></td><td>960</td><td>2000</td><td>2000</td><td>0</td><td>960</td><td>480</td><td>740</td><td>1420</td><td>740</td><td>9300</td></tr><tr><td>SUM</td><td>Total Cost Per Role</td><td></td><td></td><td>48000</td><td>70000</td><td>70000</td><td>0</td><td>76800</td><td>38400</td><td>88800</td><td>49700</td><td>25900</td><td>$ 467,600.00</td></tr></tbody></table>

### **Deliverable 5: Cumulative Cost Forecast**

<figure><img src="../../../.gitbook/assets/CleanShot 2024-10-27 at 00.52.50.png" alt=""><figcaption></figcaption></figure>

## Appendices

### Appendix A: Understanding the Assignment

There's a list of plans. Pick one topic area and do a project plan. Then do the following:

* [x] Write a 1-2 page review of the subject matter. Include major competitors, technical background of the area, history of the topic, and current best practices.
* [x] Create a table that lists proposed technical tasks for the project. Give a two-sentence explanation of the task with at least eight technical tasks.
* [x] Graphically created a task list containing major and subtasks within a Gantt chart.
  * [ ] \[x] Include selected _completion_ or due dates
  * [ ] Add in subtasks
* [x] Create a table displaying staff & their total hour breakdown/cost.
  * [x] Total hour breakdown
  * [x] Cost across the whole project.
* [x] Create a monthly line graph to visualize and predict how expenses are distributed over time, with each month representing the x-axis (independent variable) and the total cost as the y-axis (dependent variable).
  * [x] Plot a budget as y=$budget
  * [x] Add axes, a title, axes titles, legend.
  * [ ] Change my chart to be month-by-month
* [ ] Export to a word document with 1" margins and Times New Romans font.

#### Requirements

* [ ] Proposal budget must be between $400K-$500K.
* [ ] Scope is 2024JAN01-2024DEC31
* [ ] Mock budget over the level of effort required to complete each deliverable.
* [ ] Use the mock budget attached.
* [ ] 12 point times new roman font with 1" margins with excel spreadsheets and charts attached in the document and as separate attachments.

### Appendix B: Original Review of Projects

I used an LLM to clean this up, but left my original:

> Suppose there may exist a part that is manufactured and flown around in a plane for testing during the manufacturing process. In aerospace, parts are often tested in aircrafts for due to how vital they are to a mission and people's lives.
>
> **Importance of Training in Aircraft Maintenance**
>
> Safety and regulatory compliance are of concern when training aircraft maintneance crews (and the money/investment). Proper training ensures that the maintenance crews can effectively perofrm check and repairs, reducing the risk of accidents or equipment failure.
>
> Plane parts are expensive, and finding "broken" parts for training are still considerably expensive, so it's not feasible to test if someone recognizes damages by physically damaging parts of a plane. Therefore, the simulation and training is practical.
>
> Still, there is regulatory compliance and aviation standards/regulations which requires these thorough knowledge checks of maintenance procedures.
>
> **VR/AR in Training**
>
> Virtual and Augmented Reality offer ways to "break" equipment without breaking it in real-life.
>
> Allows aircraft maintenance checks to be possible & include broken stuff.
>
> Works well in geospatial environments such as performing inspections. Makes training more realistic than training manuals because it's' more hands-on approach. Faster to learn this way and better.
>
> **How Airplane Checks Work**
>
> There are different types of checks on airplanes at different frequencis. Line checks must be conducted every 24-60hrs of accumulated flight time. Wheels, breaks, and fluid levels are inspected every time before takeoff.
>
> A checks are every 400-600hrs of or 200-300 flights and focus on interior or exterior damage and function. B checks follow, then C, and D.
>
> **Requested Features from Customer**
>
> * Suppose current best practices are to read documentaiton and take a test.
> * VR Maintenance Training would incorporate a step-by-step guide.
> * Error management: provide hints and corrective measures.
> * Time Tracking and Performance Evaluation would promote self assessment and improvement.
>
> **Future Impact**
>
> * Expected to enhance learning curve for technicians
> * Ensures accuracy and increases preparedness
> * Expedites learning times.

### Appendix C: Merlin Software

<figure><img src="../../../.gitbook/assets/CleanShot 2024-10-19 at 08.58.50.png" alt=""><figcaption></figcaption></figure>

In the [prior](../as02-estimating-budget-and-time.md) software project management scenario, I learned plantuml which took too much time learning syntax. This time, I learned Merlin

The printouts are a bit better, but I need to adjust the scale to a month-by-month view instead of individual weeks.

<figure><img src="../../../.gitbook/assets/CleanShot 2024-10-19 at 09.13.58.png" alt=""><figcaption></figcaption></figure>

Overall, it was a great learning experience and I plan to use this with other projects. It's a great tool for communicating my timeline with others. Unfortunately, there was a learning curve and to use it efficiently, you must get familiar with keyboard shortcuts which slowed me down.
