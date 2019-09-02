class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        if (grid.size() == 0 || grid[0].size() == 0)
        	return 0;
        int height = grid.size(), width = grid[0].size();

        std::vector<std::vector<int>> dp( height, std::vector<int>(width, 0) );

        for (int i = 0; i < height; i++)
        {	
        	for (int j = 0; j < width; j++)
        	{
        		if (i == 0 && j == 0)
        			dp[i][j] = grid[i][j];
        		else if (i == 0)
        			dp[i][j] = dp[i][j-1] + grid[i][j];
        		else if (j == 0)
        			dp[i][j] = dp[i-1][j] + grid[i][j];
        		else 
        			dp[i][j] = min( dp[i-1][j], dp[i][j-1] ) + grid[i][j];
        	}
        }

        return dp[height - 1][width - 1];
    }

    // method 2: sliding array
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        if (grid.size() == 0 || grid[0].size() == 0)
        	return 0;
        int height = grid.size(), width = grid[0].size();

        std::vector<std::vector<int>> dp( 2, std::vector<int>(width, 0) );

        for (int i = 0; i < height; i++)
        {	
        	for (int j = 0; j < width; j++)
        	{
        		if (i == 0 && j == 0)
        			dp[i][j] = grid[i][j];
        		else if (i == 0)
        			dp[i][j] = dp[i][j-1] + grid[i][j];
        		else if (j == 0)
        			dp[i % 2][j] = dp[(i-1) % 2][j] + grid[i][j];
        		else 
        			dp[i % 2][j] = min( dp[(i-1) % 2][j], dp[i % 2][j-1] ) + grid[i][j];
        	}
        }

        return dp[(height - 1) % 2][width - 1];
    }
};