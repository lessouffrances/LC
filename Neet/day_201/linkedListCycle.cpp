class Solution 
{
    public:
    ListNode *detectCycle(ListNode *head) 
    {
        if (!head) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        // if there's no cycle
        if (!fast || !fast->next) return nullptr;

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};