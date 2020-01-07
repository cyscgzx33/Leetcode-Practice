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
    TreeNode* parent;
    TreeNode* target;
    void findNode(TreeNode* root, int key)
    {
        parent = nullptr;
        target = root;
        TreeNode* curr = root;

        while (curr)
        {
            if (curr->val > key)
            {
                parent = curr;
                curr = curr->left;
            }
            else if (curr->val < key)
            {
                parent = curr;
                curr = curr->right;
            }
            else
            {
                target = curr;
                break;
            }
        }
    }


public:
    TreeNode* removeNode(TreeNode* root, int key) {

        findNode(root, key);

        /* Case 0: if the node is root */
        if (root == target)
            return nullptr;

        /* Case 1: if target is a leaf node */
        if (target->left == nullptr && target->right == nullptr)
        {
            if (target == parent->left)
                parent->left == nullptr;
            else
                parent->right == nullptr;
        }

        


    }
};