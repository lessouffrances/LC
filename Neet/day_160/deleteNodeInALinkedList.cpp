/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
    public:
    void deleteNode(ListNode* node) 
    {
        if (!node) return;
        
        // if the node is the last node
        if (!node->next) {
            delete node;
            return;
        }

        int nextVal = node->next->val;
        ListNode* next = node->next->next;
        node->val = nextVal;
        delete node->next;
        node->next = next;
        return;
    }
};