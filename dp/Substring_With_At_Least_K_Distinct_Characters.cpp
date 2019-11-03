class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
    long long kDistinctCharacters(string &s, int k) {
        // Write your code here
        std::unordered_map<char, long long> mapping;
        
        long long n = s.size();
        long long left = 0, right = 0;
        long long cnt = 0;
        while ( right < n)
        {
            while (mapping.size() < k && right < n)
            {
                mapping[ s[right] ]++;
                right++;
            }
            
            while (mapping.size() == k && left <= right)
            {
                cnt += (n - right + 1); // everything starting with left counts
                mapping[ s[left] ]--;
                if (mapping[ s[left] ] == 0)
                    mapping.erase( s[left] );
                left++;
            }
        }
        
        return cnt;
    }
};