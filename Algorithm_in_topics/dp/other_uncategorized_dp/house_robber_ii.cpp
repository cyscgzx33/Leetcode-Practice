#include<vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        if (n == 3)
            return max(max(nums[0], nums[1]), nums[2]);

        vector<int> dp1(n-1, 0);
        vector<int> dp2(n-1, 0);
        dp1[0] = nums[0]; dp1[1] = max(nums[0], nums[1]);
        dp2[0] = nums[1]; dp2[1] = max(nums[1], nums[2]);

        for (int i = 2; i < n - 1; i++)
        {
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i+1]);
        }

        return max(dp1[n-2], dp2[n-2]);
    }
};