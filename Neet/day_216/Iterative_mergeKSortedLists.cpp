/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// iterative && BF solution
// K LLs
// while we have more than 1 LL:
//    merge2LL pair by pair
// return the only 1 remaining LL

// heap solution
// use the nature of a minHeap, because the resultant LL is sorted in non-descending order
// maintain a minHeap, continuously grab the top of the minHeap and step forward

class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i=0; i<lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1) < lists.size() ? lists[i+1] : nullptr;
                ListNode* mergedOne = merge2LL(l1, l2);
                mergedLists.push_back(mergedOne);
            }
            lists = mergedLists; // go back to while
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