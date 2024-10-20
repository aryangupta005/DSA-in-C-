class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    
		ListNode *slow = head, *fast = head->next;
		while (fast->next !=NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;

  }
};