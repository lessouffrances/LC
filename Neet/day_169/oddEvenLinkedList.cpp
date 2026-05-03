class Solution 
{
    public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head) return head;

        ListNode* oddCurr = head;
        ListNode* evenCurr = head->next;
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