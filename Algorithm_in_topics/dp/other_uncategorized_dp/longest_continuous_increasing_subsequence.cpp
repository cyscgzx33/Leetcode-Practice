#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n == 0)
            return 0;
        
        // dp[i] indicates the longest continuous increasing subsequence (from left to right) ending @ i
        vector<int> dp(n, 1);

        // firstly loop from left to right
        int res = 1;
        for (int i = 1; i < n; i++)
        {
            if (A[i] <= A[i-1])
                continue;
            
            dp[i] = dp[i-1] + 1;
            res = max(res, dp[i]);
        }

        // secondly loop from right to left
        dp.assign(n, 1);
        for (int i = n-2; i >= 0; i--)
        {
            if (A[i] <= A[i+1])
                continue;
            dp[i] = dp[i+1] + 1;
            res = max(res, dp[i]);
        }

        return res;
    }
};