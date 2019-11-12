class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */

	// TC(NlogN)
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here

    	std::vector<int> dp; // a fake LIS that shares the same size as a true one
        for (auto& num : nums)
        {
        	auto it = std::lower_bound(dp.begin(), dp.end(), num);
        	if ( it != dp.end() )
        		*it = num;
        	else
        		dp.push_back(num);
        }

        return dp.size();
    }

    // TC(N^2)
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0)
        	return 0;
        int n = nums.size();
    	std::vector<int> dp(n, 1); // dp[i]: LIS value ending with current idx i

    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < i; j++)
    		{
    			if (nums[j] < nums[i] && dp[i] < dp[j] + 1)
    				dp[i] = dp[j] + 1;
    		}
    	}

    	int LIS = 0;
    	for (auto d : dp)
    		LIS = d > LIS ? d : LIS;

    	return LIS;
    }

};