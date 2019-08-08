class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here

    	if (nums.size() == 0) return;

    	int nonzero_storer = -1;
        for (int nonzero_seeker = 0; nonzero_seeker < nums.size(); nonzero_seeker++) {
        	if (nums[nonzero_seeker] != 0) {
        		nonzero_storer++;
        		nums[nonzero_storer] = nums[nonzero_seeker];
        	}
        }

        for (int zero_filler = nonzero_storer + 1; zero_filler < nums.size(); zero_filler++) {
        	nums[zero_filler] = 0;
        }

        return;
    }
};