class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here

    	if (m == 0 || n == 0)
    		return 0;

        std::vector<std::vector<int>> dp(2, std::vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
        	for (int j = 0; j < n; j++)
        	{
        		if (i == 0 || j == 0)
        			dp[i % 2][j] = 1;
        		else 
        			dp[i % 2][j] = dp[(i - 1) % 2][j] + dp[i % 2][j - 1];
        	}
        }

        return dp[(m - 1) % 2][n - 1];
    }
};