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
    	std::vector<std::vector<int>> dp( sz, std::vector<int>(m, 0) );


    	for (int i = 1; i <= sz; i++)
    	{
    		for (int j = 1; j <= m; j++)
    		{
    			if ( j < A[i - 1] )
    				dp[i][j] = max(dp[i - 1][j], 0);
    			else
    				dp[i][j] = max( dp[i - 1][j], dp[i - 1][ j - A[i - 1] ] + A[i - 1] * V[i - 1] );
    		}
    	}

    	return dp[sz][m];
    }
};