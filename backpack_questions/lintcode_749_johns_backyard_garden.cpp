/* 1D dp method */
class Solution {
public:
    /**
     * @param x: the wall's height
     * @return: YES or NO
     */
    string isBuild(int x) {
        // write you code here
    	std::vector<int> heights = {3, 7};
    	std::vector<bool> dp(x + 1, false);
    	dp[0] = true;

    	for (int i = 0; i < 2; i++)
    	{
    		for (int j = heights[i]; j <= x; j++)
    			dp[j] = dp[j] || dp[ j - heights[i] ];
    	}

    	return dp[x] ? "YES" : "NO";
    }
};


/* 2D dp method */
class Solution {
public:
    /**
     * @param x: the wall's height
     * @return: YES or NO
     */
    string isBuild(int x) {
        // write you code here
    	std::vector<int> heights = {3, 7};
    	std::vector<bool> row(x + 1, false);
    	row[0] = true;

    	std::vector<std::vector<bool>> dp( 2 + 1, row );
    	for (int i = 1; i <= 2; i++)
    	{
    		for (int j = 1; j <= x; j++)
    		{
    			if ( j < heights[i - 1] )
    				dp[i][j] = dp[i - 1][j];
    			else
    				dp[i][j] = dp[i][ j - heights[i - 1] ] || dp[i - 1][j];
    		}
    	}

    	return dp[2][x] ? "YES" : "NO";
    }
};