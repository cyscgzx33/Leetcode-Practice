# Binary Index Tree \(BIT\)

## Type 1: BIT Working as Counter 

### LeetCode 60. Permutation Sequence

The set `[1,2,3,...,`_`n`_`]` contains a total of _n_! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for _n_ = 3:

1. `"123"`
2. `"132"`
3. `"213"`
4. `"231"`
5. `"312"`
6. `"321"`

Given _n_ and _k_, return the _k_th permutation sequence.

**Note:**

* Given _n_ will be between 1 and 9 inclusive.
* Given _k_ will be between 1 and _n_! inclusive.

**Example 1:**

```text
Input: n = 3, k = 3
Output: "213"
```

**Example 2:**

```text
Input: n = 4, k = 9
Output: "2314"
```

**Logic:**

* Check[ this website](https://zh.wikipedia.org/wiki/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80) for algorithm of calculation `k`'th permutation
* Use **BIT** and **binary search** to find out the `rank`'th available spot, where there are two core functions in regular BIT algorithm:
  * `void update(int x, int v, int n);`
  * `int getSum(int x);`

#### Sample Code:

{% code title="permutation\_sequence.cpp" %}
```cpp
class Solution {
private:
    vector<int> BIT;
    int getFactorial(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++) res *= i;
        return res;
    }
    /**
     * param x: change freq value @ target position x
     * param v: value change @ position x 
     * param n: total nodes number n
     */
    void update(int x, int v, int n) {
        for (int i = x; i <= n; i += (i&-i)) {
            BIT[i] += v;
        }
    }
    int getSum(int x) {
        int sum = 0;
        for (int i = x; i > 0; i -= (i&-i)) {
            sum += BIT[i];
        }
        return sum;
    }
public:
    string getPermutation(int n, int k) {
        // construct BIT (binary index tree) for later use
        BIT.assign(n+1, 0); // note: BIT[0] will not be used
        for (int i = 1; i <= n; i++) update(i, 1, n);

        // refer to https://zh.wikipedia.org/wiki/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80
        int target = k - 1;
        string res = "";
        for (int i = n-1; i >= 0; i--) { // why i ending at 0: beacuse finally, we have to process the last digit
            int i_fac = getFactorial(i);
            int rank = target / i_fac + 1; // there are target / i_fac numbers that are smaller than current digit, so + 1 is the actual rank
            target %= i_fac;
            // use binary search and BIT to obtain the rank'th available number
            int l = 1, r = n;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (getSum(mid) < rank) l = mid;
                else r = mid;
            }
            char add_on = '0';
            if (getSum(l) == rank) {
                update(l, -1, n);
                add_on += l;
            } else {
                update(r, -1, n);
                add_on += r;
            }
            res.push_back(add_on);
        }

        return res;
    }
};
```
{% endcode %}

