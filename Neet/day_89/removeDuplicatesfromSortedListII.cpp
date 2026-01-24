class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = head;

        while (head) {
            if (head->next && head->next->val == head->val) {
                while (head->next && head->next->val == head->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};


