---
description: >-
  Note: there's lots of things I do not understand. Go back to 25:00 and try to
  finish. Also try maximum subarray problem on Leetcode.
---

# Lecture 05: Divide and Conquer, Part 2

## Goals

1. Analyze the maximum-subarray problem _\(the stock market\)_
2. Find the general formula for computing running times of divide & conquer using the **Master Theorem**.

## Maximum Contiguous Subarray Problem

### Understand The Problem

We'll use the idea of a stock market where we try to figure out when we buy and sell the stock to better understand the maximum contiguous subarray problem.

1. _The Problem:_ In a stock market, when should you have bought or sold the stock?
2. **Contiguous** means there's not a break. In a stock market, they must be consecutive days.
3. A **subarray** is a subset of the original array that is contiguous and maintains the sequence of all elements from the original array. _\(Definition Source: Back to Back SWE\)_
4. We are trying to find the largest sum.
5. Try to find all the sub arrays I can find the sums to find the one with the maximum sum?

{% tabs %}
{% tab title="General Case" %}
How Many Subarrays?

1. The number of subarrays with one single element has _n_ subarrays.
2. The number of elements with 2 consecutive elements has _n-1_ subarrays.
3. The number of elements with 3 consecutive elements has _n-2_ subarrays.
4. The number of elements with 4 consecutive elements has _n-3_ subarrays.

The number of subarrays with _n_ elements is

$$
1 + 2 + ... + (n-2) + (n-1) + n ⇒ n(n+1)/2
$$

\[Words for later\]
{% endtab %}

{% tab title="4 Elements" %}
Let's say we have an original array with the elements `[3, -2, 5, -1]`. We can count the number of subarrays because there are 4 elements.

1. The number of subarrays with one single element has _4_ subarrays.
2. The number of elements with 2 consecutive elements has _3_ subarrays.
3. The number of elements with 3 consecutive elements has _2_ subarrays.
4. The number of elements with 4 consecutive elements has _1_ subarrays.



The number of subarrays with 4 elements is

$$
1 + 2 + 3 + 4⇒ n(n+1)/2 ⇒10
$$

{% hint style="warning" %}
I'm only 90% sure I calculated this right, not 100%
{% endhint %}
{% endtab %}
{% endtabs %}

### Solutions

