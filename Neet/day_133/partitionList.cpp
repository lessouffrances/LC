
// head = [1,4,3,2,5,2], x = 3
// lessDummy->1->2->2
// greaterDummy->4->3->5

// Time: O(N)
// Space: O(N)

class Solution 
{
    public:
    ListNode* partition(ListNode* head, int x) 
    {
        if (!head) return nullptr;

        ListNode* lessDummy = new ListNode();
        ListNode* greaterDummy = new ListNode();
        ListNode* less = lessDummy;
        ListNode* greater = greaterDummy;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        // reconnect
        less->next = greaterDummy->next;
        greater->next = nullptr;
        return lessDummy->next;
    }
};