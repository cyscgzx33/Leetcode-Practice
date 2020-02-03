/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* dummy = new ListNode(0);
    	ListNode* cur = dummy;

    	int holder = 0;

    	while (true)
    	{
    		if (l1)
    		{
    			holder += l1->val;
    			l1 = l1->next;
    		}

    		if (l2)
    		{
    			holder += l2->val;
    			l2 = l2->next;
    		}

    		cur->next = new ListNode(holder % 10);
    		cur = cur->next;
    		holder /= 10;

    		if (l1 == NULL && l2 == NULL && holder == 0)
    			return dummy->next;
    	}

    }
};
