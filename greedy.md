# Greedy

## Type 1: Greedy in Array

### LeetCode 1130. Minimum Cost Tree From Leaf Values

Given an array `arr` of positive integers, consider all binary trees such that:

* Each node has either 0 or 2 children;
* The values of `arr` correspond to the values of each **leaf** in an in-order traversal of the tree.  _\(Recall that a node is a leaf if and only if it has 0 children.\)_
* The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

**Example 1:**

```text
Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
```

**Constraints:**

* `2 <= arr.length <= 40`
* `1 <= arr[i] <= 15`
* It is guaranteed that the answer fits into a 32-bit signed integer \(ie. it is less than `2^31`\).

#### Logic:

* Every number `a` in the `arr` will be removed at some time
* Removing `a` will have some cost equals to `a * b`, which depends on `a` and another number `b` that pairs with `a`
* our goal is to minimize the sum of the costs
* we use **greedy** to achieve this goal:
  * choose the smallest `a` in the remaining `arr`
  * find the closest number that is `>= a` on the right side of `a`, same as left side
  * we remove `a` and get a cost `a * min(left, right)`
  * \*how do we prove it? maybe we can use prove by contradiction: by Well Ordering, there must exist a first number that is larger than `a` , or `a` is the largest number in the array
* as we know, a plain algorithm implemented in the way of mentioned above can be slow, we use monotonic stack to speed it up.

```cpp
class Solution {
public:
    /* Method 2: greedy + mono-stack (Time: O(N), Space: O(N)) */
    int mctFromLeafValues(vector<int>& arr) {
        // Logic:
        //   1. every number a in the arr will be removed at some time, 
        //   2. removing a will have some cost = a * b, which depends on a and another number b that pairs with a
        //   3. our goal is to minimize the sum of costs
        //   4. we use greedy to achive this:
        //       (1) choose the smallest a in the arr
        //       (2) find the closest number that is >= a on a's right, same on a's left
        //       (3) we remove a, and get a cost a * min(left, right)
        //       * how to prove it? maybe using contraditionc: by Well Ordering example, there must exsit a first one that is larger than or equal to a, or a is the largest number in the arr
        //   5. as we know, a plain algorithm implemented in the way of 4. can be O(N^2) in time complexity, if we use mono-stack we can further improve it to O(N)
        
        // monotonically decreasing stack:
        //    note: the top element has the closest larger number on its right side when it's "kicked out" by the arr[i], 
        //          and the one on its left side is the next top in the stack
        stack<int> s({0});
        int n = arr.size();
        int res = 0;
        for (int i = 1; i < n; i++) {
            while (s.size() > 0 && arr[s.top()] <= arr[i]) {
                int top = s.top(); s.pop();
                res += s.empty() ? arr[top] * arr[i] : arr[top] * min(arr[i], arr[s.top()]);
            }
            s.push(i);
        }
        
        while (s.size() > 0) {
            int top = s.top(); s.pop();
            res += s.empty() ? 0 : arr[top] * arr[s.top()];
        }
        
        return res;
    }
};
```

