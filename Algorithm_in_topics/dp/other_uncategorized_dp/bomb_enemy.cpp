#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */


    // method: 4 look-up tables
    int maxKilledEnemies(vector<vector<char>> &grid) {
        vector<vector<int>> up_left, up_right, down_left, down_right;
    }
};