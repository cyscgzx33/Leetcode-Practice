class Solution {
public:
    /**
     * @param n: An integer
     * @return: An Integer
     */
    int climbStairs2(int n) {
        // write your code here
        if (n == 0)
        	return 0;
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
        	for (int k = 1; k <= 3; k++)
        	{
        		if (i - k < 0) 
        			continue;
        		else 
        			dp[i] += dp[i - k];
        	}
        }

        return dp[n];
    }
};