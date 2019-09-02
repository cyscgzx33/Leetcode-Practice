class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int n = A.size();
        std::vector<int> dp(n, 0); // whether the spot is reachable
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
        	if (dp[i] == 0)
        		break;
        	for (int j = 1; j <= A[i]; j++)
        	{
        		if (i + j < n && dp[i + j] == 0)
        			dp[i + j] = 1;
        	}
        }

        return dp.back();
    }
};