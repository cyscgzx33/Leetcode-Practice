class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        int n = A.size();
        if (n == 0)
            return true;
        std::vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == 0)
                return false;
            for (int j = i + 1; j <= i + A[i] && j < n; j++)
            {
                if (dp[j] == 0)
                    dp[j] = 1;
            }
        }
        return dp[n-1];
    }
};