class Solution 
{
    public:
    ListNode* reverseList(ListNode* head) 
    {
        if (!head) return nullptr;

        // move
        ListNode* curr = new ListNode(head->val); 
        head = head->next;

        while (head) {
            ListNode* node = new ListNode(head->val);
            node->next = curr;
            curr = node;

            head = head->next;
        }
        return curr;
    }
};