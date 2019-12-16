/**
 * Definition for a multi tree node.
 * struct MultiTreeNode {
 *     int val;
 *     vector<MultiTreeNode*> children;
 *     MultiTreeNode(int x) : val(x) {}
 * };
 */
class Solution {
public:


    /**
     * @param root the root of k-ary tree
     * @return the length of the longest consecutive sequence path
     */
    int longestConsecutive3(MultiTreeNode* root) {
        // Write your code here
    }
};


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

class ResultType
{
  public:
  	int max_len;
  	int max_down_len;
  	int max_up_len;

  	ResultType(int max_l, int max_d_l, max_u_l) : 
  			   max_len(max_l),
  			   max_down_len(max_d_l),
  			   max_up_len(max_u_l) {}
}

class Solution {
public:
	/* return the max_len, max increasing seq len, and max decreasing seq len that goes thru the curr node*/
	ResultType helper(MultiTreeNode* root)
	{
		if (root == nullptr)
			return ResultType(0, 0, 0); // since it's empty

		int left  = helper(root->left);
		int right = helper(root->right);

		int root_max = 1;

		if (root->left && root->left->val == root->val + 1)

		

	}

    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        // write your code here
    }
};