/* Method 1: memoized search */

class Solution {
public:
	/* dp[i][j] defines the max output in [i, j] */
	int memoizedSearch(std::vector<int>& nums,
					   std::vector<std::vector<int>>& dp,
					   int start, int end)
	{
		if (dp[start][end] != 0)
			return dp[start][end];

		int max_cost = 0;
		for (int i = start; i <= end; i++)
		{
			int curr = nums[i - 1] * nums[i] * nums[i + 1];
			int left = memoizedSearch(nums, dp, start, i - 1);
			int right = memoizedSearch(nums, dp, i + 1, end);

			max_cost = max(max_cost, curr + left + right);
		}

		dp[start][end] = max_cost;

		return max_cost;

	}

    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
    	std::vector<int> padded_nums(n + 2);
    	padded_nums[0] = 1;
    	padded_nums[n + 1] = 1;
    	for (int i = 1; i <= n; i++)
    		padded_nums[i] = nums[i-1];

    	std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));

    	memoizedSearch(padded_nums, dp, 1, n);

    	return dp[1][n];
    }
};

/* Method 2: explicit DP */
// Technically, it is a so-called "bottom-up" dynamic programming method

class Solution {
public:
	
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
    	std::vector<int> padded_nums(n + 2);
    	padded_nums[0] = 1;
    	padded_nums[n + 1] = 1;
    	for (int i = 1; i <= n; i++)
    		padded_nums[i] = nums[i-1];

    	/* dp[i][j] defines the max output in [i, j] */
    	std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));


    	// length need to vary from 2 to n
    	for (int j = 1; j <= n; j++)
    	{
    		for (int i = j; i >= 1; i--)
    		{
    			int max_cost = 0;
    			// Can k == j? (or k == i?)
    			// Yes. Same as k can equal to i.
                // Because it would give left or right to zero, which is as required,
                // as the padded ballons are not supposed to burst, so it gives 0
    			for (int k = i; k <= j; k++)
    			{
    				int left = dp[i][k-1];
    				int right = dp[k+1][j];
    				int curr = padded_nums[i-1] * padded_nums[k] * padded_nums[j+1];
    				max_cost = max(max_cost, left + right + curr);
    			}

    			dp[i][j] = max_cost;
    		}
    	}

    	return dp[1][n];
    }
};