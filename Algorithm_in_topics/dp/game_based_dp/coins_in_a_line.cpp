class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        /**
         * 0. Meaning of state f[i]: when facing i coins, if I start first, will I win or lose (for sure)?
         * 1. State transition equation: f[i] = f[i-1] == false || f[i-2] == false
         * 2. Initial condition or boundary condition: f[0] = false, f[1] = true
         * 3. Direction of recursion: f[0], f[1], ... f[n-1]
         */
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        vector<bool> f(n + 1, false);
        f[1] = true;
        
        for (int i = 2; i < n + 1; i++)
            f[i] = f[i-1] == false || f[i-2] == false;
        
        return f[n];
    }
};