#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    vector<string> split(const string& s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);

        while (getline(tokenStream, token, delimiter))
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



/* Method 2: using dfs to deserialize the data */
// Decodes your encoded data to tree.

class Codec {
public:
    vector<string> split(const string& s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);

        while (getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }

        return tokens;
    }
    void traverseRecur(TreeNode* root, vector<int>& traverse_vec)
    {
        if (root == nullptr)
        {
            traverse_vec.push_back(INT_MAX);
            return;
        }
        traverse_vec.push_back(root->val);
        traverseRecur(root->left, traverse_vec);
        traverseRecur(root->right, traverse_vec);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";

        // Implementation 1: recursion
        vector<int> traverse_vec;
        traverseRecur(root, traverse_vec);
        string res = "";
        for (auto t_vec : traverse_vec)
        {
            if (t_vec != INT_MAX)
                res += to_string(t_vec) + ",";
            else
                res += "#,";
        }
        res.erase(res.end() - 1);
        return res;

        // dfs: front-order-traversal
        // (TODO) Implementation 2: manual stack
        // string res = "";
        // stack<TreeNode*> s;
        // s.push(root);
        // res += to_string(root->val);
        // res += ",";

        // TreeNode* curr = root;
        // while (s.size() > 0)
        // {
            
        // }
    }

    TreeNode* dfs(vector<string>& data, int& i)
    {
        TreeNode* root = nullptr;
        if (i >= data.size())
            return nullptr;
        if (data[i] != "#")
            root = new TreeNode(stoi(data[i++]));
        else
        {
            i++; // don't forget this, otherwise it stuck somewhere
            return root;
        }
        TreeNode* left = dfs(data, i);
        TreeNode* right = dfs(data, i);
        root->left = left;
        root->right = right;

        return root;
    }

    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;
        vector<string> input_vec = split(data, ',');
        TreeNode* root;

        int itor = 0;
        root = dfs(input_vec, itor);

        return root;
    }
};