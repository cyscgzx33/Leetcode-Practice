#include <string>
#include <iostream>
#include <vector>

using namespace std;

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

vector<int> patternMatch(string& s, string& p)
{
    // S = l e e t $ l e e t c o d e l e e t
    string S = p;
    S.push_back('$'); // divider
    S += s;

    // Essential: Z vector construction
    int len = S.length();
    vector<int> Z(len, 0);
    int L = 0, R = 0;
    int K = 1; // iteration index

    while (K < len)
    {
        // Case I: K > R
        if (K > R)
        {
            vector<int> updated_pos = naiveCompare(S, 0, K);
            int steps = updated_pos[0]; // steps forward, indicating # of characters equal to prefix
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
        K++;
    }

    return Z;
}

int main(int argc, char** argv)
{
    string source = "leetcodeleet";
    string pattern = "leet";

    vector<int> Z_vec = patternMatch(source, pattern);

    cout << "Z values starting from Z[1] are: ";
    for (auto Z_val : Z_vec)
        cout << Z_val << ", ";
    cout << endl;
    return 0;
}