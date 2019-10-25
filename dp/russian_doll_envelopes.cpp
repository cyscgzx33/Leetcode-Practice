class Solution
{
public:
    /* Method 1: TC(O(N^2)) */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0)
            return 0;
        
        // sort envelopes first
        std::sort( envelopes.begin(), envelopes.end() );
        // construct 1d dp vec
        std::vector<int> dp(envelopes.size(), 1); // init to 1, since ego envelope can be 1
        for (int i = 0; i < envelopes.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ( envelopes[j][0] < envelopes[i][0] && 
                     envelopes[j][1] < envelopes[i][1] &&
                     dp[j] + 1 > dp[i] )
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        return *max_element( dp.begin(), dp.end() );
    }
};