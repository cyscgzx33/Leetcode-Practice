class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
        	return 0;
        int row_num = obstacleGrid.size(), col_num = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp( row_num, std::vector<int>(col_num, 0) );

        // init the first grid
        dp[0][0] = 1;

        // traverse the first col
        for (int i = 0; i < row_num; i++)
        {
        	if (obstacleGrid[i][0] == 1)
        		break;
        	dp[i][0] = 1;
        }

        // traverse the first row
        for (int i = 0; i < col_num; i++)
        {
        	if (obstacleGrid[0][i] == 1)
        		break;
        	dp[0][i] = 1;
        }

        // traverse the whole grid
        for (int i = 1; i < row_num; i++)
        {
        	for (int j = 1; j < col_num; j++)
        	{
        		// cannot reach obstacle occupied grid
        		if (obstacleGrid[i][j] == 1)
        			continue;
        		dp[i][j] = dp[i-1][j] + dp[i][j-1];
        	}
        }

        return dp[row_num-1][col_num-1];

    }
};