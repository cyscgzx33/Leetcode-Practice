class TrieNode
{
  public:
    vector<TrieNode*> sons;
    bool is_word;
    TrieNode()
    {
        sons.resize(26, nullptr);
        is_word = false;
    }
};

class Solution {
  private:
    TrieNode* root;
    int max_count = INT_MIN;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

  public:

    void addWords(vector<string>& words)
    {
        for (auto word : words)
        {
            TrieNode* cur = root;
            for (auto c : word)
            {
                if (cur->sons[c-'a'] == nullptr)
                    cur->sons[c-'a'] = new TrieNode();
                cur = cur->sons[c-'a'];
            }
            cur->is_word = true;
        }
    }

    void dfs(vector<vector<char>>& board,
             vector<vector<bool>>& visit,
             TrieNode* cur,
             int temp_count, // necessary to get a temporary count
             int x, int y,
             int x_start, int y_start)
    {
        if (cur->is_word == true)
        {
            // update temp and global counts
            temp_count++;
            max_count = max(max_count, temp_count);

            // start search new words after starting from (x_start, y_start)
            // for example: all the 'x's are checked, 'o's are not
            //              '!' indicates the starting cell needs to check, i.e.,
            //              '!' <=> (x_start, y_start) 
            // [ x  x  x  x  x  x ]
            // [ x  x  x  x  x  x ]
            // [ x  x  x  !  o  o ]
            // [ o  o  o  o  o  o ]
            // [ o  o  o  o  o  o ]
            // [ o  o  o  o  o  o ]
            // [ o  o  o  o  o  o ]
            cur = root;

            for (int i = x_start; i < board.size(); i++)
            {
                for (int j = y_start; j < board[0].size(); j++)
                {
                    if (visit[i][j] == true)
                        continue;
                    char cur_c = board[i][j];
                    if (cur->sons[cur_c-'a'] == nullptr)
                        continue;

                    visit[i][j] = true;
                    dfs(board, visit, cur->sons[cur_c-'a'], temp_count, i, j, i, j);
                    visit[i][j] = false;
                }

                /* VERY IMPORTANT */
                // Reason to reset y_start:
                // y 需要重置为0是因为：在每次选定一个word的path并加入visited后，便会进入下一重DFS在剩余字母中搜索可能的词，此时需要遍历初始点（i，j）以后的所有点。
                // 在x坐标为i时，只需遍历j以后的点，而x递增进入下一行（i + 1及后续所有行）后，
                // 则需要遍历从0到len(board[0])的所有y坐标，所以除了i=x这一行外，后续行的y坐标都应该从0开始。否则会遗漏(i, j)点左下方的区域。
                // Yusen's Note: technically, only the first row of this iteration loops from column of y_start, the next rows are all looped
                //               starting from 0
                y_start = 0;
            }
        }
        else
        {
            // it's not ending for an on-going word search
            for (int i = 0; i < 4; i++)
            {
                int x_n = x + dx[i];
                int y_n = y + dy[i];
                if (x_n < 0 || x_n >= board.size() || y_n < 0 || y_n >= board[0].size() || visit[x_n][y_n] == true)
                    continue;
                char cur_c = board[x_n][y_n];
                if (cur->sons[cur_c-'a'] == nullptr)
                    continue;

                visit[x_n][y_n] = true;
                dfs(board, visit, cur->sons[cur_c-'a'], temp_count, x_n, y_n, x_start, y_start);
                visit[x_n][y_n] = false;
            }
        }
    }

    int boggleGame(vector<vector<char>>& board, vector<string> &words) {
        if (board.size() == 0 || board[0].size() == 0)
            return 0;

        root = new TrieNode();
        addWords(words);

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        // main loop
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char cur_c = board[i][j];
                if (root->sons[cur_c-'a'] == nullptr)
                    continue;
                visit[i][j] = true;
                dfs(board, visit, root->sons[cur_c-'a'], 0, i, j, i, j);
                visit[i][j] = false;
            }
        }

        return max_count;
    }
};