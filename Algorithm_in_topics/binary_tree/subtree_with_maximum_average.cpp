/* M3: revised version of M1 (only check cur_avg) */

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
	 * @param:
	 * @return: {cur subtree node num, cur subtree sum}
	 */
	std::pair<int, int> findMaxAvgNode(TreeNode* cur, 
									   TreeNode*& max_avg_node, 
									   double& max_avg)
	{
		if (cur == nullptr)
			return {0, 0};
		auto left  = findMaxAvgNode(cur->left, max_avg_node, max_avg);
	    auto right = findMaxAvgNode(cur->right, max_avg_node, max_avg);

		double cur_avg = (left.second + right.second + cur->val) / (double)(left.first + right.first + 1);

		if (cur_avg > max_avg)
		{
			max_avg = cur_avg;
			max_avg_node = cur;
		}

		return { left.first + right.first + 1, left.second + right.second + cur->val };
	}
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode* findSubtree2(TreeNode* root) {
        // write your code here
    	TreeNode* max_avg_node = root;
    	double max_avg = INT_MIN;

    	findMaxAvgNode(root, max_avg_node, max_avg);

    	return max_avg_node;
    }
};


/* M2: https://yeqiuquan.blogspot.com/2017/03/lintcode-597-subtree-with-maximum.html */

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
	class ResultType
	{
	  public:
		TreeNode* node;
		int sum;
		int size;
		ResultType(TreeNode* n, int sum, int size) : node(n), sum(sum), size(size) {}
	};

	ResultType* res = nullptr;

	ResultType* helper(TreeNode* root)
	{
		if (root == nullptr)
			return new ResultType(root, 0, 0);

		auto left  = helper(root->left);
		auto right = helper(root->right);
		auto cur   = new ResultType(root, 
									left->sum + right->sum + root->val,
									left->size + right->size + 1);
		if (res == nullptr || cur->sum * res->size > res->sum * cur->size)
			res = cur;

		return cur;
	}


    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode* findSubtree2(TreeNode* root) {
    	if (root == nullptr)
    		return root;

    	ResultType* root_res = helper(root);
    	return root_res->node;
    }
};


/* M1: naive, compare all cur, left and right; please ignore */

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
	 * @param:
	 * @return: {cur subtree node num, cur subtree sum}
	 */
	std::pair<int, int> findMaxAvgNode(TreeNode* cur, 
									   TreeNode*& max_avg_node, 
									   double& max_avg)
	{
		if (cur == nullptr)
			return {0, 0};
		auto left  = findMaxAvgNode(cur->left, max_avg_node, max_avg);
		auto right = findMaxAvgNode(cur->right, max_avg_node, max_avg);

		double left_avg = 0.0, right_avg = 0.0, cur_avg = 0.0;

		if (cur->left && cur->right)
		{
			left_avg  = left.second / (double)left.first;
			right_avg = right.second / (double)right.first;
			cur_avg   = (left.second + right.second + cur->val) / ( (double)left.first + (double)right.first + 1 );

			double cur_max_avg = std::max( {left_avg, right_avg, cur_avg} );
			if (cur_max_avg > max_avg)
			{
				max_avg = cur_max_avg;

				if (left_avg == cur_max_avg)
					max_avg_node = cur->left;
				else if (right_avg == cur_max_avg)
					max_avg_node = cur->right;
				else
					max_avg_node = cur;
			}

		}
		else if (cur->left)
		{
			left_avg  = left.second / (double)left.first;
			cur_avg   = (left.second + cur->val) / ( (double)left.first + 1 );

			double cur_max_avg = std::max(left_avg, cur_avg);
			if (cur_max_avg > max_avg)
			{
				max_avg_node = left_avg > cur_avg ? cur->left : cur;
				max_avg = cur_max_avg;
			}

		}
		else if (cur->right)
		{
			right_avg = right.second / (double)right.first;
			cur_avg   = (right.second + cur->val) / ( (double)right.first + 1 );

			double cur_max_avg = std::max(cur_avg, right_avg);
			if (cur_max_avg > max_avg)
			{
				max_avg_node = cur_avg > right_avg ? cur : cur->right;
				max_avg = cur_max_avg;
			}
		}
		else
		{
			if ( (double)cur->val > max_avg )
			{
				max_avg = cur->val;
				max_avg_node = cur;
			}
		}

		return { left.first + right.first + 1, left.second + right.second + cur->val };
	}
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode* findSubtree2(TreeNode* root) {
        // write your code here
    	TreeNode* max_avg_node = root;
    	double max_avg = INT_MIN;

    	findMaxAvgNode(root, max_avg_node, max_avg);

    	return max_avg_node;
    }
};