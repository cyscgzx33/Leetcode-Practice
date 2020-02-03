class Solution {
public:

	// Point 1: definition of the recursion
	void dfs(std::vector<int>& nums,
		     std::vector<bool>& is_visited,
		     std::vector<int>& permutation,
		     std::vector<std::vector<int>>& permutations) {

		// Point 2: exit of the recursion
		if ( permutation.size() == nums.size() ) {
			permutations.push_back(permutation);
			return;
		}

		// Point 3: taking apart the recursion
		for (int i = 0; i < nums.size(); i++) {
			if (is_visited[i]) continue;

			// Step I: eg: [] => [1]
			is_visited[i] = true;
			permutation.push_back( nums[i] );
			dfs(nums, is_visited, permutation, permutations);
			// Step II: eg [1] => [] 
			// which is BACKTRACK
			permutation.pop_back();
			is_visited[i] = false;
		}


	}

    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here

        if ( nums.size() == 0) return std::vector<std::vector<int>>{ {} };

        std::vector<bool> is_visited(nums.size(), false);
        std::vector<int> permutation;
        std::vector<std::vector<int>> permutations;

        dfs(nums, is_visited, permutation, permutations);

        return permutations;
    }
};