class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dq; // hot hawthorn theory
        std::vector<int> res;
        
        for (int i = 0; i < nums.size(); i++)
        {
            // step I: check if the dq is overwhelmed
            if ( !dq.empty() && i - k == dq.front() )
                dq.pop_front();
            
            // step II: process the hot hawthorn theory
            while ( !dq.empty() && nums[ dq.back() ] <= nums[i] ) // "<" will work as well
                dq.pop_back();
            
            // step III: push the curr index
            dq.push_back(i);
            
            // step IV: process the res vector
            if (i - k + 1 >= 0) // needs to take care of i - k + 1
                res.push_back( nums[ dq.front() ] );
        }
        
        return res;
    }
};