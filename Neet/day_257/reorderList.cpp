class Solution 
{
    public:
    void reorderList(ListNode* head) 
    {
        if (!head || !head->next) return;

        ListNode* m = getMiddleOfLL(head);
        ListNode* preSecond = m->next;
        m->next = nullptr;

        ListNode* second = reverseLL(preSecond);
        ListNode* first = head;

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
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode* getMiddleOfLL(ListNode* head)
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