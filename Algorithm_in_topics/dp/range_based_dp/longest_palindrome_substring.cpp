#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] indicates length of palindrome in [i, j], boundaries included
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // init: dp[i][i] = 1;
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // loop order: l -> i
        string res = s.substr(0, 1);
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + l - 1;
                if (j >= n)
                    continue;
                if (s[i] != s[j]) // no matter odd or even, it's not gonna be palindrome
                    continue;
                if (l % 2 == 0)
                {
                    if (l > 2)
                        dp[i][j] = dp[i+1][j-1] == 0 ? 0 : dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = 2;
                }
                else
                    dp[i][j] = dp[i+1][j-1] == 0 ? 0 : dp[i+1][j-1] + 2; 
                if (res.size() < dp[i][j])
                    res = s.substr(i, l);
            }
        }
        return res;
    }
};