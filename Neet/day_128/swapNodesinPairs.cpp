

class Solution 
{
    public:
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head) return nullptr;

        ListNode* first = head;
        ListNode* second = head->next;

        first->next = swapPairs(second->next); // swap intact pairs
        second->next = first;
        return head;
    }
};