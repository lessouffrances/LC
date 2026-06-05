
class Solution 
{
    public:
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr && curr->next) {
            // save nextPair
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            // reconnect
            second->next = curr;
            curr->next = nextPair;
            prev->next = second;

            // update pointers
            prev = curr;
            curr = nextPair;
        }
        return dummy->next;
    }
};