/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <stack>
#include <vector>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer,
    // rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds,
    // if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds,
    // if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// method 1: using iterator to loop the given nestedList (a little bit align with jiuzhang video method)
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        stack<vector<NestedInteger>::const_reverse_iterator> stk; // 注意因为getList（） 返回的是const & 所以iterator必须是const iterator，

        for (auto it = nestedList.rbegin(); it != nestedList.rend(); it++) // now it is const_reverse_iterator (a reverse-direction iterator) of std::vector<NestedInteger>
                                                                           // auto <=> vector<NestedInteger>::const_reverse_iterator
            stk.push(it);
        
        vector<int> res;
        while (stk.size() > 0)
        {
            auto cur = stk.top();
            stk.pop();

            if (cur->isInteger())
                res.push_back(cur->getInteger());
            else
            {
                const vector<NestedInteger>& cur_list = cur->getList();
                for (auto it = cur_list.rbegin(); it != cur_list.rend(); it++)
                    stk.push(it);
            }
        }

        return res;
    }
};

// method 2: just read each instance of the given nestedList instead of using iterator