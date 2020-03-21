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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
    stack<TreeNode*> stk;
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        while (root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        return stk.size() > 0;
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        TreeNode* top = stk.top();
        TreeNode* cur = top;
        stk.pop();
        
        if (cur->right != nullptr)
        {
            cur = cur->right;
            while (cur != nullptr)
            {
                stk.push(cur);
                cur = cur->left;
            }
        }
        else
        {
            // ... complicated
            while (stk.size() > 0 && stk.top()->right == cur)
            {
                cur = stk.top();
                stk.pop();
            }
        }
        
        return top;
    }
};