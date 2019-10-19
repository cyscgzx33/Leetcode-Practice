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

	void findPath(TreeNode* cur,
				  int target,
				  std::vector<std::vector<int>>& paths)
	{
		if (cur == nullptr)
			return;
		std::vector<int> path;
		helper(cur, target, path, paths);
		findPath(cur->left, target, paths);
		findPath(cur->right, target, paths);
	}

	void helper(TreeNode* cur,
				int target,
				std::vector<int>& path,
				std::vector<std::vector<int>>& paths)
	{
		if (cur == nullptr)
			return;

		path.push_back(cur->val);
        // std::cout << "cur->val = " << cur->val << ", target = " << target << std::endl;
		if (target == cur->val)
			paths.push_back(path);

		helper(cur->left, target - cur->val, path, paths);
		helper(cur->right, target - cur->val, path, paths);

		path.pop_back();
	}

    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        // write your code here
    	std::vector<std::vector<int>> paths;

    	findPath(root, target, paths);
    	return paths;
    }
};



/* M2: using a buffer to save some space complexity */

class Solution {
public:

	void findPaths(TreeNode* cur,
				   int target, int level,
				   std::vector<int>& buffer,
				   std::vector<std::vector<int>>& paths)
	{
		if (cur == nullptr)
			return;

		int tmp_target = target;
		buffer.push_back(cur->val);

		// search paths whose ending node is sum and has sum equal to target
		for (int i = level; i >= 0; i--)
		{
			tmp_target -= buffer[i];
			if (tmp_target == 0) // a path is found
								 // construct it among the buffer
			{
				std::vector<int> path;
				for (int j = i; j <= level; j++)
					path.push_back( buffer[j] );
				paths.push_back(path);
			}
		}

		findPaths(cur->left, target, level + 1, buffer, paths);
		findPaths(cur->right, target, level + 1, buffer, paths);
		buffer.pop_back();
	}

    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        // write your code here
        if (root == nullptr)
        	return paths;
    	std::vector<std::vector<int>> paths;
    	std::vector<int> buffer;
    	findPath(root, target, 0, buffer, paths);
    	return paths;
    }
};