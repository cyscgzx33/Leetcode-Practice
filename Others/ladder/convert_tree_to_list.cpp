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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        if (root == nullptr)
        	return {};
        
        std::vector<ListNode*> lists;
        std::queue<TreeNode*> q;
        q.push(root);

        while (q.size() > 0)
        {
        	int sz = q.size();
        	ListNode* dummy = new ListNode(0);
        	ListNode* cur_ln = dummy; // current list node
        	for (int i = 0; i < sz; i++)
        	{
        		// process the queue
        		TreeNode* cur_tn = q.front(); // current tree node
        		q.pop();

        		// process the list node
        		cur_ln->next = new ListNode(cur_tn->val);
        		cur_ln = cur_ln->next;

        		// process the tree node
        		if (cur_tn->left)
        			q.push(cur_tn->left);
        		if (cur_tn->right)
        			q.push(cur_tn->right);
        	}
        	lists.push_back(dummy->next);
        }

        return lists;
    }
};