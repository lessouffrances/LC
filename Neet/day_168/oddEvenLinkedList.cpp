


class Solution 
{
    public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head) return head;

        ListNode* evenCurr = head->next;
        ListNode* oddCurr = head;

        // this one has to be memorized now for reconnection
        ListNode* evenHead = evenCurr;

        while (evenCurr && evenCurr->next) {
            oddCurr->next = evenCurr->next;
            oddCurr = oddCurr->next;
            evenCurr->next = oddCurr->next;
            evenCurr = evenCurr->next;
        }

        // reconnect
        oddCurr->next = evenHead;
        return head;
    }
};