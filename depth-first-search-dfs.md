# Depth-First-Search \(DFS\)

## Type 1: Classic DFS

### LintCode 570. Find the Missing Number II

Giving a string with number from 1-`n` in random order, but miss `1` number.Find that number.

n &lt;= 30  
Data guarantees have only one solutionHave you met this question in a real interview?  YesProblem Correction

#### Example

**Example1**

```text
Input: n = 20 and str = 19201234567891011121314151618
Output: 17
Explanation:
19'20'1'2'3'4'5'6'7'8'9'10'11'12'13'14'15'16'18
```

**Example2**

```text
Input: n = 6 and str = 56412
Output: 3
Explanation:
5'6'4'1'2
```

#### Logic:

* DFS classic question, need to apply several techniques of cutting branches
* Refer to [this page](https://www.jiuzhang.com/solution/find-the-missing-number-ii/) for detailed solution

#### Sample Code:

{% code title="find\_the\_missing\_number\_ii.cpp" %}
```cpp
class Solution {
public:
    /**
     * @param n: indicating numbers range [1, n] with a missing number
     * @param str: the given string
     * @param cnt: number of found numbers
     * @param pos: iterating position @ str
     * @param visit: all visited nums within [1, n]
     * @return: the missing number; -1 if invalid output
     */
    int dfs(int n, string& str, int cnt, int pos, vector<int>& visit) {
        // stop criteria
        if (cnt == n - 1 && pos == str.length()) {
            // cout << "hello!!!\n";
            int res = -1;
            for (int i = 1; i <= n; i++) {
                if (visit[i] == 0) return i;
            }
            // if all the visit[i] == 1, invalid
            return -1;
        }

        // cutting branches
        int rest_num  = n - 1 - cnt;
        int rest_char = str.length() - pos;
        if (rest_char < rest_num || rest_char > rest_num * 2 || str[pos] == '0') { 
            // the rest nums of char is smaller than rest nums of uncounted numbers, OR
            // the rest nums of char is larger than twice of rest nums of uncounted numbers
            // invalid number starting from digit '0'
            return -1;
        }
        
        // two options to expand: 1 digit & 2 digits
        int curr_num = 0;
        for (int num_dgt = 0; num_dgt <= 1; num_dgt++) {
            curr_num = curr_num * 10 + str[pos+num_dgt] - '0';
            if (curr_num >= 1 && curr_num <= n && visit[curr_num] == 0) {
                visit[curr_num] = 1;
                int ans = dfs(n, str, cnt+1, pos+num_dgt+1, visit);
                if (ans > 0) return ans;
                visit[curr_num] = 0;
            }
        }

        // in the end, if nothing found...
        return -1;
    }

    /**
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    int findMissing2(int n, string &str) {
        // write your code here
        vector<int> visit(n+1, 0);
        return dfs(n, str, 0, 0, visit);
    }
};
```
{% endcode %}

