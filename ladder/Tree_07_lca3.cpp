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
	/*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @param LCA: global LCA
     * @return: 0 - non; 1 - A; 3 - B; 4 - both
     */
	int findTreeNode(TreeNode* root, TreeNode* A, TreeNode* B, TreeNode*& LCA) {
		int ego_flag = 0;
		if (!root) return ego_flag;
		if (root == A) ego_flag = 1;
		if (root == B) ego_flag = 3;

		int left_flag = findTreeNode(root->left, A, B, LCA);
		int right_flag = findTreeNode(root->right, A, B, LCA);
		int total_flag = left_flag + right_flag + ego_flag;

		if (left_flag < 4 && right_flag < 4 && total_flag == 4) {
			LCA = root;
			return total_flag;
		}
	}

    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) {
        // write your code here
        TreeNode* LCA = NULL;
        findTreeNode(root, A, B, LCA);
        return LCA;
    }
};