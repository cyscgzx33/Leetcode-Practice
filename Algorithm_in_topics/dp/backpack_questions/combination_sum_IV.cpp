#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        // Important: totally different than backpack problems!
        /*
         * [Method]
         * 动态规划基础应用。简化成爬楼梯，题目例子[1,2,3], target = 4, 想象成一共4 级楼梯，每次只能爬 1、2、3 级，一共有多少种爬法。
         * DP思路：
         * 1.状态
         * - 最后一步从 (target - num) 开始走，target = 4, num 为 1，2，3
         * - 子问题：target - 1， target - 2， 。。。， target = 0
         * 2.转移方程
         * - dp[i] = sum{for all num in nums && i >= num} ( dp[i-num] )
         * 3.初始条件和边界条件
         * - f[0] = 1
         */

        // dp[i] => with all the nums, how many methods to counts if target = i
        vector<int> dp(target+1, 0);
        // init: dp[0] = 1
        dp[0] = 1;

        // state transition: dp[i] = sum{for all num in nums && i >= num} ( dp[i-num] )
        for (int i = 1; i <= target; i++)
        {
            // loop for every num in nums
            for (auto num : nums)
            {
                if (i >= num)
                dp[i] += dp[i-num];
            }
        }

        return dp[target];
    }
};