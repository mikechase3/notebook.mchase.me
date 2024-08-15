# AI-Driven Conversational Data Collection

From Gem City Tech's AI - 2024AUG15.

## Background

* **Tyler Rupert**: main speaker | jon\<hisFirstName>@seercg.com | \<twThreeeeIne> 348 5998
* **Kevin Pham**: secondary speaker | kspham99@gooleMale.com | \<DaytonArea> -286-3225

An experiment w/ Generative AI Oracle. Has a business: Marco has a handfull of organization/businesses & ask if there's somewhere where we can insert this tech in his business. Client intakes; doesn't get enough detail about the vendor from the intake questioneer. Make a chatbot to help people share a bit more. If they're not clear on the question. The bot can do the same.&#x20;

If you have a specific application of this, you might not be able to find information on how to accomplish what you want to accomplish.&#x20;

## What's an Oracle

* Helps translate data from the real world into something computers can use.

## Problem Statement

* How do you convert the "sit and talk to someone" to extract data?&#x20;
* How do we get this information int he computer from the client?

## [#background](ai-driven-conversational-data-collection.md#background "mention")ools

* [**LangChain**](https://www.langchain.com/):&#x20;
  * **Pros**: most popular. Great for ideas.
  * **Cons**: Couldn't predict what the output was going to do. Had a habit of breaking changes. Prone to breaking. Somewhat unstable. Dependency issues.&#x20;
* [**Pydantic**](https://docs.pydantic.dev/latest/): forces you to abide by rules of development. It's a JSON serializer.&#x20;
* **Instructor**: Pros: solves extraction very well. If you need something extracted in a structured way, this is how it does it.&#x20;
* Pydantic vs. JSSON Schema: OpenAI came out with something called JSON output. Hopefully, you get your data returned to you. In Instructor, it's a lot easier.&#x20;

## Goals

* Figure out a way to build a caht-bot
* Provide structured output you can do something with.
* Build a report and give it to Marcus to gain what his clients are looking for.

### Approach 1: Basic LLM Chat w/ Data Extraction

#### Strategy

* Build a simple chat program using OpenAI's API.
* Use an "intake definition" to define the structured data schema.
* Secondary LLM "agent" to extract structured data from chat history.

### Approach 2: Enhanced LLM Chat w/ Data Extraction

Basically, gave it some context of the data. It satayed on-track, but was too good. It didn't really chat back, it just asked questions.

* **Challenges**: two discrete approaches. Basic chat wasn't focused enough. The second approach with some system instructions was too specific & worked too well.&#x20;
* **Objective**: start with foundational knowledge (abstract this and see how this fits into techonlogy that we already know), conduct open-ended experimentation, and enable rapid iteration (play & try things, don't just keep chatting things & go through full conversations to see how it performed).

### Tuning the LLM

* NEEDS: tunability, responsiveness (rapid iteration), consistency.
* SOLUTIONS: tunability (a 6-part prompt structure), responsiveness (a mock user test system), and consistency (abstract architecture? Hoping and praying?)

## 6-Part Prompt

Basically, these were all system prompts/instructions.&#x20;

* Role, task, specifics, context, examples, and notes.&#x20;
* It's manageable, tuneable, consistent, abstract, source claimed vast increases in accuracy from 5-115%
* On the time, ti was based on research papers. The first thing is weighted, the second is weighted second heavyiest, and the middle is less important.

```python
role = [
    "You are a ..."
    "Your goal is..."
]

task = [
    "The client is seeking a peraonal trainer to..."
]

.
.
.

examples = []
notes = [
    "Focus on understanding the client's need and how you can help them achieve..."
    "Don't discuss more than 1 topic at a time. Ensure the conversation flows naturally."
    "Only ask 1 question at a time to avoid overwhelming the client"
]
```

You can put this in the very first message, the very last, or the second to last message. The third one is when the user responds as a heavier weight. Appending this second to last produces some interesting results?&#x20;

## Mock User

They used three mock users pretty quickly.

```python
role = [
    "You are a potential client..."
    "You can decide who you are..."
]
.. other params
```

## Approach 4: Combining approach w/ a state machine

* **Strategy**: devise a solution allowing us to tune behavior between those two discrete approaches.
* **Hyptohesis**: if we can create a state machine, install some tunable elements, and continue playing with it, we can probably find a happy-medium.

### The Tunable Elements

* 6-part prompt.
* Turn constraint within states: you add a limit for how long you can stay in a specific "state"
* Intake definition - those questions.
* Goal: the total number of turns, reducing them if you need specific questions answer. Don't just say "i don't think you don't need that question answered because it doesn't matter". This is what you're working towards & not just letting the LLM run wild.&#x20;

### The State Machine

<pre><code>start() // what can I do for you?
while not done:
<strong>    while turn_count &#x3C; 5:
</strong>        freeConversation
    if dataExtraction() == isDone?
        wrap_up_conversation()
        generate_report()
        send_data()
        return extracted_parameters/data
    else if madeSufficientProgress == true:
        pass  //return to free conversation for 4 more turns
    else:
        while turn_count &#x3C; 3:
            doTargetedConversation()
</code></pre>

Throughout, it'll do "checking progress" and output data (detail collected) and return to getting back on track. It'll show something like:

```python
Details Collected:
{
    "fitness_goals": "weight loss"
    "current_fitness_level": "intermediate"
    "workout_preferences": "null"
    "current_health_conditions": null
}
```

You can define in `event_details.py` what the intake definitions are.&#x20;

GPT 4o Mini is super cheap - like pennies per test.

## Key Takeaways

* 6-part prompt.
* User tests
* Those'll let you iterate very quickly in short periods of time.&#x20;
* **State Machine** structures will let you extend/enhance cleanly for gradient transitions between the states.

