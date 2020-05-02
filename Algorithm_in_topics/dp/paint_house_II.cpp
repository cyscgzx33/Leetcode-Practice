#include <vector>

using namespace std;

// Method 2: dp with two minimum values / indices to avoid the NON-SAME INDEX RESTRICTION (very clever, may be useful later)
class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        if (costs.size() == 0 || costs[0].size() == 0)
            return 0;

        int n = costs.size(), k = costs[0].size();

        vector<vector<int>> dp(n, vector<int>(k, 0)); // dp[i][j] means:
                                                      // till house i (including i), what is the minimum cost to paint if choosing color j 

        pair<int, int> min_p1, min_p2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                dp[i][j] = costs[i][j];
                if (i > 0)
                    dp[i][j] += min_p1.second == j ? min_p2.first : min_p1.first;
            }

            // calculate min pair 1 and 2 for next loop
            for (int j = 0; j < k; j++)
            {
                if (j == 0)
                    min_p1 = {dp[i][j], j};
                else if (j == 1)
                {
                    if (dp[i][j] < min_p1.first)
                    {
                        min_p2 = min_p1;
                        min_p1 = {dp[i][j], j};
                    }
                    else
                        min_p2 = {dp[i][j], j};
                }
                else // j > 1
                {
                    if (dp[i][j] < min_p1.first)
                    {
                        min_p2 = min_p1;
                        min_p1 = {dp[i][j], j};
                    }
                    else if (dp[i][j] < min_p2.first)
                    {
                        min_p2 = {dp[i][j], j};
                    }
                }
            }
        }
        
        return min_p1.first;
    }
};


// Method 1: brutal force dp
class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        if (costs.size() == 0 || costs[0].size() == 0)
            return 0;
            
        int n = costs.size(), k = costs[0].size();
        
        vector<vector<int>> dp(n, vector<int>(k, 0)); // dp[i][j] means:
                                                      // till house i (including i), what is the minimum cost to paint if choosing color j 
        
        for (int i = 0; i < k; i++)
            dp[0][i] = costs[0][i];
            
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                int prev_min = 0x3f3f3f3f;
                for (int m = 0; m < k; m++)
                {
                    if (m == j)
                        continue;
                    prev_min = min(prev_min, dp[i-1][m]);
                }
                dp[i][j] = costs[i][j] + prev_min;
            }
        }
        
        int res = 0x3f3f3f3f;
        for (int i = 0; i < k; i++)
            res = min(res, dp[n-1][i]);
            
        return res;
    }
};




















































