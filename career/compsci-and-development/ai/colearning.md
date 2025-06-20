# Colearning: Human/AI Teaming Vision
From slides - distribution A. Approved for public release. Case No AFRL-2025-2905
## Huma Autonomy Teaming Review
(Lyons, Scyra, Lewis, Capiola, 2021)
* Relevant team dynamics: shared mental models, team-oriented intent communications.
* **Challenges**: optimize the performance of human-machine teaming. 
    * How do you foster relationship w/ computer? (Vector spaces, knowledge graphs)
    * How do you measure if they have the same mental model?
    * HAT training. How does it update?
    * How to foster joint awareness of attention, state monitoring, confusion/uncertainty.
    * Who is accountable? How?

## HMT Considerations
Interactivity - humans update information well, but we don't know when they're doing it.
* What happens with these is hard for computers to do.
* How do you adjust weights/etc.

### Autonomy
* Most of it is happening manually, but more and more it'll be autonomous.
* We're a piece of the larger pie... trying to get to higher autonomy but that's down the road.

### Orbital Games Example
* Different types of games exist.
* Satellite vs Satelite.
* Satellite vs Constellation.
* War gaming - figuring it out, but there's formats.
  * Sequential games: my actions will dictate someone elses
  * Dual games: both take actions at the same time.
  * Nash Equilibrium / prisoner's dilemma.
  * Rudimentary Asequential Deterrence Game (Sequential).
* UC Boulder: trying to apply to Bassilisk. Hidden Markov model?
* Col Blatto (Glatto?) Game: two players make decisions simultaneously & winner takes all (Concurrent Example)

# Kramer Research Questions
* PA Approved Distro A AFRL-2025-2905 Distribution is Unlimiited.
* These are research-focus areas. 


## Anomoly Detection
* Identify subtle anomalies.
* Predicting long-ter mtrajectory deviations
* Reduce false positive rates
* Identify deviations from expected behavior
* Provide classification of anomaly causes (technical, natural, intentional)
* Get insights into the potential intent behind those anomalies.

## Collision Avoidance in Crowded GEO/MEO/LEO Orbits
* Short-term collision avoidance maneuvers.
* Fuel conservation balance
* Developing a continuously learning collision avoidance system
* System adapts to changes in geo environment.
* Update risk models and maneuver strategies.

## Dimensionality Reduction for Explainable Cislounar Orbit Analysis
* Leveraging dimensionality reduction to cluster/classify different types of cislunar orbits based on their dynamical properties/stabbility characteristics.
* Visualizations. Make 'em.
  * REpresent the classes of orbits
  * Hlighlight their interconnectedness
* Identify and explain potential risks or opportunities associated with specific cislunar orbits, such as regions of instability or low-energy transfer pathways.

## Human & Intent-Informed ML for Cislunar Space Situational Awareness
* How might we develop algs that effectively fuse data from multiple source,s including spacecraft telemetry, contextual info, and expert knowledge to **infer the intent** behind anomalous behavior?
* How might we design ML models leveraging both human-provided nintent (e.g. lunar resource observation) and general cislounar region (near L1) to **predict likely orbital familites or risk prone trajectories**
* How might we **quantify the impact of human input** on classification accuracy and **identify scenarios** where human expertise significantly improves performance?

## Sumamry
* We're looking for situations where humans & machines perform better.

# Oko Framework
From Distro A AFRL-2025-1858

## Front-End
* NodeJS, Vue, Quasar, D3.js, three.js, SQLite, Astro.
* **Backend**:
  * Nginx: web server
  * Docker: ctonainer-focused aproach
  * Microservices, APIs, Data Adapters between NGINX and Docker.
  * **Basilsk**: UC Boulder C++, Python, OMQ, ProtoBuf
  * **Virginia Tech**: Resonnate, Python, SQlite
  * **idk**: Node, SQlite, Python.
  * **Future**: Protobox/Mazer
  * AFSIM
  * Astrodynamics Support Wrokstation (ASW): Omnitron

