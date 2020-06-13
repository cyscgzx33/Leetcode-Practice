# Two Pointers

## Type 1: Partition

### LeetCode 75. Sort Colors

Given an array with _n_ objects colored red, white or blue, sort them [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) ****so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

**Note:** You are not suppose to use the library's sort function for this problem.

**Example:**

```text
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Follow up:**

* A rather straight forward solution is a two-pass algorithm using counting sort. First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
* Could you come up with a one-pass algorithm using only constant space?

#### Logic:

* Check the picture below

![LC 75. Sort Colors](.gitbook/assets/lc_sort_colors.jpg)

#### Sample Code:

{% code title="sort\_colors.cpp" %}
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int seeker = 0;
        int small_storer = -1, large_storer = n;
        
        while (seeker < large_storer) {
            if (nums[seeker] == 0) {
                swap(nums[++small_storer], nums[seeker++]); // only the small storer can ++, the large storer can not -- 
            } else if (nums[seeker] == 2) {
                swap(nums[--large_storer], nums[seeker]);
            } else seeker++; // if nums[seeker] == 1, do nothing
        }
    }
};
```
{% endcode %}

