class Solution {
public:

	void dfs(int target, 
		     std::vector<int>& result,
		     std::vector<std::vector<int>>& results)
	{
		// exit criteria
		if (target == 1)
			results.push_back(result);

		for (int i = 2; i <= n / 2; i++)
		{
			int next_target = target / i;
			if ( i * next_target != target )
				continue;

			result.push_back(i);
			dfs(next_target, result, results);
			result.pop_back();
		}
	}

    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here
        std::vector<int> result;
        std::vector<std::vector<int>> results;

        dfs(n, result, results);

        return results;
    }
};