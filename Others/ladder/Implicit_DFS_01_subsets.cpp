class Solution {
public:
	// Point 1: definition of the recursion
	void dfs(std::vector<int>& nums,
			 int start_index,
			 std::vector<int>& subset,
			 std::vector<std::vector<int>>& subsets) {
		// Point 2: exit of the recursion
		subsets.push_back(subset);

		// Point 3: taking apart the recursion
		for (int i = start_index; i < nums.size(); i++) {
			subset.push_back(nums[i]);
			dfs(nums, i + 1, subset, subsets);
			subset.pop_back();
		}
	}

    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here

        if ( nums.size() == 0) return { {} };

        std::vector<int> subset;
        std::vector<std::vector<int>> subsets;
        dfs();

        return subsets;
    }
};