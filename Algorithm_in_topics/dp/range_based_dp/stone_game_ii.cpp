#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame2(vector<int> &A) {
        int n = A.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(2*n, vector<int>(2*n, 0x3f3f3f3f));

        // since it's a circule array, simply double it
        vector<int> A_double;
        A_double.insert(A_double.end(), A.begin(), A.end());
        A_double.insert(A_double.end(), A.begin(), A.end());

        // construct a pfsum array
        vector<int> pfsum(2*n+1, 0);
        for (int i = 0; i < 2*n; i++)
            pfsum[i+1] = pfsum[i] + A_double[i];

        // init dp: dp[i][i] = 0, dp[i][i+1] = sum[i, i+1]
        for (int i = 0; i < 2*n; i++)
            dp[i][i] = 0;
        for (int i = 0; i < 2*n-1; i++)
            dp[i][i+1] = pfsum[i+2] - pfsum[i];

        // dp[i][j] = sum[i, j] + min {i<=k<j} (dp[i][k] + dp[k+1][j])
        // main loop: first l (important: from 2 to n), then i, j, finally k
        int res = 0x3f3f3f3f;
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < 2*n; i++)
            {
                int j = i + l - 1;
                if (j >= 2*n)
                    continue;
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], pfsum[j+1] - pfsum[i] + dp[i][k] + dp[k+1][j]);
                // note: need to analyze res when l == n
                if (l == n)
                    res = min(res, dp[i][j]);
            }
        }

        return res == 0x3f3f3f3f ? 0 : res;
    }
};