struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int v) : val(v), next(nullptr);
};


class Solution
{
  public:
  	ListNode* reverseLinkedList(ListNode* head)
  	{
      ListNode* curr = head;
      ListNode* last = nullptr;
      while (curr)
      {
        ListNode* tp = curr->next;
        curr->next = last;
        last = curr;
        curr = tp;
      }

      return last;

  	}
}