# LLM Intro GemCityTech

Taught by:

{% embed url="https://ngerakines.me/" %}

{% embed url="https://github.com/ngerakines" %}

Course Material:

{% embed url="https://github.com/ngerakines/llm_fundamentals" %}

## HuggingFace

* They're building libraries
* Have lots of data sets! You can find tune it with some parameters and experiment on how it operates and behaves.

{% embed url="https://huggingface.co/datasets/fka/awesome-chatgpt-prompts" %}

* Treat hugging face & the content like you would with any downloadable thing. It's remote code. Don't download everything.

## Command

* htop: does stuff... whatever
* nvtop is better and does GPU

<figure><img src="../../../../.gitbook/assets/CleanShot 2024-07-18 at 18.29.29@2x.png" alt=""><figcaption></figcaption></figure>

## Transformers

<figure><img src="../../../../.gitbook/assets/CleanShot 2024-07-18 at 19.07.09@2x.png" alt=""><figcaption></figcaption></figure>

{% embed url="https://www.linkedin.com/pulse/llm-transformer-architecture-shivasish-mahapatra-kj9qf" %}

The util.py module documentation do some very useful things for sentence transformers.&#x20;

## Examples

### Exercise 4

* We'll get a big dataset. 80% train. 20% test.
* Create model, do 4 batches, save three of them.
* Train & compute this dataset.
* So when we go to query the model with...?

### Exercise 5

We'll use BERTopic\_Wikipedia

{% embed url="https://huggingface.co/MaartenGr/BERTopic_Wikipedia" %}

This has lots of different models across topics.

### Exercise 9

Going to load a vector database, inject a bunch of facts into it. He's using an existing model just for embedding. Taking tokens & shoving them into the database, then querying based on some prompt (see examples). He's going to lookup facts relavant to the prompt that he's going to supplement the query with like "what is michael jordan known for?"

## How does Stable Diffusion Work

*

