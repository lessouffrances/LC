class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (head) {
            while (head->next && head->val == head->next->val) {
                head = head->next;
            }
            curr->next = head;
            curr = curr->next;

            head = head->next;
        }
        
        return dummy->next;
    }
};