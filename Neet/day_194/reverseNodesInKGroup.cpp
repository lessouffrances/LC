class Solution 
{
    public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head || !head->next) return head;

        // count if there are k nodes left
        ListNode* node = head;
        for (int i=0; i<k; i++) {
            if (!node) return head;
            node = node->next;
        }

        // reverse the k nodes
        ListNode* curr = head;
        ListNode* prev = nullptr;
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