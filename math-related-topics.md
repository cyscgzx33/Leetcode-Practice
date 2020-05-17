# Math Related Topics

## Type 1: Factors / GCD

### LintCode 235. Prime Factorization

Prime factorize a given integer.

**Example 1:**

```text
Input: 10
Output: [2, 5]
```

**Example 2:**

```text
Input: 660
Output: [2, 2, 3, 5, 11]
```

#### Logic:

* Simply loop `i` from  `2` to `sqrt(num)`
* Toward the end, the `res` vector shall store one more element, given the condition:
  * `if (res.size() == 0 || res.back() <= target)` or, more straightforward,
  * `if (target > 1)`

#### Sample code:

{% code title="prime\_factorization.cpp" %}
```cpp
class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
        // write your code here
        int target = num;
        
        vector<int> res;
        for (int i = 2; i * i <= target; i++)
        {
            while (target % i == 0)
            {
                target /= i;
                res.push_back(i);
            }
        }
        if (res.size() == 0 || res.back() <= target)
            res.push_back(target);
        
        return res;
    }
};
```
{% endcode %}



