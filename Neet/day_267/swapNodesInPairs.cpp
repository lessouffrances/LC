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
            ListNode* nextPairStartingNode = curr->next->next;
            ListNode* secondNodeInThisPair = curr->next;

            secondNodeInThisPair->next = curr;
            curr->next = nextPairStartingNode;
            prev->next = secondNodeInThisPair;

            prev = curr;
            curr = nextPairStartingNode;
        }
        return dummy->next;
    }
};