class Solution {
public:
    // calculate the next words
    std::vector<std::string> getNextWords(std::string& word,
                                          std::unordered_set<std::string>& dict)
    {
        std::vector<std::string> next_words;
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (c == word[i])
                    continue;
                std::string new_word = word;
                new_word[i] = c;
                if (dict.count(new_word) > 0)
                    next_words.push_back(new_word);
            }
        }
        return next_words;
    }
    
    // obtain dist_map using bfs
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
    
                if (dict.count(cur_word) == 0 || dist_map.count(next_word) > 0)
                    continue;
                dist_map.insert( {next_word, dist_map[cur_word] + 1} );
                q.push(next_word);
            }
        }
    }
    
    // search paths according to dist_map using dfs
    void dfs(std::vector<std::vector<std::string>>& paths,
             std::vector<std::string>& path,
             std::unordered_set<std::string>& dict,
             std::unordered_map<std::string, int>& dist_map)
    {
        if (dist_map[ path.back() ] == 1)
        {
            paths.push_back(path);
            return;
        }
    
        for ( auto next_word : getNextWords(path.back(), dict) )
        {
            if ( dist_map.count(next_word) == 0 || dist_map[next_word] != dist_map[ path.back() ] - 1 )
                continue;
            path.push_back(next_word);
            dfs(paths, path, dict, dist_map);
            path.pop_back();
        }
    }
    
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        dict.insert(start);
        dict.insert(end);
        // Step I: using bfs to obtain dist_map
        std::unordered_map<std::string, int> dist_map;
        dist_map.insert( {end, 1} );
        bfs(end, start, dict, dist_map);
        // Step II: using dfs to find out all the shortest paths
        std::vector<std::vector<std::string>> paths;
        std::vector<std::string> path;
        path.push_back(start);
        dfs(paths, path, dict, dist_map);
        // note: at least one path exists, skip the final check
        return paths;
    }
};