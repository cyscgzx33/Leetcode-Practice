class Solution {
public:
    /*
     * @param source: A source string
     * @param target: A target string
     * @return: An integer as index
     */
     
    vector<int> computePrefixFunction(string& P)
    {
        int m = P.size() - 1;     // here we have to make sure it is consistent with definition of the main part
        vector<int> pi(m + 1, 0); // let's only take care of the 1 ... m parts
        int k = 0;

        for (int q = 2; q <= m; q++)
        {
            while (k > 0 && P[k+1] != P[q])
                k = pi[k];
            if (P[k+1] == P[q])
                k++;
            pi[q] = k;
        }

        return pi;
        
    }

    int strStr2(const char* source, const char* target) {
        if (source == nullptr || target == nullptr)
            return -1;
        string T(source), P(target);

        int m = P.size(), n = T.size();
        if (m == 0)
            return 0;
        if (n == 0) // since m != 0 now
            return -1;

        // modify the T and P to start over index 1 rather than 0
        T = "#" + T;
        P = "#" + P;

        // compute the prefix function
        vector<int> pi = computePrefixFunction(P);
        int q = 0;
        for (int i = 1; i <= n; i++)
        {
            while (q > 0 && P[q+1] != T[i])
                q = pi[q];
            if (P[q+1] == T[i])
                q++;
            if (q == m)
                return i - m;
        }

        return -1;
    }
};