class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {

        /**
         * Note 1: must maintain two types of variables: 1) frequency of source/target
         *                                               2) unique count of source/target
         * Note 2: using ++/-- combined with other commands might deteriate 
         *         the structure of the code... (does NOT look beautiful...)
         */

        vector<int> s_freq(256, 0);
        vector<int> t_freq(256, 0);
        int s_uni_cnt = 0, t_uni_cnt = 0;

        for (auto tar : target)
        {   
            if (t_freq[tar]++ == 0)
                t_uni_cnt++; 
        }

        int l = 0, r = 0;
        string res = "";
        for (r; r < source.size(); r++)
        {
            char r_char = source[r];
            if (s_freq[r_char]++ == t_freq[r_char] - 1)
                s_uni_cnt++;

            while (s_uni_cnt >= t_uni_cnt && l <= r)
            {
                if (res == "" || res.size() > r - l + 1)
                    res = source.substr(l, r - l + 1);
                char l_char = source[l++];
                if (s_freq[l_char]-- == t_freq[l_char])
                    s_uni_cnt--;
            }
        }

        return res;
    }
};

/* another version w/o too much combination of ++/-- with other commands */
class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here
        std::vector<int> t_freq(256, 0);
        std::vector<int> s_freq(256, 0);
        
        int t_uni_cnt = 0;
        int s_uni_cnt = 0;
        
        for (auto t : target)
        {
            if (t_freq[t] == 0)
                t_uni_cnt++;
            t_freq[t]++;
        }
        
        int n = source.size();
        int l = 0, r = 0;
        std::string res = source;
        bool res_found = false;
        for (r; r < n; r++)
        {
            if (s_freq[source[r]] == t_freq[source[r]] - 1)
                s_uni_cnt++;
            s_freq[source[r]]++;
            
            if (res_found == false && t_uni_cnt == s_uni_cnt)
                res_found = true;
            
            while (l <= r && t_uni_cnt == s_uni_cnt)
            {
                if ( r - l + 1 < res.size() )
                    res = source.substr(l, r - l + 1);
                if ( s_freq[source[l]] == t_freq[source[l]] )
                    s_uni_cnt--;
                s_freq[source[l]]--;
                l++;
            }
        }
        
        return res_found ? res : "";
    }
};