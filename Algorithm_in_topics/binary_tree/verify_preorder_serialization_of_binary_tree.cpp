class Solution {
public:
    vector<string> split(const string& s, char delimeter)
    {
        vector<string> tokens;
        string token;
        istringstream token_stream(s);
        while (getline(token_stream, token, delimeter))
            tokens.push_back(token);
        
        return tokens;
    }
    TreeNode* deserialize(vector<string>& data, int& idx, bool& valid)
    {
        if (idx >= data.size()) // it wants to construct left or right subtree, but the data just ends with fault, thus invalid
        {
            valid = false;
            return nullptr;
        }

        TreeNode* root = nullptr;
        if (data[idx] != "#")
            root = new TreeNode(stoi(data[idx++]));
        else
        {
            idx++;
            return nullptr;
        }

        root->left = deserialize(data, idx, valid);
        root->right = deserialize(data, idx, valid);
        return root;
    }

    bool isValidSerialization(string preorder) {
        vector<string> input_vec = split(preorder, ',');
        bool valid = true;
        int idx = 0;
        TreeNode* root = deserialize(input_vec, idx, valid);
        
        return idx == input_vec.size() && valid;
    }
};