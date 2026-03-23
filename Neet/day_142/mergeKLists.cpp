

// Time: O()
// M for total number of nodes, and N for the number of LL
// Space: O(log N)

class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> merged;
            for (int i=0; i<lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1 >= lists.size() ? nullptr : lists[i+1];
                ListNode* mergedOne = merge2LL(l1, l2);
                merged.push_back(mergedOne);
            }
            lists = merged;
        }
        return lists[0];
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
};