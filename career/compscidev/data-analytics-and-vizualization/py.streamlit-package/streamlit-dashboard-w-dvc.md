---
description: >-
  Streamlit will host a web app. DVC stands for data version control, but isn't
  version controlled data ironically.
---

# Streamlit Dashboard w/ DVC

.

{% @github-files/github-code-block %}

\-

## Project Initialization & Setup

First, I made an empty repository on Github and cloned it.  I already had Ubuntu WSL, so I had PyCharm configure a virtual environment in the Ubuntu environment at `/home/<username>/.virtualenvs/<repository_name>/bin/python`. The environment should look something like this:

<figure><img src="../../../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

.

Next, I installed all the packages I thought I needed. Most of these were dependencies that get installed, but I manually added streamlit, matplotlib, pandas, and numpy. The rest were generated or installed in the base environment.



.

<figure><img src="../../../../.gitbook/assets/image%20(1).png" alt=""><figcaption></figcaption></figure>

I probably fiddled around with some other stuff

#### Troubleshooting - not important

<figure><img src="../../../../.gitbook/assets/image%20(2).png" alt=""><figcaption></figcaption></figure>

## Setup a Basic App & Data

I had an LLM generate me a config file & some data to go along with it to get me started:

```python
import streamlit as st
import pandas as pd
import matplotlib.pyplot as plt

# Load the skills data
skills_df = pd.read_csv("skills.csv")

# Streamlit app title
st.title("My Computer Science Journey")

# Display the raw data
st.subheader("Skills Data")
st.dataframe(skills_df)

# Group skills by category and calculate average level
average_skills = skills_df.groupby("Category")["Level"].mean().reset_index()

# Create a bar chart
fig, ax = plt.subplots()
ax.bar(average_skills["Category"], average_skills["Level"])
plt.xticks(rotation=45)
plt.ylabel("Average Level")
plt.title("Average Skill Level by Category")

# Display the chart in Streamlit
st.pyplot(fig)

# Add a timeline (you'll need to add your actual timeline data)
st.subheader("Timeline")
st.write("Timeline of my learning journey and projects...")
```

And then some data

```
Skill,Category,Level
AI,General,30
Cloud Environments,General,60
Cybersecurity,General,20
Data Structures & Algorithms,General,60
Databases,General,20
Documentation,General,90
Data Science,General,40
Mobile Development,General,15
Electrical Engineering,General,50
Environment/OS Setups,General,80
Game Development,General,60
Graphics Programming,General,25
Python,Languages,90
Java,Languages,90
Bash,Languages,60
C,Languages,60
HTML/CSS/JS,Languages,60
C#,Languages,60
R,Languages,20
Racket,Languages,20
Regular Expressions,General,60
Git,General,60
Web3,General,20
Cryptographic Algorithms,General,20
```

When you're done, it'll look something like this:

<figure><img src="../../../../.gitbook/assets/image%20(765).png" alt=""><figcaption></figcaption></figure>



