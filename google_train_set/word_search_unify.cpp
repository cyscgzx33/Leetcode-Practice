#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};

	bool isInside(std::vector<std::vector<char>>& board, int x, int y)
    {
    	return ( x >= 0 && y >= 0 && x < board.size() && y < board[0].size() );
    }

    bool dfs(std::vector<std::vector<char>>& board, 
    	     std::string& word, 
    	     std::vector<std::vector<bool>>& visited,
    	     int idx, int x, int y) 
    {
    	if ( idx == word.size() )
    		return true;
        if (isInside(board, x, y) == false)
            return false;
        if (visited[x][y] == true)
            return false;
        if ( board[x][y] != word[idx] )
            return false;
        visited[x][y] = true;
    	for (int i = 0; i < 4; i++)
    	{
    		int x_next = x + dx[i];
    		int y_next = y + dy[i];
    		
    		if ( dfs(board, word, visited, idx + 1, x_next, y_next) )
    			return true;
    	}
        visited[x][y] = false;
    	return false;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
    	if (board.size() == 0 || board[0].size() == 0)
    		return false;

    	int m = board.size(), n = board[0].size();
        std::vector<std::vector<bool>> visited( m, std::vector<bool>(n, false) );
    	for (int i = 0; i < m; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{	
    			if ( dfs(board, word, visited, 0, i, j) )
    				return true;
    		}
    	}

    	return false;
    }

};

int main()
{
    Solution s;
    std::vector<std::vector<char>> board1 = { {'A', 'B', 'C', 'E'},
                                              {'S', 'F', 'C', 'S'},
                                              {'A', 'D', 'E', 'E'} };
    std::string word1 = "ABCCED";
    std::cout << "test 1 is : " << word1 
              << ", answer of test 1 is: " << s.exist(board1, word1) << std::endl;


    std::string word2 = "SEE";
    std::cout << "test 2 is : " << word2 
              << ", answer of test 2 is: " << s.exist(board1, word2) << std::endl;

    std::string word3 = "ASESD";
    std::cout << "test 3 is : " << word2 
              << ", answer of test 3 is: " << s.exist(board1, word3) << std::endl;


    std::vector<std::vector<char>> board2 = { {'a'} };
    std::string word4 = "a";

    std::cout << "test 4 is : " << word4
              << ", answer of test 4 is: " << s.exist(board2, word4) << std::endl;
    return 0;
}