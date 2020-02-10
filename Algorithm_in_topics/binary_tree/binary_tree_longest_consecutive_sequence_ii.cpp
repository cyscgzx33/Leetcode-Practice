#include <algorithm>
// #include <vector>
// //Definition for a multi tree node.
// struct MultiTreeNode {
//     int val;
//     std::vector<MultiTreeNode*> children;
//     MultiTreeNode(int x) : val(x) {}
// };

// class Solution {
// public:


//     /**
//      * @param root the root of k-ary tree
//      * @return the length of the longest consecutive sequence path
//      */
//     int longestConsecutive3(MultiTreeNode* root) {
//         // Write your code here
//     }
// };



// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};


class ResultType
{
  public:
  	int max_len;
  	int max_down_len;
  	int max_up_len;

  	ResultType(int max_l, int max_d_l, int max_u_l) : 
  			   max_len(max_l),
  			   max_down_len(max_d_l),
  			   max_up_len(max_u_l) {}
};

class Solution {
public:
	/* return the max_len, max increasing seq len, and max decreasing seq len that starts from curr node*/
	ResultType helper(TreeNode* root)
	{
		if (root == nullptr)
			return ResultType(0, 0, 0); // since it's empty

		auto left  = helper(root->left);
		auto right = helper(root->right);

		int incr = 0, decr = 0;

		// case I: increasing seq starts from curr node
		if (root->left && root->left->val == root->val + 1)
			incr = std::max(left.max_up_len, incr);
		if (root->right && root->right->val == root->val + 1)
			incr = std::max(right.max_up_len, incr);

		// case II: decreasing seq starts from curr node
		if (root->left && root->left->val == root->val - 1)
			decr = std::max(left.max_down_len, decr);
		if (root->right && root->right->val == root->val - 1)
			decr = std::max(right.max_down_len, decr);

		int max_len = decr + 1 + incr;
        max_len = std::max( max_len, std::max(left.max_len, right.max_len) );
        
		return ResultType(max_len, decr + 1, incr + 1);
	}

    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        // write your code here

		ResultType res = helper(root);

		return res.max_len;
    }
};