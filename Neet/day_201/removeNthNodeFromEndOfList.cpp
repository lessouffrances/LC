class Solution 
{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (!head) head;
        // edge case:
        // if the node to remove is the first node
        // then n = len(LL)
        int len = getLengthOfLL(head);
        if (n == len) {
            return head->next;
        }

        // general case
        // go to the node that's before the node to remove
        // reconnect the prev to the next node
        // [1,2,3,4,5], n=2, len=5
        // the prev node is the (len-n)-th node
        ListNode* prev = head;
        for (int i=0; i<len-n-1; i++) {
            prev = prev->next;
        }
        // now prev is the real prev
        // save the next
        ListNode* next = prev->next->next;
        prev->next = next;
        return head;
    }

    private:
    int getLengthOfLL(ListNode* head)
    {
        if (!head) return 0;
        int res = 0;
        ListNode* curr = head;
        while (curr) {
            res++;
            curr = curr->next;
        }
        return res;
    }
};