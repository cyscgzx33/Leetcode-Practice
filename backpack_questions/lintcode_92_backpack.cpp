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