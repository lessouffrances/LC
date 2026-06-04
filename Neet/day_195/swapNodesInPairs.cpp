


// [1,2,3,4]
//  prev   curr
// dummy -> 1 -> 2 -> 3 -> 4

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
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            // reconnect
            second->next = curr;
            curr->next = nextPair;
            prev->next = second;

            // move forward
            prev = curr;
            curr = nextPair;
        }
        return dummy->next;
    }
};