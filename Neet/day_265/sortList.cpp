
// mergeSort on a LL
// find the middle
// cut off the first half and the second
// recursively call on both halves
// call merge2LL

class Solution 
{
    public:
    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next) return head;   

        ListNode* first = head;
        ListNode* m = getMiddleOfLL(head);
        ListNode* second = m->next;
        m->next = nullptr;

        first = sortList(first);
        second = sortList(second);

        return merge2LL(first, second);
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

        while (l1) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }

        while (l2) {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        return dummy->next;
    }

    ListNode* getMiddleOfLL(ListNode* head)
    {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};