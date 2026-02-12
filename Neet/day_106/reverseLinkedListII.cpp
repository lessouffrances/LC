







class Solution 
{
    public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (!head || right == left) return head;

        // let prev go to the one before left
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i=0; i<left-1; i++) {
            prev = prev->next;
        }

        // reverse the sublist
        ListNode* curr = prev->next;
        for (int i=0; i<right-left; i++) {
            ListNode* temp = curr->next;
            curr->next = temp->nenxt;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy->next;
    
    }
};