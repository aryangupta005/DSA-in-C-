class Solution {
public:
    int lengthLL(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }   

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;

        int len = lengthLL(head);
        if(len < k) return head; 

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        while(curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};
