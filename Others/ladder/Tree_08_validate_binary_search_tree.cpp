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
    // using long to avoid leak
    /**
     * @param root: The root of binary tree.
     * @return: a vetcor contains: min_val, max_val, and is_valid_BST
     */
	std::vector<long> findMinMaxValue(TreeNode* root) {
		std::vector<long> assess = {LONG_MAX, LONG_MIN, 1};
		if (!root) return assess;

		std::vector<long> left_assess = findMinMaxValue(root->left);
		std::vector<long> right_assess = findMinMaxValue(root->right);
		long left_min = left_assess[0], left_max = left_assess[1], left_is_valid = left_assess[2];
		long right_min = right_assess[0], right_max = right_assess[1], right_is_valid = right_assess[2];
		
		if (left_is_valid == 0 || right_is_valid == 0) {
			assess[2] = 0;
			return assess;
		}

		if (left_max < root->val && root->val < right_min) {
			assess[0] = std::min( left_min, long(root->val) ); // erase INT_MAX encountered with leaf nodes
			assess[1] = std::max( right_max, long(root->val) );
			assess[2] = 1;
		}
		else assess[2] = 0;

		return assess;
	}

    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here
    	if (!root) return true;
    	std::vector<long> res = findMinMaxValue(root);
    	return res[2];
    }
};