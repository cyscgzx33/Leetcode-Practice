class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here
        
        if (A.size() == 0)
            return 0;
        
        // dp[i][j] means the minimum efforts to arrange stones in [i, j]
        int sz = A.size();

        // init the dp vector
        // by definition, dp[i][i] = 0
        std::vector<std::vector<int>> dp( sz, std::vector<int>(sz, INT_MAX) );
        for (int i = 0; i < sz; i++)
            dp[i][i] = 0;

        // format the pfsum vector first for reference
        // definition: pfsum[i] = pfsum[i-1] + A[i-1]    for any i > 0
        //             pfsum[i] = 0				         for i = 0
        // note: in a word, pfsum[i] sums up elements within [0, i)
        std::vector<int> pfsum(sz + 1, 0);
        for (int i = 1; i <= sz; i++)
        	pfsum[i] = pfsum[i-1] + A[i-1];
        
        // format the upper part of the dp matrix (since i <= j must be maintained, we don't care about lower part)
        // the initial state transition formula is: dp[i][j] = min_{ for any k in [i, j) } ( dp[i][k], dp[k+1][j] ) + sum[i][j]
        for (int i = sz - 1; i >= 0; i--)
        {
        	for (int j = i + 1; j < sz; j++)
        	{
                for (int k = i; k < j; k++) // as we have to access dp[k+1][j], so k < j
                    dp[i][j] = min( dp[i][j], dp[i][k] + dp[k+1][j] + pfsum[j+1] - pfsum[i] );
        	}
        }

        return dp[0][sz - 1];
    }
};