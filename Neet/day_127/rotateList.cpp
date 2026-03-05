class Solution 
{
    public:
    //         0 1 2 3 4 
    // head = [1,2,3,4,5], k = 2
    // [4,5,1,2,3]
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head) return nullptr;

        // get the size of the LL
        ListNode* curr = head;
        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }

        // get effective k
        k = k % length;
        if (k == 0) return head;

        // go the new tail, at idx (length - k - 1)
        ListNode* nt = head;
        for (int i=0; i<length-k-1; i++) {
            nt = nt->next;
        }
        ListNode* nh = nt->next;
        nt->next = nullptr;

        // from nh, go to old tail
        ListNode* ot = nh;
        while (ot->next) {
            ot = ot->next;
        }

        ot->next = head;
        return nh;
    }
};