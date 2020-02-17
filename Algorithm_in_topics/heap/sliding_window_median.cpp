#include <vector>
#include <set>

using namespace std;

/** 
 * [Important question] why do we have to use multiset here instead of heap/priority_queue?
 *      Reasons: 1. it can delete a given element ( TC: O(logN) )
 *               2. it can contain more than one single elements (while set cannot do that)
 * 
 * [Important note] when erasing something in multiset, don't just erase the val itself but use an iterator
 *                  because multiset.erase(int val) will erase all the multiple elements equal to val,
 *                  while using an iterator will only erase one of them
 */

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        if (nums.size() == 0 || nums.size() < k)
            return {};

        int n = nums.size();
        multiset<int> min_h, max_h;

        // firstly insert the front k elements
        for (int i = 0; i < k; i++)
            max_h.insert(nums[i]);
        
        // secondly balance two multisets
        for (int i = 0; i < k/2; i++)
        {
            min_h.insert(*max_h.rbegin());
            max_h.erase( max_h.find(*max_h.rbegin()) );
        }

        // thirdly, loop the rest of the array
        vector<int> res;
        res.push_back(*max_h.rbegin());
        for (int i = k; i < n; i++)
        {   
            // firstly erase the front element in the window
            if (max_h.find(nums[i-k]) != max_h.end())
                max_h.erase(max_h.find(nums[i-k]));
            else
                min_h.erase(min_h.find(nums[i-k]));

            // secondly insert the next element
            if (max_h.size() <= min_h.size())
                max_h.insert(nums[i]);
            else
                min_h.insert(nums[i]);

            // thirdly balance the two multisets by SWAPPING elements if necessary
            if (max_h.size() > 0 && min_h.size() > 0 && *max_h.rbegin() > *min_h.begin()) // must check if empty or not!!!!!
            {
                min_h.insert(*max_h.rbegin());
                max_h.insert(*min_h.begin());
                min_h.erase(min_h.begin());
                max_h.erase(max_h.find(*max_h.rbegin()));
            }

            // fourthly, process the res
            res.push_back(*max_h.rbegin());
        }

        return res;
    }
};