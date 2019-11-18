class Solution {
public:
    /**
     * @param p: sequence p = <p_0, p_1, ..., p_n> where A_i has dimensions p_{i-1} x p_i and p.length = n + 1
     * @return: minimum operation numbers
     */
    int matrixChainOrder(vector<int> &p) {
        int n = p.size() - 1;
        std::vector<std::vector<int>> m( n, std::vector<int>(n, INT_MAX) ); // stores costs
        std::vector<std::vector<int>> s( n, std::vector<int>(n, INT_MAX) ); // stores which index of k achieved the optimal cost

        // by difinition, m[i][i] means no multiplication, i.e., 0
        for (int i = 0; i < n; i++)
            m[i][i] = 0;

        for (int l = 2; ; l <= n; l++) // l is the chain length
        {
            for (int i = 0; i < n - l + 1; i++)
            {
                int j = i + l;

                // already initilized m[i][j] = INT_MAX
                for (int k = i; k < j; k++)
                {
                    int cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                    if ( cost < m[i][j] )
                    {
                        m[i][j] = cost;
                        s[i][j] = k;
                    }
                }
            }
        }

        // now m and s have been obtained
        // one can access the result he wants
        // for example, the minimum operation numbers
        return m[0][n];
    }
};