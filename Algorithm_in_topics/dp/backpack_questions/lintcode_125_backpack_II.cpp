#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int sz = A.size();
    	std::vector<std::vector<int>> dp( sz + 1, std::vector<int>(m + 1, 0) );

    	for (int i = 1; i <= sz; i++)
    	{
    		for (int j = 1; j <= m; j++)
    		{
    			if ( j < A[i - 1] )
    				dp[i][j] = max(dp[i - 1][j], 0);
    			else
    				dp[i][j] = max( dp[i - 1][j], dp[i - 1][ j - A[i - 1] ] + V[i - 1] );
    		}
    	}
        
    	return dp[sz][m];
    }
};

/* Rewarm */

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int n = A.size();

		// dp[i][j] indicates within the front i items, in the volumn j, what is the maximum value can be achieved
		// * dp[i][j] = -1 means front i items cannot fit in j volumn (Yusen: do we really need this??)
		// * thought:
		//           1) take A[i-1]: dp[i-1][j-A[i-1]] + V[i-1] if j >= A[i-1]
		// 			 2) not take A[i-1]: dp[i-1][j]
		// state transition: dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]] + V[i-1])
		// initial & boundary conditions:
		// f[0][0] = 0
		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (j >= A[i-1])
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]] + V[i-1]);
				else
					dp[i][j] = dp[i-1][j];
			}
		}

		return dp[n][m];
    }
};