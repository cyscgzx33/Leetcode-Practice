class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    // A Method returns a pair of values using pair 
    std::pair<int, int> longestPalindrome(const std::string& str, int left, int right) 
    { 
        while (left >= 0 && right < str.size() && str[left] == str[right])
        {
            left--;
            right++;
        }           

        // the return format is: {start, longest}
        return std::make_pair(left + 1, right - left - 1);
    } 
    
    string longestPalindrome(string &s) {
        // write your code here
        if ( s.empty() ) return 0;
        
        int start = 0, longest = 0;
        for (int middle = 0; middle < s.size(); middle++) 
        {
            // Case I: the middle line is an actual char of the string
            std::pair<int, int> res_actual = longestPalindrome(s, middle, middle);
            if (longest < res_actual.second) 
            {
                longest = res_actual.second;
                start = res_actual.first;
            }
            
            // Case II: the middle line is an virtual line between two chars of the string
            std::pair<int, int> result_virtual = longestPalindrome(s, middle, middle + 1);
            if (longest < result_virtual.second) 
            {
                longest = result_virtual.second;
                start = result_virtual.first;
            }
        }
        
        return s.substr(start, longest);        
    }
};