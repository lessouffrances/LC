

// Time: O(N * logM), where M is the number of lists, and N is the length of a LL
// Space: O(logM), where M is the number of lists
class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> merged;
            for (int i=0; i<lists.size(); i+=2) {
                ListNode* list1 = lists[i];
                ListNode* list2 = (i+1) >= list.size() ? nullptr : lists[i+1];
                ListNode* mergedOne = mergeTwoLists(list1, list2);
                merged.push_back(mergedOne);
            }
            lists = merged;
        }
        return lists[0];
    }
    private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1) {
            curr->next = list1;
        }
        if (list2) {
            curr->next = list2;
        } 
        return dummy->next;
    }
};
        