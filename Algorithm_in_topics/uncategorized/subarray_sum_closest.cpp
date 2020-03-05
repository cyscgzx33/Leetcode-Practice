#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static bool comp(pair<long, int>& a, pair<long, int>& b)
    {
        return a.first < b.first;
    }
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        vector<pair<long, int>> pfsum(nums.size() + 1, {0, 0});
        pfsum[0].second = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pfsum[i+1].first = pfsum[i].first + nums[i];
            pfsum[i+1].second = i+1;
        }
        
        sort(pfsum.begin(), pfsum.end(), comp);

        int first = 0, second = 0, min_dist = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (fabs(pfsum[i+1].first - pfsum[i].first) < min_dist)
            {
                min_dist = fabs(pfsum[i+1].first - pfsum[i].first);
                second = pfsum[i+1].second;
                first = pfsum[i].second;
            }
        }

        return {first, second};
    }
};