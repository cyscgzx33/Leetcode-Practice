/* Method 1: using multiset and lower_bound, TC: O(N*logK) */

class Solution {
public:
    /**
     * @param nums: the given array
     * @param k: the given k
     * @param t: the given t
     * @return: whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
     */
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        // Write your code here
        multiset<int> buffer;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (buffer.size() >= k)
                buffer.erase(buffer.find(nums[i-k]));
            buffer.insert(nums[i]);
            
            auto lb = buffer.lower_bound(nums[i+1]);

            // find the right side closest number
            if (lb != buffer.end() && *lb - nums[i+1] <= t)
                return true;

            // find the left side closest number
            if (lb != buffer.begin() && nums[i+1] - *--lb <= t)
                return true;
        }
        
        return false;
    }
};