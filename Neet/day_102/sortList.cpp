






// l              r
// 1 -> 2 -> 3 -> 4 -> 5 -> 6


class Solution 
{
    public:
    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next) return head;

        // get mid
        ListNode* mid = findMid(head);

        // assign left and right
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge2Lists(left, right);
    }
    private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
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

        curr->next = (l1) ? l1 : l2;
        return dummy->next;
    }

    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head; //1
        ListNode* fast = head->next; //2

        while (fast && fast->next) { //2 & 3, 4 && 5
            slow = slow->next; //2 3
            fast = fast->next->next; //4 6
        }

        return slow; //3
    }
};