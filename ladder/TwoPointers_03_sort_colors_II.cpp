class Solution {
public:

	/* quick sort */
	void quickSort(std::vector<int>& colors, int start, int end) {
		int pivot = start;
		int small_storer = start;

		if (start + 1 >= end) return;

		/*   [Partition Step]
		 *
		 *   after the partition step:
		 *   -----------------------------------------
		 *   P O O O O O X X X X X X X X X
		 *   ^         ^                 ^
		 *   PIVOT     small_storer      small_seeker
		 *   -----------------------------------------
		 */
		for (int small_seeker = start; small_seeker < end; small_seeker++) {
			if ( colors[small_seeker] < colors[pivot] ) {
				small_storer++;
				std::swap( colors[small_seeker], colors[small_storer] );
			}
		}
		std::swap( colors[pivot], colors[small_storer] );

		// Search left hand side
		quickSort(colors, start, small_storer + 1);
		// Search right hand side
		quickSort(colors, small_storer + 1, end);
	}

    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
    	quickSort(colors, 0, colors.size());
    }
};