class Solution 
{
    public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head || !head->next) return head;

        // base case
        // if there are k nodes left
        ListNode* curr = head;
        for (int i=0; i<k; i++) {
            if (!curr) return head;
            curr = curr->next;
        }

        ListNode* prev = nullptr;
        curr = head;
        for (int i=0; i<k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = reverseKGroup(curr, k);
        return prev;
    }
};