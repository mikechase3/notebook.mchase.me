# Chapter 1: Gathering Data

## Sampling Terminology

| Term                  | Definition                                                                                                                    |
| --------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| Population            | What you're **seeking** to learn about.                                                                                       |
| Sample                | Who you actually survey/observe.                                                                                              |
| Simple Random Sample  | A method of selecting your population like a lottery.                                                                         |
| Tangible Populations  | These are finite populations with **numerical** identities. When Mike Chase dies, there will be one less person on the earth. |
| Conceptual Population | Tells you about data that _might possibly have been observed_ since it doesn't consist of real objects.                       |

* A **sample** is the subset of the population which we actually observe data on.
* **Populations** is the entire collection of objects. It can be realistic or conceptual.

Think about these when stating your claims:

1. **Conclusions:** what can we conclude?
2. **Uncertainty:** We estimate that $$61 \pm 4$$
3. **Confidence:** I could be up to 5% wrong?&#x20;

{% hint style="info" %}
What's the difference between uncertainty/confidence?
{% endhint %}

### Super Bowl Example

The NFL mints a commemorative coin to be used for the coin toss at the Super Bowl. To check whether the coin is fair, the NFL has the head official toss the coin on the field 100 times. Of the 100 tosses, 56 land on head.

* **Population**:&#x20;
* **Conceptual**: coin tosses don't physically exist.
* **Population**: the amount&#x20;

### Considerations

1. Who or what should we sample?
2. How should we sample them? What conditions and what questions do we ask?
3. What could go wrong.

## Random Sampling

* A sample is **random** if it involves randomness.
* The fundamental random sampling method is the simple random sample.
* A simple random sample (SRS) of size `n` from a populations is one where every possible subset of size `n` has equal chance of being sample.
* Note: it is not sufficient that every individual has equal chance of being included in the sample.
  * If all the rows had the same number of students,&#x20;

## Sampling Conceptual Populations

### Independent Samples

* Samples are **independent** if knowing the values of of some observations does not give any information about the others.
  * If you just choose random numbers out of a phone book and ask if they went on vacation, there's no way I could know what the second person's response is from the first person's response.
* For Conceptual population: generally satisfied if experimental conditions are held constant.
* For Tangible populations: not true in a SRS (simple random sample) without replacement because once an individual in the population has been sampled, they cannot be sampled again.
  * If the population is large, this effect is negligible and often ignored.
  * We can also take an SRS with replacement to obtain an independent sample, but for practicality, we don't do this.

### Sample in Practice

Here are some ways to sample:

1. Non-Computers: put names into a hat and draw them.
2. Computers:

#### Creating a Simple Random Sample in R

```
pop = c(1:100)  // Concatinates 1 to 100
n = 30  // 
sample(pop, n)  // Type of population, 

c(1, 3, 5)
```

### Other Sampling Methods

| Method                 | Description                                                                                                    | Examples |
| ---------------------- | -------------------------------------------------------------------------------------------------------------- | -------- |
| Convenience Sample     |                                                                                                                |          |
| Weighted Random Sample |                                                                                                                |          |
| Stratified Sample      |                                                                                                                |          |
| Cluster Sample         | split them into groups and choose groups randomly and choose people in the groups randomly. Double randomness. |          |

{% hint style="info" %}
TODO: Finish
{% endhint %}

## Biases

|                      | Definition                                                                                               | Example                                                                             |
| -------------------- | -------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| Incorrect population |                                                                                                          | Software company sampled their customers hoping they represent all their customers. |
| Nonresponsive Bias   | Individuals you wish to sample may not respond. Equipment or experimental units may become damaged/fail. | Political surveys. Census where foreigners are afraid they'll be deported.          |

## Types of Experiments

| Type                  | Definition                                                                                | Examples                                                                                                         |
| --------------------- | ----------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| Observational Study   | the researcher observes data generated from the world without controlling the conditions. | Does smoking cause caner? We can't force people to smoke, so we won't know.                                      |
| Controlled Experiment |                                                                                           | Clinical trials                                                                                                  |
| One Sample            | Draw a single sample from one population of interest.                                     |                                                                                                                  |
| Multisample           | Draw a single sample from each of multiple populations of interest.                       |                                                                                                                  |
| Factorial Experiment  | Multiple populations are distinguished by various combinations of factors.                | A clinical trial investigates the effect of combinations of a weight loss drug or no drug and exercise regime... |

## Types of Data

| Data Type               | Measures                      | Example            |
| ----------------------- | ----------------------------- | ------------------ |
| Quantitative/Numerical  | How much or how many.         | Height, thickness. |
| Categorical/qualitative | Places items into categories. | Location.          |

## Describing Data

| Type                      | Equation                                     | English   |
| ------------------------- | -------------------------------------------- | --------- |
| Sample Mean               | $$\bar{X} = \frac{1}{n} \sum_{i=1}^{n} X_i$$ |           |
| Sample Variance           | $$f(x) = x * e^{2 pi i \xi x}$$              | Incorrect |
| Sample Standard Deviation | $$f(x) = x * e^{2 pi i \xi x}$$              | Incorrect |
| Absolute Deviation        | $$\frac{i}{n} \sum |x_i - \bar{x}|$$         |           |

### Linear Transformations

How do $$\bar{X}$$ and `s` change when the `X` are transformed?

| Final Form                 | Proof                                                                                      |
| -------------------------- | ------------------------------------------------------------------------------------------ |
| $$\bar{Y} = a \bar{X} +b$$ | $$\bar{y} = \frac{1}{n} \sum a X_1 + b \implies a \frac{1}{n} \sum X_1 + b = a \bar{X}+b$$ |
| $$S_y^2 = a^2 s_x^2$$      | Probably not important.                                                                    |
| $$S_y = |a|s_x$$           | Probably not important.                                                                    |

## Sample Median

A **sample median** is a number&#x20;

## Trimmed Mean

* The p% trimmed mean is the mean after removing the largest p% and smallest p% of the data.&#x20;
* If np/100 is not a whole number, we round it.

## Outliers

* Outliers are values much different from the rest of the sample.
* While heuristics exist, what constitutes an outlier is context dependent and somewhat subjective.

## Working in R

```
data = c(7, 11, 3, 6, 5, 11, 47, 8, 8, 6)
```

|                              |                       |   |
| ---------------------------- | --------------------- | - |
| Mean                         | mean(data)            |   |
| Standard Deviation           | sd(data)              |   |
| Variance                     | var(data)             |   |
| Compute the 10% trimmed mean | mean(data, trim = .1) |   |
|                              |                       |   |

Trimming removes from both ends and throwing them away. Trimming is like an automated algorithm, while removing the outliers&#x20;

## Works Cited

Course: Wascher, Matthew. "Chapter 1 Class/Powerpoint" _MTH 367 Statistics._ Spring 2022. University of Dayton.
