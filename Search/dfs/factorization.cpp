class Solution {
public:
    void dfs(int target,
             int start_factor,
             std::vector<int>& result,
             std::vector<std::vector<int>>& results)
    {
        if (result.size() > 0)
        {
            result.push_back(target);
            results.push_back(result);
            result.pop_back();
        }

        for (int i = start_factor; i < target; i++)
        {
            if (i > target / i)
                return;
            if (target % i != 0)
                continue;

            int next_target = target / i;
            result.push_back(i);
            dfs(next_target, i, result, results);
            result.pop_back();
        }
    } 
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        std::vector<int> result;
        std::vector<std::vector<int>> results;

        dfs(n, 2, result, results);

        return results;
    }
};