#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    std::vector<std::string> split(const std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);

        while (std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }

        return tokens;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        queue<TreeNode*> q({root});

        vector<string> res;
        while (q.size() > 0)
        {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (curr == nullptr)
                {
                    res.push_back("#");
                    continue;
                }

                res.push_back(to_string(curr->val));
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        string res_str = "";
        for (auto str : res)
            res_str += str + ",";
        if (res.size() > 0)
            res_str.erase(res_str.size() - 1); // delete the last ","

        return res_str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;
        vector<string> input_vec = split(data, ',');

        int i = 0; // iterator of the input vector
                   // every time moment, i is ready for the next subtree to be assigned
        TreeNode* root = new TreeNode(stoi(input_vec[i++]));
        queue<TreeNode*> q({root});
        while (i < input_vec.size())
        {
            int q_size = q.size();
            for (int k = 0; k < q_size; k++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (input_vec[i] == "#")
                    curr->left = nullptr;
                else
                {
                    curr->left = new TreeNode(stoi(input_vec[i]));
                    q.push(curr->left);
                }
                i++; // every time conducting the assignment, move iterator

                // check i iter
                if (i >= input_vec.size())
                    break;
                if (input_vec[i] == "#")
                    curr->right = nullptr;
                else
                {
                    curr->right = new TreeNode(stoi(input_vec[i]));
                    q.push(curr->right);
                }
                i++; // every time conducting the assignment, move iterator
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));