class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<int> merged;
            for (int i=0; i<lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1 < lists.size()) ? lists[i+1] : nullptr;
                merged.push_back(merge2Lists(l1, l2));
            }
            lists = merged;
        }
        return lists[0];
    }
    private: 
    ListNode* merge2Lists(ListNode* head1, ListNode* head2)
    {
        if (!head1) return head2;
        if (!head2) return head1;

        // ListNode* curr1 = head1;
        // ListNode* curr2 = head2;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (head1 && head2) {
            if (head1->val <= head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        if (head1) {
            curr->next = head1;
        }
        if (head2) {
            curr->next = head2;
        }
        return dummy->next;
    }
};