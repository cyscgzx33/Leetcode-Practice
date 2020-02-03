int findKth(vector<int>& A, vector<int>& B, int startA, int endA, int startB, int endB, int K) {
	/* Case I: A or B is empty */
	if (A.size() <= startA) return B[startB + K - 1];
	if (B.size() <= startB) return A[startA + K - 1];

	/* Case II: K == 1 */
	if (K == 1) return min(A[0], B[0]);

	/* Case III: general case*/
	int valA = startA + K/2 < A.size() ? A[startA + K/2] : INT_MAX;
	int valB = startB + K/2 < B.size() ? B[startB + K/2] : INT_MAX;
	
	/* Ethan's comment: 
	   try to think over it!!!
	   If current size of A is 3, current size of B is 10, and you want to find K == 10,
	   then of course for A is oversized though, B[5] should never be the Kth largest one,
	   the best choice it can take is the 8th largest one.
	   Thus, cut off the B[5] and its formers  
	*/

	if (valA > valB) return findKth(A, B, startA, endA, startB + K/2, endB, K - K/2);
	else return findKth(A, B, startA + K/2, endA, startB, endB, K - K/2);
}

double findMedian(vector<int> A, vector<int> B) {

}

