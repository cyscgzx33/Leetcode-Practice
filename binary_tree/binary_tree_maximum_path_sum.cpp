#include <algorithm>
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
    int max_sum;
    int max_left_sum;
    int max_right_sum;

    ResultType(int max_s, int max_l_s, int max_r_s) :
               max_sum(max_s),
               max_left_sum(max_l_s),
               max_right_sum(max_r_s)
               {}
};

class Solution {
public:
    ResultType helper(TreeNode* root)
    {
        if (root == nullptr)
            return ResultType(INT_MIN, 0, 0);

        auto left = helper(root->left);
        auto right = helper(root->right);

        int max_left_sum = std::max( 0, std::max(left.max_left_sum, left.max_right_sum) );
        int max_right_sum = std::max( 0, std::max(right.max_left_sum, right.max_right_sum) );

        int max_sum = std::max(root->val + max_left_sum + max_right_sum, std::max(left.max_sum, right.max_sum) );

        return ResultType(max_sum, max_left_sum + root->val, max_right_sum + root->val);
    }

    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        // write your code here

        auto res = helper(root);

        return res.max_sum;
    }
};