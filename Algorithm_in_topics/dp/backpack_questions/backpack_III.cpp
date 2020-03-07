#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        int n = A.size();
        if (n == 0)
            return 0;
        
        // dp[i][w] ==> front i items, with weight w, can form max value
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // initial condition
        // dp[0][w] = 0, dp[i][0] = 0

        // state transition function: dp[i][w] = max{dp[i-1][w-k*Ai-1] + k*Vi-1} (for any w >= k*Ai-1)
        // (it is equivalent to)      dp[i][w] = max(dp[i-1][w], dp[i][w-Ai-1] + Vi-1) (for w >= Ai-1)
        for (int i = 1; i <= n; i++)
        {
            for (int w = 1; w <= m; w++)
            {
                dp[i][w] = dp[i-1][w];
                if (w >= A[i-1])
                    dp[i][w] = max(dp[i][w], dp[i][w-A[i-1]] + V[i-1]);
            }
        }

        return dp[n][m];
    }
};