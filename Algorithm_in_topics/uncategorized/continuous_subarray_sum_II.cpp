#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int> &A) {
        int n = A.size();

        // for S1, assume the gap is not crossed
        int S1 = 0xcfcfcfcf;
        vector<int> res1 = {0, 0};
        int valley = 0; // valley is pfsum[0]
        vector<int> pfsum(n+1, 0);
        for (int i = 0; i < n; i++)
        {
            pfsum[i+1] = pfsum[i] + A[i];
            if (pfsum[i+1] - pfsum[valley] > S1)
            {
                S1 = pfsum[i+1] - pfsum[valley];
                res1[0] = valley;
                res1[1] = i;
            }
            if (pfsum[i+1] < pfsum[valley])
                valley = i+1;
        }

        // for S2, assume the gap is crossed
        // in this case, we calculate the opposite way, the min value, instead of max value
        // so S2 is the min value, res2 records the min value indices
        int S2 = 0x3f3f3f3f;
        vector<int> res2 = {0, 0};
        int peak = 0; // peak is pfsum[0]
        for (int i = 0; i < n; i++)
        {
            if (pfsum[i+1] - pfsum[peak] < S2)
            {
                S2 = pfsum[i+1] - pfsum[peak];
                res2[0] = peak;
                res2[1] = i;
            }
            if (pfsum[i+1] > pfsum[peak])
                peak = i + 1;
        }

        
        // now let's take care of S1 & S2
        // firstly check the corner case, if S2 is the whole array, then not valid, return res1
        if (S2 == pfsum[n])
            return res1;
        // then compare S1 and (pfsum[n] - S2)
        if (S1 > pfsum[n] - S2)
            return res1;
        else
            return {(res2[1] + 1) % n, (res2[0] - 1 + n) % n}; // to prevent overflow
    }
};