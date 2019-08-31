class Solution {
public:

	// Point 0: recursion definition
	bool dfs(std::string pattern, 
		     std::string str, 
		     std::unordered_set<std::string>& used,
		     std::unordered_map<char, std::string>& mapping)
	{
		// Point 1: exit criteria of recursion
		if (pattern.size() == 0) return str.size() == 0;

		// Point 2: taking apart the recursion
		char cur_char = pattern[0];
		if (mapping.count(cur_char) > 0) {
			std::string cur_word = mapping[cur_char];
			if (str.rfind(cur_word, 0) != 0) return false; // find the first time occurrance of cur_word in str
			return dfs(pattern.substr(1), str.substr( cur_word.size() ), used, mapping);
		}

		for (int i = 0; i < str.size(); i++) {
			// Note: important to check
			std::string cur_word = str.substr(0, i + 1);
			if (used.count(cur_word) > 0) continue;

			used.insert(cur_word);
			mapping[cur_char] = cur_word;
			if ( dfs(pattern.substr(1), str.substr( cur_word.size() ), used, mapping) ) return true;
			used.erase(cur_word);
			mapping.erase(cur_char);
		}
		
		return false;

	}
	
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        // write your code here
        std::unordered_set<std::string> used;
        std::unordered_map<char, std::string> mapping;
        return dfs(pattern, str, used, mapping);
    }
};