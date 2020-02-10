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

    std::vector<std::string> parse_str_with_delimiter(std::string str, std::string delimeter) {
        std::vector<std::string> parsed_str_vec;
        size_t pos = 0;
        std::string token;

        while ( ( pos = str.find(delimeter) ) != std::string::npos ) {
            token = str.substr(0, pos);
            parsed_str_vec.push_back(token);
            str.erase(0, pos + delimeter.length());
        }

        return parsed_str_vec;
    }
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
                if (!cur_node) {
                    res += "#,";
                    continue;
                } else res += std::to_string(cur_node->val) + ",";
	            
	            if (cur_node->left) q.push(cur_node->left);
                else q.push(NULL);

	            if (cur_node->right) q.push(cur_node->right);
                else q.push(NULL);
        	}
        }

        // erase the tailing "," and close it by "}"
        res.erase( res.end()-1 );
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
    TreeNode* deserialize(string &data) {
        // write your code here
    	if (data == "{}") return NULL;

    	TreeNode* dummy(0);
        // take the the part with out "{}"
        std::string data_without_bracket = data.substr(1, data.size() - 2);

        std::vector<std::string> parsed_data_vec = parse_str_with_delimiter(data_without_bracket, ",");
        int parsed_vec_size = parsed_data_vec.size();
        int cur_pos = 0; // maintain the pos at parsed_data_vec;
        int cur_val = std::atoi( parsed_data_vec[cur_pos].c_str() );
        TreeNode* root = new TreeNode(cur_val);

        // Using level traverse BFS
        std::queue<TreeNode*> q;
        q.push(root);



        bool is_left_child = true;
        cur_pos++; // move from pos 0 to 1, as we already process the very first one to root
        while ( !q.empty() ) {
            int cur_level_size = q.size();
            for (int i = 0; i < cur_level_size; ) { // an unusual choice, do not increment i
                
                // a return criteria
                if (cur_pos >= parsed_vec_size) return root;

                TreeNode* cur_node = q.front();
                if ( parsed_data_vec[cur_pos] == "#" ) {
                    
                    if (is_left_child) {
                        cur_node->left = NULL;
                    } else {
                        cur_node->right = NULL;
                        q.pop(); // cur_node is processed completedly, pop it out
                        i++; // process next node in the queue
                    }

                } else { // it is a number in cur_pos
                    cur_val = std::atoi( parsed_data_vec[cur_pos].c_str() );
                    TreeNode* cur_child = new TreeNode(cur_val);

                    // based on the val of is_left_child
                    if (is_left_child) {
                        cur_node->left = cur_child;
                    } else {
                        cur_node->right = cur_child;
                        q.pop();
                        i++;
                    }
                    q.push(cur_child);
                }

                is_left_child = !is_left_child;
                cur_pos++; // prepare to process next pos at parsed_data_vec
            }
        }
        
        return 0;
    }  
};
