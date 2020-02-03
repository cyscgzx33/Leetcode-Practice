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
	/**
	 * @intuition: loop & store the global min val and node
	 * @note: return the sum val, instead of min sum val 
     * @param root: the root of binary tree
     * @return: current tree sum value
     */
	int findMinSubtree(TreeNode* root, int& glb_min_val, TreeNode*& glb_min_node) {
		if (!root) return 0;

		int left_subtree_sum = findMinSubtree(root->left, glb_min_val, glb_min_node);
		int right_subtree_sum = findMinSubtree(root->right, glb_min_val, glb_min_node);
		int cur_tree_sum = root->val + left_subtree_sum + right_subtree_sum;

		if (cur_tree_sum < glb_min_val) {
			glb_min_val = cur_tree_sum;
			glb_min_node = root;
		}

		return cur_tree_sum;
	}

    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        int glb_min_val = INT_MAX;
        TreeNode* glb_min_node = root;

        findMinSubtree(root, glb_min_val, glb_min_node);

        return glb_min_node;
    }
};