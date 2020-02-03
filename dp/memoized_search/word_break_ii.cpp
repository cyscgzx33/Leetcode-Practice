class Solution {
public:
    std::vector<std::string> memoSearch(std::unordered_map<std::string, std::vector<std::string>>& memo,
                                        std::unordered_set<std::string>& dict,
                                        std::string s)
    {
        if (s.size() == 0)
            return {};
        if (memo.count(s) > 0)
            return memo[s];

        std::vector<std::string> res;
        for (int i = 1; i <= s.size(); i++)
        {
            std::string prefix = s.substr(0, i);
            if (dict.count(prefix) == 0)
                continue;

            std::vector<std::string> postfixes = memoSearch( memo, dict, s.substr(i) );

            for (auto postfix : postfixes)
            {
                std::string tmp = prefix + " " + postfix;
                res.push_back(tmp);
            }
        }

        if (dict.count(s) > 0)
            res.push_back(s);

        memo[s] = res;
        return res;
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        std::unordered_map<std::string, std::vector<std::string>> memo;
        std::unordered_set<std::string> dict( wordDict.begin(), wordDict.end() );
        return memoSearch(memo, dict, s);
    }
};