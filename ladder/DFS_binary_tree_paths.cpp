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

/* Method I: traversal in recursion */

class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    std::string convert_vec_int_2_str(std::vector<int>& vec_int) {
    	std::string res = "";
    	for (auto& ele_int : vec_int) {
    		res += std::to_string( ele_int );
    		res += "->";
    	}
    	// it's guaranteed that res would not be empty
    	res = res.substr(0, res.length() - 2);
    	return res;
    }

    void dfs(std::vector<std::string>& res, 
    		 TreeNode* node, 
    		 std::vector<int>& cur_vec_int)
    {	
    	// It is guaranteed that root is not empty
        cur_vec_int.push_back(node->val);

    	if (!node->left && !node->right) {
    		res.push_back( convert_vec_int_2_str(cur_vec_int) );
    		return;
    	}

    	if (node->left) {
    		this->dfs(res, node->left, cur_vec_int);
    		cur_vec_int.pop_back(); // Note: we have to pop it here, not at the exit entrance,
    								// 	     as not only the leaf nodes need to be popped out,
    								//	     every step needs to be backtracked.
    	}

    	if (node->right) {
    		this->dfs(res, node->right, cur_vec_int);
    		cur_vec_int.pop_back(); // Note: same as above
    	}

    }


    vector<string> binaryTreePaths(TreeNode * root) {
        if (!root) return std::vector<std::string>{};
        std::vector<std::string> res;
        std::vector<int> cur_vec_int;

        this->dfs(res, root, cur_vec_int);
        return res;
    }

};


/* Method II: devide-and-conquer in recursion */

class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */

    std::vector<std::string> devide_and_conquer(TreeNode* node) {	
    	// It is guaranteed that node is not empty
    	if (!node->left && !node->right) {
    		std::vector<std::string> res;
    		res.push_back( std::to_string(node->val) );
    		return res;
    	}

    	// init two string vectors to empty ones
    	std::vector<std::string> res_left{};
    	std::vector<std::string> res_right{};

    	if (node->left) {
    		res_left = devide_and_conquer(node->left);
    		for (auto& str_ele : res_left) {
    			str_ele = std::to_string(node->val) + "->" + str_ele;
    		}
    	}

    	if (node->right) {
    		res_right = devide_and_conquer(node->right);
    		for (auto& str_ele : res_right) {
    			str_ele = std::to_string(node->val) + "->" + str_ele;
    		}
    	}

    	// combine res_left and res_right
    	res_left.insert( res_left.end(), res_right.begin(), res_right.end() );

    	return res_left;

    }


    vector<string> binaryTreePaths(TreeNode * root) {
        if (!root) return std::vector<std::string>{};
        std::vector<std::string> res = devide_and_conquer(root);
        return res;
    }

};