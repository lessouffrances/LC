



//           nt   nh
// 1 -> 2 -> 3 -> 4 -> 5, k=2
// 4 -> 5 -> 1 -> 2 -> 3

class Solution 
{
    public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head) return nullptr;

        // get the length of the LL
        ListNode* curr = head;
        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        } 

        // check if k is effective
        if (k % length == 0) return head;
        // get the effective k
        k = k % length;

        // go to the newTail, at the length - k - 1 pos of old LL
        ListNode* newTail = head;
        for (int i=0; i<(length-k-1); i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        // go to originalTail
        ListNode* originalTail = newHead;
        while (originalTail->next) {
            originalTail = originalTail->next;
        }
        originalTail->next = head;
        return newHead;
    }
};