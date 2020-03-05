#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        unordered_map<int, int> map;
        vector<int> pfsum(nums.size() + 1, 0);
        map[pfsum[0]] = 0; // starting position

        for (int i = 0; i < nums.size(); i++) // Note: it would be much easier to understand just by writing it in two loops
        {   
            pfsum[i+1] = pfsum[i] + nums[i];
            if (map.count(pfsum[i+1]) == 0)
                map[pfsum[i+1]] = i+1;
            else
                return {map[pfsum[i+1]], i}; // because pfsum[i] indicates the front i nums sum
        }
    }
};