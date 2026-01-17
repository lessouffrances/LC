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
                mergedLists.push_back(merge2Lists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
    private:
    ListNode* merge2Lists(ListNode* head1, ListNode* head2) 
    {
        if (!head1) return head2;
        if (!head2) return head1;

        ListNode* curr1 = head1;
        ListNode* curr2 = head2;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (curr1 && curr2) {
            if (curr1->val <= curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }

        if (curr1) {
            curr->next = curr1;
        }
        if (curr2) {
            curr->next = curr2;
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};