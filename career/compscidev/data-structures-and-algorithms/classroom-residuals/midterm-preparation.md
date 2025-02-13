# CPS 350 Midterm Preparation

## Format

The midterm will have similar questions, but they will all be new.

### Short Answers

1. A programming question on divide and conquer
2. A programming question on dynamic programming
3. An amortized analysis question.

## Chapters

| Chapter | Content              |
| ------- | -------------------- |
| 3       | Asymptotic Notations |
| 4       | Divide & Conquer     |
| 15      | Dynamic Programming  |
| 16      | Greedy Algorithms    |
| 17      | Amortized Analysis   |

## Midterm

### Concerning Problems

If this is marked wrong, make sure she knows why I thought this way.

![](<../../../../.gitbook/assets/image (39).png>)

{% hint style="info" %}
O(n) depends on the constant. If the constant o(n) has a constant of 1, then yes, this works because it's exactly equal. I said A, B, and C.
{% endhint %}

![](<../../../../.gitbook/assets/image (40).png>)

{% hint style="info" %}
We're diving the function time by 2 every iteration, but also adding `n`.
{% endhint %}

Given an input array with length n, what is the running time of the divide and conquer approach for finding the maximum subarray?

Given that a divide and conquer approach is used, which of the following is the recurrence function for finding the maximum subarray?

