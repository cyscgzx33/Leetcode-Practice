class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int bfs(vector<vector<int>>& grid,
            int x, int y,
            int row, int col) {
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        // put it as visited but actually not checked yet
        visited[x][y] = true;
        queue<int> qx({x});
        queue<int> qy({y});
        
        int dist = 0;
        int sum = 0;
        
        while (qx.size() > 0) {
            dist++;
            // Note: for the type of BFS highly related to steps, must searhc every existing nodes in one step!!!
            int cur_size = qx.size();
            for (int k = 0; k < cur_size; k++) {
                int x_cur = qx.front(); qx.pop();
                int y_cur = qy.front(); qy.pop();
                for (int i = 0; i < 4; i++) {
                    int x_n = dx[i] + x_cur;
                    int y_n = dy[i] + y_cur;
                    
                    if (x_n < row && x_n >= 0 && y_n < col && y_n >= 0 && visited[x_n][y_n] == false) {
                        visited[x_n][y_n] = true;
                        
                        // if meeting a house, add dist to sum
                        // Note: not add to queue, because not allowing the houses to be passed as a road
                        if (grid[x_n][y_n] == 1) {
                            sum += dist;
                        }
                        
                        // if meeting an empty position, add to queue
                        if (grid[x_n][y_n] == 0) {
                            qx.push(x_n);
                            qy.push(y_n);
                        }
                        
                        // do nothing if meeting a wall
                    }
                }
            }
        }
        
        // necessary: check if all the houses are visited
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && visited[i][j] == false)
                    return 0x3f3f3f3f;
            }
        }

        return sum;
    }
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return -1;
        }
        
        int m = grid.size(), n = grid[0].size();
        
        int res = 0x3f3f3f3f;
        
        // loop through the map, try to build post office at each empty position and BFS
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    res = min(res, bfs(grid, i, j, m, n));
                }
            }
        }
        
        return res == 0x3f3f3f3f ? -1 : res;
    }
};