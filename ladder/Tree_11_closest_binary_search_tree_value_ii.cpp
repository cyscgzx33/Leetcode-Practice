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

	TreeNode* getLowerBound(TreeNode* root, double target, std::stack<TreeNode*>& node_stack) {
		if (!root) return NULL;

		if (target > root->val) {
			TreeNode* lower_bound = getLowerBound(root->right, target);
			if (lower_bound) return lower_bound;
			else return root;
		}
		else return getLowerBound(root->left, target);
	}

	TreeNode* getUpperBound(TreeNode* root, double target, std::stack<TreeNode*>& node_stack) {
		if (!root) return NULL;

		if (target < root->val) {
			TreeNode* upper_bound = getUpperBound(root->left, target);
			if (upper_bound) return upper_bound;
			else return root;
		}
		else return getUpperBound(root->right, target);
	}

	void getLowerNode(std::stack<TreeNode*>& node_stack) {

	}

	void getUpperNode(std::stack<TreeNode*>& node_stack) {

	}

    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        // write your code here

        // Find the lower_bound and upper_bound of target
        TreeNode* lower_bound = getLowerBound(root, target);
        TreeNode* upper_bound = getUpperBound(root, target); // should be good: upper_bound = getNextNode(lower_bound)

        // Init the stacks for iteration
        std::stack<TreeNode*> lower_stack, upper_stack;
        if (lower_bound) lower_stack.push(lower_bound);
        if (upper_bound) upper_stack.push(upper_bound);

        // Loop through stack
    }
};