class Solution {
public:
    /**
     * @param A: an array
     * @return: the sum of subarray minimums
     */
    int sumSubarrayMins(vector<int> &A) {
        // Write your code here.
        // dp[i+1] indicates sum of subarrays ending with A[i]
        std::vector<int> dp(A.size() + 1, 0);
        std::stack<int> lb;
        lb.push(-1);
        int result = 0;

        for (int i = 0; i < A.size(); i++) {
            while (lb.top() != -1 && A[lb.top()] >= A[i]) lb.pop();
            int lower_bound = lb.top();
            dp[i+1] = A[i] * (i - lower_bound) + dp[lower_bound + 1]; // don't forget +1 to lower_bound 
            lb.push(i);
            result += dp[i+1];
        }

        return result;
    }
};