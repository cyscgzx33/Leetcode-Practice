class Solution {
public:
    int lengthOfLongestSubstring2Distinct(string s) {
        int left = 0, right = 0, max_len = 0;
        std::unordered_map<char, int> cnt;
        while( right < s.size() )
        {
            cnt[ s[right] ]++;
            right++;
            while ( cnt.size() > 2 )
            {
                cnt[ s[left] ]--;
                if (cnt[ s[left] ] == 0)
                    cnt.erase( s[left] );
                left++;
                std::cout << "cnt[ s[left] ] = " << cnt[ s[left] ] << std::endl;
                std::cout << " left = " << left << std::endl;
            }
            max_len = max(max_len, right - left);
        }

        return max_len;
    }
};