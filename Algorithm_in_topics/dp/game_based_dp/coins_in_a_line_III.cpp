class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        /**
         * 0. State of f[i][j]: max diff value at facing [A[i],A[j]]
         * 1. State transition: f[i][j] = max(a[i] - f[i+1][j], a[j] - f[i][j-1])
         * 2. Boundary condition or initial condition: f[i][i] = A[i]
         * 3. Iteration order: l = 1 (f[0][0] ... f[N-1][N-1]), l = 2(f[0][1], ..., f[N-2][N-1]), ..., l = N (f[0][N-1])
         */
         
        int n = values.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++)
            f[i][i] = values[i];
        
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + l - 1;
                if (j >= n)
                    continue;
                f[i][j] = max(values[i] - f[i+1][j], values[j] - f[i][j-1]);
            }
        }
        
        return f[0][n-1] >= 0;
    }
};