/* [C++ Program for QuickSort]
 *
 * Like Merge Sort, QuickSort is a Divide and Conquer algorithm. 
 * It picks an element as pivot and partitions the given array 
 * around the picked pivot. There are many different versions of quickSort that 
 * pick pivot in different ways: 
 * (1) Always pick first element as pivot;
 * (2) Always pick last element as pivot (implemented below);
 * (3) Pick a random element as pivot.
 * (4) Pick median as pivot.
 *
 * The key process in quickSort is partition(). 
 * Target of partitions is, given an array and an element x of array as pivot, 
 * put x at its correct position in sorted array and put all smaller elements (smaller than x) 
 * before x, and put all greater elements (greater than x) after x. 
 * All this should be done in linear time.
 * 
 */

#include <iostream>
#include <vector>

template <typename _Tf>
int partition(std::vector<_Tf>& vec, int left, int right) {
	int i = left - 1; // TODO: figure out the intuition of the "strange" number
					  // Guess: the largest element among the ones that are smaller than pivot
	_Tf pivot = vec[right]; // Right now, the pivot is the right one.


	/* Note:
	 * This algorithm is brilliant!
	 * at each step, it can be guaranteed that,
	 * after the swap, all the elements that are right to the i and left to the j,
	 * i.e., elements belong to the region (i, j), are larger than pivot 
	 */

	for (int j = left; j < right; j++) {
		if (vec[j] <= pivot) { // Note 1: make sure it's "<=" here.
							   // Note 2: if one just change it to ">=", then it will sort the vector in descending order
			i++; // TODO: figure our the intuition here.
			std::swap(vec[i], vec[j]);
		}
	}

	// Gurantee that all the elements to the left of the pivot are SMALLER than (or equal to) it.
	std::swap(vec[i + 1], vec[right]);
	return i + 1;
}

template <typename _Tf>
void quickSort(std::vector<_Tf>& vec, int left, int right) {
	if (left < right) {
		/* p_index is the partition index, p_index is now at right place */
		int p_index = partition(vec, left, right);

		quickSort(vec, left, p_index - 1); // Before partition index
		quickSort(vec, p_index + 1, right); // After partition index
	}
}


int main() {
	std::vector<int> test_vec_1 = {2, 5, 3, 4, 1, 2, 4, 3, 7, 8, 6};
	quickSort(test_vec_1, 0, test_vec_1.size() - 1);

	// output the result
	std::cout << "the sorted vector is : {";
	for (auto ele : test_vec_1) {
		std::cout << ele << ", ";
	}
	std::cout << "}\n";

}