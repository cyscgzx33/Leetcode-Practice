int coinChange(std::vector<int> coins, int amount)
{
	std::vector<int> dp(amount + 1, amount + 1);
	dp[0] = 0;

	for (int = 1; i <= amount; i++)
	{
		for (auto coin : coins)
		{
			if (i < coin)
				continue;
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}

	return dp[amount] == amount + 1 ? -1 : dp[amount];
}

class Solution {
public:
    // M2: Bottom-up DP
    int coinChange(std::vector<int>& coins, int amount)
    {	
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (auto& coin : coins)
            {
                if (i - coin < 0)
                    continue;
                dp[i] = min( dp[i], 1 + dp[i - coin] );
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};