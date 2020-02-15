#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        int len1 = word1.size(), len2 = word2.size();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        // init dp starter values
        for (int i = 0; i <= len1; i++)
            dp[i][0] = i;
        for (int i = 0; i <= len2; i++)
            dp[0][i] = i;

        // loop dp
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                // target: induce how the tail of word2 matches to tail of word1
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1; // method 1: adding a same letter to tail of word1
                                                            // method 2: cutting the current tail of word1
                dp[i][j] = min(dp[i-1][j-1] + 1, dp[i][j]); // method 3: change the tail of word1 to tail of word2
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
            }
        }

        return dp[len1][len2];
    }
};