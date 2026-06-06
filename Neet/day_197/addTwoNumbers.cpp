class Solution 
{
    public:
    // 2 -> 4 -> 3
    // 5 -> 6 -> 4
    // 7 -> 0 -> 8
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (!l1) return l2;
        if (!l2) return l1;

        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            } 
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum % 10;
            ListNode* node = new ListNode(digit);
            curr->next = node;
            curr = curr->next;
            carry = sum / 10;
        }

        return dummy->next;
    }
};