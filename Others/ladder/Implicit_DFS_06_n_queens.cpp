class Solution {
public:
	void dfs(int n,
			 std::unordered_set<int>& is_visited_col,
			 std::unordered_set<int>& is_visited_sum,
			 std::unordered_set<int>& is_visited_diff,
		     std::vector<int>& permutation,
		     std::vector< std::vector<std::string> >& boards)
	{
		if ( permutation.size() == n) {
			// process the board
			std::vector<std::string> board = drawBoard(permutation);
			boards.push_back(board);
			return;
		}

		int row = permutation.size();
		for (int col = 0; col < n; col++) {
			// check if the current pos is valid
			if ( isValid(is_visited_col, is_visited_sum, is_visited_diff, row, col) == false) continue; 

			permutation.push_back(col);
			is_visited_col.insert(col); // column wise
			is_visited_sum.insert(row + col); // diagonal wise I
			is_visited_diff.insert(row - col); // diagnal wise II
			dfs(n, is_visited_col, is_visited_sum, is_visited_diff, permutation, boards);
			is_visited_col.erase(col); // column wise
			is_visited_sum.erase(row + col); // diagonal wise I
			is_visited_diff.erase(row - col); // diagnal wise II
			permutation.pop_back();
		}
	}

	bool isValid(std::unordered_set<int>& is_visited_col,
				 std::unordered_set<int>& is_visited_sum,
				 std::unordered_set<int>& is_visited_diff,
				 int row, int col) 
	{
		if (is_visited_col.count(col) > 0) return false;
		if (is_visited_sum.count(row + col) > 0) return false;
		if (is_visited_diff.count(row - col) > 0) return false;

		return true;
	}

	std::vector<std::string> drawBoard(std::vector<int>& permutation) {
		int length = permutation.size();
		std::vector<std::string> board;
		for (int i = 0; i < length; i++) {
			std::string row = "";
			for (int j = 0; j < length; j++) {
				if ( j != permutation[i] ) row += '.';
				else row += 'Q';
			}
			board.push_back(row);
		}
		return board;
	}

    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
    	std::unordered_set<int> is_visited_col;
		std::unordered_set<int> is_visited_sum;
		std::unordered_set<int> is_visited_diff;

    	std::vector<int> permutation;
    	std::vector< std::vector<std::string> > boards;
		dfs(n, is_visited_col, is_visited_sum, is_visited_diff, permutation, boards);

    	return boards;
    }
};