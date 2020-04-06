class Solution {
public:
    // intuition: make sure a >= b >= c, otherwise rotate
    // always try to add aa, if after this adding, a >= b, add bb
    string longestDiverseString(int a, int b, int c, char aa, char bb, char cc)
    {
        if (a < b)
            return longestDiverseString(b, a, c, bb, aa, cc);
        if (b < c)
            return longestDiverseString(a, c, b, aa, cc, bb);
        
        if (b == 0)
            return string(min(2, a), aa);
        int use_b = a - min(2, a) >= b ? 1 : 0;
        return string(min(2, a), aa) + string(use_b, bb) + longestDiverseString(a - min(2, a), b - use_b, c, aa, bb, cc);
    }
    string longestDiverseString(int a, int b, int c) {
        return longestDiverseString(a, b, c, 'a', 'b', 'c');
    }
};