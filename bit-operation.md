---
description: Puzzles related to bit operation in LeetCode/LintCode
---

# Bit Operation

## Type 1: Bitwise AND \(`&`\)

### LeetCode 231. Power Of Two



Given an integer, write a function to determine if it is a power of two.

**Example 1:**

```text
Input: 1
Output: true 
Explanation: 20 = 1
```

**Example 2:**

```text
Input: 16
Output: true
Explanation: 24 = 16
```

**Example 3:**

```text
Input: 218
Output: false
```

#### **Logic:**

* If `n` is the power of two:
  * `n = 2 ^ 0 = 1 = 0b0000...00000001, and (n - 1) = 0 = 0b0000...0000`
  * `n = 2 ^ 1 = 2 = 0b0000...00000010, and (n - 1) = 1 = 0b0000...0001`
  * `n = 2 ^ 2 = 4 = 0b0000...00000100, and (n - 1) = 3 = 0b0000...0011`
  * `n = 2 ^ 3 = 8 = 0b0000...00001000, and (n - 1) = 7 = 0b0000...0111`
* Thus, for any `n` which is the power of `2` we have: **`n & (n-1) == 0b0000...0000 (== 0)`**
* Otherwise, for any `n` which is not the power of 2, we have: **`n & (n-1) != 0`**
  * For example, `n =14 = 0b0000...1110`, and `(n - 1) = 13 = 0b0000...1101`, we have `n & (n-1) != 0`
* Check [this discuss](https://leetcode.com/problems/power-of-two/discuss/63966/4-different-ways-to-solve-Iterative-Recursive-Bit-operation-Math) note for reference.

#### Sample Code:

{% code title="power\_of\_two.cpp" %}
```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n & (n-1)) == 0);
    }
};
```
{% endcode %}

