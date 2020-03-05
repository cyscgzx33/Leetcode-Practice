#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * input: array A, length n
     * output: {start pos, end pos} if contain some range that sums up to 0
     *         otherwise, {-1, -1}
     */
    vector<int> subarraySum(vector<int>& A, int n)
    {
        vector<int> pfsum(n+1, 0);
        unordered_map<int, int> map;
        map[pfsum[0]] = 0;

        for (int i = 0; i < n; i++)
        {
            pfsum[i+1] = pfsum[i] + A[i];
            if (map.count(pfsum[i+1]) == 0)
                map[pfsum[i+1]] = i + 1;
            else
                return {map[pfsum[i+1]], i};
        }
        return {-1, -1};
    }
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        /* idea: restrict the problem at some row(s) and regard as a super row, and for each super row, it's a Subarray Sum problem */
        int n = matrix.size(), m = matrix[0].size();

        vector<int> superrow(m, 0);
        for (int up = 0; up < n; up++)
        {
            vector<int> superrow(m, 0);
            for (int i = 0; i < m; i++)
                superrow[i] = matrix[up][i];
            for (int down = up; down < n; down++)
            {
                for (int i = 0; i < m && down > up; i++)
                    superrow[i] += matrix[down][i];
                vector<int> eval_superrow = subarraySum(superrow, m);
                if (eval_superrow[0] != -1)
                    return {{up, eval_superrow[0]}, {down, eval_superrow[1]}};
            }
        }
    }
};