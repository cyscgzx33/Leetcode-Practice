/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    bool is_proper_position(std::vector<std::vector<bool>>& grid, Point& cur_pos) {
        if (cur_pos.x >= grid.size() || cur_pos.x < 0 || cur_pos.y >= grid[0].size() || cur_pos.y < 0) return false;
        if ( grid[cur_pos.x][cur_pos.y] ) return false;
        
        // set the visited position to true, in case duplicated visiting
        grid[cur_pos.x][cur_pos.y] = true;
        
        return true; 
    }

    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        
        if ( grid.empty() ) return -1;

        // define increment arrays
        int dx[8] = { 1, 1, -1, -1, 2, 2, -2, -2};
        int dy[8] = { 2, -2, 2, -2, 1, -1, 1, -1};
        
        // set the source to visited
        grid[source.x][source.y] = true;

        // start the BFS
        std::queue<Point> q;
        q.push(source);
        int steps = 0;
        while ( !q.empty() ) {
            steps++;

            // level wise search
            int cur_queue_size = q.size();
            for (int j = 0; j < cur_queue_size; j++) {
                Point cur_pos = q.front();
                int cur_posX = cur_pos.x;
                int cur_posY = cur_pos.y;
                q.pop();
                
                // try 8 different scenarios for each
                for (int i = 0; i < 8; i++) {
                    Point next_pos(cur_posX + dx[i], cur_posY + dy[i]);
                    if ( is_proper_position(grid, next_pos) ) {
                        if ( next_pos.x == destination.x && next_pos.y == destination.y ) 
                            return steps; // it reaching the goal, return current steps
                        q.push(next_pos);
                    }
                }
            }

        }

        return -1;
        
    }
};