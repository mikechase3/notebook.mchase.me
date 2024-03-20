# Prescriptive Analytics w/ Python

## What is Prescriptive Analytics

Prescriptive analytics is a branch of analytics that'll use data & matghematical models to provide recommendations for decision-making. It's called "prescriptive" because it'll provide actionable insights & recommendations to improve future outcomes.

### Questions to Consider

1. What's the difference between descriptive, predictive, and prescriptive analytics? _A: descriptive is something you'd have to maually process & grep. Prescriptive is recommended. Predicted is... seems the same._
2. How does prescriptive analytics leverage data and mathematical mdoels? _A: you can use likes on youtube (or before that, stars). Back when you could see likes/dislikes, you could evaluate the like/dislike ratio to answer questions like what is controversial but not bullcrap if you saw there were 1000+ views from rating={ups/downs} were mixed rather._&#x20;
3. What are the main components of a prescriptive analytics system? _Guesses: a reward function would be how much time someone spends on the next recommended video to see if they like it? Action is which video is recommended. Introduce some chance if it's Bellman operations (I think that's probability ones instead of policy but both probably work)._
4. What are the challenges/limitations of prescriptive analytics? _A: hard to visualize beyond a 3D vector space. Too many relations I suppose make it somewhat incomprehensible._



This interactive tutorial discusses RL fundamental concepts & applications like product recommendations & content recommendations.

Goals: understand RL, environments, and Google RecSim



## Design & Understand a RL Environment

```
pip install recsim
```

So in RL, the _agent_ has to choose an action from the set of possible actions. Depending on what the agent recommends/does, the user will take an action and respond back to the agent. That response might be a reward like how long someone watches a youtube video or something else measurable.

### Recsim's Prebuilt Environments

We'll use RecSim to define a pre-built model?

* Long term satisfaction (the one we will use in this lab)
* Interest evolution
* Interest exploration

### Imports

```
import recsim
from recsim import environments
from pprint import pprint # for better print formatting
```

### Required Classes

See this [documentation](https://github.com/google-research/recsim/blob/master/recsim/colab/RecSim\_Developing\_an\_Environment.ipynb) for a visual.

> The blue classes refer to the documents, the green classes to the user, and the red classes to the agent. The various boxes represent conditional probability distributions. Therefore, a RecSim environment can be seen as a dynamic Bayesian network (DBN). -Lab

```
// Some code
```

### Slate Size

Slatee size is just the set of items presented to the user for recommendation. Like how many pieces of clothing you have for sale or something like that. It can be represented as a number attached to probably a pointer/id/index to something with more detail.

```
lts_env = recsim.environments.long_term_satisfaction.create_environment({
    "num_candidates": NUM_CANDIDATES,
    "slate_size": SLATE_SIZE,
    "resample_documents": False
})
```



<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-19 at 21.04.47@2x.png" alt=""><figcaption></figcaption></figure>

### Observation Space

\>>> pprint(observation\_space) {'doc': OrderedDict(\[('0', array(\[0.5488135])), ('1', array(\[0.71518937])), ('2', array(\[0.60276338])), ('3', array(\[0.54488318])), ('4', array(\[0.4236548])), ('5', array(\[0.64589411])), ('6', array(\[0.43758721])), ('7', array(\[0.891773])), ('8', array(\[0.96366276])), ('9', array(\[0.38344152]))]), 'response': None, 'user': array(\[], dtype=float64)}

Observation space in RecSim represents the information available to the recommendation system about the user's past behavior and the current context.

{% hint style="info" %}
What is the observation space composed of?
{% endhint %}

The observation space consists of three components:

1. 'doc': This represents the features of documents or items that are presented to the user. Each document is identified by a number ('0', '1', '2', ...). In the example, the features of ten documents are given as arrays of floating-point values.
2. 'response': This represents the user's response to the previously recommended items. In this case, the response field is set to None, indicating that there is no information available about the user's previous response.
3. 'user': This represents the features or state of the user. The example shows an empty array, which means that no user features or state information is provided in this observation.

Overall, this observation space indicates that the recommendation system has access to information about the features of documents/items, but no information about the user's previous response or user-specific features or state.

### Action Space

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-19 at 21.16.06@2x.png" alt=""><figcaption></figcaption></figure>



## Works Cited & Further Reading

The following sources helped me compose this:

* [Recsim Docs](https://github.com/google-research/recsim/blob/master/recsim/colab/RecSim\_Developing\_an\_Environment.ipynb)

{% embed url="https://learning.oreilly.com/scenarios/define-and-understand/9781098121587/" %}

{% embed url="https://github.com/google-research/recsim/blob/master/recsim/colab/RecSim_Developing_an_Environment.ipynb" %}

