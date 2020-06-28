# Programming Assignments

## The Assignment

Details can be found on Dr. Yao's Isidore page. _\(It's not really mine so I can't share it here, but I've shared my work\)._

## Longest Palindrome Substring

* Here is the [Leetcode](https://leetcode.com/problems/longest-palindromic-substring/submissions/) challenge

If you google around on Leetcode, you'll find something really similar to the project. 

```python
# Michael Chase
# Jun 22, 2020
# Bugs: None found.
# Purpose: take a string and return the longest palendrome within that string.

class Longest_Palindrome:
    # Takes a string and returns the longest palendrome.
    def longestPalindrome(self, s: str):

        # Member Variables
        substring: str = ""
        length_of_substring: int = 0
        LENGTH = len(s)

        for index in range(0, LENGTH): #Leftmost ⇒
            tempString1 = self.cat_wisker(s, index, index) # Move L/R from just one index
            tempString2 = self.cat_wisker(s, index, index + 1) # Move L/R from both indexes
            longestTempString: str

            if (len(tempString1) > len(tempString2)):
                longestTempString = tempString1
            else: # If they're equal or the 2nd one is larger. Warning: Just picks one...
                longestTempString = tempString2

            # Compare the stuff to the original.
            if len(longestTempString) > length_of_substring:
                substring = longestTempString
                length_of_substring = len(longestTempString)

        return substring


    def cat_wisker(self, s, leftMostIndex, rightMostIndex): #Go to the middle center of the substring and work outwards.
        #Check if left & right are equal. If they are, we're going to view the left/right.
        returnString = ""
        LENGTH = len(s)

        while(leftMostIndex >= 0 and rightMostIndex < LENGTH and s[leftMostIndex] is s[rightMostIndex]):
            if leftMostIndex == rightMostIndex:
                returnString = s[leftMostIndex]
            else:
                returnString = s[leftMostIndex] + returnString + s[rightMostIndex] # mostLeft + existing + mostRight
            leftMostIndex -= 1 # move indexes
            rightMostIndex +=1
        return returnString

# Test Code
name = "helloworldiamthelovelymichaelchasebananas"
print(Longest_Palindrome().longestPalindrome(name))
```

![Stats for my submission.](../../.gitbook/assets/image%20%2829%29.png)

## Median of Two Sorted Arrays

![](../../.gitbook/assets/image%20%2831%29.png)

* See the Leet challenge [here](https://leetcode.com/problems/median-of-two-sorted-arrays/)!
* There is an amazing article that shares the approach [here](https://medium.com/@hazemu/finding-the-median-of-2-sorted-arrays-in-logarithmic-time-1d3f2ecbeb46)! I highly recommend reading it; I could not have done this assignment without it. 
* See Dr. Yao's assignment sheet on Isidore for more instructions and hints.

```python
# Michael Chase
# Jun 22, 2020
# Bugs: None found.
# Purpose: This function finds the medium given two sorted arrays. Returns a float.

# This function finds the medium given two sorted arrays. Returns a float.
def find_median_of_two_sorted_arrays(a, b) -> float:
    a_length: int = len(a)
    b_length: int = len(b)
    median: int = 0;
    left_pointer: int = 0;
    right_pointer: int = 0;
    min_index: int = 0
    max_index: int = a_length

    while min_index <= max_index:

        # Specify the location in the subarray for the pointers.
        left_pointer = int((min_index + max_index) / 2)
        right_pointer = int(((a_length + b_length + 1) / 2) - left_pointer)

        # We have to check the pointers are > 0 or else we'd get null pointers... or actually it'd wrap
        # around because this isn't java, but that would still be bad. Avoid checking empty sets.
        if (left_pointer < a_length and right_pointer > 0 and b[right_pointer - 1] > a[left_pointer]):
            min_index = left_pointer + 1
        elif (left_pointer > 0 and right_pointer < b_length and b[right_pointer] < a[left_pointer - 1]):
            max_index = left_pointer - 1

        # We found the halves woot woot!
        else:
            # No elements in the first half from a[].
            if left_pointer == 0:
                median = b[right_pointer - 1]

            # No elements in the first half from b[].
            elif (right_pointer == 0):
                median = a[left_pointer - 1]
            else:
                median = findMax(a[left_pointer - 1], b[right_pointer - 1])
            break

    # Now calculate the median
    if ((a_length + b_length) % 2 == 1): #If odd, it's easy.
        return median

    # If it's even...
    if (left_pointer == a_length):
        return float((median + b[right_pointer]) / 2)

    if (right_pointer == b_length):
        return float((median + a[left_pointer]))

    return float((median + findMin(a[left_pointer], b[right_pointer])))


# Returns the maximum, given two values.
def findMax(a, b):
    return a if a > b else b  # Well fun fact, there's a max() function that just returns two values. Oops.


# Returns the smaller of two values.
def findMin(a, b):
    return a if a < b else b  # Fun fact of the day 2: There's a min() function. Oops #2.


# Test Code
a = [1, 2, 3, 4, 5, 6, 7, 8, 9]
b = [1, 1, 1, 1, 6, 9]



# Call Test Code: It's faster if the smaller array is the 1st parameter.
if (len(a) < len(b)):
    print("Median: " + str(find_median_of_two_sorted_arrays(a, b)))
else:
    print("Median: " + str(find_median_of_two_sorted_arrays(b, a)))

```

## Works Cited

| Title | Content Used | Author |
| :--- | :--- | :--- |
| \_\_[_Finding the Median of 2 Sorted Arrays in Logarithmic Time_](https://medium.com/@hazemu/finding-the-median-of-2-sorted-arrays-in-logarithmic-time-1d3f2ecbeb46) | Picture | "[hamid](https://medium.com/@hazemu?source=post_page-----1d3f2ecbeb46----------------------)" |
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/submissions/) | None really. | Leetcode |



