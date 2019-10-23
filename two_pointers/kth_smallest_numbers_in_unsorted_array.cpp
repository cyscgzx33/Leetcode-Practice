class Solution {
public:

	int quickSelect(int k, int start, int end, std::vector<int>& nums)
	{
		int small_storer = start, small_seeker = start;

		for (;small_seeker <= end; small_seeker++)
		{
			if ( nums[small_seeker] < nums[start] )
			{
				small_storer++;
				std::swap( nums[small_storer], nums[small_seeker] );
			}
		}
		std::swap( nums[start], nums[small_storer] );

		if (k == small_storer)
			return nums[small_storer]
		else if (k < small_storer)
			return quickSelect(k, start, small_storer - 1, nums);
		else
			return quickSelect(k, small_storer + 1, end, nums);

	}

    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) 
    {
    	return quickSelect(k - 1, 0, nums.size() - 1, nums);
    }
};