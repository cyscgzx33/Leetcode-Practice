class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        // write your code here
    	int n = nums.size();
    	if (n == 0)
    		return 0;

    	std::sort(nums.begin(), nums.end());

    	int l = 0, r = n - 1;
    	int cnt = 0;
    	while (l < r)
    	{
    		if (nums[l] + nums[r] > target)
    			r--;
    		else
    		{
    			cnt += r - l;
    			l++;
    		}
    	}

    	return cnt;
    }
};