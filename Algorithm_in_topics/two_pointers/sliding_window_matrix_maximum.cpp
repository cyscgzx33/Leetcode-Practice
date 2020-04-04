#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: an integer array of n * m matrix
     * @param k: An integer
     * @return: the maximum number
     */
    int maxSlidingMatrix(vector<vector<int>> &matrix, int k) {
        if (matrix.size() < k || matrix[0].size() < k) // otherwise doesn't exist
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        // init a 2D pfsum: pfsum[i][j] represents the sum from (0, 0) to (i, j), including the boundaries
        vector<vector<int>> pfsum(m, vector<int>(n, 0));
        vector<int> pfsum_1d(n+1, 0);// temporay 1d pfsum
        // how to calculate pfsum[i][j]?
        // 1. obtain pfsum[i-1][j]
        // 2. use 1D pfsum methods to get this line's sum
        int epi_area = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0)
                    epi_area = pfsum[i-1][j];
                pfsum_1d[j+1] = pfsum_1d[j] + matrix[i][j];
                pfsum[i][j] = epi_area + pfsum_1d[j+1];
            }
        }

        int res = 0xcfcfcfcf;
        // iterate the matrix and find the maximum
        for (int i = 0; i < m - k + 1; i++)
        {
            for (int j = 0; j < n - k + 1; j++)
            {   
                int up_area = i == 0 ? 0 : pfsum[i-1][j+k-1];
                int left_area = j == 0 ? 0 : pfsum[i+k-1][j-1];
                int left_up_area = i == 0 || j == 0 ? 0 : pfsum[i-1][j-1];
                res = max(res, pfsum[i+k-1][j+k-1] - up_area - left_area + left_up_area);
            }
        }

        return res;
    }
};