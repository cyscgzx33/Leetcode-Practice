class Solution {
public:
    /**
     * @param A: a integer array A,
     * @return: Return true if and only if after such a move
     */
    bool splitArraySameAverage(vector<int> &A) {
        int len_A = A.size(), len_A_half = A.size() / 2;
        int sum_A = std::accumulate( A.begin(), A.end(), 0 );
        bool isSplit = false;
        for (int i = 1; i <= len_A_half && isSplit == false; i++)
        {
            if (sum_A * i % len_A == 0)
                isSplit = true;
        }
        if (isSplit == false)
            return false;

        // dp[i] stands for randomly pick i numbers in A, all the possible sums
        std::vector<std::unordered_set<int>> dp(len_A_half + 1);
        dp[0].insert(0);
        for (auto num : A)
        {
            for (int i = len_A_half; i >= 1; i--)
            {
                for (auto elem : dp[i - 1]) 
                {
                    dp[i].insert(num + elem);
                }
            }
        }

        for (int i = 1; i <= len_A_half; i++)
        {
            if (sum_A * i % len_A == 0 && dp[i].count(sum_A * i / len_A) > 0)
                return true;
        }  

        return false;
    }
};