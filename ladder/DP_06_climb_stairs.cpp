class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n == 0)
    		return 0
    	std::vector<int> dp(n, 0);
    	dp[0] = 1;
    	dp[1] = 1;

    	for (int i = 2; i < n; i++)
    		dp[i] = dp[i-1] + dp[i-2];

    	return dp.back();
    }

    // method 2: sliding array
    int climbStairs(int n)
    {
    	if (n == 0)
    		return 0;
    	std::vector<int> dp(3, 0);
    	dp[0] = 1;
    	dp[1] = 2;

    	for (int i = 2; i < n; i++)
    		dp[i % 3] = dp[(i-1) % 3] + dp[(i-2) % 3]; 

    	return dp[(n - 1) % 3];
    }

    // method 3: unified methods with climbing stairs II
    int climbStairs(int n)
    {
    	if (n == 0)
    		return 0;
    	std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
        	for (int k = 1; k <= 2; k++)
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