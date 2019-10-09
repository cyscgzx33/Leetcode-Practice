class Solution {
public:
	void dfs(std::vector<int>& candidates,
		     std::vector<int>& comb,
			 std::vector<std::vector<int>>& combs,
			 int start_idx, int target)
	{
		if (target == 0)
		{
			combs.push_back(comb);
			return;
		}

		if (target < 0)
			return;


		for (int i = start_idx; i < candidates.size(); i++)
		{
			comb.push_back( candidates[i] );
			dfs( candidates, comb, combs, i, target - candidates[i] );
			comb.pop_back();
		}
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	std::sort( candidates.begin(), candidates.end() );
    	std::vector<int> comb;
    	std::vector<std::vector<int>> combs;
    	dfs(candidates, comb, combs, 0, target);

    	return combs;
    }
};