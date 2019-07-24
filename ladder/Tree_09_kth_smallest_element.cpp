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
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        // write your code here
        TreeNode* dummy = new TreeNode(-1);
        dummy->right = root;
        std::stack<TreeNode*> stk;
        stk.push(dummy);
        
        // [Intuition] loop over k elements including the dummy
        // so the next one is the kth smallest element in the tree
        for (int i = 0; i < k; i++) {
            TreeNode* cur_node = stk.top();
            stk.pop();
            
            // Important: recite it!
            // Intuition: if the right subtree is valid:
            // (Acoording to the in-order rule) left -- root -- right
            if (cur_node->right) {
                cur_node = cur_node->right;
                while (cur_node) {
                    stk.push(cur_node);
                    cur_node = cur_node->left;
                }
            }
            // unfortunately there is no kth element in the tree
            if ( stk.empty() ) break;
        }
        
        if ( stk.empty() ) return -1;
        return stk.top()->val;
        
    }

    int findNumOfNodes(TreeNode* root, std::unordered_map<TreeNode*, int>& nums_node_contains) {
        if (!root) return 0;
        int left_node_nums = findNumOfNodes(root->left, nums_node_contains);
        int right_node_nums = findNumOfNodes(root->right, nums_node_contains);
        int cur_node_nums = left_node_nums + right_node_nums + 1;
        nums_node_contains[root] = cur_node_nums;
        return  cur_node_nums;
    }

    /* follow-up: if the BST is frequently changed */
    int kthSmallestFollowUp(TreeNode* root, int k, std::unordered_map<TreeNode*, int>& nums_node_contains) {
        if (root->left) {
            int left_node_nums = nums_node_contains[root->left];
            if (left_node_nums >= k) return kthSmallestFollowUp(root->left, k, nums_node_contains);
            else if (left_node_nums == k - 1) return root->val;
            else return kthSmallestFollowUp(root->right, k - left_node_nums - 1, nums_node_contains);
        }
        if (k == 1) return root->val;
        else return kthSmallestFollowUp(root->right, k - 1, nums_node_contains);
    }

    int kthSmallest(TreeNode* root, int k) {
        std::unordered_map<TreeNode*, int> nums_node_contains;
        // initialize the nums_node_contains hash table
        int node_nums = findNumOfNodes(root, nums_node_contains);
        // find the kth smallest value
        return kthSmallestFollowUp(root, k, nums_node_contains);
    }
};


