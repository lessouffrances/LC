// 1 2 3 3 4 4 5

class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0); // 0
        dummy->next = head; 
        ListNode* prev = dummy; // 0

        while (head) { // 1  2  3  4  5
            if (head->next && head->next->val == head->val) { // 3==3 4==4
                while (head->next && head->next->val == head->val) { // 3==3 3!=4 4==4
                    head = head->next; // (1)3 (1)4
                }
                prev->next = head->next; // 2->5
            } else {
                prev = prev->next; // 1  2  5
            }

            head = head->next; // 2  3  4  5 null
        }
        return dummy->next; 
    }
};