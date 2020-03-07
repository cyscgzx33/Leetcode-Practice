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

    /*
    最后一步:最后一个数An-1是否选入这K个数
    • 状态:f[i][k][s]表示有多少种方法可以在前i个数中选出k个,
            使得它们的和是s
    • 转移方程:f[i][k][s] = f[i-1][k][s] + f[i-1][k-1][s-Ai-1]|k>=1 
                    AND s>=Ai-1
    • 初始条件:
    – f[0][0][0] = 1
    – f[0][0][s] = 0, s = 1, 2, ..., Target
    • 计算顺序:
    – f[0][0~K][0~Target]
    – ...
    – f[N][0~K][0~Target]
    • 时间复杂度O(N*K*Target),空间复杂度O(N*K*Target),
    可以用滚动数组优化至O(K*Target)
     */

    int kSum(vector<int> &A, int k, int target) {
        int n = A.size();
        if (n == 0)
            return 0;
        // dp[i][m][j] ==> in the front i items of A,  how many solutions to use m number to form j
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(target+1, 0)));
        // initial & boundary condition: front 0 item, use 0 number to form ans 0, there is 1 solution ==> dp[0][0][0] = 1
        // other than ans 0, dp[0][0][1~target] = 0
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