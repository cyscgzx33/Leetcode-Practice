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
private:
    void findTarget(TreeNode*& root, TreeNode*& parent, int key)
    {
        while (root)
        {
            if (root->val < key)
            {
                parent = root;
                root = root->right;
            }
            else if (root->val > key)
            {
                parent = root;
                root = root->left;
            }
            else
                break;
        }
    }

    void findLeftMax(TreeNode*& lmax, TreeNode*& par)
    {
        while (lmax->right)
        {
            par = lmax;
            lmax = lmax->right;
        }
    }


public:
    TreeNode* removeNode(TreeNode* root, int key) {
        /* Case -1: root is nullptr */
        if (root == nullptr)
            return nullptr;

        TreeNode* tar = root;
        TreeNode* par = nullptr;
        findTarget(tar, par, key);

        /* Case 0: if tar is nullptr (can't find) */
        if (tar == nullptr)
            return root;

        /* Case 1: if the tar is a leaf node */
        if (tar->left == nullptr && tar->right == nullptr)
        {
            // Special subcase
            if (tar == root)
                return nullptr;

            if (tar == par->left)
                par->left == nullptr;
            else
                par->right == nullptr;
        }

        /* Case 2: if the tar only has one child */
        else if (tar->left == nullptr && tar->right)
        {
            // Special subcase
            if (tar == root)
                return tar->right;

            if (tar == par->left)
                par->left = tar->right;
            else
                par->right = tar->right;
        }
        else if (tar->left && tar->right == nullptr)
        {
            // Special subcase
            if (tar == root)
                return tar->right;

            if (tar == par->left)
                par->left = tar->left;
            else
                par->right = tar->left;
        }

        /* Case III: if the tar contains two children */
        else if (tar->left && tar->right)
        {
            TreeNode* lmax = tar->left;
            TreeNode* lmax_par = tar;

            findLeftMax(lmax, lmax_par);

            if (lmax == tar->left)
            {
                tar->val = lmax->val;
                tar->left = nullptr;
            }
            else
            {
                tar->val = lmax->val;
                lmax_par->right = nullptr;
            }
        }

        return root;
    }
};