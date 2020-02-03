class Solution {
public:

	void rainbowSort(std::vector<int>& nums, int nums_start, int nums_end, int colors_start, int colors_end)
	{
		// Point 1: exit criteria
		if (nums_start >= nums_end || colors_start >= colors_end) return;

		// Point 2: start partition based on the colors
		// every color stays in (nums_start, nums_left) should be <= colors_mid
		// every color stays in (nums_right, nums_end) should be > colors_mid
		int colors_mid = (colors_end - colors_start) / 2 + colors_start;
		int nums_left = nums_start, nums_right = nums_end;

		while (nums_left <= nums_right) {
			while (nums_left <= nums_right && nums[nums_left] <= colors_mid) nums_left++;
			while (nums_left <= nums_right && nums[nums_right] > colors_mid) nums_right--;

			if (nums_left <= nums_right) {
				std::swap( nums[nums_left], nums[nums_right] );
				nums_left++; 
				nums_right--;
			}
		}

		rainbowSort(nums, nums_start, nums_left - 1, colors_start, colors_mid);
		rainbowSort(nums, nums_right + 1, nums_end, colors_mid + 1, colors_end);
	}

    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
    	quickSort(colors, 0, colors.size() - 1, 1, k);
    }
};