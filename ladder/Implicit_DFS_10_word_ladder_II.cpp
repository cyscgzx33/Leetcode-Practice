class Solution {
public:
	// calculate the next words
	std::vector<std::string> getNextWords(std::string& word, std::unordered_set<std::string>& dict) 
	{
		std::vector<std::string> next_words;
		for (char c = 'a'; c <= 'z'; c++) {
			for (int i = 0; i < word.size(); i++) {
				if (c == word[i]) continue;
				std::string new_word = word;
				new_word[i] = c; // a naive method to replace
				if (dict.count(new_word) > 0) next_words.push_back(new_word);
			}
		}

		return next_words;
	}

	// construct the map about the distance from specific node to end node 
	// the queue stores the node that needs to be visited
	void bfs(std::string& start,
		     std::string& end,
		     std::unordered_map<std::string, int>& distance,
		     std::unordered_set<std::string>& dict)
	{
		std::queue<std::string> queue_traj;
		distance[start] = 0;
		queue_traj.push(start);

		while (queue_traj.size() > 0) {
			std::string cur_word = queue_traj.front();
			queue_traj.pop();

			// calculate the next word
			std::vector<std::string> next_words = getNextWords(cur_word, dict);
			for (auto& next_word : next_words) {
				if (distance.count(next_word) > 0) continue;
				distance[next_word] = distance[cur_word] + 1;
				queue_traj.push(next_word);
			}
		}
	}

	// search paths
	void dfs(std::string& cur_word,
		     std::string& target,
		     std::unordered_map<std::string, int>& distance,
		     std::unordered_set<std::string>& dict,
		     std::vector<std::string>& ladder,
		     std::vector<std::vector<std::string>>& ladders)
	{
		if (cur_word == target) {
			ladders.push_back(ladder);
			return;
		}

		std::vector<std::string> next_words = getNextWords(cur_word, dict);
		for (auto& next_word : next_words) {
			if (distance[cur_word] - distance[next_word] != 1) continue;
			ladder.push_back(next_word);
			dfs(next_word, target, distance, dict, ladder, ladders);
			ladder.pop_back();
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

        // first step: bfs, get distance table (distance to the end)
        std::unordered_map<std::string, int> distance;
        bfs(end, start, distance, dict);

        // second step: dfs, find all the cloest paths/ladders
        std::vector<std::string> ladder;
		std::vector<std::vector<std::string>> ladders;
        dfs(start, end, distance, dict, ladder, ladders);
        return ladders;
    }
};