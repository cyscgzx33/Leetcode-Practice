class Solution {
public:
    int getFirstDescendingBit(std::vector<int>& nums) {
        int first_des_bit = -1; // not found
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] >= nums[i]) continue;
            else {
                first_des_bit = i - 1;
                return first_des_bit;
            }
        }
        return first_des_bit;
    }

    /* find the smallest one which are LARGER than the first_des_bit */
    int getUpperBound(std::vector<int>& nums, int first_des_bit) {
        int upper_bound_index = first_des_bit;
        for (int i = first_des_bit + 1; i < nums.size() && nums[i] > nums[first_des_bit]; i++) {
            upper_bound_index = i;
        }
        return upper_bound_index;
    }

    /**
     * @param nums: An array of integers
     * @return: nothing
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0) return;
        int first_des_bit = getFirstDescendingBit(nums);

        if (first_des_bit != -1) {
            int upper_bound_index = getUpperBound(nums, first_des_bit);
            std::swap( nums[first_des_bit], nums[upper_bound_index] );
            std::sort( nums.begin() + first_des_bit + 1, nums.end() );
        }
        else {
            std::sort( nums.begin(), nums.end() );
        }

    }
};