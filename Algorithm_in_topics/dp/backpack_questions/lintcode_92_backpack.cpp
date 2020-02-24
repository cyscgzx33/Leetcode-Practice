#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
    	int sz = A.size();

    	std::vector<std::vector<int>> dp( sz + 1, std::vector<int>(m + 1, 0) );

    	// start to iterate
    	// skip i == 0 || j == 0, those positions are supposed to be 0s
    	for (int i = 1; i <= sz; i++)
    	{
    		for (int j = 1; j <= m; j++)
    		{
    			if ( j < A[i - 1] )
    				dp[i][j] = dp[i - 1][j]; // technically, it should be max(dp[i-1][j], 0)
    			else
    				dp[i][j] = max( dp[i - 1][j], dp[i - 1][j - A[i - 1]] + A[i - 1] );
    		}
    	}
    
    	return dp[sz][m];
    }
};


class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
		int n = A.size();
        // dp[i][w] indicates whether we can use the front i items come up with w weights
		vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
		
		// initial conditions
		dp[0][0] = true; // 0 item can come up with 0 weight
		for (int w = 1; w <= m; w++)
			dp[0][w] = false; // can not use 0 item come up with w weight for any w >= 1
		
		for (int i = 1; i <= n; i++)
		{
			for (int w = 0; w <= m; w++)
			{
				dp[i][w] = dp[i-1][w] || w >= A[i-1] && dp[i-1][w-A[i-1]]; // as the "front i items"
																	     // here we must use A[i-1]
			}
		}

		for (int w = m; w >= 0; w--)
		{
			if (dp[n][w] == true)
				return w;
		}

    }
};