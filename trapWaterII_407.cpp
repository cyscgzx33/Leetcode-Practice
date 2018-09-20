class Solution /* a BFS Method */ {
private:
	void BFS(vector<int>& heightMap_1d, priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>& prQ, vector<int>& visitMap, int& res, int& localMaxVal, int row, int col) {

		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};

		while(!prQ.empty()) {

            int curIndex = prQ.top().second;
            int curVal = prQ.top().first;

            // update the localMaxVal
            localMaxVal = max(localMaxVal, curVal);

			prQ.pop();

            for (int k = 0; k < 4; k++) {
                int nextIndex = dx[k]*col + dy[k] + curIndex;
                int nextVal = heightMap_1d[nextIndex];
                if (nextIndex >= 0 && nextIndex < row*col && visitMap[nextIndex] == 0) {
                    // firstly, set the visitMap to 1
                    visitMap[nextIndex] = 1;
                    // then push them into the priority queue anyway
                    prQ.push({nextVal, nextIndex});
                    // try to do some comparison and change the res value
                    if (nextVal < localMaxVal) res += (localMaxVal - nextVal);

                }

            }

		}
	}

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        // pair.first is value, pair.second is index
        // here, the priority queue is modified to put minimum element in top()
        // (important!!!) priority queue will treat the pair.first as the sort related number  
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> prQ;

        int localMaxVal = INT_MIN;

        int row = heightMap.size();
        int col = heightMap[0].size();

        // initialize a 1D vector<int> that dupliacte heightMap
        vector<int> heightMap_1d(row*col, 0);
        for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
                int id = i * col + j;
        		heightMap_1d[i*col + j] = heightMap[i][j];
        	}
        }

        // initialize a 1D map that records if the element is visited
        vector<int> visitMap(row * col, 0);
        int res = 0;

        // push all the elements in boundary into the prQ
        // first row and last row
        for (int i = 0; i < col; i++) {
        	prQ.push({heightMap[0][i], i});
            visitMap[i] = 1;
        	if (row != 1) {
                prQ.push({heightMap[row-1][i], (row-1)*col + i});
                visitMap[(row-1)*col + i] = 1;
            }

        }
        // first col and last col (without duplications)
        for (int i = 0; i < row; i++) {
        	if (i == 0 || i == row - 1) continue;
        	prQ.push({heightMap[i][0], i * col});
            visitMap[i * col] = 1;
        	if (col != 1) {
                prQ.push({heightMap[i][col-1], i * col + col - 1});
                visitMap[i * col + col - 1] = 1;
            }
        }

        // call the BFS function and return res
        BFS(heightMap_1d, prQ, visitMap, res, localMaxVal, row, col);
        return res;

    }
};