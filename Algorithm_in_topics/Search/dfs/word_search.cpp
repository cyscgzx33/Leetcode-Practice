class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isInside(std::vector<std::vector<char>>& board, int x, int y)
    {
        return ( x >= 0 && x < board.size() && y >= 0 && y < board[0].size() );
    }

    bool dfs(std::vector<std::vector<char>>& board,
             std::string& word,
             std::vector<std::vector<bool>>& visit,
             int x, int y, int idx) 
    {
        if ( idx = word.size() )
            return true;
        if ( isInside(board, x ,y) == false || visit[x][y] == true || board[x][y] != word[idx] )
            return false;
        // std::cout << "x = " << x << ", y = " << y << ", idx = " << idx << std::endl;
        visit[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int x_n = x + dx[i];
            int y_n = y + dy[i];

            if ( dfs(board, word, visit, x_n, y_n, idx + 1) )
                return true;
        }
        visit[x][y] = false; // don't forget
        return false;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        if (board.size() == 0 || board[0].size() == 0)
            return false;

        int height = board.size();
        int width  = board[0].size();
        std::vector<std::vector<bool>> visit( height, std::vector<bool>(width, false) );

        for (int x = 0; x < height; x++)
        {
            for (int y = 0; y < width; y++)
            {
                if ( dfs(board, word, visit, x, y, 0) )
                    return true;
            }
        }

        return false;
    }
};

class Solution {
  public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isInside(std::vector<std::vector<char>>& board, int x, int y)
    {
        return ( x >= 0 && x < board.size() && y >= 0 && y < board[0].size() );
    }

    bool dfs(std::vector<std::vector<char>>& board,
             std::string& word,
             std::vector<std::vector<bool>>& visit,
             int x, int y, int idx)
    {
        if (word.size() == idx)
            return true;
        if ( isInside(board, x, y) == false || visit[x][y] == true || board[x][y] != word[idx] )
            return false;

        // backtrack
        visit[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int x_n = x + dx[i];
            int y_n = y + dy[i];

            if ( dfs(board, word, visit, x_n, y_n, idx + 1) )
                return true;
        }
        visit[x][y] = false;
        return false;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        if ( board.size() == 0 || board[0].size() == 0 )
            return false;
        int m = board.size(), n = board[0].size();
        std::vector<std::vector<bool>> visit( m, std::vector<bool>(n, false) );
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ( dfs(board, word, visit, i, j, 0) )
                    return true;
            }
        }

        return false;
    }
};