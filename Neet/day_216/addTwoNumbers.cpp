// struct ListNode
// {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x): val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {} 
// };

// need to add from the single-digit pos
// already been satisfied by the reversed linkedlist
// carry? happened when the sum of current two digits is > 9
//    digit = sum % 10
//    carry = sum / 10

class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
            carry = sum / 10;
            curr->next = new ListNode(digit);
            curr = curr->next;
        }
        return dummy->next;
    }
};