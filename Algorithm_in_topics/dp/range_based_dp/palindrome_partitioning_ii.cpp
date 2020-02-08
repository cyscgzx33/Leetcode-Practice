class Solution {
public:
    int minCut(string s) {
    	int len = s.length();

    	// indicate whether the substring within the range [i, j] is a palindrome
        std::vector<std::vector<bool>> is_palindrome( len, std::vector<bool>(len, false) );
        // indicate how many cuts do we need to make the substring from [0, i] a palindrome set
        std::vector<int> dp(len, 0);

        for (int i = 0; i < len; i++)
        {
        	dp[i] = i;
        	for (int j = 0; j <= i; j++)
        	{	
        		// using a method feeling like recursive to set up the criteria
        		if ( s[i] == s[j] && (i - j < 2 || is_palindrome[j+1][i-1] == true) )
        		{
        			is_palindrome[i][j] = true;
        			is_palindrome[j][i] = true;
        			if (j == 0)
        				dp[i] = 0;
        			else
        				dp[i] = min(dp[i], dp[j-1] + 1);
        		}
        	}
        }

        return dp[len - 1];
    }
};