### Interface
See slides for the interface.

#### Simulated Sensor Data
* Historical list of past deision points.
* Recent changes in magnitudes. Some noise characteristics.
* ML Confidence value to determine if satellite was in active maneuvering state or else.

#### Information Displays
* Latest sensor data
* Historical sensor data bar chart
* Recent Delta-V
* ML Confidence
* Intel/Weather Reports
* Camera Manipulation (Admin Control)s
* 3D Objet Control (Admin Ctrls)
* Simulation data control (Admin Ctrl)

### Sensed Orbit Points
* **Green Outline**: boundary of station keeping
* **Yellow Dots**: Locations depicting when the satellite was sensed.
* **Blue Curve**: estimated trajectory based on sensed location points.

### Satellite Velocities
* Resonnate generated all the data.
* Pick how many satellites & sensors on the ground you want to have.
* \delta V is the magnitude of the x, y, and z deltas. 
  * \deltaV = \sqrt{\deltax * \delta x + \delta y * \delta y + \delta z * \delta z}
* This is an example of dimension reduction?

# AFIT Cislunar Research Overview
* Lt Col Robert A. Bettinger
* Division chief for faculty/research operations
  * Cirriculum Chair, Graduate Astronautical Engineering Program
  * Dept of Aeronautics and Astronautics (ENY)

## CHAOS: Characterization and Heuristics of Aperiodic Orbits for SDA
For things with changing & weird trajectories, what's worth understanding? 

### Poincare Mapping Development
* Let's imagine we have a cislunar environment and we don't have any 'z' motion for now (so x/y plane)
* Mapping (P) of a set of initial condition x\_0 as it returns to the Poincare section at some later time t.
  * **x(t) = P(x_0)**
  * Record position and speed in that plane.

After plotting multiple returns of numeric...
* 3-body problems...
* saw a "AFIT-made, single-file MATLAB App" figure w/ example zero fveocity curve.
* Chains of violence, where quazi stuff is.
* Fixed points are the periodicals. 
* Periodical 
* Quazi Periodical is we're beginning/ending at different points but it's characterizable.
* Chaotic is just dots of other interesting behavior with random-ish points.

### Fast Lyapunov Indicator (Chaos Indicator)
This is a way to visualize the amount of chaos in an environment... relatively.
* Left half was the earth, right was the moon.

### Fast Fourier Transform (FFT) Analysis
* Every trajecory has a unique FFT signature.
* FFT signatures are dependent on the time frame for trajectory propagation
* Compute FFT of trajectory and periodic orbits -> compute RMSE to find closest match.

## ML/AI Applications
GOAL: predict fixed point transitions as a function of time for quasi-chaotic trajectories using AI/ML techniques.
* **Process 1**: propagate 400+ trajectories for 1,000 TU and divide into 100-TU increments for FFT computation.
* **Process 2**: compute RMSE (root mean square error) of trajectories with periodic orbits.
* **How to read chart**: if starting at orbit 1 from the x-axis, then where does the trajectory travel for the next 100-TU window?

# Adaptive Tutoring
Distribution A: AFRL-2025-2876

## Adaptive Tutor Motivations
* Cislunra space and knowing what's there is increasingly important
* Space is hard. Cislunar space is harder because gravitational dynamics are complex.
* Adaptive/intelligent tutors successfully developed ?
* Adaptive tutoring software takes information from students and adapts course experiences (materials) to a student.
  * Reduces instructor workload.
  * Supplemental student instruction
  * Adpative pracce probelm difficulty, and/or personalized feedback.
* GIFT: Generalized intelligence... 
* Driving and AI example is a great way to share/judge the "experience" of AIs
  * [PSS14 Mine Detector](https://www.military.com/equipment/pss-14-mine-detector)
  * Cognitive task analysises are good at the "they didn't even know they were doing it" for experts.
    * Because they're so good.
    * They may never talk about some of the cognitive processes that are automatic for them.


