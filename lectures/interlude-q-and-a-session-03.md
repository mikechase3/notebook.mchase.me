# Interlude: Q&A Session 03

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
```
{% endtab %}
{% endtabs %}

We discussed how to find the running time of binary search recursively, so we can find `T(n)`.

## Dynamic Programming

### Staircase Problem

* We want to consider the last step and then keep thinking backwards.
  * The base case, if the last step is 1 step, then `f(k) = (k-1)`.
  * The other base case, if the last step is 2 steps, then `f(k) = f(k-2)`.
* This is super similar to the Fibonacci number! 

### Our Implementation

```java
//This is the recursive function call
public static long climb (int n){
    if (n ≤ 2) return n; //There are two ways to climb 2 steps. One at a time or both at once.
    
```

