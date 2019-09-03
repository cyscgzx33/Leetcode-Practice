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

	std::tuple<int, int, int> findMinMaxBST(TreeNode* root, int& max_len)
	{
		std::tuple<int, int, int> min_max_BST = std::make_tuple(INT_MAX, INT_MIN, 0);
		if (root == NULL)
			return min_max_BST;

		std::tuple<int, int, int> left_min_max_BST = findMinMaxBST(root->left, max_len);
		std::tuple<int, int, int> right_min_max_BST = findMinMaxBST(root->right, max_len);
		int left_min = std::get<0>(left_min_max_BST);
		int left_max = std::get<1>(left_min_max_BST);
		int left_nodes = std::get<2>(left_min_max_BST);
		int right_min = std::get<0>(right_min_max_BST);
		int right_max = std::get<1>(right_min_max_BST);
		int right_nodes = std::get<2>(right_min_max_BST);
        
        std::cout << "outside:  "
                  << ", root->val = " << root->val
                  << ", left_max = " << left_max
                  << ", right_max = " << right_max
		          << ", left nodes = " << left_nodes
		          << ", right nodes = " << right_nodes << std::endl;
        
		if (left_nodes == -1 || right_nodes == -1)
		{
			std::get<2>(min_max_BST) = -1;
			return min_max_BST;
		}

		if (left_max < root->val && root->val < right_min)
		{
			std::get<0>(min_max_BST) = std::min(left_min, root->val);
			std::get<1>(min_max_BST) = std::max(right_max, root->val);
			std::get<2>(min_max_BST) = left_nodes + right_nodes + 1; // root counted as one
			std::cout << "inside:  "
			          << "root->val = " << root->val
			          << ", left nodes = " << left_nodes
			          << ", right nodes = " << right_nodes << std::endl;
			if (max_len < std::get<2>(min_max_BST) )
				max_len = std::get<2>(min_max_BST);
		}
		else
			std::get<2>(min_max_BST) = -1;

		return min_max_BST;
	}

    /**
     * @param root: the root
     * @return: the largest subtree's size which is a Binary Search Tree
     */
    int largestBSTSubtree(TreeNode * root) {
        // Write your code here
        int max_len = 0;
        findMinMaxBST(root, max_len);
        return max_len;
    }
};