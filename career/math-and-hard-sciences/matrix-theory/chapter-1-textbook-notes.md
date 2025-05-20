# Chapter 1 Textbook Notes

## 1.1: Sampling

* **Populations** describe entire collections of objects or outcomes about which information is _sought_.
* **Tangible populations** already exist; they are not hypothetical future things.
* **Conceptual populations** are hypothetical future predictions.

## 1.2: Summary Statistics

* _**Sample Mean Formula:**_ $$\bar{X} = \frac{1}{n} \sum_{i=1}^{n} X_i$$ where x is a `1xn` array of data.
* The bar over X denotes a **sample mean**.
* **Sample Variance** is the first step in finding the standard deviation. It is computed as follows\*\*:\*\* $$s^2 = \frac{1}{n-1}\sum_{i=1}^{n} (X_i - \bar{X})^2 \equiv \frac{1}{n-1}(\sum_{i=1}^{n}X_i^2 - n\bar{X}^2)$$. Its units are not the same as the sample values, and we take the square root of this to get the sample standard deviation by `s`.
* **Standard Deviation Formula**: $$s = \sqrt{\frac{1}{n-1}(\sum_{i=1}^{n}X_i^2 - n\bar{X}^2)}$$

### The $50 raise question

> In a certain company, every worker received a $50-per-week raise. How does this affect the mean salary and the standard deviation of the salaries? Here's the choices:
>
> 1. The mean is unchanged, and the standard deviation increases by $50.
> 2. The mean increases by $50, and the standard deviation is unchanged.
> 3. The mean and standard deviation increase by $50.
> 4. Both the mean and the standard deviation are unchanged.

It's not easy to look at that formula and see what will happen, so I ran the numbers in Wolfram Alpha. Let's say this is some kid's part-time ice cream job and there's 4 kids.

![](<../../../.gitbook/assets/CleanShot 2022-01-20 at 04.25.12.jpg>)

And what happens if I give everyone a $50 raise? The mean increases, but the population standard deviation remains the same.

![](<../../../.gitbook/assets/CleanShot 2022-01-20 at 04.25.42.jpg>)

### The 5% raise question

> In a certain company, every worker received a 5% raise. How does this affect the mean salary and the standard deviation of the salaries?
>
> \
> &#xNAN;_&#x41;nswer: The mean and standard deviation increase by 5%._

* If we change the parameters to 5% instead of a fixed value, the mean will also increase.
