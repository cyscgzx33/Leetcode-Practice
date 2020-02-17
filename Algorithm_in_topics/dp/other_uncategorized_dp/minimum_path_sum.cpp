#include <vector>

using namespace std;

/* Method 1: m * n sized dp array */
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();

        // dp[i][j] indicates the minimum steps to reach position (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {   
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if (j == 0)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else if (i == 0)
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};

/* Method 2: sliding window with 2 * n sized dp array */
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if (j == 0)
                    dp[i%2][j] = dp[(i-1)%2][j] + grid[i][j];
                else if (i == 0)
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                else
                    dp[i%2][j] = min(dp[i%2][j-1], dp[(i-1)%2][j]) + grid[i][j];
            }
        }

        return dp[(m-1)%2][n-1];
    }
};