class Solution {
public:
	bool dfs(std::string& pattern,
			 int p_id,
			 std::string& target,
			 int t_id,
			 std::unordered_set<std::string>& used,
			 std::unordered_map<char, std::string>& mapping)
	{
		if ( p_id == pattern.size() )
			return t_id == target.size();

		int cur_p = pattern[p_id];
		std::string cur_target = target.substr(t_id);
		if (mapping.count(cur_p) > 0)
		{
			if (cur_target.rfind( mapping[cur_p] ) != 0) return false;
			return dfs(pattern, p_id + 1, target, t_id + mapping[cur_p].size(), used, mapping);
		}

		bool matched = false;
		for (int i = 0; i < cur_target.size(); i++)
		{
			std::string new_target = cur_target.substr(0, i + 1); // the range is [0, i+1)
			if ( used.count(new_target) ) 
				continue; // the mapping between pattern to target is a singly map
						  // i.e., not allowing neither multiple-to-one, nor one-to-multiple

			// start to backtracking process
			used.insert(new_target);
			mapping[cur_p] = new_target;
			// matched = matched || dfs(pattern, p_id + 1, target, t_id + i + 1, used, mapping);
			if (dfs(pattern, p_id + 1, target, t_id + i + 1, used, mapping)) return true;
			mapping.erase(cur_p);
			used.erase(new_target);
		}

		// return matched;
		return false;
	}

    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        std:unordered_set<std::string> used;
        std::unordered_map<char, std::string> mapping;
        return dfs(pattern, 0, str, 0, used, mapping);
    }
};

/* [Input]
 * "aaaa"
 * "dogdogdogdog"
 *
 * [Output]
 * false
 *
 * [Expected]
 * true
 *
 * */

class Solution {
public:
	bool dfs(std::string& pattern,
			 int p_id,
			 std::string& target,
			 int t_id,
			 std::unordered_set<std::string>& used,
			 std::unordered_map<char, std::string>& mapping)
	{
		if ( p_id == pattern.size() )
			return t_id == target.size();

		int cur_p = pattern[p_id];
		std::string cur_target = target.substr(t_id);
		if (mapping.count(cur_p) > 0)
		{
			if (cur_target.rfind( mapping[cur_p] ) != 0) return false;
			return dfs(pattern, p_id + 1, target, t_id + mapping[cur_p].size(), used, mapping);
		}

		bool matched = false;
		for (int i = 0; i < cur_target.size(); i++)
		{
			std::string new_target = cur_target.substr(0, i + 1); // the range is [0, i+1)
			if ( used.count(new_target) ) 
				continue; // the mapping between pattern to target is a singly map
						  // i.e., not allowing neither multiple-to-one, nor one-to-multiple

			// start to backtracking process
			used.insert(new_target);
			mapping[cur_p] = new_target;
			matched = matched || ( dfs(pattern, p_id + 1, target, t_id + i + 1, used, mapping) );
			mapping.erase(cur_p);
			used.erase(new_target);
		}

		return matched;

	}

    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        std:unordered_set<std::string> used;
        std::unordered_map<char, std::string> mapping;
        return dfs(pattern, 0, str, 0, used, mapping);
    }
};

/* [Input]
 * "aaaa"
 * "dogdogdogdog"
 *
 * [Output]
 * false
 *
 * [Expected]
 * true
 *
 * */