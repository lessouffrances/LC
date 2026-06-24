
// head = [1,2,3,4,5], k = 2
//            sh st
// fh    ft->nullptr
// 1->2->3    4->5
// 4->5->1->2->3
// right count for k nodes and put them upfront, reconnect with the rest

class Solution 
{
    public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head) return head;
        int len = getLengthOfLL(head);
        k = k % len;
        if (k == 0) return head;

        // right count k nodes
        // <=> left count (len - k) nodes
        ListNode* ft = head;
        for (int i=0; i<(len-k-1); i++) {
            ft = ft->next;
        }
        ListNode* sh = ft->next;

        // go to the st
        ListNode* st = sh;
        while (st->next) {
            st = st->next;
        }
        ft->next = nullptr; // cut off
        st->next = head;
        return sh;
    }

    private:
    int getLengthOfLL(ListNode* head)
    {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }
};