class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     * @description: 
     *   Given a boolean 2D matrix, 0 is represented as the sea, 
     *   1 is represented as the island. If two 1 is adjacent, 
     *   we consider them in the same island. 
     *   We only consider up/down/left/right adjacent.
	 *   Find the number of islands.

	 * @Example
	 *   Example 1:

	 * Input:
	 * [
	 *   [1,1,0,0,0],
	 *   [0,1,0,0,1],
	 *   [0,0,0,1,1],
	 *   [0,0,0,0,0],
	 *   [0,0,0,0,1]
	 * ]
	 * Output:
	 * 3
	 * Example 2:	

	 * Input:
	 * [
	 *   [1,1]
	 * ]
	 * Output:
	 * 1
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
    	if (grid.size() == 0 || grid[0].size() == 0) return 0;

    	int length = grid.size(), width = grid[0].size();
    	int res = 0;

    	for (int i = 0; i < length; i++) {
    		for (int j = 0; j < width; j++) {
    			if ( grid[i][j] ) {
    				SearchNeighborGrid(grid, i, j, length, width);
    				res++;
    			}
    		}
    	}

    	return res;
    }

    /* A simple BFS method: find all the neighbor land grids (true), and make them sea (false) */
    void SearchNeighborGrid(std::vector<std::vector<bool>>& grid, int row, int col, int length, int width) 
    {
    	// define the incremental difference for every step
    	int dx[4] = {-1, 0, 1, 0};
    	int dy[4] = {0, -1, 0, 1};

    	std::queue< std::vector<int> > q;
    	q.push( std::vector<int>{row, col} );

    	while ( !q.empty() ) {
    		int cur_row = q.front()[0];
    		int cur_col = q.front()[1];
    		q.pop();

    		for (int i = 0; i < 4; i++) {
    			int next_row = cur_row + dx[i];
    			int next_col = cur_col + dy[i];
    			// boundary check && isLand check
    			if ( next_row >= 0 &&
    				 next_row < length &&
    				 next_col >= 0 &&
    				 next_col < width &&
    				 grid[next_row][next_col] 
    			    ) 
    			{
    				// Note: important! must trigger this to kill duplicate loop
    				grid[next_row][next_col] = false; 
    				q.push( std::vector<int> {next_row, next_col} );
    			}
    				
    			else continue;
    		}
    	}
    }

};