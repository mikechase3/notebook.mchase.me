# Text Gen Temperature, K, P Lab

I made my own lab because one day aistudio.google.com will probably charge me money and I don't know how much. Let's adjust some parameters and try a prompt with different temperatures.\


## Understanding the Experiment

Before we dive into specific prompts, let's recap the parameters:

* **Temperature:** Controls randomness. Higher values lead to more creative and unexpected outputs.
* **Top-k:** Selects the top k most probable tokens. Higher values increase diversity.
* **Top-p:** Selects tokens until their cumulative probability reaches p. Balances exploration and exploitation.

### Prompt: My DAM-IT Business Plans

Write a short story about a college student in a rural Midwest town who starts an IT services business targeting other students. The business offers a variety of services including computer repair, tutoring, equipment rental, and a shared workspace. The student entrepreneur faces challenges such as limited capital, competition from larger tech companies, and balancing schoolwork with business demands. The story should explore themes of innovation, community building, and the challenges and rewards of entrepreneurship.

#### Small k=10 | large p=1 | low temp=0.1

Hypothesis: should have a deterministic output but has a broad range of tokens to choose.

<details>

<summary>Output: </summary>

In the quaint Midwest town of Willow Creek, amidst rolling hills and whispering cornfields, a young college student named Ethan embarked on an entrepreneurial journey that would forever alter the technological landscape of his community.

Ethan, a computer science major at Willow Creek University, had always been fascinated by the transformative power of technology. He noticed a growing need among his fellow students for reliable and affordable IT services. With limited options available in the rural town, Ethan saw an opportunity to fill this void.

Armed with a laptop, a toolbox, and an unwavering belief in his abilities, Ethan launched "Tech Haven," an IT services business tailored specifically to students. His services ranged from computer repair and tutoring to equipment rental and a shared workspace.

The initial days were filled with challenges. Ethan's capital was limited, and competition from larger tech companies loomed. Balancing his academic workload with the demands of his business proved to be a constant juggling act. Yet, Ethan persevered, driven by his passion for innovation and a desire to serve his community.

Word of Tech Haven spread quickly through the university. Students flocked to Ethan for his expert repairs, patient tutoring, and affordable equipment rentals. The shared workspace became a hub for collaboration and idea-sharing, fostering a sense of community among students.

As Tech Haven's reputation grew, so did Ethan's confidence. He expanded his services to include website design, social media marketing, and cloud computing solutions. He hired a small team of fellow students, creating employment opportunities and fostering a culture of mentorship.

The success of Tech Haven not only transformed Ethan's life but also had a profound impact on Willow Creek. The town's technological infrastructure improved, and students gained access to cutting-edge resources that had previously been unavailable. Ethan's entrepreneurial spirit inspired others to pursue their own ventures, creating a ripple effect of innovation and economic growth.

Through the challenges and triumphs of his journey, Ethan learned invaluable lessons about the power of perseverance, the importance of community, and the rewards of pursuing one's passions. Tech Haven became a testament to the transformative potential of entrepreneurship, proving that even in the most unlikely of places, innovation can flourish and make a lasting impact.

***

Rerun:

In the quaint, rural town of Willow Creek, nestled amidst rolling hills and whispering cornfields, a young college student named Ethan embarked on an entrepreneurial journey that would forever alter the technological landscape of his community.

Ethan, a bright and ambitious computer science major, noticed a glaring void in the town's tech ecosystem. Students struggled with computer issues, lacked access to specialized equipment, and yearned for a collaborative workspace. Inspired by his passion for technology and a desire to serve his peers, Ethan conceived an innovative business idea: Willow Creek IT Services.

With limited capital and a shoestring budget, Ethan transformed his dorm room into a makeshift office. He offered a range of services, from computer repair and tutoring to equipment rental and a shared workspace. Word of his services spread like wildfire through the student grapevine.

However, Ethan's path was not without its challenges. Larger tech companies, with their vast resources and established presence, posed a formidable threat. Ethan had to work tirelessly to differentiate his business, emphasizing personalized service and a deep understanding of the unique needs of college students.

Balancing schoolwork with the demands of his business proved to be a constant juggling act. Ethan spent countless nights poring over textbooks and coding until the early hours, only to wake up and tackle a full day of business operations. The strain on his time and energy was immense.

Yet, amidst the challenges, Ethan found solace in the community he was building. Students flocked to his shared workspace, forming study groups, collaborating on projects, and sharing knowledge. The sense of camaraderie and support fueled Ethan's determination.

As Willow Creek IT Services gained traction, Ethan's reputation as a skilled technician and a resourceful entrepreneur grew. He became a trusted advisor to students, faculty, and even local businesses. The once-dormant tech scene in Willow Creek was now thriving, thanks to Ethan's vision and unwavering commitment.

Through his entrepreneurial journey, Ethan learned invaluable lessons about innovation, community building, and the transformative power of technology. He discovered that even in the most unassuming of places, a single individual with a passion and a willingness to work hard could make a profound impact.

And so, in the heart of rural Midwest, Willow Creek IT Services became a testament to the indomitable spirit of entrepreneurship, the power of community, and the boundless possibilities that lie within the realm of technology.

</details>

I observed they both used "Ethan" and largely the same language.

#### Small k=10 | large p=1 | high temp=0.95

<details>

<summary>Out: Deterministic. Same Name. </summary>



</details>

TODO: make a word doc with columns.
