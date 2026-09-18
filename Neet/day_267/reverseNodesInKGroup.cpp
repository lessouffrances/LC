class Solution 
{
    public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head || !head->next) return head;

        ListNode* curr = head;
        for (int i=0; i<k; i++) {
            if (!curr) return head;
            curr = curr->next;
        }

        curr = head;
        ListNode* prev = nullptr;
        for (int i=0; i<k; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};