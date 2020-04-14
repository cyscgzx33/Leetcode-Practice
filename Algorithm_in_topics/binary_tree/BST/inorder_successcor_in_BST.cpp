/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
	TreeNode* res = nullptr;

	void helper(TreeNode* root, TreeNode* p)
	{
		if (root == nullptr)
			return;

		if (root->val <= p->val)
			helper(root->right, p);
		else
		{
			res = root;
			helper(root->left, p);
		}
	}
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here

    	helper(root, p);
    	return res;
    }
};