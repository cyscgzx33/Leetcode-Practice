class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { 
        int n = nums.size();
        if (n == 0)
            return 0;
        
        std::unordered_map<int, int> pfsum2Cnt{ {0, 1} };
        
        int pf_sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            pf_sum += nums[i];
            cnt += pfsum2Cnt[pf_sum - k];
            pfsum2Cnt[pf_sum]++;
        }
        
        return cnt;
    }
};