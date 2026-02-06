






class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (!l1) return l2;
        if (!l2) return l1;

        stack<int> deck1;
        while (l1) {
            deck1.push(l1->val);
            l1 = l1->next;
        }
        stack<int> deck2;
        while (l2) {
            deck2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        int sum = carry;
        ListNode* newTail = nullptr;

        while (!deck1.empty() || !deck2.empty() || carry) {
            sum = carry;

            if (!deck1.empty()) {
                sum += deck1.top();
                deck1.pop();
            }
            if (!deck2.empty()) {
                sum += deck2.top();
                deck2.pop();
            }

            int val = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(val);
            node->next = newTail;
            newTail = node;
        }
        
        return newTail;
    }
};