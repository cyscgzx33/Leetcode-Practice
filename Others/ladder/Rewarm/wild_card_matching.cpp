class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool memSearch(std::string& p,
                   int p_id,
                   std::string& s,
                   int s_id,
                   std::vector<std::vector<int>>& memo)
    {
        if (p.size() == p_id)
            return s.size() == s_id;

        if (s.size() == s_id)
        {
            for (int i = p_id; i < p.size(); i++)
            {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }

        if (memo[p_id][s_id] > -1)
            return memo[p_id][s_id];

        bool matched = false;

        if (p[p_id] == '*')
        {
            bool option_I  = memSearch(p, p_id + 1, s, s_id, memo);
            bool option_II = memSearch(p, p_id, s, s_id + 1, memo);
            matched = option_I || option_II;
        }
        else
        {
            matched = ( p[p_id] == '?' || p[p_id] == s[s_id] ) && memSearch(p, p_id + 1, s, s_id + 1, memo);
        }

        memo[p_id][s_id] = matched;
        return matched;
    }
    
    bool isMatch(std::string& s, std::string& p)
    {
        std::vector<std::vector<int>> memo( p.size(), std::vector<int>(s.size(), -1) );
        return memSearch(p, 0, s, 0, memo);
    }
};