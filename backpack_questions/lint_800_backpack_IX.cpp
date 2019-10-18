class Solution {
public:
    /**
     * @param n: Your money
     * @param prices: Cost of each university application
     * @param probability: Probability of getting the University's offer
     * @return: the  highest probability
     */
    double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
        // write your code here
        int sz = prices.size();
        std::vector<std::vector<double>> dp( sz, std::vector<double>(n, 0.0) );

        for (int i = 1; i <= sz; i++)
        {
        	for (int j = 1; j <= n; j++)
        	{
        		if ( j < prices[i - 1] )
        			dp[i][j] = dp[i - 1][j];
        		else
        			dp[i][j] = max(dp[i - 1], 1 - (1 - dp[i - 1][j - cost[i - 1]]) * (1 - probability[i - 1]) );
        	}
        }

        return dp[sz][n];
    }
};