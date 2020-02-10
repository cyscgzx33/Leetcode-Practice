class Solution {
public:
	std::vector<std::string> dfs(std::string str,
		     				 std::unordered_set<std::string>& wordDict,
		     				 std::unordered_map<std::string, std::vector<std::string>>& memo)
	{
		if (str.length() == 0)
			return {};

		if (memo.count(str) > 0)
			return memo[str];

		std::vector<std::string> partitions;
		for (int i = 1; i < str.length(); i++)
		{
			std::string prefix = str.substr(0, i);
			if (wordDict.count(prefix) == 0)
				continue;

			std::vector<std::string> postfixes = dfs(str.substr(i), wordDict, memo);
			for (auto& postfix : postfixes)
				partitions.push_back(prefix + " " + postfix);
		}

		if (wordDict.count(str) > 0)
			partitions.push_back(str);

		memo[str] = partitions;
		return partitions;
	}

    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here
        std::unordered_map<std::string, std::vector<std::string>> memo;
        return dfs(s, wordDict, memo);
    }
};