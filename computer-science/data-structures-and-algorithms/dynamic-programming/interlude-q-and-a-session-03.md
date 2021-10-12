# Problem Session: Dynamic Programming

## Running Time Fundamentals

### Binary Search

{% tabs %}
{% tab title="Recursive" %}
```java
// Java implementation of recursive Binary Search 
class BinarySearch { 
	// Returns index of x if it is present in arr[l.. 
	// r], else return -1 
	int binarySearch(int arr[], int l, int r, int x) 
	{ 
		if (r >= l) { 
			int mid = l + (r - l) / 2; 

			// If the element is present at the 
			// middle itself 
			if (arr[mid] == x) 
				return mid; 

			// If element is smaller than mid, then 
			// it can only be present in left subarray 
			if (arr[mid] > x) 
				return binarySearch(arr, l, mid - 1, x); 

			// Else the element can only be present 
			// in right subarray 
			return binarySearch(arr, mid + 1, r, x); 
		} 

		// We reach here when element is not present 
		// in array 
		return -1; 
	} 

	// Driver method to test above 
	public static void main(String args[]) 
	{ 
		BinarySearch ob = new BinarySearch(); 
		int arr[] = { 2, 3, 4, 10, 40 }; 
		int n = arr.length; 
		int x = 10; 
		int result = ob.binarySearch(arr, 0, n - 1, x); 
		if (result == -1) 
			System.out.println("Element not present"); 
		else
			System.out.println("Element found at index " + result); 
	} 
} 
/* This code is contributed by Rajat Mishra */

```
{% endtab %}

{% tab title="Recursive" %}
The iterative solution is `T(n) = T(n/2) + c`

```java
// Java implementation of iterative Binary Search 
class BinarySearch { 
    // Returns index of x if it is present in arr[], 
    // else return -1 
    int binarySearch(int arr[], int x) 
    { 
        int l = 0, r = arr.length - 1; 
        while (l <= r) { 
            int m = l + (r - l) / 2; 
  
            // Check if x is present at mid 
            if (arr[m] == x) 
                return m; 
  
            // If x greater, ignore left half 
            if (arr[m] < x) 
                l = m + 1; 
  
            // If x is smaller, ignore right half 
            else
                r = m - 1; 
        } 
  
        // if we reach here, then element was 
        // not present 
        return -1; 
    } 
  
    // Driver method to test above 
    public static void main(String args[]) 
    { 
        BinarySearch ob = new BinarySearch(); 
        int arr[] = { 2, 3, 4, 10, 40 }; 
        int n = arr.length; 
        int x = 10; 
        int result = ob.binarySearch(arr, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at "
                               + "index " + result); 
    } 
} 

//Source: Geeks for Geeks.
```
{% endtab %}
{% endtabs %}

We discussed how to find the running time of binary search recursively, so we can find `T(n)`.

## Dynamic Programming

### Example: Staircase Problem

* We want to consider the last step and then keep thinking backwards.
  * The base case, if the last step is 1 step, then `f(k) = (k-1)`.
  * The other base case, if the last step is 2 steps, then `f(k) = f(k-2)`.
* This is super similar to the Fibonacci number! 

### Example: Our Implementation

```java
//This is the recursive function call
public static long climb (int n){
    //Validate Input

    //There are two ways to climb 2 steps. One at a time or both at once.
    long[] f = new long[n+1];
    f[0] = 0; //Will be used? (If f is -, it will be 0).
    f[1] = 1;
    f[2] = 2;
    
    //Recursive step. 
    for (int i = 3; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    
    return f[??];
```

{% hint style="success" %}
View the video at 0:40 for the full solution.
{% endhint %}

### Example: Rob Police

#### Problem

> A robber plans to rob houses along a street. Adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police. _Source: Dr. Yao's Slides_

#### Recursive Case:

We can assume that we will always rob the k-th house. If so, we can look at two more houses, find the one that makes the most money `f(k) = MAX(f(k-2) + a[k], f(k-1)) `What if we do...?

#### Testing A Small Set

Let's test a small set to see if this will work by passing in the array: `[2, 7, 9, 3, 1].` 

```java
f(k) = MAX(f(k-2) + a[k], f(k-1)):
    f(1) = 2; //Base case.
    f(2) = 7: 
        MAX(f(0) + a[2], f(1));
        AKA(MAX(7,2));
    f(3) = ? MAX(f(1) + 9, f(2)) = MAX(2+9, 7) 1)⇒11
```

{% hint style="success" %}
When we think backwards and test all the cases, we'll find that we found it!
{% endhint %}

## Assignment Notes

### Part 1: Divide & Conquer

* We can solve this in a divide & conquer approach from `O(n)` to` log(n+m).`
* Placeholder.

### Palindrome Problem

* We can think of this like the [longest subsequence problem](lecture-07-dynamic-programming.md#the-longest-common-subsequence-problem).
* We need to know how long the palindrome is; so we can find the length.
* `i` could be the starting index.
* `j` could be the last index. 

#### How to make this recursive?

* Think about the robbing your house problem.
* Modify this program to find the length of the longest palindromic substring.

#### Definition Idea

Consider the array: `[b, a, b, a, d]`.

Let `f(i, j)` be the length of the longest palindromic substring if we consider `s[i, j]`, where `s[i, j]` is the substring of `s` from index `i` to index `j`, inclusively.

`f(0, n-1)` is the solution to our input s. That means that `f(0, 0)` contains no palindromes and is just 1. `f(1, 3)` would return 3.

#### Other ideas from classmates

{% hint style="warning" %}
Below is just a regurgitation. I was hungry and thinking about food, but I can work with this later 🌯
{% endhint %}

* `Max(f(i+1 , j-1) + 2, if s[i] == s[j], len(s[i,j]))` we just need some way to move i and j _(Ian Cannon & Dr. Yao)._
  * The previous problem, `i` will be plus 1.
  * `j-1` on the other side.
  * Len is the length function.

## Works Cited

1. Dr. Zhongmei Yao's [CPS 450 course](http://academic.udayton.edu/zhongmeiyao/450592.html). _(Problems & Solutions)._
2. Geeks for Geeks: Binary Search
