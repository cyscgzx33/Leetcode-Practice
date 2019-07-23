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
    /**
     * @intuition: reconstruct the tree and return the last node in preorder
     * @param root: a TreeNode, the root of the binary tree
     * @return: last node in preorder
     */
    TreeNode* daq_helper(TreeNode* root) {

        if (!root) return NULL;

        TreeNode* left_last = daq_helper(root->left);
        TreeNode* right_last = daq_helper(root->right);

        // (thought of steps 2) connect
        // Note: only do this if left_last is not empty;
        //       otherwise the "connection" is actually done, no need
        if (left_last) {
            left_last->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        // According to the pre-order, root -- left -- right
        // First check right, then left, last root
        if (right_last) return right_last;
        if (left_last) return left_last;
        return root;
    }

    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        
        /* Devide and conquer */
        // Thought of steps: 
        // 1. flatten left subtree and right subtree independently
        // 2. connect the last node of left subtree to the last node of right subtree
        //           [how to do 2? Using the property that in d-a-q we have return values]
        // 3. return the last_node of flattened subtree

        daq_helper(root);
        return;
    }
};