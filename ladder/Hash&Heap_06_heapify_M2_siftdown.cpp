class Solution {
public:
    void siftDown(std::vector<int>& A, int k) {
        while( k * 2 + 1 < A.size() ) {
            int son = k * 2;
            if ( A[son] > A[son + 1] ) son = son + 1;
            if ( A[k] < A[son] ) break;
            std::swap(A[son], A[k])
            k = son;
        }
    }
    
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        // write your code here
        for (int i = A.size() - 1; i >= 0; i--) siftDown(A, i);
    }
};