/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


/* Refer to Wikipedia for more information: https://en.wikipedia.org/wiki/Tree_traversal#Pre-order */
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr)
            return {};

        stack<Node*> s;
        s.push(root);
        
        vector<int> res;
        while (s.size() > 0)
        {
            Node* curr = s.top();
            s.pop();
            res.push_back(curr->val);
            
            for (auto it = curr->children.rbegin(); it != curr->children.rend(); it++)
                s.push(*it);
        }

        return res;
    }
};