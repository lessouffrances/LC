
// 1    2    3    4    5
// 1 -> 2 -> 3 -> 4 -> 5
//      o
// 1 -> 3 -> 5
//      e
// 2 -> 4

// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head) return head;

        ListNode* oddCurr = head;
        ListNode* evenCurr = head->next;
        // remember evenHead for reconnection
        ListNode* evenHead = evenCurr;

        while (evenCurr && evenCurr->next) {
            oddCurr->next = evenCurr->next;
            oddCurr = oddCurr->next;
            evenCurr->next = oddCurr->next;
            evenCurr = evenCurr->next;
        }

        // reconnect 2 LL
        oddCurr->next = evenHead;
        return head;
    }
};