// 1->2->3->4->5
//             f
//       s

// 1->2->3
// 5->4

class Solution 
{
    public:
    void reorderList(ListNode* head) 
    {
        if (!head || !head->next) return;

        ListNode* m = findMiddleOfLL(head);
        ListNode* secondHead = m->next;
        m->next = nullptr;

        ListNode* reversedSecondHead = reverseLL(secondHead);

        // merge 2 LL in-place
        ListNode* first = head;
        ListNode* second = reversedSecondHead;
        while (first && second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }

    private:
    ListNode* reverseLL(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    ListNode* findMiddleOfLL(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};