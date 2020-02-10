#include <vector>
using namespace std;
class ParentTreeNode {
public:
    int val;
    ParentTreeNode *parent, *left, *right;
};



class Solution {
public:
    void findSum(ParentTreeNode* root, 
                 ParentTreeNode* prev, // it's important to avoid duplicates
                 int target,
                 std::vector<int>& result,
                 std::vector<std::vector<int>>& results)
    {
        result.push_back(root->val);

        target -= root->val;

        // there could be multiple seqs, don't have to stop here
        if (target == 0)
            results.push_back(result);

        if (root->parent != nullptr && root->parent != prev)
            findSum(root->parent, root, target, result, results);

        if (root->left != nullptr && root->left != prev)
            findSum(root->left, root, target, result, results);

        if (root->right != nullptr && root->right != prev)
            findSum(root->right, root, target, result, results);

        result.pop_back();
    }

    void dfs(ParentTreeNode* root, 
             int target,
             std::vector<std::vector<int>>& results)
    {
        if (root == nullptr)
            return;
        
        std::vector<int> result;
        findSum(root, nullptr, target, result, results);

        dfs(root->left, target, results);
        dfs(root->right, target, results);
    }

    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum3(ParentTreeNode * root, int target) {
        // write your code here
        std::vector<std::vector<int>> results;

        dfs(root, target, results);

        return results;
    }
};