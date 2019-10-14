class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        int sz = nums.size();
        
        /* dp[i][j] means if we have i objects and we want to fill out j space, how many options we have */
        // init with first element equals to 1
        // becuase 0~N object(s) can have 0 space, then total options equal to 1
        std::vector<int> row(target + 1, 0);
        row[0] = 1;
        std::vector<std::vector<int>> dp(sz + 1, row);

        for (int i = 1; i <= sz; i++)
        {
        	for (int j = 1; j <= target; j++)
        	{
        		if ( j < nums[i - 1] )
        			dp[i][j] = dp[i - 1][j];
        		else
        			dp[i][j] = dp[i - 1][j] + dp[i - 1][ j - nums[i - 1] ];
        	}
        }

        return dp[sz][target];
    }
};