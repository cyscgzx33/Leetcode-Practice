class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int n = nums.size();
        std::vector<int> pfsum(n + 1, 0);

        // construct the prefix-sum array, pfsum
        for (int i = 0; i < n; i++)
        	pfsum[i+1] = pfsum[i] + nums[i];

        int r = 0, l = 0;
        int min_len = INT_MAX;
        for (r; r < n; r++)
        {
        	// move the l pointer to find the right-most "good" position
        	while (l < r && pfsum[r+1] - pfsum[l] >= s && pfsum[r+1] - pfsum[l+1] >= s)
        		l++;

        	// update the min_len
        	if (pfsum[r+1] - pfsum[l] >= s)
        		min_len = min(min_len, r - l + 1);
        }

        return min_len == INT_MAX ? -1 : min_len;
    }
};