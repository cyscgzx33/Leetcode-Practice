class Solution {
public:
	bool memSearch(std::string& target,
				   std::string& pattern,
				   std::vector<std::vector<int>>& memo,
				   int t_id,
				   int p_id)
	{	
		// exit criteria I
		if ( t_id >= target.length() )
			return isValid( pattern.substr(p_id) );

		// exit criteria II
		if ( p_id >= pattern.length() )
			return false;

        // exit criteria III
		if (memo[p_id][t_id] > -1)
			return memo[p_id][t_id];

		bool matched;
		// taking apart recursion
		if ( p_id + 1 < pattern.size() && pattern[p_id + 1] == '*' )
		{
			// option I: '*' will matches 0 char (let the prev pateern char disapear)
        	bool option_I  = memSearch(target, pattern, memo, t_id, p_id + 2);
        	// option II: '*' will matches >= 1 char (duplicate multiple prev pattern char)
        	bool option_II = isMatchedChar( target[t_id], pattern[p_id] ) && 
        					 memSearch(target, pattern, memo, t_id + 1, p_id);
        	
        	matched = option_I || option_II;
		}
		else
			matched = isMatchedChar( target[t_id], pattern[p_id] ) && 
			          memSearch(target, pattern, memo, t_id + 1, p_id + 1);

		// log info into memo
		memo[p_id][t_id] = matched;
		return matched;
	}

	bool isValid(std::string rest_of_pattern) // rest_of_pattern must be like "X*X*..." or EMPTY
	{   
	    std:: cout << "rest_of_pattern = " << rest_of_pattern << std::endl; 
		if (rest_of_pattern.length() % 2 == 1)
			return false;

		for (int i = 0; i < rest_of_pattern.length() / 2; i++)
		{
			if (rest_of_pattern[2 * i + 1] != '*')
				return false;
		}

		return true;
	}
	
	bool isMatchedChar(char tar_char, char pat_char)
	{
		return tar_char == pat_char || pat_char == '.';
	}

    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) 
    {
    	std::vector<std::vector<int> > memo( p.length(), std::vector<int>(s.length(), -1) );
    	return memSearch(s, p, memo, 0, 0);
    }
};