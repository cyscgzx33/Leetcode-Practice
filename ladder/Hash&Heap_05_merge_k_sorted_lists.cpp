/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    
    // an example of defining comparator of priority_queue
    struct Comparator {
        bool operator() (ListNode* left, ListNode* right) const {
            return left->val > right->val;
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // pay attention to the declaration of priority_queue here
        std::priority_queue<ListNode*, std::vector<ListNode*>, Comparator> pq;
        ListNode* dummy = new ListNode(0);
        ListNode* cur_node = dummy;
        
        for (auto& elem : lists) if (elem) pq.push(elem);
        
        while ( !pq.empty() ) {
            cur_node->next = pq.top();
            pq.pop();
            cur_node = cur_node->next;
            if (cur_node->next) pq.push(cur_node->next);
        }
        
        return dummy->next;
    }
};
