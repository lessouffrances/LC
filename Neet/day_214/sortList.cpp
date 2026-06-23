class Solution 
{
    public:
    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next) return head;

        ListNode* mid = getMiddleOfLL(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // cut off

        left = sortList(left);
        right = sortList(right);
        return merge2LL(left, right);
    }
    private:
    ListNode* merge2LL(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;
        return dummy->next;
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