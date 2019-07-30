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
     * @param k: the given k
     * @return: largest subtree node value among those whose values are less than OR EQUAL TO root
     */
	TreeNode* buildLowerBoundStack(TreeNode* root, double target, std::stack<TreeNode*>& lower_bound_stack) {
		if (!root) return NULL;

		// process the current subtree and expand the stack
		lower_bound_stack.push(root);
  	
		if (root->val <= target) { // IMPORTANT: LESS THAN OR EQUAL TO, only active in one side lower/upper
			TreeNode* lower_bound = buildLowerBoundStack(root->right, target, lower_bound_stack);
			if (lower_bound) return lower_bound;
			else {
				return root;
			}
		}
		else {
			TreeNode* lower_bound = buildLowerBoundStack(root->left, target, lower_bound_stack);
			return lower_bound;
		}
	}

	TreeNode* buildUpperBoundStack(TreeNode* root, double target, std::stack<TreeNode*>& upper_bound_stack) {
		if (!root) return NULL;

		// process the current subtree and expand the stack		
		upper_bound_stack.push(root);

		if (root->val > target) {
			TreeNode* upper_bound = buildUpperBoundStack(root->left, target, upper_bound_stack);
			if (upper_bound) return upper_bound;
			else {
				return root;
			}
		}
		else {// root->val < target; it's already taken care of at lower bound for root->val == target 
			TreeNode* upper_bound = buildUpperBoundStack(root->right, target, upper_bound_stack);
			return upper_bound;
		}
	}

	void moveUpper(std::stack<TreeNode*>& upper_bound_stack) {
		TreeNode* cur_node = upper_bound_stack.top();
		
		if (cur_node->right) {
			cur_node = cur_node->right;
			while (cur_node) {
				upper_bound_stack.push(cur_node);
				cur_node = cur_node->left;
			}
		}
		else {
			upper_bound_stack.pop();
			while ( !upper_bound_stack.empty() && upper_bound_stack.top()->right == cur_node ) {
				cur_node = upper_bound_stack.top();
				upper_bound_stack.pop();
			}
		}
	}

	void moveLower(std::stack<TreeNode*>& lower_bound_stack) {
		TreeNode* cur_node = lower_bound_stack.top();

		if (cur_node->left) {
			cur_node = cur_node->left;
			while (cur_node) {
				lower_bound_stack.push(cur_node);
				cur_node = cur_node->right;
			}
		}
		else {
			lower_bound_stack.pop();
			while ( !lower_bound_stack.empty() && lower_bound_stack.top()->left == cur_node ) {
				cur_node = lower_bound_stack.top();
				lower_bound_stack.pop();
			}
		}
	}

	bool isLowerCloser(std::stack<TreeNode*>& lower_bound_stack, std::stack<TreeNode*>& upper_bound_stack, double target) {
		if ( lower_bound_stack.empty() ) return false;
		if ( upper_bound_stack.empty() ) return true;

		return target - lower_bound_stack.top()->val < upper_bound_stack.top()->val - target;
	}

	void trimStack(std::stack<TreeNode*>& upper_bound_stack, 
				   std::stack<TreeNode*>& lower_bound_stack,
				   TreeNode*& lower_bound,
				   TreeNode*& upper_bound) 
	{
		if (lower_bound) {
    		while (lower_bound_stack.top() != lower_bound) lower_bound_stack.pop();
    	}
    	else {
    		while ( !lower_bound_stack.empty() ) lower_bound_stack.pop();
    	}

    	if (upper_bound) {
    		while (upper_bound_stack.top() != upper_bound) upper_bound_stack.pop();
    	}
    	else {
    		while ( !upper_bound_stack.empty() ) upper_bound_stack.pop();
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

        // init the stacks for lower bound and upper bound 
    	std::stack<TreeNode*> lower_bound_stack, upper_bound_stack;
    	TreeNode* lower_bound = buildLowerBoundStack(root, target, lower_bound_stack);
    	TreeNode* upper_bound = buildUpperBoundStack(root, target, upper_bound_stack);

    	// process the stacks such that if lower/upper bound exists, the stack top should be equal to them
    	// AND IF lower/upper bound doesn't exists, empty the stack
    	trimStack(upper_bound_stack, lower_bound_stack, lower_bound, upper_bound);

    	// loop k times and obtain the res
    	std::vector<int> res;
    	for (int i = 0; i < k; i++) {
    		if ( isLowerCloser(lower_bound_stack, upper_bound_stack, target) ) {
    			res.push_back(lower_bound_stack.top()->val);
    			moveLower(lower_bound_stack);
    		}
    		else {
    			res.push_back(upper_bound_stack.top()->val);
    			moveUpper(upper_bound_stack);
    		}
    	}

    	return res;
    }
};