


//                                    h
// d -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
// p -> 1 -> 2 -> 4 -> 5


class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};