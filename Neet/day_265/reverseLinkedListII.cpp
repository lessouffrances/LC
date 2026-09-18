
// head = [1,2,3,4,5], left = 2, right = 4

//       2     4
//    b
// d->1->2->3->4->5
//    1->4->3->2->5

// go to the left-1 node, memorize it as before
// go to the left node, memorize it as nt, the new tail of the reversed chunk
// go to the right and right+1 node, memorize right as nh and right+1 as after, 
// cut off the link between nh and after
// run reverseLL(nt)
// before->next = reverseLL(nt)
// nt->next = after

class Solution 
{
    public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* before = dummy;

        for (int i=0; i<left-1; i++) {
            before = before->next;
        }
        ListNode* nt = before->next;
        
        // start from before
        ListNode* nh = before;
        for (int i=0; i<(right-left+1); i++) {
            nh = nh->next;
        }
        ListNode* after = nh->next;
        nh->next = nullptr;

        before->next = reverseLL(nt);
        nt->next = after;

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