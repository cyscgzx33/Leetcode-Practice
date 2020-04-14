struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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

    void findMaxLeftSub(TreeNode*& root, TreeNode*& parent)
    {
        while (root->right)
        {
            parent = root;
            root = root->right;
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
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }

        /* Case 2: if target only contains on child */
        if (target->right && target->left == nullptr)
        {
            if (target == parent->left)
                parent->left = target->right;
            else
                parent->right = target->right;
        }

        if (target->left && target->right == nullptr)
        {
            if (target == parent->left)
                parent->left = target->left;
            else
                parent->right = target->left;
        }

        /* Case 3: if target contains two children */
        // Note: in this case, find the largest node in its left sub-tree, and swap
        if (target->left && target->right)
        {
            TreeNode* maxLeftSub = target->left;
            TreeNode* prtMaxLeftSub = target;

            if (maxLeftSub == target->left) /* equivalent to Case 2 */
            {
                target->val = maxLeftSub->val;
                target->left->left = maxLeftSub->left;
            }
            else
            {
                target->val = maxLeftSub->val;
                parent->right = nullptr;
            }
            
        }

        return root;
    }
};