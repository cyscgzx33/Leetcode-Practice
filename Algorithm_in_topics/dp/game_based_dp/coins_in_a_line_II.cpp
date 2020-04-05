class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        
        // f[i] indicates the max value diff to fetch the coins between [, ..., n-1], suppo
        // state transition equation: f[i] = max(a[i] - f[i-1], a[i] + a[i+1] - f[i-2])
        vector<int> f(n + 1, 0);
        f[n-1] = values[n-1]; // Note: one can also derive it thru the equation, but it should be changed into f[i] = max(a[i] - f[i-1]), thus f[n-1] = a[n-1]
        
        for (int i = n-2; i >= 0; i--)
            f[i] = max(values[i] - f[i+1], values[i] + values[i+1] - f[i+2]);
            
        return f[0] >= 0; // it means: the max value diff to fetch the coins between [0, ..., n-1] (i.e., all the coins) is >= 0
    }
};