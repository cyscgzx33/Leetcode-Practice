class Solution {
public:
    
    void dfs(std::vector<int>& nums,
             int start_index,
             std::vector<int>& subset,
             std::vector<std::vector<int>>& subsets)
    {
      subsets.push_back(subset);

      for (int i = start_index; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1] && i > start_index) continue;

        subset.push_back( nums[i] );
        dfs(nums, i + 1, subset, subsets);
        subset.pop_back();
      }
    }
    
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
      // write your code here
      if (nums.size() == 0) return { {} };

      std::sort( nums.begin(), nums.end() );
      std::vector<int> subset;
      std::vector<std::vector<int>> subsets;
      dfs(nums, 0, subset, subsets);

      return subsets;
    }
};