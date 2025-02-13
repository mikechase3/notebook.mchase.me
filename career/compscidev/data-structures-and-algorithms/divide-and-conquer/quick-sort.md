# Quick Sort

### Example: [Quick Sort](https://medium.com/basecs/pivoting-to-understand-quicksort-part-1-75178dfb9313)

* Average is O(n \* log(n))
* Worst case is O(n^2).

```java
class Solution {
  public int[] quicksort(int[] arr) {
    quicksort(arr, 0, arr.length - 1);

    return arr;
  }

  private void quicksort(int[] arr, int left, int right) {
    if (left < right) {
      int pivotFinalRestingPosition = partition(arr, left, right);

      quicksort(arr, left, pivotFinalRestingPosition - 1);
      quicksort(arr, pivotFinalRestingPosition + 1, right);
    }
  }

  /*
   * The partition function that chooses a pivot, partitions the array around the
   * pivot, places the pivot value where it belongs, and then returns the index of
   * where the pivot finally lies
   */
  private int partition(int[] arr, int left, int right) {
    int pivot = arr[right];

    /*
     * i will keep track of the "tail" of the section of items less than the pivot
     * so that at the end we can "sandwich" the pivot between the section less than
     * it and the section greater than it
     */
    int i = left - 1;

    for (int j = left; j < right; j++) {
      if (arr[j] <= pivot) {
        i++;

        swap(arr, i, j);
      }
    }

    swap(arr, i + 1, right);

    return i + 1; // Return the pivot's final resting position
  }

  private void swap(int[] arr, int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
  }
}
```

#### Split Subroutine

* This **splits** the array into roughly two halves around a **pivot**.
  * It figures out where to chop the array.
* The partition subroutine will return this "pivot" value and `split(T[] arr)` will be called on the left and right halves.

#### Partition Subroutine `partition(int arr[])`

* The job is to **choose a pivot**.
* A **pivot** is the value within the partitioning space that I want to find a position for.
  * Take everything less than the pivot to the left.
  * Take everything more than the pivot to the right.
* **I**'s job is to remember the last position that an element was placed in, that was less than the pivot.
* **J's** job is to scan from the left boundary to the right boundary and see what is greater or less than the pivot.

## Analyzing Running Time

When we analyze the running time of recurrence functions, we do so using piecewise functions.

![An example of a piecewise function defining the running time.](../../../../.gitbook/assets/recurrence-function-time-example.jpg)

## Comparing to others

{% embed url="https://www.youtube.com/watch?v=aXXWXz5rF64" %}

{% embed url="https://www.youtube.com/watch?v=es2T6KY45cA" %}

## Quicksort Analysis

