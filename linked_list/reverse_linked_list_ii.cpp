struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int v) : val(v), next(nullptr);
};


class Solution
{
  public:
  	ListNode* reverseLinkedListII(ListNode* root)
  	{
  		ListNode* dummy = new ListNode(0);
  		dummy->next = root;

  		ListNode* curr = dummy;

  		for (int i = 1; i < m; i++)
  			curr = curr->next;

  		/* set an anchor */
  		ListNode* anchor = curr;
  		curr = curr->next;

  		/* prepare for the loop */
  		last = curr;
  		curr = curr->next;

  		for (int i = m; i < n; i++)
  		{
  			ListNode* tp = curr->next;
  			curr->next = last;
  			last = curr;
  			curr = tp;
  		}

  		anchor->next->next = curr;
  		anchor->next = last;

  		return root;

  	}
}