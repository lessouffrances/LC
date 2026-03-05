
 
class Solution 
{
    public:
    // head = [1,2,3,4]
    // [2,1,4,3]

    // head = [1,2,3]
    // [2,1,3]
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // swap
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // move the prev by 2
            prev = first;
        }
        return dummy->next;
    }

    // recursion approach
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head || !head->next) return head;

        ListNode* first = head;
        ListNode* second = head->next;
        
        // first's next will be attached to the result of swapping the remaining portion
        first->next = swapPairs(second->next);
        // second swap with the first
        second->next = first;

        return second;
    }
};