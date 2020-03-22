/* Method 2: using unordered_map and bucket sort (check jiuzhang solution), TC: O(N) */
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: the given array
     * @param k: the given k
     * @param t: the given t
     * @return: whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
     */
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        int bucket_size = t + 1;           // use some examples to help understand
        unordered_map<int, int> bucket;    // key: bucket id that nums belong to, val: nums value
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (bucket.size() >= k)
                bucket.erase(bucket.find(nums[i-k]/bucket_size));
            bucket[nums[i]/bucket_size] = nums[i];
            
            int cur_id = nums[i+1] / bucket_size;
            
            if (bucket.count(cur_id) == 1) // there's a same item staying the same bucket, must be less than t distance
                return true;

            if (bucket.count(cur_id - 1) == 1 && abs(bucket[cur_id-1] - nums[i+1]) <= t)
                return true;
            
            if (bucket.count(cur_id + 1) == 1 && abs(bucket[cur_id+1] - nums[i+1]) <= t)
                return true;
        }

        return false;
    }
};