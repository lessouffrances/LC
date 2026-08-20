class Solution 
{
    public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // base case
        if (!head || !head->next) return head;

        // if there are k nodes left
        ListNode* curr =  head;
        for (int i=0; i<k; i++) {
            if (!curr) return head;
            curr = curr->next;
        }

        // if the code can be executed until here
        // there are indeed k nodes left
        curr = head;
        ListNode* prev = nullptr;
        for (int i=0; i<k; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};