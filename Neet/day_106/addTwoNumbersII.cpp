



// 7 -> 2 -> 4 -> 3
//      5 -> 6 -> 4
// 7    8    0    7

class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> deck1;
        stack<int> deck2;
        
        while (l1) {
            deck1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            deck2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* newHead = nullptr;

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