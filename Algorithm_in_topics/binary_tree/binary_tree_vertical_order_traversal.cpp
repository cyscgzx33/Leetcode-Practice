class Solution {
public:
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode * root) {
        if (root == nullptr)
            return {};
        
        // write your code here
    	std::queue<std::pair<TreeNode*, int>> q;
    	q.push({ root, 0 });
    	std::map<int, std::vector<int>> m; // stores the information of each col

    	while (q.size() > 0)
    	{
    		auto curr = q.front();
    		q.pop();
    		int col = curr.second;
    		TreeNode* node = curr.first;
    		m[col].push_back(node->val); // do I need to create a new element if m[col] is empty?
    									 // Answer: yes! map::operator[] inserts an item for the givin key if one doesn't already exist

    		if (node->left)
    			q.push( {node->left, col - 1} );
    		if (node->right)
    			q.push( {node->right, col + 1} );
    	}

    	std::vector<std::vector<int>> res;
    	for (auto it = m.begin(); it != m.end(); it++)
    		res.push_back(it->second);

    	return res;
    }
};