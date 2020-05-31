# Dynamic Programming

## Type 1: Simple DP

### LeetCode 1277. Count Square Matrices with All Ones

Given a `m * n` matrix of ones and zeros, return how many **square** submatrices have all ones.

**Example 1:**

```text
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
```

**Example 2:**

```text
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
```

**Constraints:**

* `1 <= arr.length <= 300`
* `1 <= arr[0].length <= 300`
* `0 <= arr[i][j] <= 1`

#### Logic:

* Simply apply dp to loop everything once, take the following picture as the intuition:

![LeetCode 1277 Picture: DP representation](.gitbook/assets/leetcode_1277_pic.jpg)

#### Sample code:

{% code title="count\_square\_submatrices\_with\_all\_ones.sh" %}
```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j];
                else
                {
                    if (matrix[i][j] == 1)
                        dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                }
                res += dp[i][j];
            }
            
        }

        return res;
    }
};
```
{% endcode %}



## Type 2: Two-Sequence

### LeetCode 1143. Longest Common Subsequence

Given two strings `text1` and `text2`, return the length of their longest common subsequence.

A _subsequence_ of a string is a new string generated from the original string with some characters\(can be none\) deleted without changing the relative order of the remaining characters. \(eg, "ace" is a subsequence of "abcde" while "aec" is not\). A _common subsequence_ of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

**Example 1:**

```text
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
```

**Example 2:**

```text
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

**Example 3:**

```text
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

**Constraints:**

* `1 <= text1.length <= 1000`
* `1 <= text2.length <= 1000`
* The input strings consist of lowercase English characters only.

#### Logic:

* Use dynamic programming to describe the matching process
  * `dp[i][j]` represents: within the front `i` letters of `text1`, and front `j` letters of `text2` what is the longest common subsequence
  * with the `dp` definition above, we need to have `m+1` and `n+1` as the size of the `dp` 

{% code title="longest\_common\_subsequence.cpp" %}
```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        
        // dp[i][j]: within the front i letters of text1, and front j letters of text2
        //           what is the longest common subsequence
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
        
        return dp[m][n];
    }
};
```
{% endcode %}

#### Related Problems:

* [Max Dod Product of Two Subsequences](https://leetcode.com/problems/max-dot-product-of-two-subsequences/)
* [Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/)

