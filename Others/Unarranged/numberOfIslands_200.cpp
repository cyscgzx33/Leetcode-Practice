class Solution {
    
// a BFS method
private:
    void BFS(vector<vector<char>>& grid, vector<vector<int>>& visitMap, int i, int j, int row, int col) {
        typedef pair<int, int> point;
        queue<point> q;
        q.push(point(i,j));
        visitMap[i][j] = 1;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        while (!q.empty()) {
            point curP = q.front();
            q.pop();
            int cx = curP.first;
            int cy = curP.second;
            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visitMap[nx][ny] && grid[nx][ny] == '1') {
                    q.push(point(nx, ny));
                    visitMap[nx][ny] = 1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int row = grid.size();
        if (!row) return res;
        int col = grid[0].size();
        vector<vector<int>> visitMap(row, vector<int>(col, 0));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visitMap[i][j] && grid[i][j] == '1') {
                    BFS(grid, visitMap, i, j, row, col);
                    res++;
                }
            }
        }
        
        return res;
    }
};