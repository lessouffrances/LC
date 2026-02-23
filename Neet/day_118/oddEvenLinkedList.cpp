




// head = [2,1,3,5,6,4,7]
//         o
//           e
class Solution 
{
    public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head) return nullptr;

        ListNode* oddCurr = head;
        ListNode* evenCurr = head->next;
        ListNode* evenHead = evenCurr; // remember the evenhead now 

        while (evenCurr && evenCurr->next) {
            oddCurr->next = evenCurr->next;
            oddCurr = oddCurr->next;
            evenCurr->next = oddCurr->next;
            evenCurr = evenCurr->next;
        }
        oddCurr->next = evenHead;
        return head;
    }
};