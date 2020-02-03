/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    std::vector<std::string> splitData(std::string data, std::string delimiter)
    {
        std::vector<std::string> res;
        size_t idx = 0;
        std::string token;

        while ( ( idx = data.find(delimiter) ) != std::string::npos ) // std::string::nps = -1, 
                                                                      // indicating the end of the string
                                                                      // FIX ME: it will ignore the last element
        {
            token = data.substr(0, idx);
            res.push_back(token);
            data.erase( 0, idx + delimiter.length() );
        }
        return res;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "[]";
        
        std::string res = "[";
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (q.size() > 0)
        {
            int cur_size = q.size();
            
            for ( int i = 0; i < cur_size; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (cur != NULL)
                    res += std::to_string(cur->val) + ',';    
                else
                {
                    res += "null,";
                    continue; // otherwise would cause segmentation error
                }
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        
        res.erase( res.size() - 1 );
        res += ']';
        
        std::cout << "serialize res = " << res << std::endl;
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]")
            return NULL;

        // remove the front and back bracket
        // split data among the commas
        std::string data_without_brackets = data.substr(1, data.size() - 2);
        std::vector<std::string> splited_data = splitData(data_without_brackets, ",");
        for (auto& elem : splited_data)
            std::cout << elem << ", ";
        std::cout << '\n';
        
        // initialize the data
        int data_size = splited_data.size();
        int cur_idx = 0;
        int cur_val = std::atoi( splited_data[cur_idx].c_str() );
        cur_idx++;
        
        // initialize binary tree level traverse
        std::queue<TreeNode*> q;
        TreeNode* root = new TreeNode(cur_val);
        q.push(root);
        bool is_left_child = true;

        while (q.size() > 0)
        {
            int cur_level_size = q.size();

            for (int i = 0; i < cur_level_size;  ) // Note: no self increment
                                                   // actively controlled by user
            {
                std::cout << "splited_data[cur_idx] = " << splited_data[cur_idx]
                          << ", cur_idx = " << cur_idx << std::endl;

                if (cur_idx >= data_size)
                    return root;

                TreeNode* cur_node = q.front();
                if ( splited_data[cur_idx] == "null" )
                {
                    if (is_left_child)
                        cur_node->left = NULL;
                    else
                    {
                        cur_node->right = NULL;
                        q.pop();
                        i++;
                    }
                }
                else
                {
                    cur_val = std::atoi( splited_data[cur_idx].c_str() );
                    TreeNode* cur_child = new TreeNode(cur_val);
                    q.push(cur_child); // DON'T FORGET !!!!!!!!!!!!!!!!!

                    if (is_left_child)
                        cur_node->left = cur_child;
                    else
                    {
                        cur_node->right = cur_child;
                        q.pop();
                        i++;
                    }
                }

                // iterate this step
                cur_idx++;
                is_left_child = !is_left_child;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));