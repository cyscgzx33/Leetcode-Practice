class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) 
    {
        /**
         * [Description]
         * 1. dp[i] represents the largest divisible sets length ending with nums[i]
         * 2. parents[i] represents the last divisible position
         * 3. max_len is the largest set length
         * 4. max_idx is the largest set starting position
         * */
        if (nums.size() == 0)
            return {};

        std::sort( nums.begin(), nums.end() );
        std::unordered_map<int, int> dp;         // key: num_val,   val: dp_val
        std::unordered_map<int, int> parents;    // key: num_val,   val: parent_val

        // init dp hashmap
        for(auto& num : nums)
            dp[num] = 1;

        std::vector<int> result;
        int max_val = 0, max_len = 0;

        for (auto& num : nums)
        {
            for (int dv = 1; dv * dv <= num && dv < num; dv++) // dv stands for divisor
            {   
                if (num % dv != 0)
                    continue;

                int dv_rm = num / dv; // dv_rm stands for divisor remainder

                if ( dp.count(dv) > 0 && dp[dv] + 1 > dp[num] )
                {
                    dp[num] = dp[dv] + 1;
                    parents[num] = dv;
                }

                if ( dv_rm != num && dv_rm != dv & dp.count(dv_rm) > 0 && dp[dv_rm] + 1 > dp[num] )
                    // corner case I:  dv == 1         ==> dv_rm == num       (not legal to be same as num)
                    // corner case II: dv == sqrt(num) ==> dv_rm == sqrt(num) (not leagl to be same as dv)
                {
                    dp[num] = dp[dv_rm] + 1;
                    parents[num] = dv_rm;
                }

                if (dp[num] > max_len)
                {
                    max_len = dp[num];
                    max_val = num;
                }
            }
        }
        
        result.push_back(max_val);
        while( result.size() < max_len )
        {
            int parent = parents[ result.back() ];
            result.push_back(parent);
        }

        return result;
    }
};