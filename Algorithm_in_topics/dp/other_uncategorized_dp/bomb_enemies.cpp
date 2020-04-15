class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        // write your code here
        int m = grid.size(), n = grid[0].size();
        
        // 4 lookup tables
        vector<vector<int>> left(m, vector<int>(n, 0)), right(m, vector<int>(n, 0)), up(m, vector<int>(n, 0)), down(m, vector<int>(n, 0));
        
        // fill in 4 lookup tables
        for (int i = 0; i < m; i++)
        {
            // fill in left
            int enemy_count = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '0')
                    left[i][j] = enemy_count;
                else if (grid[i][j] == 'E')
                    enemy_count++;
                else // grid[i][j] == 'W'
                    enemy_count = 0;
            }
            
            // fill in right
            enemy_count = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == '0')
                    right[i][j] = enemy_count;
                else if (grid[i][j] == 'E')
                    enemy_count++;
                else // grid[i][j] == 'W'
                    enemy_count = 0;
            }
        }
        for (int j = 0; j < n; j++)
        {
            // fill in up
            int enemy_count = 0;
            for (int i = 0; i < m; i++)
            {
                if (grid[i][j] == '0')
                    up[i][j] = enemy_count;
                else if (grid[i][j] == 'E')
                    enemy_count++;
                else // grid[i][j] = 'W'
                    enemy_count = 0;
            }
            
            // fill in down
            enemy_count = 0;
            for (int i = m - 1; i >= 0; i--)
            {
                if (grid[i][j] == '0')
                    down[i][j] = enemy_count;
                else if (grid[i][j] == 'E')
                    enemy_count++;
                else // grid[i][j] == 'W'
                    enemy_count = 0;
            }
        }
        
        // now find the res
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                res = max(res, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
        }
        
        return res;
    }
};