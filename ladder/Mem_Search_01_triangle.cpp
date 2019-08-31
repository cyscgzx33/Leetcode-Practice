class Solution {
public:
    // it returns the value of: min value staring from (x, y) and ending at the bottom
    // memo has a key or pair
    int divideAndConquer(std::vector<std::vector<int>>& triangle,
                         int x, 
                         int y,
                         std::vector<std::vector<int>>& memo_int,
                         std::vector<std::vector<bool>>& memo_bool)
    {
        // exit criteria
        if ( x == triangle.size() ) return 0;
        
        // by-pass the existent pair in memo:
        if ( memo_bool[x][y] ) return memo_int[x][y];
        

        int left = divideAndConquer(triangle, x + 1, y, memo_int, memo_bool);
        int right = divideAndConquer(triangle, x + 1, y + 1, memo_int, memo_bool);
        memo_bool[x][y] = true;
        memo_int[x][y] = min(left, right) + triangle[x][y];
        return memo_int[x][y];
        
    }
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0) return 0;
        // write your code here
        std::vector<std::vector<int>> memo_int( triangle.size(), std::vector<int>(triangle[0].size(), -1) );
        std::vector<std::vector<bool>> memo_bool( triangle.size(), std::vector<bool>(triangle[0].size(), false) );
        return divideAndConquer(triangle, 0, 0, memo_int, memo_bool);
    }
};