# Prescriptive Analytics w/ Python



This interactive tutorial discusses RL fundamental concepts & applications like product recommendations & content recommendations.

Goals: understand RL, environments, and Google RecSim

{% embed url="https://learning.oreilly.com/scenarios/define-and-understand/9781098121587/" %}

### Design & Understand a RL Environment

{% embed url="https://github.com/google-research/recsim/blob/master/recsim/colab/RecSim_Developing_an_Environment.ipynb" %}

```
pip install recsim
```

So in RL, the _agent_ has to choose an action from the set of possible actions. Depending on what the agent recommends/does, the user will take an action and respond back to the agent. That response might be a reward like how long someone watches a youtube video or something else measurable.

### Recsim's Prebuilt Environments

We'll use RecSim to define a pre-built model?

* Long term satisfaction (the one we will use in this lab)
* Interest evolution
* Interest exploration

