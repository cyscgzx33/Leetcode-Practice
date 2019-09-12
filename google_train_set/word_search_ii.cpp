#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

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
	         )
	{	
		if (prefix_word.count(cur_word) == 0)
			return;
        if ( !isInside(board, x, y) )
            return;
        if ( visited[x][y] == 1 )
            return;

        cur_word = cur_word + board[x][y];
		if (word_set.count(cur_word) > 0)
			res.insert(cur_word);

        visited[x][y] = 1;
		for (int i = 0; i < 4; i++)
		{
			int x_next = x + dx[i];
			int y_next = y + dy[i];
			dfs(board, cur_word, word_set, prefix_word, res, visited, x_next, y_next);
		}
        visited[x][y] = 0;
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
        prefix_word.insert(""); // dummy start
        for (auto& word : words)
        {
        	word_set.insert(word);
        	for (int i = 0; i < word.size(); i++)
        		prefix_word.insert( word.substr(0, i + 1) );
        }

        // obtain an unordered set of res
        // construct a visit map
        std::vector<std::vector<int>> visited( board.size(), std::vector<int>(board[0].size(), 0) );
        std::unordered_set<std::string> res;
        for (int i = 0; i < board.size(); i++)
        {
        	for (int j = 0; j < board[0].size(); j++)
        		dfs(board, "", word_set, prefix_word, res, visited, i, j);
        }

        // construct the final result
        std::vector<std::string> result;
        for (auto it = res.begin(); it != res.end(); it++)
        	result.push_back(*it);

        return result;
    }
};

int main()
{
    std::vector<std::vector<char>> board = { {'o','a','a','n'}, 
                                             {'e','t','a','e'}, 
                                             {'i','h','k','r'}, 
                                             {'i','f','l','v'} };
    std::vector<std::string> words = {"oath","pea","eat","rain"};

    Solution s;

    std::vector<std::string> res1 = s.findWords(board, words);

    std::cout << "answer1 is :" << std::endl;
    for (auto& str : res1)
        std::cout << str << ", ";

    std::cout << std::endl;
    return 0;
}