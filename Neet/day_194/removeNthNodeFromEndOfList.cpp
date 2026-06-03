
//             s
// head = [1,2,3,4,5], n = 2
class Solution 
{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (!head) return head;

        int len = getLengthOfLL(head);
        if (n == len) return head->next;

        // Skipping the toRemove node 
        // and reconnect prev with next
        // 1. go to the prev
        ListNode* prev = head;
        for (int i=0; i<len-n-1; i++) {
            prev = prev->next;
        }

        // 2. go to the next
        ListNode* next = prev->next->next;
        // 3. reconnect
        prev->next = next;
        return head;
    }

    private:
    int getLengthOfLL(ListNode* head)
    {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        return len;
    }
};