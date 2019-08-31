class Solution {
public:
	bool memSearch(std::string& pattern,
				   std::string& target,
				   std::vector<std::vector<int> >& memo,
				   int pt_index,
				   int tg_index)
	{
		// exit criteria I: target empty
		if (target.size() == tg_index) // if target is empty
		{
			// every next character in pattern should be '*'
			for (int i = pt_index; i < pattern.size(); i++)
				if (pattern[i] != '*') return false;
			return true;
		}

		// exit criteria II: pattern empty
        if (pattern.size() <= pt_index) // if pattern is empty 
        	return false; // the exit criteria I indicates that target is not empty
        
        // exit criteria III: if visited
		if (memo[pt_index][tg_index] > -1) return memo[pt_index][tg_index];
        
        // taking apart the recursion
        bool matched;
        if ( pattern[pt_index] == '*' ) 
        {
        	// option I: '*' matches >= 1 characters in target
        	bool option_I  = memSearch(pattern, target, memo, pt_index, tg_index + 1);
        	// option II: '*' matches 0 character in target
        	bool option_II = memSearch(pattern, target, memo, pt_index + 1, tg_index);
        	
        	matched = option_I || option_II;
        } 
        else if ( pattern[pt_index] == '?' )
        	matched = memSearch(pattern, target, memo, pt_index + 1, tg_index + 1);
        else
        	matched =  pattern[pt_index] == target[tg_index] && memSearch(pattern, target, memo, pt_index + 1, tg_index + 1);

        // log visited in the memo, then return
        memo[pt_index][tg_index] = matched;
        return memo[pt_index][tg_index];
	}
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) 
    {
    	std::vector<std::vector<int> > memo( p.size(), std::vector<int>(s.size(), -1) ); // not visited
    	return memSearch(p, s, memo, 0, 0);
    }
};