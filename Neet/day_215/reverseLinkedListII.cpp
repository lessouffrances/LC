//         1,  2,3,4,  5
// head = [1,  2,  3,  4,          5], left = 2, right = 4
//         p  ch    ct->nullptr   nxt
class Solution 
{
    public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        // we need to take n-2 steps to the prev
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = dummy;
        for (int i=0; i<left-1; i++) {
            p = p->next;
        }
        // after the forloop exits, the p will be at the right pos
        ListNode* ch = p->next;
        // go to the ct from ch for (right-left) steps
        ListNode* ct = ch;
        for (int i=0; i<(right-left); i++) {
            ct = ct->next;
        }
        // after the forloop exits, the ct will be at the right pos
        ListNode* nxt = nullptr;
        if (ct->next) nxt = ct->next;
        ct->next = nullptr; // cut off

        // reverse the chunk
        reverseLL(ch);

        // reconnect
        p->next = ct;
        ch->next = nxt;
        return dummy->next;
    }

    private:
    ListNode* reverseLL(ListNode* head)
    {
        if (!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};