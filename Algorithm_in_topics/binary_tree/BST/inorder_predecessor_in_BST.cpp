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
	TreeNode* res = nullptr;

	void helper(TreeNode* root, TreeNode* p)
	{
		if (root == nullptr)
			return;
		if (root->val >= p->val)
			helper(root->left, p);
		else
		{
			res = root;
			helper(root->right, p);
		}
	}

    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        // write your code here

        helper(root, p);
        return res;
    }
};


/* M2: non-recursive */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        // write your code here

        TreeNode* res = nullptr;
        TreeNode* cur = root;

        while (cur)
        {
        	if (cur->val >= p->val)
        		cur = cur->left;
        	else
        	{
        		res = cur;
        		cur = cur->right;
        	}
        }

        return res;
    }
};