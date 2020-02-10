class Solution {
public:
    /*
     * @param s: a string
     * @param dict: a set of n substrings
     * @return: the minimum length
     */
    int minLength(string &s, unordered_set<string> &dict) {
        // write your code here
        std::queue<std::string> q;
        std::unordered_set<std::string> visit;

        int min_sz = s.size();
        q.push(s);
        visit.insert(s);

        while (q.size() > 0)
        {
        	std::string cur = q.front();
        	q.pop();

        	for (auto& sub_str : dict)
        	{
        		int found = cur.find(sub_str);
        		while (found != -1)
        		{
        			std::string new_s = cur.substr(0, found) + cur.substr( found + sub_str.size(), cur.size() - found - sub_str.size());
        			if (visit.count(new_s) == 0)
        			{
        				if (new_s.size() < min_sz)
        					min_sz = new_s.size();
        				q.push(new_s);
        				visit.insert(new_s);
        			}
        			found = cur.find(sub_str, found + 1);
        		}
        	}
        }

        return min_sz;
    }
};

class Solution {
public:
    /*
     * @param s: a string
     * @param dict: a set of n substrings
     * @return: the minimum length
     */
    int minLength(string &s, unordered_set<string> &dict) {
    	std::queue<std::string> q;
    	std::unordered_set<std::string> visit;

    	int min_sz = s.size();
    	q.push(s);
    	visit.insert(s);

    	while (q.size() > 0)
    	{
    		std::string cur = q.front();
    		q.pop();
    		for (auto& sub_str : dict)
    		{
    			int found = cur.find(sub_str);
    			while (found != -1)
    			{
    				std::string new_s = cur.substr(0, found) 
    								  + cur.substr( found + sub_str.size() );
    				if (visit.count(new_s) == 0)
    				{
    					if (new_s.size() < min_sz)
    						min_sz = new_s.size();
    					q.push(new_s);
    					visit.insert(new_s);
    				}
    				found = cur.find(sub_str, found + 1);
    			}
    		}
    	}

    	return min_sz;
    }
};