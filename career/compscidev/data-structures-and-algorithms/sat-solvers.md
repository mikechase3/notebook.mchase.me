# SAT Solvers

From [Dynamic](../conferences-and-interest-groups/gem-city-tech/dynamic-languages-group.md) languages group. 2024 AUG 14

## Setup/Installation

* [SAT solvers](https://en.wikipedia.org/wiki/SAT_solver) evaluate boolean logic.
* [https://pypi.org/project/pycosat/](https://pypi.org/project/pycosat/)
* [https://github.com/python-constraint/python-constraint?tab=readme-ov-file#magic-squares](https://github.com/python-constraint/python-constraint?tab=readme-ov-file#magic-squares)

Code is under `protect@g` here.&#x20;



<figure><img src="../../../.gitbook/assets/CleanShot 2024-08-14 at 19.54.03@2x.png" alt=""><figcaption></figcaption></figure>

## Magic Square Examples

The sum of diagnals & all rows/columns add up to a number:

```python
>>> problem = Problem()
>>> problem.addVariables(range(0, 16), range(1, 16 + 1))
>>> problem.addConstraint(AllDifferentConstraint(), range(0, 16))
>>> problem.addConstraint(ExactSumConstraint(34), [0, 5, 10, 15])
>>> problem.addConstraint(ExactSumConstraint(34), [3, 6, 9, 12])
>>> for row in range(4):
...     problem.addConstraint(ExactSumConstraint(34),
                              [row * 4 + i for i in range(4)])
>>> for col in range(4):
...     problem.addConstraint(ExactSumConstraint(34),
                              [col + 4 * i for i in range(4)])
>>> solutions = problem.getSolutions()
```

From [https://github.com/python-constraint/python-constraint?tab=readme-ov-file#magic-squares](https://github.com/python-constraint/python-constraint?tab=readme-ov-file#magic-squares)



<figure><img src="../../../.gitbook/assets/CleanShot 2024-08-14 at 20.00.25@2x.png" alt=""><figcaption></figcaption></figure>

## Soduku Challenge

Using this - how can you solve soduku? You can do it & we did a live demo, but it was too fast to take notes & run it at the same time. Here's how I got started.

<figure><img src="../../../.gitbook/assets/CleanShot 2024-08-14 at 20.17.10@2x.png" alt=""><figcaption></figcaption></figure>

