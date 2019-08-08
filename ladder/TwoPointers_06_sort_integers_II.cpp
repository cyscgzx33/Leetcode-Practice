class Solution {
public:

	void quickSort(std::vector<int>& nums, int start, int end) {
		if (start >= end) return;

		int small_storer = start;
		int pivot = start;

		for (int small_seeker = start; small_seeker <= end; small_seeker++) {
			if ( nums[small_seeker] < nums[pivot] ) {
				small_storer++;
				std::swap( nums[small_seeker], nums[small_storer] );
			}
		}

		std::swap( nums[small_storer], nums[pivot] );

		quickSort(nums, start, small_storer - 1);
		quickSort(nums, small_storer + 1, end);
	}

    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
    	if (A.size() == 0) return;
        quickSort(A, 0, A.size() - 1);
    }
};