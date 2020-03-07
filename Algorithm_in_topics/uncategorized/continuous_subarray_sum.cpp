#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        // write your code here
        int n = A.size();
        vector<int> pfsum(n+1, 0);

        int valley = 0; // valley if pfsum[0]
        int max_val = 0xcfcfcfcf;
        vector<int> res = {0, 0};
        for (int i = 0; i < n; i++)
        {
            pfsum[i+1] = pfsum[i] + A[i];
            if (pfsum[i+1] - pfsum[valley] > max_val)
            {
                res[0] = valley;
                res[1] = i;
            }
            if (pfsum[i+1] < pfsum[valley])
                valley = i + 1;
        }

        return res;
    }
};