class Solution 
{
    public:
    bool hasCycle(ListNode *head) 
    {
        if (!head) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        return false;
    }
};