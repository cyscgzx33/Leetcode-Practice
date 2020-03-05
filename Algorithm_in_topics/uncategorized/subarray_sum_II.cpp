#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        int n = A.size();
        vector<int> pfsum(n+1, 0); // pfsum[i] means sum of the front i numbers
        for (int i = 0; i < n; i++)
            pfsum[i+1] = pfsum[i] + A[i];
        
        // l : first valid start position
        // r : the one after the valid start position
        int l = 0, r = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) // why i start from 1? because at least first one element
        {
            while (l < r && pfsum[i] - pfsum[l] > end) // means illegal
                l++;
            while (r < i && pfsum[i] - pfsum[r] >= start) // means leage
                r++;
            res += r - l;            
        }

        return res;
    }
};