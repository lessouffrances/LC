
// d->1->2->3->3->4->4->5
//    1->2->->5

class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;

        while (head)
        {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // we don't want the last dup
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};