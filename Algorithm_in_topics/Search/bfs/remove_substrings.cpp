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
    			    std::string new_s = cur.substr(0, found) + cur.substr( found + sub_str.size() );
    				
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
        std::unordered_set<std::string> visit;
        std::queue<std::string> q{ {s} };

        int min_sz = s.size();
        while (q.size() > 0)
        {
            auto curr = q.front();
            q.pop();

            for (auto& word : dict)
            {
                std::size_t found = curr.find(word);
                while (found != std::string::npos)
                {
                    // erase the word part to get next_s
                    std::string next_s = curr.substr(0, found) + curr.substr( found + word.size() );

                    if (visit.count(next_s) == 0)
                    {
                        if (next_s.size() < min_sz)
                            min_sz = next_s.size();
                        q.push(next_s);
                        visit.insert(next_s);
                    }

                    // update found
                    found = curr.find(word, found + 1);
                }
            }
        }

        return min_sz;
    }
};