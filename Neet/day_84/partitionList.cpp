class Solution 
{
    public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        while (head) {
            if (head->val >= x) {
                greater->next = head;
                greater = greater->next;
            } else {
                less->next = head;
                less = less->next;
            }
            head = head->next;
        }
        
        less->next = greaterHead->next;
        greater->next = nullptr;
        return lessHead->next;
    }
};