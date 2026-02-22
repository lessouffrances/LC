
//         h
// head = [2, 1, 3, 5, 6, 4, 7]
//         o
//            e

class Solution 
{
    public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head) return nullptr;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // remember the even head now

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};