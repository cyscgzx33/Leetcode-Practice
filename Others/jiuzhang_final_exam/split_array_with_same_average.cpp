class Solution {
public:
    /**
     * @param A: a integer array A,
     * @return: Return true if and only if after such a move
     */
    bool splitArraySameAverage(vector<int> &A) {
        // write your code here
        int len_A = A.size(), len_half_A = len_A / 2, sum_A = std::accumulate( A.begin(), A.end(), 0 );
        bool isSplit = false;
        for (int i = 1; i <= len_half_A && isSplit == false; i++)
        {
        	if ( sum_A * i % len_A == 0 )
        		isSplit = true;
        }

        if (isSplit == false)
        	return false;

        // dp[i] indicates that if choosing i nums in array A, what are all the possible sums could be 
        std::vector<std::unordered_set<int>> dp(len_half_A + 1);
        dp[0].insert(0);
        for (int num : A)
        {
        	for (int i = len_half_A; i >= 1; i--)
        	{
        		for ( auto psb_sum : dp[i-1] )
        		{
        			dp[i].insert(psb_sum + num);
        		}
        	}
        }

        for (int i = 1; i <= len_half_A; i++)
        {
        	if ( sum_A * i % len_A == 0 && dp[i].count(sum_A * i / len_A) > 0 )
        		return true;
        }

        return false;
    }
};