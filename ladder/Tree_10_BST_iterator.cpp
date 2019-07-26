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
public:
    std::stack<TreeNode*> node_stack;

    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        TreeNode* dummy = new TreeNode(0);
        dummy->right = root;
        
        // init the node_stack
        while ( !node_stack.empty() ) node_stack.pop();
        this->node_stack.push(dummy);
        
        // Take care of the dummy node
        this->next();
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        return !this->node_stack.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        TreeNode* cur_node = node_stack.top();
        node_stack.pop();
        TreeNode* next_node = cur_node;
        
        if (cur_node->right) {
            cur_node = cur_node->right;
            while (cur_node) {
                node_stack.push(cur_node);
                cur_node = cur_node->left;
            }
        }
        
        return next_node;
    }
};