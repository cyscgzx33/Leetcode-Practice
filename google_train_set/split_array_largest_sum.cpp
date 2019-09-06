class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long n = nums.size();
        
        // define dp[i][j] as: 
        // within nums[0, ..., i] taken into j parts, what is the answer
        // thus, it needs +1 for both sides naturally
        std::vector<std::vector<long>> dp( n + 1, std::vector<long>(m + 1, LONG_MAX) );
        std::vector<long> pf_sums(n + 1, 0);
        // start iteration
        for (int i = 0; i < n; i++)
            pf_sums[i + 1] = pf_sums[i] + nums[i];
        // init dp
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 0; k < i; k++)
                    dp[i][j] = min( dp[i][j], max( dp[k][j - 1], pf_sums[i] - pf_sums[k] ) );
            }
        }

        return int(dp[n][m]);
    }
};

// solution
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long>> f(n + 1, vector<long>(m + 1, INT_MAX));
        vector<long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return f[n][m];
    }
};

/*
    Approach #2 Dynamic Programming [Accepted]
    [Intuition]

    The problem satisfies the non-aftereffect property. We can try to use dynamic programming to solve it.

    The non-aftereffect property means, once the state of a certain stage is determined, it is not affected by the state in the future. 
    In this problem, if we get the largest subarray sum for splitting nums[0..i) into j parts, this value will not be affected by how 
    we split the remaining part of nums.

    To know more about non-aftereffect property, this link may be helpful : http://www.programering.com/a/MDOzUzMwATM.html

    [Algorithm]

    Let's define f[i][j] to be the minimum largest subarray sum for splitting nums[0..i) into j parts.

    Consider the jth subarray. We can split the array from a smaller index k to i to form it. Thus f[i][j] can be derived from 
    max(f[k][j - 1], nums[k + 1] + ... + nums[i]). For all valid index k, f[i][j] should choose the minimum value of the above formula.

    The final answer should be f[n][m], where n is the size of the array.

    For corner situations, all the invalid f[i][j] should be assigned with INFINITY, and f[0][0] should be initialized with 0.
*/