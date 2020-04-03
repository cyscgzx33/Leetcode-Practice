class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};


class Solution {
public:
    TreeNode* last; // last node visited during the traversal
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void traverse(TreeNode* root)
    {
        // Step 0: sanity check
        if (root == nullptr)
            return;
        
        // Step 1: stick accroding to the given rule
        if (last != nullptr)
        {
            last->left = nullptr;
            last->right = root;
        }
        last = root;
        TreeNode* right = root->right; // must store as a temp, or it would be "transformed"
        // Step 2: traverse to left
        traverse(root->left);
        // Step 3: traverse to right
        traverse(right); // should be the stored right, NOT root->right
    }

    void flatten(TreeNode * root) {
        // write your code here
        traverse(root);
    }
};


/* As a very good reference !!!! */
void preorderTraverse(TreeNode* root)
{
    // print root -> left -> right
    
    // Step 0: sanity check
    if (root == nullptr)
        return;
    
    // Step 1: print root val
    printf("root->val = %d\n", root->val);

    // Step 2: traverse to left
    preorderTraverse(root->left);

    // Step 3: traverse to right
    preorderTraverse(root->right);
}