class Solution {
public:
	void dfs(std::vector<int>& comb,
			 std::vector<std::vector<int>>& combs,
			 std::unordered_set<int>& diag1,
			 std::unordered_set<int>& diag2,
			 std::unordered_set<int>& vert,
			 int x, int n)
	{
		if (x == n)
		{
			combs.push_back(comb);
			return;
		}

		for (int y = 0; y < n; y++)
		{
			if (vert.count(y) > 0)
				continue;
			if (diag1.count(x + y) > 0)
				continue;
			if (diag2.count(x - y) > 0)
				continue;
			comb.push_back(y);
			vert.insert(y);
			diag1.insert(x + y);
			diag2.insert(x - y);
			dfs(comb, combs, diag1, diag2, vert, x + 1, n);
			comb.pop_back();
			vert.erase(y);
			diag1.erase(x + y);
			diag2.erase(x - y);
		}
	}

	std::vector<std::vector<std::string>> createBoard(std::vector<std::vector<int>>& combs, int n)
	{
		std::vector<std::vector<std::string>> boards;

		for (int i = 0; i < combs.size(); i++)
		{
			std::vector<std::string> board;
			for(int j = 0; j < n; j++)
			{
				std::string row(n, '.');
				row[combs[i][j]] = 'Q';
				board.push_back(row);
			}
			boards.push_back(board);
		}
		return boards;
	}

    vector<vector<string>> solveNQueens(int n) 
    {
        std::vector<int> comb;
        std::vector<std::vector<int>> combs;
        std::unordered_set<int> diag1;
		std::unordered_set<int> diag2;
		std::unordered_set<int> vert;
        dfs(comb, combs, diag1, diag2, vert, 0, n);
        // std::cout << "combs.size() = " << combs.size() 
        //           << ", combs[0].size() = " << combs[0].size()
        //           <<std::endl;
        return createBoard(combs, n);
    }
};
