#include <vector>

using namespace std;

/* Method 1: 3d basic, time complexity (O(N^3*K) */
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1) != 0)
            return -1;

        vector<int> pfsum(n+1, 0);
        for (int i = 0; i < n; i++)
            pfsum[i+1] = pfsum[i] + stones[i];

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K+1, 0x3f3f3f3f)));
        for (int i = 0; i < n; i++)
            dp[i][i][1] = 0;

        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + l - 1;
                if (j >= n)
                    continue;
                for (int p = 2; p <= K; p++) // at least 2 piles
                {
                    for (int m = i; m < j; m++)
                        dp[i][j][p] = min(dp[i][j][p], dp[i][m][1] + dp[m+1][j][p-1]); // only divide/patition, no merge
                                                                                       // Reason why partition the left side into 1: 
                                                                                       // because any other number can be shrinked to 1, think about it,
                                                                                       // we only discuss about the generic posibility
                                                                                       // For the Method 3, we even shrink the right side piles number
                                                                                       // so as to decrease the dimension number from 3-D to 2-D
                }
                dp[i][j][1] = dp[i][j][K] + pfsum[j+1] - pfsum[i]; // merge after partition
            }
        }

        return dp[0][n-1][1];
    }
};

/* Method 2: 3d optimized, time complexity (O(N^3) */
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1) != 0)
            return -1;

        vector<int> pfsum(n+1, 0);
        for (int i = 0; i < n; i++)
            pfsum[i+1] = pfsum[i] + stones[i];

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K+1, 0x3f3f3f3f)));
        for (int i = 0; i < n; i++)
            dp[i][i][1] = 0;

        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + l - 1;
                if (j >= n)
                    continue;
                for (int p = 2; p <= K; p++) // at least 2 piles
                {
                    for (int m = i; m < j; m += K-1) // Optimization point: skip obviously invalid choice
                        dp[i][j][p] = min(dp[i][j][p], dp[i][m][1] + dp[m+1][j][p-1]); // only divide/patition, no merge
                                                                                       // Reason why partition the left side into 1: 
                                                                                       // because any other number can be shrinked to 1, think about it,
                                                                                       // we only discuss about the generic posibility
                                                                                       // For the Method 3, we even shrink the right side piles number
                                                                                       // so as to decrease the dimension number from 3-D to 2-D
                    if (dp[i][j][p]) // if we check by printing out each iteration, there're still a lot of them INVALID!
                                     // actually, only the ones that assigns right side piles equal to (j-i+1) % K + (j-i+1) / K - 1 are legal
                                     // thus, the final optimization thought: no need to care about the dim of p, as there is ONLY one VALID p
                    {
                        printf("i = %d, j = %d, p = %d, dp[i][j][p] = %d\n", i, j, p, dp[i][j][p]);
                        printf("(j-i+1) % K + (j-i+1) / K = %d\n",(j-i+1) % K + (j-i+1) / K);
                        cout << "-------------------\n";
                    }
                }
                dp[i][j][1] = dp[i][j][K] + pfsum[j+1] - pfsum[i]; // merge after partition
            }
        }

        return dp[0][n-1][1];
    }
};

/* Method 3: 2d optimized, time complexity (O(N^2*K) */
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1) != 0)
            return -1;

        vector<int> pfsum(n+1, 0);
        for (int i = 0; i < n; i++)
            pfsum[i+1] = pfsum[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, 0x3f3f3f3f)); // dp[i][j] means the cost to merge [i, j] to 1 pile
        for (int i = 0; i < n; i++)
            dp[i][i] = 0; // no merge at all

        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + l - 1;
                if (j >= n)
                    continue;
                for (int m = i; m < j; m += K-1) // Optimization point: skip obviously invalid choice
                                                 // here, different than Method 2, must be m += K-1, other points have no definition
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j]); // only divide/patition, no merge
                if ((i - j) % (K - 1) == 0)
                    dp[i][j] = dp[i][j] + pfsum[j+1] - pfsum[i]; // merge after partition
            }
        }

        return dp[0][n-1];
    }
};