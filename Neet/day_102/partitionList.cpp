





class Solution 
{
    public:
    ListNode* partition(ListNode* head, int x) 
    {
        if (!head) return nullptr;

        ListNode* greaterHead = new ListNode();
        ListNode* lessHead = new ListNode();

        ListNode* greater = greaterHead;
        ListNode* less = lessHead; 

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