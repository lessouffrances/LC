


//                           h
// d -> 1 -> 1 -> 2 -> 3 -> 3
// c -> 1 -> 2 -> 3

class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        curr->next = head;

        while (head) {
            while (head->next && head->val == head->next->val) {
                head = head->next;
            }
            curr->next = head;
            curr = curr->next;

            head = head->next;
        }

        return dummy->next;
    }
};