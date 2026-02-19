



class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (!l1) return l2;
        if (!l2) return l1;

        stack<int> deck1;
        stack<int> deck2;

        ListNode* curr = l1;
        while (curr) {
            deck1.push(curr->val);
            curr = curr->next;
        }
        curr = l2;
        while (curr) {
            deck2.push(curr->val);
            curr = curr->next;
        }

        ListNode* newHead = nullptr;
        int carry = 0;
        while (!deck1.empty() || !deck2.empty() || carry) {
            int sum = carry;

            if (!deck1.empty()) {
                sum += deck1.top();
                deck1.pop();
            }
            if (!deck2.empty()) {
                sum += deck2.top();
                deck2.pop();
            }

            int digit = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(digit);
            node->next = newHead;
            newHead = node;
        }

        return newHead;
    }
};