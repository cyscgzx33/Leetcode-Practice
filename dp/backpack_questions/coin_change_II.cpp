class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sz = coins.size();

        // dp[i] means: with amount i, how many different methods are there to come up with
        std::vector<int> dp(amount + 1, 0);

        // init dp[0]: with amount 0, actually one method is to come up with, that is "[]"
        dp[0] = 1;

        // start iterating
        for (int i = 1; i <= sz; i++)
        {
        	for (int j = 1; j <= amount; j++)
        	{
        		if (coins[i-1] < j)
        			continue;
        		dp[j] += dp[ j - coins[i - 1] ];
        	}
        }

        return dp[amount];
    }
};