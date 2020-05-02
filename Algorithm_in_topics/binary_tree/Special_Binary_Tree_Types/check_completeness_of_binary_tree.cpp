/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // a bfs method: just check if there's an empty node preceding a non-empty node
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q({root});
        bool has_empty = false;
        while (q.size() > 0)
        {
            int n_q = q.size();
            for (int i = 0; i < n_q; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if (curr == nullptr)
                {
                    has_empty = true;
                    continue;
                }
                else
                {
                    if (has_empty == true)
                        return false;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    // a dfs method: compare the number of non-empty nodes and max index among them
    // However, it can not handle the case with long single subtree chain, will clearly stack overflow, 
    // even the index will go out of range, also based on the property that we want to collect max, modulo can not work
    int count = 0;
    int max_index = 1;
    bool isCompleteTree(TreeNode* root) {
        dfs(root, 1);
        return count == max_index;
    }
    void dfs(TreeNode* root, int root_index)
    {
        if (root == nullptr)
            return;
        count++;
        max_index = max(max_index, root_index); // record max valid index
        
        // an assumption that this can work: completeness checking from left to right
        dfs(root->left, root_index * 2);
        dfs(root->right, root_index * 2 + 1);
    }
};