{% tabs %}
{% tab title="Cubic Time" %}
This work is not my own, but from [Back to Back SWE](https://backtobackswe.com/platform/content/max-contiguous-subarray-sum/solutions): 

```java
class Solution {
  public int maxContiguousSubarraySum(int[] nums) {
    int n = nums.length;
    int maximumSubArraySum = Integer.MIN_VALUE;

    /*
      We will use these outer 2 for loops to investigate all
      windows of the array.
      
      We plant at each 'left' value and explore every
      'right' value from that 'left' planting.

      These are our bounds for the window we will investigate.
    */
    for (int left = 0; left < n; left++) {
      for (int right = left; right < n; right++) {
        // Let's investigate this window
        int windowSum = 0;

        // Add all items in the window
        for (int k = left; k <= right; k++) {
          windowSum += nums[k];
        }

        // Did we beat the best sum seen so far?
        maximumSubArraySum = Math.max(maximumSubArraySum, windowSum);
      }
    }

    return maximumSubArraySum;
  }
}
```
{% endtab %}

{% tab title="Quadratic Time" %}
This work is not my own, but again, from [Back to Back SWE](https://backtobackswe.com/platform/content/max-contiguous-subarray-sum):

```java
class Solution {
  public int maxContiguousSubarraySum(int[] nums) {
    int n = nums.length;
    int maximumSubArraySum = Integer.MIN_VALUE;

    for (int left = 0; left < n; left++) {
      int runningWindowSum = 0;

      for (int right = left; right < n; right++) {
        runningWindowSum += nums[right];

        // Does this window beat the best sum we have seen so far?
        maximumSubArraySum = Math.max(maximumSubArraySum, runningWindowSum);
      }
    }

    return maximumSubArraySum;
  }
}
```
{% endtab %}

{% tab title="Linear Time \(Divide & Conquer\)" %}
#### Divide into Two Halves

Given the subarray: `[3, -2, 5, -1]`, we can split it up into the left half and the right half:

* Left half: `[3, -2]`
* Right half: `[5, -1]`

There are three cases we must consider:

* The left half
* The right half
* Across the middle portion

{% hint style="danger" %}
I do not understand how to cross between the middle point _\(Video: 17:30: We need to compare the three sum, if we go from A\[0\]_ ⇒_A\[2\]_, we find the sum is 6._\)_
{% endhint %}

\_\_

#### Pseudocode

1. **Divide** by computing the mid-point and splitting.
2. **Conquer** by two recursive calls:
   1. Find the maximum subarray of `A[low...mid]` 
   2. Find the maximum subarray of  `A[mid+1...high]`
3. **Combine**  by calling the _Find-max-crossing subarray_ that crosses the midpoint, and then determining which of the three results gives the maximum sum _\(Source: Yao\)_.
4. Solve the **base case**, where the array only has one element _by returning just that element._

{% hint style="danger" %}
I don't understand step 3. _\(Video, 21:00\)_
{% endhint %}

```java
if high == low:
    //Base case, Just return the element.
    return (low, high, A[low]
    
else{
    mid = (low + high) / 2
    
    //TODO
    

//Find Max Crossing Subarray (A, low, mid, high)
if the maximum sum is bigger then... update something? 
See video @ 24:00.
```

{% hint style="danger" %}
I don't understand this pseudocode @ 26:00 for crossing the array.
{% endhint %}

#### Full Solution

Solution from [Back to Back SWE](https://backtobackswe.com/platform/content/max-contiguous-subarray-sum/solutions):

```java
class Solution {
  public int maxContiguousSubarraySum(int[] nums) {
    /*
      We default to say the the best maximum seen so far is the first
      element.

      We also default to say the the best max ending at the first element
      is...the first element.
    */
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];

    /*
      We will investigate the rest of the items in the array from index
      1 onward.
    */
    for (int i = 1; i < nums.length; i++) {
      /*
        We are inspecting the item at index i.

        We want to answer the question:
        "What is the Max Contiguous Subarray Sum we can achieve ending at index i?"

        We have 2 choices:

        maxEndingHere + nums[i] (extend the previous subarray best whatever it was)
          1.) Let the item we are sitting at contribute to this best max we achieved
          ending at index i - 1.

        nums[i] (start and end at this index)
          2.) Just take the item we are sitting at's value.

        The max of these 2 choices will be the best answer to the Max Contiguous
        Subarray Sum we can achieve for subarrays ending at index i.

        Example:

        index     0  1   2  3   4  5  6   7  8
        Input: [ -2, 1, -3, 4, -1, 2, 1, -5, 4 ]
                 -2, 1, -2, 4,  3, 5, 6,  1, 5    'maxEndingHere' at each point
        
        The best subarrays we would take if we took them:
          ending at index 0: [ -2 ]           (snippet from index 0 to index 0)
          ending at index 1: [ 1 ]            (snippet from index 1 to index 1) [we just took the item at index 1]
          ending at index 2: [ 1, -3 ]        (snippet from index 1 to index 2)
          ending at index 3: [ 4 ]            (snippet from index 3 to index 3) [we just took the item at index 3]
          ending at index 4: [ 4, -1 ]        (snippet from index 3 to index 4)
          ending at index 5: [ 4, -1, 2 ]     (snippet from index 3 to index 5)
          ending at index 6: [ 4, -1, 2, 1 ]  (snippet from index 3 to index 6)
          ending at index 7: [ 4, -1, 2, 1, -5 ]    (snippet from index 3 to index 7)
          ending at index 8: [ 4, -1, 2, 1, -5, 4 ] (snippet from index 3 to index 8)

        Notice how we are changing the end bound by 1 everytime.
      */
      maxEndingHere = Math.max(maxEndingHere + nums[i], nums[i]);

      // Did we beat the 'maxSoFar' with the 'maxEndingHere'?
      maxSoFar = Math.max(maxSoFar, maxEndingHere);  
    }

    return maxSoFar;
  }
}
```
{% endtab %}
{% endtabs %}



## Works Cited

1. [Back to Back SWE: Max Contiguous Subarray Sum Solutions](https://backtobackswe.com/platform/content/max-contiguous-subarray-sum/solutions)
2. Dr. Yao's classroom lecture \(problems & formatting mostly\).



