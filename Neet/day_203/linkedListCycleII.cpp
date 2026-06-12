class Solution 
{
    public:
    // return the entrance of the cycle
    ListNode *detectCycle(ListNode *head) 
    {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        // what if no break?
        // actually no cycle
        // dist from start to entrace: F
        // dist travelled in the cycle: C
        // when fast and slow meet for the first time
        // slow travels F+C, fast travels 2(F+C)
        // the diff the a full cycle len: L = F+C
        // so L = F - C
        if (!fast || !fast->next) return nullptr;

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};