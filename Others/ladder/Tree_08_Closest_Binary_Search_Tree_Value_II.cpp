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

	int binarySearch(TreeNode* root, double target) { // guaranteed that root is not empty()
		if (root->val == target) return root->Val;

		if (root->val < target) {
			if (root->right) return binarySearch(root->right, target);
			else return root->val;
		}

		if (root->val > target) {
			if (root->left) return binarySearch(root->left, target);
			else return root->val;
		}
	}

    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        // write your code here
        int steps = 0;
    }
};