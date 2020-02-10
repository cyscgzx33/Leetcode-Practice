/******************************************* Method 1: *******************************************************/

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

/******************************************* Method 2: *******************************************************/
class Solution
{
public:
    /* Method 2: TC(O(NlogN)) */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // construct a fake LIS 1d dp vec
        std::vector<int> dp;
        // important point: to avoid height overlaping when conducting the process of insertion
        // after this step, the question is almost the same as LIS, as width varies from small to large
        std::sort(envelopes.begin(), envelopes.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; 
                  });
        
        for (auto& evlp : envelopes)
        {
            auto iter = std::lower_bound( dp.begin(), dp.end(), evlp[1] );
            if ( iter != dp.end() )
                *iter = evlp[1];
            else
                dp.push_back( evlp[1] );
        }
        
        /* eg: [[1,5], [1,3], [2,7], [2, 2], [2,1], [3, 6], [4,5], [4,4], [5,6], [6,4], [6,2], [6,1], [7,7], [7,5]] */
        // for (auto elem : dp)
        //     std::cout << elem << ", ";
        /* output: [1, 2, 5, 7] */
        
        return dp.size();
    }
};
