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

/* rewarm: 10/22/2019: 
   note-1, no visit map; 
   note-2, necessary to init dists map; 
   note-3, init of queue should be the basic way 
   */

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
    	if (maze.size() == 0 || maze[0].size() == 0)
    		return -1;
    	int hgt = maze.size(), width = maze[0].size();
    	// Note 1: it's improper to init q as before, must do it in this way
    	std::queue<std::pair<int,int>> q;
    	q.push( { start[0], start[1] } );

    	// Note 2: it's important to init dists@start position
    	std::vector<std::vector<int>> dists( hgt, std::vector<int>(width, INT_MAX) );
    	dists[ start[0] ][ start[1] ] = 0;


    	while (q.size() > 0)
    	{
    		auto curr = q.front();
    		q.pop();
    		int x = curr.first;
    		int y = curr.second;

    		for (int i = 0; i < 4; i++)
    		{
    			int x_n = x;
    			int y_n = y;
    			int dist = dists[x][y];
    			while (x_n >= 0 && x_n < hgt && y_n >= 0 && y_n < width && maze[x_n][y_n] == 0)
    			{
    				x_n += dx[i];
    				y_n += dy[i];
    				dist++;
    			}
    			x_n -= dx[i];
    			y_n -= dy[i];
    			dist--;
    			if ( dist < dists[x_n][y_n] )
    			{
    				dists[x_n][y_n] = dist;
    				if ( x_n != destination[0] || y_n != destination[1] )
    					q.push( {x_n, y_n} );
    			}
    		}
    	}

    	int min_dist = dists[ destination[0] ][ destination[1] ];
    	return min_dist == INT_MAX ? -1 : min_dist;
    }
};