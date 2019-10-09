class Solution {
public:
	std::vector<std::string> getNextWords(std::string cur_word,
										  std::unordered_set<std::string>& dict)
	{
		std::vector<std::string> next_words;
		// std::cout << "cur_word = " << cur_word << ", next_words = {";
		for (char c = 'a'; c < 'z'; c++)
		{
			for (int i = 0; i < cur_word.size(); i++)
			{	
				std::string new_word = cur_word;
				new_word[i] = c;
				if (dict.count(next_word) > 0)
				{
					// std::cout << next_word << ", ";
					next_words.push_back(new_word);
				}
			}
		}

		// std::cout << "}" << std::endl;

		return next_words;
	}

	void bfs(std::string start_word, 
			 std::string end_word,
		     std::unordered_set<std::string>& dict,
			 std::unordered_map<std::string, int>& dist_map)
	{
		// using queue to find the dist_map
		std::queue<std::string> q{ {start_word} };
		std::unordered_set<std::string> visit{ {start_word} };
		int dist = 1;

		while (q.size() > 0)
		{	
			dist++;
			int sz = q.size();
			for (int i = 0; i < sz; i++)
			{
				auto cur_word = q.front();
				q.pop();

				for (auto next_word : getNextWords(cur_word, dict) )
				{
					if (visit.count(next_word) > 0)
						continue;
					dist_map.insert( {next_word, dist} );
					if (next_word == end_word) // as soon as we find the end_word, exit
						return;
					visit.insert(next_word);
					q.push(next_word);
				}
			}
		}

		return;
	}

	void dfs(std::string cur_word,
			 std::string end_word,
             std::unordered_set<std::string>& dict,
			 std::unordered_map<std::string, int>& dist_map,
			 std::vector<std::string>& path,
			 std::vector<std::vector<std::string>>& paths)
	{
		if (cur_word == end_word)
		{
			paths.push_back(path);
			return;
		}

		for (auto next_word : getNextWords(cur_word, dict) )
		{
			if (dist_map.count(next_word) == 0 || dist_map[cur_word] - dist_map[next_word] != 1)
				continue;
			path.push_back(next_word);
			dfs(next_word, end_word, dict, dist_map, path, paths);
			path.pop_back();
		}
	}

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
    	std::unordered_set<std::string> dict( wordList.begin(), wordList.end() );
        std::unordered_map<std::string, int> dist_map{ {endWord, 1} };

        // construct the dist_map via bfs
        bfs(endWord, beginWord, dict, dist_map);
        
        // for (auto it = dist_map.begin(); it != dist_map.end(); it++)
        // 	std::cout << "{word, int} = {" << it->first << ", " << it->second << "}\n";

        // std::cout << "dist_map.size() = " << dist_map.size() << std::endl; 
        // traverse the dist_map and find the path via dfs
        std::vector<std::vector<std::string>> paths;
        std::vector<std::string> path{ {beginWord} };
        dfs(beginWord, endWord, dict, dist_map, path, paths);

        return paths;
    }
};