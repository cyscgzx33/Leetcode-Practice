class Position
{
  public:
  	int x;
  	int y;
  	Position(int X, int Y) : x(X), y(Y) {}
};

class Solution {
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
    int zombie(vector<vector<int>> &grid) {
    	std::queue<Position> q;
    	if (grid.size() == 0 || grid[0].size() == 0)
    		return 0;
    	int m = grid.size();
    	int n = grid[0].size();

    	// put all zombies into the q
    	// count the people number
    	int num_p = 0;
    	for (int i = 0; i < m; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			if (grid[i][j] == 1)
    				q.push( Position(i, j) );
    			if (grid[i][j] == 0)
    				num_p++;
    		}
    	}

    	// start bfs
    	int days = 0;
    	while (q.size() > 0)
    	{
    		int zb_sz = q.size();
    		for (int zb = 0; zb < zb_sz; zb++)
    		{
	    		Position z_pos = q.front();
	    		q.pop();
	    		std::cout << "days = " << days
	    				  << ", zombie pos x = " << z_pos.x
	    				  << ", pos y = " << z_pos.y << std::endl;
	    		for (int i = 0; i < 4; i++)
	    		{
	    			int x_n = z_pos.x + dx[i];
	    			int y_n = z_pos.y + dy[i];
	    			if (x_n < 0 || x_n >= m || y_n < 0 || y_n >= n || grid[x_n][y_n] != 0)
	    				continue;

	    			grid[x_n][y_n] = 1; // a zombie transforms people (0) to zombies (1)
	    			num_p--;
	    			q.push( Position(x_n, y_n) );
	    		}    			
    		}
    		// zombies call it a day
    		days++;
    	}

    	return num_p == 0 ? days -1 : -1;
    }
};