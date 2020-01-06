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
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here
        int n = matrix.size();
        int m = matrix[0].size();
        std::priority_queue<Node, std::vector<Node>, Compare> pq;
        pq.push( Node(matrix[0][0], 0, 0) );
        std::vector<std::vector<int>> visit( n, std::vector<int>(m, 0) );
        visit[0][0] = 1;

        for (int i = 0; i < k - 1; i++)
        {
        	Node curr = pq.top();
        	pq.pop();
        	int r = curr.row;
        	int c = curr.col;

        	if (r + 1 < n && visit[r+1][c] == 0)
        	{
        		visit[r+1][c] = 1;
        		pq.push( Node(matrix[r+1][c], r+1, c) );
        	}

        	if (c + 1 < m && visit[r][c+1] == 0)
        	{
        		visit[r][c+1] = 1;
        		pq.push( Node(matrix[r][c+1], r, c+1) );
        	}
        }

        return pq.top().val;
    }
};