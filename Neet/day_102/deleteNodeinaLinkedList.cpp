





class Solution 
{
    public:
    void deleteNode(ListNode* node) 
    {
        if (!node) return;

        // if node is the last node
        if (!node->next) {
            delete node;
            return;
        }

        node->val = node->next->val;
        // delete node->next;
        ListNode* saved = node->next->next;
        delete node->next;
        
        node->next = saved;

    }
};