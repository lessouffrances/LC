

 
//     1    2  3  4    5
//     p    h     t    nxt
// d-> 1->  2->3->4  ->5, left=2, right=4
// save p, save nxt
// set t->next = nullptr
// reverse h
// set p->next = t
// set h->next = nxt

class Solution 
{
    public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i=0; i<left-1; i++) {
            prev = prev->next;
        }
        ListNode* h = prev->next;

        // go to tail
        ListNode* t = h;
        for (int i=0; i<(right-left); i++) {
            t = t->next;
        }
        // go to nxt
        ListNode* nxt = t->next;
        t->next = nullptr;

        // reverse the chunk
        ListNode* reversedHead = reverseLL(h);
        prev->next = reversedHead;
        h->next = nxt;
        return dummy->next;
    }

    private:
    ListNode* reverseLL(ListNode* head)
    {
        if (!head) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next;
        }
        return prev;
    }
};
