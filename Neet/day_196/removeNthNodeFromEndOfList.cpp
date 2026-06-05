class Solution 
{
    public:
    // len = 5
    // n = 2
    //           p    t
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int len = getLengthOfLL(head);

        if (len == n) {
            return head->next;
        }

        // skip the nodeToRemove and reconnect
        ListNode* prev = head;
        for (int i=0; i<len-n-1; i++) {
            prev = prev->next;
        }
        ListNode* target = prev->next;
        ListNode* next = prev->next->next;
        prev->next = next;
        return head;
    }
    private:
    int getLengthOfLL(ListNode* head) 
    {
        ListNode* curr = head;
        int len = 0;
        while (curr) {
            len++;
            curr = curr->next;
        }
        return len;
    }
};