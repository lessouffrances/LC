class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* newHead = dummy;

        while (head) {
            while (head->next && head->next->val == head->val) {
                head = head->next;
            }

            ListNode* node = new ListNode(head->val);
            newHead->next = node;
            newHead = newHead->next;

            head = head->next;
        }
        return dummy->next;
    }
};