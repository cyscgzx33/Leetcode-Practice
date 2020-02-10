vector<int> largestDivisibleSubset(vector<int> &nums) {
    /**
     * [Description]
     * 1. dp[i] represents the largest divisible sets length ending with nums[i]
     * 2. parents[i] represents the last divisible position
     * 3. max_len is the largest set length
     * 4. max_idx is the largest set starting position
     * */
    if (nums.size() == 0)
        return 0;

    sort( nums.begin(), nums.end() );
    int n = nums.size();
    std::vector<int> dp(n, 1), parents(n, 0), result;
    int max_len = 0, max_idx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]);
            {
                dp[i] = dp[j] + 1;
                parents[i] = j;
            }

            if (dp[i] > max_len)
            {
                max_len = dp[i];
                max_idx = i;
            }
        }
    }

    int idx = max_idx;
    for (int i = 0; i < max_len; i++)
    {
        result.push_back( nums[idx] );
        idx = parents[idx];
    }

    return result;
}


// Method 2
class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        /**
         * [Description]
         * 1. dp[i] represents the largest divisible sets length ending with nums[i]
         * 2. parents[i] represents the last divisible value
         * 3. max_len is the largest set length
         * 4. max_idx is the largest set starting position
         * */
        if (nums.size() == 0)
            return {};
    
        sort( nums.begin(), nums.end() );
        int n = nums.size();
        std::unordered_map<int, int> dp;      // key: num,     val: initial dp's value
        std::unordered_map<int, int> parents; // key: cur val, val: parent val
        // init dp hash map
        for (auto& num : nums)
            dp[num] = 1;
    
        std::vector<int> result;
        int max_len = 0, max_idx = 0;
    
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j * j <= nums[i]; j++) // loop j as value instead of index
            {
                int divisor1 = j, divisor2 = nums[i] / j;
                
                if ( divisor1 * divisor2 != nums[i] )
                    continue;
                
                if ( divisor1 < nums[i] && dp.count(divisor1) > 0 && dp[divisor1] + 1 > dp[ nums[i] ] )
                {   
                    dp[ nums[i] ] = dp[divisor1] + 1;
                    parents[ nums[i] ] = divisor1;
                }
    
                if ( divisor2 < nums[i] && divisor2 != divisor1 && dp.count(divisor2) > 0 && dp[divisor2] + 1 > dp[ nums[i] ] )
                {
                    dp[ nums[i] ] = dp[divisor2] + 1;
                    parents[ nums[i] ] = divisor2;
                }
    
                if (dp[ nums[i] ] > max_len)
                {   
                    max_len = dp[ nums[i] ];
                    max_idx = i;
                }
            }
        }
    
        result.push_back( nums[max_idx] );
        while ( result.size() < max_len )
        {
            int parent = parents[ result.back() ];
            result.push_back(parent);
        }
    
        return result;
    }
};