#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here

        int n = A.size();
        if (n == 0)
            return 0;
        // dp[i][m][j] ==> in the front i items of A,  how many solutions to use m number to form j
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(target+1, 0)));
        // initial & boundary condition
        dp[0][0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int m = 0; m <= k; m++)
            {
                for (int j = 0; j <= target; j++)
                {
                    dp[i][m][j] = dp[i-1][m][j]; // doesn't take A[i-1]
                    if (m >= 1 && j-A[i-1] >= 0) // take A[i-1]
                        dp[i][m][j] += dp[i-1][m-1][j-A[i-1]];
                }
            }
        }

        return dp[n][k][target];
    }
};