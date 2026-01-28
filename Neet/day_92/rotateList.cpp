









// 1 -> 2 -> 3 -> 4 -> 5   k=2
// 4 -> 5 -> 1 -> 2 -> 3 




class Solution 
{
    public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next || k==0) return head;

        // get the length of the LL
        int length = 0; //5
        // don't want to move the head now
        ListNode* curr = head;
        while (curr) {  
            length++; 
            curr = curr->next; 
        }

        // reduce k using %
        k = k % length; // 
        if (k == 0) return head;

        // step to the new tail, at (length - k - 1) pos (0-indexed)
        ListNode* newTail = head;
        for (int i=0; i<length-k-1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        // go the oldTail
        ListNode* oldTail = newHead;
        while (oldTail->next) {
            oldTail = oldTail->next;
        }

        // break and reconnect
        newTail->next = nullptr;
        oldTail->next = head;
        return newHead;
    }
    
};