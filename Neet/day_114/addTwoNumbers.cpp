struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


// 2 -> 4 -> 3
// 5 -> 6 -> 4
// d -> 7 -> 0 -> 8
// c
class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        int carry = 0;
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
            carry = sum / 10;
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};