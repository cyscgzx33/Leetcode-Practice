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
		int candidate = brutalHelper(coins, amount - coin);
		if (candidate < 0)
			continue;
		res = min(res, candidate);
	}

	return res == INT_MAX ? -1 : res + 1;
}
int coinChange(std::vector<int>& coins, int amount)
{
	return brutalHelper(coins, amount);
}

// M1: memoization search
int memoSearchHelper(std::vector<int>& coins, int amount, std::vector<int>& memo)
{
	if (amount == 0)
		return 0;

	if (amount < 0)
		return -1;

	if (memo[amount] > -2)
		return memo[amount];

	int res = INT_MAX;
	for (auto& coin : coins)
	{	
		int candidate = memoSearchHelper(coins, amount - coin, memo);
		if (candidate < 0)
			continue;
		res = min(res, candidate);
	}

	res = res == INT_MAX ? -1 : res + 1;
	memo[amount] = res;
	return res;
}
int coinChange(std::vector<int>& coins, int amount)
{	
	std::vector<int> memo(amount + 1, -2); // -2 means haven't reached yet
										   // -1 means not feasible at the position
	return memoSearchHelper(coins, amount, memo);
}