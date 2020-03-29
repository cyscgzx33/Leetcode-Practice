#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> naiveCompare(string& s, int L, int R)
    {
        int len = s.length();
        while (R < len && s[L] == s[R])
        {
            // move forward with same pace until unequal
            L++;
            R++;
        }
        // finally return the last equal position pair
        return {L, R};
    }

    string longestPrefix(string s) {
        // Essential: Z vector construction
        int len = s.length();
        if (len == 1)
            return "";

        vector<int> Z(len, 0);
        int L = 0, R = 0;
        int K = 1; // iteration index

        while (K < len)
        {
            // Case I: K > R
            if (K > R)
            {
                vector<int> updated_pos = naiveCompare(s, 0, K);
                int steps = updated_pos[0] - 0; // steps forward, indicating # of characters equal to prefix
                Z[K] = steps;
                if (steps > 0)
                {
                    L = K;
                    R = K + steps - 1;
                }
            }
            // Case II: K <= R
            else
            {
                // calculate length of alpha, beta
                int len_alpha = R - L + 1;
                int len_beta = R - K + 1;
                // calculate position of K'
                int K_prime = len_alpha - len_beta;
                int len_gamma = Z[K_prime];

                // Case II-a: Z[K'] > len_beta
                if (Z[K_prime] > len_beta)
                    Z[K] = len_beta;
                // Case II-b: Z[K'] < len_beta
                else if (Z[K_prime] < len_beta)
                    Z[K] = Z[K_prime];
                // Case II-c: Z[K'] == len_beta
                else
                {
                    vector<int> updated_pos = naiveCompare(s, len_gamma, R + 1);
                    int steps = updated_pos[0] - len_gamma;
                    Z[K] = len_beta + steps;
                    if (steps != 0)
                    {
                        L = K;
                        R = R + steps;
                    }
                }
            }
            if (K + Z[K] == len)
                return s.substr(K, Z[K]);
            K++;
        }

        return "";
    }
};