#include <algorithm>
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

/* method 1: */
class Solution {
public:
    int helper(TreeNode* root, int& longest_cons)
    {
        if (root == nullptr)
            return 0;
        
        int left_val = helper(root->left, longest_cons);
        int right_val = helper(root->right, longest_cons);

        int max_left_val = 0;
        int max_right_val = 0;

        if (root->left && root->val + 1 == root->left->val)
            max_left_val = left_val;
        
        if (root->right && root->val + 1 == root->right->val)
            max_right_val = right_val;

        int ans = std::max(max_left_val, max_right_val) + 1;
        longest_cons = std::max(longest_cons, ans);

        return ans;
    }

    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        // write your code here

        int longest_cons = 1;

        helper(root, longest_cons);

        return longest_cons;
    }
};

/* method 2: */
class Solution {
public:
    // Note: have to use a parent node to record,
    //       so that we can maintain "longest_cons" as "longest consecutive sequence ending from this node",
    //       and "ans" as "longest consequtive stored in this tree (node)"
    int helper(TreeNode* root, TreeNode* parent, int longest_cons)
    {
        if (root == nullptr)
            return longest_cons;
        
        // longest consecutive sequence ending from this node
        longest_cons = parent && parent->val + 1 == root->val ? longest_cons + 1 : 1;

        // dfs, memorize the longest_cons values
        int ans = std::max( longest_cons, std::max( helper(root->left, root, longest_cons), helper(root->right, root, longest_cons) ) );

        return ans;
    }

    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        // write your code here
        int longest_cons = 0;
        return helper(root, nullptr, longest_cons);
    }
};