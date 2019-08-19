bool memSearch(std::vector<std::vector<int>>& memo,
			   std::string& pattern,
			   int p_id,
			   std::string& target,
			   int t_id)
{
	if (target.size() == t_id) 
	{
		for (int i = p_id; i < pattern.size(); i++)
			if (pattern[i] != '*') return false;
		return true;
	}

	if (pattern.size() == p_id)
		return false;

	if (memo[p_id][t_id] > -1) 
		return memo[p_id][t_id];

	bool matched;
	if (pattern[p_id] == '*') 
	{
		bool option_I  = memSearch(memo, pattern, p_id + 1, target, t_id);
		bool option_II = memSearch(memo, pattern, p_id, target, t_id + 1);
		matched = option_I || option_II;
	}
	else 
	{
		matched = ( pattern[p_id] == target[t_id] || pattern[p_id] == '?' ) && 
				  memSearch(memo, pattern, p_id + 1, target, t_id + 1);
	}

	memo[p_id][t_id] = matched;
	return matched;
}

bool isMatch(std::string& s, std::string& p)
{
	std::vector<std::vector<int>> memo( p.size(), std::vector<int>(s.size(), -1) );
	return memSearch(memo, p, 0, s, 0);
}