

class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i=0; i<lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1) < lists.size() ? lists[i+1] : nullptr;
                ListNode* merged = mergeTwoLL(l1, l2);
                mergedLists.push_back(merged);
            }
            lists = mergedLists;
        }
        return lists[0];
    }

    private:
    ListNode* mergeTwoLL(ListNode* l1, ListNode* l2)
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

        if (l1) {
            curr->next = l1;
        }
        if (l2) {
            curr->next = l2;
        }
       return dummy->next;
    }
};