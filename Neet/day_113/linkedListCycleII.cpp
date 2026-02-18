

class Solution 
{
    public:
    ListNode *detectCycle(ListNode *head) 
    {
        if (!head) return nullptr;

        unordered_set<ListNode*> seen;

        while (head) {
            if (seen.count(head)) {
                return head;
            } else {
                seen.insert(head);
                head = head->next;
            }
        }
        return nullptr;
    }
};