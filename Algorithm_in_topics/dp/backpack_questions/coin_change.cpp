/* A full-backpack question */

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount)
    {	
        // dp's physical meaning:
        // dp[i] means, with target amount i, what is the minimum amount of coins to reach
        std::vector<int> dp(amount + 1, amount + 1); // at most, it's amount + 1
        int sz = coins.size();

        // to reach target amount 0, the minimum amount of coins is 0
        dp[0] = 0;
        for (int i = 1; i <= sz; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if ( j < coins[i-1] )
                    continue;
                dp[j] = min(dp[j], dp[ j - coins[i - 1] ] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];

    }
};