/* EVALUATED */
#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    /**
     * @param p: sequence p = <p_0, p_1, ..., p_n> where A_i has dimensions p_i x p_{i+1} and p.length = n + 1
     * @return: minimum operation numbers
     */
    int matrixChainOrder(std::vector<int> &p) {
        int n = p.size() - 1;
        std::vector<std::vector<int>> m( n, std::vector<int>(n, INT_MAX) ); // stores costs
        std::vector<std::vector<int>> s( n, std::vector<int>(n, INT_MAX) ); // stores which index of k achieved the optimal cost

        // by difinition, m[i][i] means no multiplication, i.e., 0
        for (int i = 0; i < n; i++)
            m[i][i] = 0;

        for (int l = 2; l <= n; l++) // l is the chain length
        {
            for (int i = 0; i < n - l + 1; i++)
            {
                int j = i + l - 1;

                // already initilized m[i][j] = INT_MAX
                for (int k = i; k < j; k++)
                {
                    int cost = m[i][k] + m[k+1][j] + p[i] * p[k+1] * p[j+1];
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
        std::cout << "m[i][j]: \n"; 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << m[i][j] << ", ";
            }
            std::cout << std::endl;
        }

        std::cout << "s[i][j]: \n"; 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << s[i][j] << ", ";
            }
            std::cout << std::endl;
        }

        return m[0][n-1];
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    // std::vector<int> p = {6, 5, 20, 100, 15, 90, 60, 30, 100};
    std::vector<int> p = {2, 3, 5, 4, 6};

    std::cout << "minimum operation numbers of p is: " << sln.matrixChainOrder(p) << std::endl;
    return 0;
}