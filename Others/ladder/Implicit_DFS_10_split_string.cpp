class Solution {
public:
	void dfs(std::vector<std::string>& result,
		     std::vector<std::vector<std::string>>& results,
		     int start_index,
		     std::string& s,
		     bool is_last_elem_couple)
	{
		if ( start_index == s.size() ) {
			results.push_back(result);
			return;
		}

		std::string cur_str = "";
		result.push_back( cur_str + s[start_index] );
		dfs(result, results, start_index + 1, s, false);
		result.pop_back();

		if ( is_last_elem_couple ) return;
		result.back() += s[start_index];
		dfs(result, results, start_index + 1, s, true);
		result.back().pop_back();
	}
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        // write your code here
        std::vector<std::string> result;
        std::vectpr<std::vector<std::string>> results;

        dfs(result, results, 0, s, true);
        return results;
    }
};