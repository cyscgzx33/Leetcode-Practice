#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array
     * @param k: An integer
     * @return: an integer
     */
    int postOffice(vector<int> &A, int k) {
        int n = A.size();
        if (n <= k)
            return 0;

        sort(A.begin(), A.end());

        /**
         * 1. dp[i][j] interprets: building i post-offices within the first j houses
         *                         can result in the minimum steps for each house to reach
         *                         a post-office
         * 2. dp[i][j] = min {0<=x<j, 0<i<=x} ( dp[i-1][x] + min_dist(x, j-1) ):
         *    Idea: split a problem into sub-problems, where min_dist[x][y] gives out the 
         *          minimum step result if only one post-office is built within [x, j]
         * 3. dp[0][j] = INT_MAX, dp[i][0] = 0, dp[i][j] = 0 if i >= j
         */

        // Note: 0x3f3f3f3f is a better choice of 0x1fffffff(INT_MAX)
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0x3f3f3f3f));
        dp[0][0] = 0;

        // Important: prepare a min_dist 2d array
        vector<vector<int>> min_dist(n, vector<int>(n, 0));
        for (int end = 0; end < n; end++)
        {
            for (int start = 0; start <= end; start++)
            {
                // int min_steps = 0;
                int mid_val = A[(start + end) / 2];
                for (int i = start; i <= end; i++)
                    min_dist[start][end] += abs(mid_val - A[i]);
            }
        }

        for (int i = 1; i <= k; i++) // because dp[0][j] = INT_MAX
        {
            for (int j = 0; j <= n; j++)
            {
                if (j <= i)
                {
                    dp[i][j] = 0;
                    continue;
                }
                // int min_step = INT_MAX;
                for (int x = 0; x < j; x++)
                    dp[i][j] = min(dp[i][j], dp[i-1][x] + min_dist[x][j-1]);
            }
        }

        return dp[k][n];
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    vector<int> A = {1, 2, 3, 4, 5};
    cout << sln.postOffice(A, 2) << endl;
    return 0;
}