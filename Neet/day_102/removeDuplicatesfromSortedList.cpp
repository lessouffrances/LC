




//                     h
// d -> 1 -> 1 -> 2 -> 3 -> 3

class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (head) {//1
            while (head->next && head->val == head->next->val) { //1 && 1 == 1, 3 && 3 == 3
                head = head->next;//1 3
            }
            curr->next = head; //1->2->3
            curr = curr->next; // 1  2  3


            head = head->next; //2 3 null
        }
        return dummy->next;
    }
};