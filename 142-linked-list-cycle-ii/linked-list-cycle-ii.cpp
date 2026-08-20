class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect whether a cycle exists
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps

            if (slow == fast) {
                // Cycle exists

                // Step 2: Find the starting node of cycle
                ListNode* start = head;

                while (start != slow) {
                    start = start->next;
                    slow = slow->next;
                }

                return start;
            }
        }

        // No cycle
        return nullptr;
    }
};