![What's the question?](<../../../../.gitbook/assets/image (41).png>)

## Past Quizzes

Question 1 of 114.0 Points

Given two sequences with lengths n and m, respectively, what is the running time of the dynamic programming approach for finding the longest common subsequence?

A.\
O(max(n, m))

B.\
O(X2), where X = max(n, m)

C.\
O(n2)

D.\
O(n \* m)

Answer Key: D Question 2 of 114.0 Points Given an input array with length n, what is the running time of the dynamic programming approach for finding the maximum subarray? A. O(n)\
B. O(log(n))\
C. O(n\_n)\_\
\_D. O(n\_log(n))

Answer Key: A Question 3 of 114.0 Points

Given a sorted sequence of keys, where key k\[i] is searched with probability p\[i], for i = 0, 1, ..., n-1, what is the running time of the dynamic programming approach for finding the optimal binary search tree with the minimum search cost?

A.\
O(2n)

B.\
O(n3)

C.\
O(n)

D.\
O(n2)

Answer Key: B Question 4 of 114.0 Points

Given n items and weight limit W>0, where item i has integer weight w\[i] and value b\[i], what is the running time of the dynamic programming approach for solving the 0-1 knapsack problem?

A.\
O(n2)

B.\
O(n\*log(n))

C.\
O(2n)

D.\
O(n\*W)

Answer Key: D Part 2 of 2 - Ch15-16 28.0 Points

Question 5 of 114.0 Points Which algorithm design paradigm is exemplified by the fractional knapsack algorithm? A. divide and conquer\
B. greedy approach\
C. brute force approach\
D. dynamic programming

Answer Key: B Question 6 of 114.0 Points Which algorithm design paradigm is exemplified by the Dijkstra’s single-source shortest path algorithm? A. dynamic programming\
B. brute force approach\
C. greedy approach\
D. divide and conquer

Answer Key: C Question 7 of 114.0 Points Given a graph with V nodes and E edges, which algorithm design paradigm is exemplified by Kruskal's minimum spanning tree algorithm we discussed in class? A. dynamic programming\
B. greedy approach\
C. brute force approach\
D. divide and conquer

Answer Key: B Question 8 of 114.0 Points Given a graph with V nodes and E edges, which algorithm design paradigm is exemplified by DFS (depth first search)? A. greedy approach\
B. brute force approach\
C. divide and conquer\
D. dynamic programming

Answer Key: B Question 9 of 114.0 Points Given a graph with V nodes and E edges, which algorithm design paradigm is exemplified by BFS (breadth first search)? A. dynamic programming\
B. divide and conquer\
C. greedy approach\
D. brute force approach

Answer Key: D Question 10 of 114.0 Points Which algorithm design paradigm is exemplified by the longest palindromic substring algorithm we discussed in class? A. divide and conquer\
B. dynamic programming\
C. greedy approach\
D. brute force approach

Answer Key: B Question 11 of 114.0 Points Given an unsorted array with n numbers, which algorithm design paradigm is exemplified by the k-th largest item algorithm we discussed in class? A. greedy approach\
B. divide and conquer\
C. dynamic programming\
D. brute force approach

Answer Key: B

\=====Recurrences====== Which of the following is the recurrence function for merge sort? A. T(n) = T(n/2) + 2\
B. T(n) = T(n/2) + n\
C. T(n) = 2T(n/2) + n\
D. T(n) = 2T(n/2) + 2

Answer Key: C Question 2 of 104.0 Points

Given T(n) = 8T(n/2) + n2 for n >1 and T(n) = O(1) for n =1, what is the solution to T(n)?

A.\
T(n) = O(n2 \* log(n))

B.\
T(n) = O(n3)

C.\
T(n) = O(n2)

D.\
T(n) = O(n3 \* log(n))

Answer Key: B Question 3 of 104.0 Points Given T(n) = T(n/2) + O(n) for n >1 and T(n) = O(1) for n =1, what is the solution to T(n)? A. T(n) = O(log(n))\
B. T(n) = O(n)\
C. T(n) = O(n log(n))\
D. T(n) = O(1)

Answer Key: B Question 4 of 104.0 Points

Given T(n) = 2T(n/2) + n for n >1 and T(n) = O(1) for n =1, what is the solution to T(n)?

A.\
T(n) = O(n2)

B.\
T(n) = O(n log(n))

C.\
T(n) = O(n)

D.\
T(n) = O(log(n))

Answer Key: B Question 5 of 104.0 Points Given T(n) = T(n/2) + O(1) for n >1 and T(n) = O(1) for n =1, what is the solution to T(n)? A. T(n) = O(log(n))\
B. T(n) = O(n log(n))\
C. T(n) = O(n)\
D. T(n) = O(1)

Answer Key: A Question 6 of 104.0 Points Which of the following is the recurrence function for quick sort? A. T(n) = T(n/2) + O(1)\
B. T(n) = 2T(n/2) + O(1)\
C. T(n) = 2T(n/2) + O(n)\
D. T(n) = T(n/2) + O(n)

Answer Key: C Question 7 of 104.0 Points Which of the following is the recurrence function for finding the maximum subarray? A. T(n) = 2\_T(n/2) + n\_\
&#xNAN;_&#x42;. T(n) = T(n/2) + n_\
&#xNAN;_&#x43;. T(n) = T(n/2) + 2_\
\_D. T(n) = 2\_T(n/2) + 2

Answer Key: A Question 8 of 104.0 Points Consider the attached figure, what problem does the method find() solve?

fig.pdf 112 KB A. Finding the minimum element in the input array.\
B. Finding the maximum element in the input array.\
C. Binary search.\
D. None of the above.

Answer Key: B Question 9 of 104.0 Points Given that the input array is sorted, which of the following is the recurrence function for binary search? A. T(n) = 2T(n/2) + n\
B. T(n) = T(n/2) + O(1)\
C. T(n) = T(n/2) + n\
D. T(n) = 2T(n/2) + O(1)

Answer Key: B Question 10 of 104.0 Points

Given T(n) = 4T(n/2) + n for n >1 and T(n) = O(1) for n =1, what is the solution to T(n)?

A.\
T(n) = O(n2)

B.\
T(n) = O(n)

C.\
T(n) = O( n log(n))

D.\
T(n) = O(log(n))

\====Running Times====== What is the running time of the following algorithm?

// n > 0 is the input array size

int count = 0;

for(int i = 0; i < n; i++)

{

for(int j = i; j < n; j++) { count++; }

}

A.\
n2

B.\
n2 / 2

C.\
n2 / 2 - n/2

D.\
n2 / 2 + n/2

Answer Key: D Question 2 of 103.0 Points What is inf{1, 2, 3, 4}? A. 2\
B. 4\
C. 3\
D. 1

Answer Key: D Question 3 of 103.0 Points

Which of the following statements is correct?

A.\
f(n) = Ω(g(n) if and only if l i m subscript n rightwards arrow infinity end subscript vertical line fraction numerator f left parenthesis n right parenthesis over denominator g left parenthesis n right parenthesis end fraction vertical line space equals space 0

B.\
f(n) = Ω(g(n) if and only if l i m s u p subscript n rightwards arrow infinity end subscript vertical line fraction numerator f left parenthesis n right parenthesis over denominator g left parenthesis n right parenthesis end fraction vertical line greater than space 0

C.\
f(n) = Ω(g(n) if and only if l i m subscript n rightwards arrow infinity end subscript vertical line fraction numerator f left parenthesis n right parenthesis over denominator g left parenthesis n right parenthesis end fraction vertical line greater than 0

D.\
f(n) = Ω(g(n) if and only if l i m i n f subscript n rightwards arrow infinity end subscript space vertical line fraction numerator f left parenthesis n right parenthesis over denominator g left parenthesis n right parenthesis end fraction vertical line space greater than space 0 space

Answer Key: D Question 4 of 103.0 Points

Which of the following statements is correct?

A.\
l i m subscript n rightwards arrow infinity end subscript vertical line fraction numerator f left parenthesis n right parenthesis over denominator g left parenthesis n right parenthesis end fraction vertical line equals 0 if and only if f(n) = O(g(n))

B.\
l i m i n f subscript n rightwards arrow infinity end subscript vertical line fraction numerator f left parenthesis n right parenthesis over denominator g left parenthesis n right parenthesis end fraction vertical line space less than space infinity space i f space a n d space o n l y space i f space f left parenthesis n right parenthesis space equals space O left parenthesis g left parenthesis n right parenthesis right parenthesis

C.\
l i m subscript n rightwards arrow infinity end subscript vertical line fraction numerator f left parenthesis n right parenthesis over denominator g left parenthesis n right parenthesis end fraction vertical line less than infinityif and only if f(n) = O(g(n))

D.\
l i m s u p subscript n rightwards arrow infinity end subscript vertical line fraction numerator f left parenthesis n right parenthesis over denominator g left parenthesis n right parenthesis end fraction vertical line space less than infinity space i f space a n d space o n l y space i f space f left parenthesis n right parenthesis space equals space O left parenthesis g left parenthesis n right parenthesis right parenthesis

Answer Key: D Question 5 of 103.0 Points Is o(g(n)) a subset of O(g(n))? True of false. A. True\
B. False

Answer Key: A Question 6 of 103.0 Points

List functions in O(n), where O is the Big Oh notation. Choose all correct items.

A.\
n3 + n/2 + 20

B.\
10

C.\
3n2 - n/2

D.\
n/2

Answer Key: B, D Question 7 of 103.0 Points

What is the running time of the following algorithm?

// n > 0 is the input array size

int count = 0;

for(int i = 0; i < n; i++)

{

for(int j = i; j < n; j++) { count++; }

}

A.\
O(n2)

B.\
O(n)

C.\
2n2

D.\
O(n\*log(n))

Answer Key: A Question 8 of 103.0 Points

List functions in o(n2), where o is the little oh notation. Choose all correct items.

A.\
n\*log(n)

B.\
100n

C.\
n2

D.\
n2 - 10\*n

Answer Key: A, B Question 9 of 103.0 Points What is sup{1, 2, 3, 4}? A. 1\
B. 2\
C. 3\
D. 4

Answer Key: D Question 10 of 103.0 Points

List functions in Θ(n2), where Θ means the Big Theta notation. Choose all correct items.

A.\
2n2 + 10n + 5

B.\
n\*(n-1)/2

C.\
100\*n + log(n)

D.\
n\*log(n)

Answer Key: A, B
