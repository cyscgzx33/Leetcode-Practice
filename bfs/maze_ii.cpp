class Solution {
public:
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int m = maze.size(), n = maze[0].size();
        
        // minimum distance to reach (i, j)
        std::vector<std::vector<int>> dists( m, std::vector<int>(n, INT_MAX) );
        std::queue<std::pair<int, int>> q;
        q.push( { start[0], start[1] } );
        dists[ start[0] ][ start[1] ] = 0;
        
        while (q.size() > 0)
        {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = cur.first;
                int y = cur.second;
                int dist = dists[x][y];
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0)
                {
                    x += dx[i];
                    y += dy[i];
                    dist++;
                }
                x -= dx[i];
                y -= dy[i];
                dist--;
                
                if ( dist < dists[x][y] )
                {
                    dists[x][y] = dist;
                    if ( x != destination[0] || y != destination[1] )
                        q.push( {x, y} );
                }
            }
        }
        
        int res = dists[ destination[0] ][ destination[1] ];
        return res == INT_MAX ? -1 : res;
        
    }
};