



// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // base case: check if k nodes still remain
        ListNode* node = head;
        for (int i=0; i<k; i++) {
            if (!node) return head;
            node = node->next;
        }

        // reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i=0; i<k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};