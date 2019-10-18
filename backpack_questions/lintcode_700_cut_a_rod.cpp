/* 1d DP full backpack*/

class Solution {
public:
    /**
     * @param prices: the prices
     * @param n: the length of rod
     * @return: the max value
     */
    int cutting(vector<int> &prices, int n) {
        // Write your code here
        std::vector<int> dp(n + 1, 0);
        int sz = prices.size();
        for (int i = 1; i <= sz; i++)
        {
        	for (int j = 1; j <= n; j++)
        	{
        		if ( j < i )
        			continue;
        		dp[j] = max( dp[j], dp[ j - i ] + prices[i - 1] );
        	}
        }
        
        return dp[n];
    }
};