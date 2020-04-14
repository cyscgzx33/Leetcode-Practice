
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class ResultType
{
  public:
    int level;          // current level
    TreeNode* LCA;      // lowest common ancester
    ResultType(int l, TreeNode* root) : level(l), LCA(root) {}
};

class Solution {
public:
    ResultType countNumOfDeepestNodes(TreeNode* root, int level)
    {
        if (root == nullptr)
            return ResultType(-1, nullptr);

        ResultType left = countNumOfDeepestNodes(root->left, level + 1);
        ResultType right = countNumOfDeepestNodes(root->right, level + 1);
        if (left.level == -1 && right.level == -1)
            return ResultType(level, root);
        else if (left.level == -1) // right subtree not empty
            return right;
        else if (right.level == -1) // left subtree not empty
            return left;
        else // both left and right subtree not empty
        {
            if (left.level == right.level)
                return ResultType(left.level, root);
            return left.level > right.level ? left : right;
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr)
            return root;
        return countNumOfDeepestNodes(root, 0).LCA;
    }
};