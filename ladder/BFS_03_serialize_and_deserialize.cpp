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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        // write your code here
        if (!root) return "{}";
        std::string res = "{";
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        	int cur_size = q.size();
        	for (int i = 0; i < cur_size; i++) {
	            TreeNode* cur_node = q.front();
	            q.pop();
	            res += std::to_string(q.val) + ",";

	            if (cur_node->left) q.push(node->left);
	            else res += "#,";

	            if (cur_node->right) q.push(node->right);
	            else res += "#,";
        	}
        }

        // erase the tailing "," and close it by "}"
        res.erase( str.end()-1 );
        res += "}";

        return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        // write your code here
    	if (data == "{}") return NULL;

    	TreeNode* dummy(0);
        // take the the part with out "{}"
        std::string data_without_bracket = data;
        data_without_bracket = data_without_bracket.substr(1, data_without_bracket.size() - 2);

        int cur_level = 0; // indicate the current level of the tree
        int node_num_in_cur_lv = 0; // indicate the number of node in current tree level
        for (int i = 0; i < data_without_bracket.size(); i+=2) { // in each step += 2, to skip the ","
        	int cur_val = std::atoi( data_without_bracket[i].c_str() );
        	TreeNode* cur_node = new TreeNode(cur_val);
        }
    }

    std::vector<string> str_vec()
};
