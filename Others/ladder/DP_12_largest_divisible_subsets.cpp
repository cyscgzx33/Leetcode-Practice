class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // write your code here

        /**
         * [Description]
         * 1. dp[i] represents the largest divisible sets length ending with nums[i]
         * 2. parents[i] represents the last divisible position
         * 3. mx is the largest set length
         * 4. mx_idx is the largest set starting position
         * */
        sort( nums.begin(), nums.end() );
        std::vector<int> dp(nums.size(), 1), parents(nums.size(), -1), res;
        int mx = 0, mx_idx = 0;

        for (int i = 0; i < nums.size(); i++)
        {
        	for (int j = 0; j < i; j++)
        	{
        		if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
        		{
        			dp[i] = dp[j] + 1;
        			parents[i] = j;
        		}
        	}

        	if (dp[i] >= mx)
        	{
        		mx = dp[i];
        		mx_idx = i;
        	}
        }

        for (int i = 0; i < mx; i++)
        {
        	res.push_back(nums[mx_idx]);
        	mx_idx = parents[mx_idx];
        }

        return res;
    }
};