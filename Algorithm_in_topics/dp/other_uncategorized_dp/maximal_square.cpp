#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        int m = matrix.size(), n = matrix[0].size();
        // dp[i][j] indicates the maximal sqaure length ending at (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j];
                else
                    dp[i][j] = matrix[i][j] == 1 ? matrix[i][j] + dp[i-1][j-1] : 0;
                res = max(dp[i][j], res);
            }
        }

        return res;
    }
};