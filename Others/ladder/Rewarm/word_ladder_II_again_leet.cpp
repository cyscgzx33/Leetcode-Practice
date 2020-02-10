class Solution {
public:
	// calculate the next words
	std::vector<std::string> getNextWords(std::string& cur_word,
		     							  std::unordered_set<std::string>& dict) 
	{
		std::vector<std::string> next_words;
		for (char c = 'a'; c <= 'z'; c++)
		{
			for (int i = 0; i < cur_word.size(); i++)
			{
				std::string new_word = cur_word;
				if (new_word[i] == c)
					continue;
				new_word[i] = c;
				if (dict.count(new_word) > 0)
					next_words.push_back(new_word);
			}
		}
		return next_words;
	}

	// construct the map about the distance from specific node to end node 
	// the queue stores the node that needs to be visited
	void bfs(std::string& start,
		     std::string& end,
		     std::unordered_set<std::string>& dict,
		     std::unordered_map<std::string, int>& dist_map)
	{
		std::queue<std::string> q;
		q.push(start);

		while (q.size() > 0)
		{
			std::string cur_word = q.front();
			q.pop();

			std::vector<std::string> next_words = getNextWords(cur_word, dict);
			for (auto next_word : next_words)
			{	
				if (next_word == end)
				{
					dist_map.insert( {next_word, dist_map[cur_word] + 1} );
					return;
				}
				if (dist_map.count(next_word) > 0)
					continue;
				dist_map.insert( {next_word, dist_map[cur_word] + 1} );
				q.push(next_word);
			}
		}
	}

	// search paths
	void dfs(std::vector<std::string>& path,
			 std::vector<std::vector<std::string>>& paths,
			 std::unordered_set<std::string>& dict,
			 std::unordered_map<std::string, int>& dist_map)
	{
		if (dist_map[ path.back() ] == 1)
		{
			paths.push_back(path);
			return;
		}

		std::string cur_word = path.back();
		std::vector<std::string> next_words = getNextWords(cur_word, dict);
		for (auto next_word : next_words)
		{
			if ( dist_map.count(next_word) == 0 || dist_map[cur_word] <= dist_map[next_word] )
				continue;
			path.push_back(next_word);
			dfs(path, paths, dict, dist_map);
			path.pop_back();
		}
	}

    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
/*    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        // step 0: preparation
        dict.insert(start);
        dict.insert(end);
        // step 1: construct dist_map via bfs
        std::unordered_map<std::string, int> dist_map;
        dist_map.insert( {end, 1} );
        bfs(end, start, dict, dist_map);
        // step 2: traverse the dist_map via dfs
        std::vector<std::string> path;
        std::vector<std::vector<std::string>> paths;
        path.push_back(start);
        dfs(path, paths, dict, dist_map);
        return paths;
    }*/

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	std::unordered_set<std::string> dict( wordList.begin(), wordList.end() );
        dict.insert(beginWord);
        std::unordered_map<std::string, int> dist_map{ {endWord, 1} };

        // construct the dist_map via bfs
        bfs(endWord, beginWord, dict, dist_map);
        
        // for (auto it = dist_map.begin(); it != dist_map.end(); it++)
        // 	std::cout << "{word, int} = {" << it->first << ", " << it->second << "}\n";

        // std::cout << "dist_map.size() = " << dist_map.size() << std::endl; 
        // traverse the dist_map and find the path via dfs
        std::vector<std::vector<std::string>> paths;
        std::vector<std::string> path{ {beginWord} };
        dfs(path, paths, dict, dist_map);

        return paths;
    }    
};