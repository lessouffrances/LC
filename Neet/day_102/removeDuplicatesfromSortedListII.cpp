








//                                     h
//  d -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
//            p

class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head) {//1 2 3 4
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    head = head->next; 
                }
                prev->next = head->next;//4 5

            } else {//
                prev = prev->next; //d->1->2->5
            }

            head = head->next; //2 null
        }

        return dummy->next; 
    }
};