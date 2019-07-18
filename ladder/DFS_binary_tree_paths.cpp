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
 * Given a binary tree, return all root-to-leaf paths.
 *
 * --------------- Example ------------------
 * Example 1:
 *
 * Input：{1,2,3,#,5}
 * Output：["1->2->5","1->3"]
 * Explanation：
 *   1
 *  /  \
 * 2    3
 * \
 *  5
 * Example 2:
 *
 * Input：{1,2}
 * Output：["1->2"]
 * Explanation：
 *   1
 *  /   
 * 2
 * 
 */


// Method I: traverse

class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        if (!root) return std::vector<std::string>{};
        std::stack<TreeNode*> stk;
        stk.push(root);
        std::vector<std::string> res;
        std::vector<int> cur_vec_int;
        while ( !stk.empty() ) {
        	TreeNode* cur_node = stk.top();
        	cur_vec_int.push_back(cur_node->val);
        } 
    }

    std::string convert_vec_int_2_str(std::vector<int>& vec_int) {
    	std::string res = "";
    	for (auto& ele_int : vec_int) {
    		res += stoi( ele_int.c_str() );
    		res += "->";
    	}
    	// it's guaranteed that res would not be empty
    	res.substring(0, res.length() - 2);
    	return res;
    }
};