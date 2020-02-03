class Node
{
  public:
  	int val;
  	int row;
  	int col;
  	Node(int v, int r, int c) : val(v), row(r), col(c) {}
};

class Compare
{
  public:
  	bool operator() (Node& a, Node& b)
  	{
  		return a.val > b.val;
  	}
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<Node, std::vector<Node>, Compare> pq;
        pq.push( Node(matrix[0][0], 0, 0) );
        int n = matrix.size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        visited[0][0] = true;
        int cnt = 0;
        int res = 0;
        while (cnt < k)
        {
        	Node cur_node = pq.top();
        	pq.pop();
        	int cur_row = cur_node.row;
        	int cur_col = cur_node.col;
        	if (cur_col + 1 < n && visited[cur_row][cur_col + 1] == false)
        	{
        		visited[cur_row][cur_col + 1] = true;
        		pq.emplace(matrix[cur_row][cur_col + 1], cur_row, cur_col + 1);
        	}
        	if (cur_row + 1 < n && visited[cur_row + 1][cur_col] == false)
        	{
        		visited[cur_row + 1][cur_col] = true;
        		pq.emplace(matrix[cur_row + 1][cur_col], cur_row + 1, cur_col);
        	}
        	// std::cout << "cur_node.val = " << cur_node.val << ", cnt = " << cnt << std::endl;
        	if (++cnt == k)
        		res = cur_node.val;
        }

        return res;
    }
};