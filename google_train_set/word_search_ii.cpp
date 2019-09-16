class Solution {
public:
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	void dfs(std::vector<std::vector<char>>& board,
			 std::string cur_word,
	         std::unordered_set<std::string>& word_set,
	         std::unordered_set<std::string>& prefix_word,
	         std::unordered_set<std::string>& res,
	         std::vector<std::vector<int>>& visited,
	         int x, int y
	         ) // 8 - 9 stuff
	{	
		if (prefix_word.count(cur_word) == 0)
			return;
		if (word_set.count(cur_word) > 0)
			res.insert(cur_word);

		std::cout << "cur_word = " << cur_word << ", x = " << x << ", y =" << y << std::endl;

		for (int i = 0; i < 4; i++)
		{
			int x_next = x + dx[i];
			int y_next = y + dy[i];

			if ( !isInside(board, x_next, y_next) )
				continue;
			if (visited[x_next][y_next] == 1)
				continue;
			
			visited[x_next][y_next] = 1;
			dfs(board, cur_word + board[x_next][y_next], word_set, prefix_word, res, visited, x_next, y_next);
			visited[x_next][y_next] = 0;
		}
	}

	bool isInside(std::vector<std::vector<char>>& board, int x, int y)
	{
		return ( x >= 0 && y >= 0 && x < board.size() && y < board[0].size() );
	}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	// exception check
    	if (board.size() == 0 || board[0].size() == 0) 
    		return {};

        // construct word_set
        // construct prefix_word
        std::unordered_set<std::string> word_set;
        std::unordered_set<std::string> prefix_word;
        for (auto& word : words)
        {
        	word_set.insert(word);
        	for (int i = 0; i < word.size(); i++)
        		prefix_word.insert( word.substr(0, i + 1) );
        }

        // obtain an unordered set of res
        // construct a visit map
        std::unordered_set<std::string> res;
        for (int i = 0; i < board.size(); i++)
        {
        	for (int j = 0; j < board[0].size(); j++)
        	{
        		std::vector<std::vector<int>> visited( board.size(), std::vector<int>(board[0].size(), 0) );
        		std::string cur_word = "";
        		cur_word += board[i][j];
        		visited[i][j] = 1;
        		dfs(board, cur_word, word_set, prefix_word, res, visited, i, j);
        	}
        }

        // construct the final result
        std::vector<std::string> result;
        for (auto it = res.begin(); it != res.end(); it++)
        	result.push_back(*it);

        return result;
    }
};

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    
    bool isInside(std::vector<std::vector<char>>& board, int x, int y)
    {
        return ( x >= 0 && y >= 0 && x < board.size() && y < board[0].size() );
    }
    
    void dfs(std::vector<std::vector<char>>& board,
             std::unordered_set<std::string>& word_set,
             std::string word,
             std::unordered_set<std::string>& res,
             std::vector<std::vector<int>>& visited,
             std::unordered_set<std::string>& prefix_set,
             int x, 
             int y)
    {   
        if (prefix_set.count(word) == 0)
            return;
        
        if (word_set.count(word) > 0)
            res.insert(word);
        
        for (int i = 0; i < 4; i++)
        {
            int x_next = x + dx[i];
            int y_next = y + dy[i];
            
            if (isInside(board, x_next, y_next) == false)
                continue;
            
            if ( visited[x_next][y_next]  == 1)
                continue;
            
            visited[x_next][y_next] = 1;
            dfs(board, word_set, word + board[x_next][y_next], res, visited, prefix_set, x_next, y_next);
            visited[x_next][y_next] = 0;
        }
    }
    
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        if (board.size() == 0 || board[0].size() == 0)
            return {};
        
        std::unordered_set<std::string> prefix_set;
        std::unordered_set<std::string> word_set;
        for (auto& word : words)
        {
            word_set.insert(word);
            for (int i = 0; i < word.size(); i++)
                prefix_set.insert( word.substr(0, i + 1) );
        }
        
        std::unordered_set<std::string> res;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {   
                std::vector<std::vector<int>> visited( board.size(), std::vector<int>( board[0].size(), 0) );
                visited[i][j] = 1;
                std::string start = "";
                start += board[i][j];
                dfs(board, word_set, start, res, visited, prefix_set, i, j);
            }
        }
        
        std::vector<std::string> result;
        for (auto it = res.begin(); it != res.end(); it++)
            result.push_back(*it);
        
        return result;
    }
};
