//         c
// head = [1,2,6,3,4,5,6], val = 6
//      p
class Solution 
{
    public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(); // null
        ListNode* prev = dummy; // null
        ListNode* curr = head; // 1

        while (curr) { // 1
            if (curr->val == val) {
                curr = curr->next; // 3
                continue;
            }
            prev->next = curr; //prev->1->2->3->4->5
            prev = prev->next; // 1 2 3 4 5
            curr = curr->next; // 2 6 4 5 6
        }
        prev->next = nullptr;
        return dummy->next;
    }
};