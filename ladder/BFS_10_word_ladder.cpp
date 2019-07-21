class Solution {
public:

	std::vector<std::string> getNextWords(std::unordered_set<std::string>& dict, std::string word) {

		// get a new_word by replacing the initial char with another char in [a, z] at position i,
		// push it back to next_words vector if such new_word exists in the dict
		std::vector<std::string> next_words;
		for (char c = 'a'; c <= 'z'; c++) {
			for (int i = 0; i < word.size(); i++) {
				if ( c == word[i] ) continue;
				std::string new_word = word;
				new_word[i] = c; // a naive method to replace
				if ( dict.find(new_word) == dict.end() ) continue;
				else next_words.push_back(new_word);
			}
		}

		return next_words;
	}


    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        
        // Step -1: stupid problem set, add end into the dict
        dict.insert(end);
            
    	// Step 0: basic preparation of BFS/queue
    	std::queue<std::string> q;
    	std::unordered_set<std::string> is_visited;
    	q.push(start);
    	is_visited.insert(start);
    	int length = 1;

    	while ( !q.empty() ) {

    		// Step 1: count the length based on level
    		length++;

    		// Step 2: loop based on the q.size()
    		int cur_q_size = q.size();
    		for (int i = 0; i < cur_q_size; i++) {
    			std:string cur_word = q.front();
    			q.pop();
	    		// Step 3: [Very Critical] get next words of current word
	    		std::vector<std::string> next_words = getNextWords(dict, cur_word);

	    		// Step 4: loop over the next_words, process them
	    		// Only if the next_word is not visited before
	    		for (auto next_word : next_words) {
	    			if ( is_visited.find(next_word) == is_visited.end() ) {
	    				if ( next_word == end ) return length;
	    				is_visited.insert(next_word);
	    				q.push(next_word);
	    			}
	    		}
    		}

    	}

    	return 0;


    }
};