class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k <= 0)
            return 0;

        int left = 0, right = 0, max_len = 0;
        std::unordered_map<char, int> char_2_cnt;
        while( right < s.size() )
        {
            char_2_cnt[ s[right] ]++;
            right++;
            while(char_2_cnt.size() > k)
            {
                char_2_cnt[ s[left] ]--;
                if (char_2_cnt[ s[left] ] == 0)
                    char_2_cnt.erase( s[left] );
                left++;
            }

            max_len = max(max_len, right - left);
        }

        return max_len;
    }
};