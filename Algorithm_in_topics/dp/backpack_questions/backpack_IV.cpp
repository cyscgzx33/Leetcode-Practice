#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0)
            return 0;

        // Similar to backpack V (from the perspective dp[i][w] meaning)
        // Similar to backpack III (from the perspective of optimizing state transition equation)
        // dp[i][w] ==> front i items, how many methods to fill weight w
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        // initial condition dp[i][0] = 1
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int w = 1; w <= target; w++)
            {
                dp[i][w] = dp[i-1][w];
                if (w >= nums[i-1])
                    dp[i][w] += dp[i][w-nums[i-1]];
            }
        }

        return dp[n][target];
    }
};