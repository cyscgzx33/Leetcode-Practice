/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
	void helper(TreeNode* cur,
				int target,
				std::vector<int>& path,
				std::vector<std::vector<int>>& paths)
	{
		if (cur->left == nullptr && cur->right == nullptr)
		{
		    if (target == cur->val)
		    {
		        path.push_back(cur->val);
		        paths.push_back(path);
		        path.pop_back();
            }
		    return;
		}
        
		path.push_back(cur->val);
		target -= cur->val;
		
		if (cur->left)
    		helper(cur->left, target, path, paths);
    	if (cur->right)
    		helper(cur->right, target, path, paths);
		path.pop_back();
	}

    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here
        if (root == nullptr)
            return {};

        std::vector<int> path;
        std::vector<std::vector<int>> paths;
        helper(root, target, path, paths);

        return paths;
    }
};

/* M1.1 */
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
	void helper(TreeNode* cur,
				int target,
				std::vector<int>& path,
				std::vector<std::vector<int>>& paths)
	{
		path.push_back(cur->val);
		target -= cur->val;
		
		// check if criteria is met ONLY @ leaf
		if (cur->left == nullptr && cur->right == nullptr && target == 0)
		    paths.push_back(path);

		// traverse both left and right sides
		if (cur->left)
    		helper(cur->left, target, path, paths);
    	if (cur->right)
    		helper(cur->right, target, path, paths);

    	// remember to pop_back
		path.pop_back();
	}

    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here
        if (root == nullptr)
            return {};

        std::vector<int> path;
        std::vector<std::vector<int>> paths;
        helper(root, target, path, paths);

        return paths;
    }
};