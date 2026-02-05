









class Solution 
{
    public:
    void deleteNode(ListNode* node) 
    {
        if (!node->next) {
            delete node;
            return;
        }

        node->val = node->next->val;
        ListNode* nextNext = node->next->next;
        node->next = nextNext;
    }
};