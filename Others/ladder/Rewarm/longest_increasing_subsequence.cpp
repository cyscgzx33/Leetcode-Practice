class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    // TC(N^1.5)
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0)
            return 0;
        
        int n = nums.size();
        std::vector<int> dp; // stores fake LIS

        for (int i = 0; i < n; i++)
        {
            auto it = std::lower_bound(dp.begin(), dp.end(), nums[i]);
            if ( it == dp.end() )
                dp.push_back( nums[i] );
            else
                *it = nums[i]
        }

        return dp.size();
    }
};

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    // TC(N^2), with exact LIS printed out
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0)
            return 0;
        
        int n = nums.size();
        std::vector<int> dp(n, 1);
        std::vector<int> parents(n, -1);
        int max_idx = 0, max_len = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parents[i] = j;
                }
            }

            if (dp[i] > max_len)
            {
                max_len = dp[i];
                max_idx = i;
            }
        }

        std::vector<int> LIS;
        int cur_idx = max_idx;
        for (int i = 0; i < max_len; i++)
        {
            LIS.push_back( nums[cur_idx] );
            cur_idx = parents[cur_idx];
        }

        std::cout << "LIS = ";
        for (auto& ele : LIS)
            std::cout << ele << ", ";
        std::cout << std::endl;

        return LIS.size();
    }
};