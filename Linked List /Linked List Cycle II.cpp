class Solution {
public:
    // Floyd's Cycle Detection Algorithm
    ListNode* floydDetectionLoop(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;

        // Detect the cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return slow;  // Cycle detected, return the meeting point
            }
        }
        
        return NULL;  // No cycle found
    }
    
    // Detect the start of the cycle
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* intersection = floydDetectionLoop(head);
        if (intersection == NULL) {
            return NULL;  // No cycle
        }

        // Find the entry point of the cycle
        ListNode* slow = head;
        while (slow != intersection) {
            slow = slow->next;
            intersection = intersection->next;
        }
        
        return slow;  // Start of the cycle
    }
};
