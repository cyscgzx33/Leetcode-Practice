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
                }
                dp[i][j][1] = dp[i][j][K] + pfsum[j+1] - pfsum[i]; // merge after partition
            }
        }

        return dp[0][n-1][1];
    }
};