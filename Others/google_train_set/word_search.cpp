/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
*/

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.


class Solution {
public:
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
    bool isInside(std::vector<std::vector<char>>& board,
    			  int x, int y)
    {
    	return ( x >= 0 && y >= 0 && x < board.size() && y < board[0].size() );
    }
	bool dfs(std::string cur_word,
			 std::string& target,
		     std::vector<std::vector<char>>& board,
		     std::vector<std::vector<int>>& visited,
		     std::unordered_set<std::string>& prefix_word,
		     int x, int y)
	{
		if (prefix_word.count(cur_word) == 0)
			return false;
		if (cur_word == target)
			return true;

		for (int i = 0; i < 4; i++)
		{
			int x_next = x + dx[i];
			int y_next = y + dy[i];

			if ( !isInside(board, x_next, y_next) )
				continue;

			if (visited[x_next][y_next] == 1)
				continue;
			visited[x_next][y_next] = 1;
			bool matched = dfs(cur_word + board[x_next][y_next], target, board, visited, prefix_word, x_next, y_next);
			visited[x_next][y_next] = 0;
		}

	}
    bool exist(vector<vector<char>>& board, string word) {
        
    	if (board.size() == 0 || board[0].size() == 0)
    		return false;

    	// construct prefix_word
    	std::unordered_set<std::string> prefix_word;
    	for (int i = 0; i < word.size(); i++)
    		prefix_word.insert( word.substr(0, i + 1) );

    	bool res = false;
    	for (int i = 0; i < board.size(); i++)
    	{
    		for (int j = 0; j < board[0].size(); j++)
    		{
    			std::vector<std::vector<int>> visited( board.size(), std::vector<int>(board[0].size(), 0) );
    			visited[i][j] = 1;
    			std::string cur_word = "";
    			cur_word += board[i][j];
    			dfs(cur_word, word, res, board, visited, prefix_word, i, j);
    		}
    	}
    	
    	return res;

    }
};


class Solution {
public:
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};

	bool isInside(std::vector<std::vector<char>>& board, int x, int y)
    {
    	return ( x >= 0 && y >= 0 && x < board.size() && y < board[0].size() );
    }

    bool dfs(vector<vector<char>>& board, 
    	     string& word, 
    	     vector<vector<bool>>& visited,
    	     int idx, int x, int y) 
    {
    	if ( idx == word.size() )
    		return true;

    	for (int i = 0; i < 4; i++)
    	{
    		int x_next = x + dx[i];
    		int y_next = y + dy[i];

    		if (isInside(board, x_next, y_next) == false)
    			continue;
    		if (visited[x_next][y_next] == true)
    			continue;
    		if ( board[x_next][y_next] != word[idx + 1] )
    			continue;
    		visited[x_next][y_next] = true;
    		if ( dfs(board, word, visited, idx + 1, x_next, y_next) )
    			return true;
    		visited[x_next][y_next] = false;
    	}

    	return false;
    }	

    bool exist(vector<vector<char>>& board, string word) 
    {
    	if (board.size() == 0 || board[0].size() == 0)
    		return false;

    	int m = board.size(), n = board[0].size();

    	for (int i = 0; i < m; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{	
    			if ( board[i][j] != word[0] )
    				continue;
    			std::vector<std::vector<bool>> visited( m, std::vector<bool>(n, false) );
    			visited[i][j] = true;
    			if ( dfs(board, word, visited, 1, i, j) )
    				return true;
    		}
    	}

    	return false;
    }

};