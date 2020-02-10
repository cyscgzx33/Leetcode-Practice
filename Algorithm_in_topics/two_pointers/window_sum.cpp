class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
        if (nums.size() == 0)
            return {};
        
        int front = 0, back = 0;
        int n = nums.size();
        int tmp_sum = 0;
        for (int i = 0; i < k; i++)
            tmp_sum += nums[i];
            
        std::vector<int> sums(n - k + 1, 0);
        sums[0] = tmp_sum;
        for (int i = 1; i < n - k + 1; i++)
            sums[i] = sums[i - 1] + nums[i + k - 1] - nums[i - 1];
        
        
        return sums;
    }
};