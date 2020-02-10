class Solution {
public:
    void siftUp(std::vector<int>& A, int k) {
        while (k != 0) {
            int father = (k - 1) / 2;
            if ( A[father] < A[k] ) break;  // must have a logic to exit the loop
            std::swap( A[father], A[k] );
            k = father;
        } 
    }
    
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        // write your code here
        for (int i = 0; i < A.size(); i++) siftUp(A, i);
    }
};