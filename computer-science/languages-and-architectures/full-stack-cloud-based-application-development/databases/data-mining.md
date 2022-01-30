---
description: How do we draw conclusions
---

# Data Mining

## Association Rule Mining

{% embed url="https://www.youtube.com/watch?v=eOOhn9CX2qU" %}

| Term       | Definition                                                        |   |
| ---------- | ----------------------------------------------------------------- | - |
| Support    | How often does this show up in the collection?                    |   |
| Confidence | Out of everything that has A, how likely is it that it goes to B. |   |



1. First iteration: identify frequent itemsets with one item.
2. Subsequently: repeat iterations?
3. Test all candidates to determine those are frequent
4. Repeat iterations until no new frequent itemsets are generated.

### The Aprioli Algorithm

This is a 3-step algorithm.

![](<../../../../.gitbook/assets/CleanShot 2021-11-16 at 11.31.39@2x.jpg>)

#### Step 1: Get Support For Each

* Support for pen: 1
* Support for ink: 0.75
* Support for diary: 0.75 (appears in 3 transactions of 4 total).
* Support for soap: 0.5

#### Step 2: Eliminate based on MinSup=.7 and MinConf =.8

* Support for pen: 1
* Support for ink: 0.75
* Support for diary: 0.75 (appears in 3 transactions of 4 total).
* ~~Support for soap: 0.5  (does not meet 0.7 support threshold)~~

#### Step 3:&#x20;

![](<../../../../.gitbook/assets/CleanShot 2021-11-16 at 11.37.47@2x.jpg>)

