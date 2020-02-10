#include <vector>

// M0: brutal force
int brutalForceHelper(std::vector<int>& coins, int amount)
{
	if (amount == 0)
		return 0;

	if (amount < 0)
		return -1;

	int res = INT_MAX;
	for (auto& coin : coins)
	{	
		int candidate = brutalForceHelper(coins, amount - coin);
		if (candidate < 0)
			continue;
		res = std::min(res, candidate);
	}

	return res == INT_MAX ? -1 : res + 1;
}
int coinChange(std::vector<int>& coins, int amount)
{
	return brutalForceHelper(coins, amount);
}