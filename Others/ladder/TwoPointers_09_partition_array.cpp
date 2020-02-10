class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */

    int partitionArray(vector<int> &nums, int k) {
        // write your code here
    	if (nums.size() == 0) return 0;

    	int small_storer = -1;
    	for (int small_seeker = 0; small_seeker < nums.size(); small_seeker++) {
    		if (nums[small_seeker] < k) {
    			small_storer++;
    			std::swap(nums[small_storer], nums[small_seeker]); // not necessary here
    		}
    	}

    	return small_storer + 1;
    }
};