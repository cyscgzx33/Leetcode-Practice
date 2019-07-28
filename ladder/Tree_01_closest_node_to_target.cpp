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
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        if (!root) return 0;
    	TreeNode* cur_left_node = root->left;
    	TreeNode* cur_right_node = root->right;
    
    	// find the lower_bound, that is the largest node in left subtree (RIGHT MOST)
    	while ( cur_left_node && cur_left_node->right ) cur_left_node = cur_left_node->right;
    	int lower_bound = cur_left_node->val;
    
    	// find the upper_bound, that is the smallest node in the right subtree (LEFT MOST)
    	while ( cur_right_node && cur_right_node->left ) cur_right_node = cur_right_node->left;
    	int upper_bound = cur_right_node->val;
    
    	if ( abs(lower_bound - root->val) < abs(upper_bound - root->val) ) return lower_bound;
    	else return upper_bound;
    }
};