class Solution 
{
    public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next) return head;
        int size = getSizeOfLL(head);
        int effectiveK = k % size;
        if (effectiveK == 0) return head;

        // will need to traverse to the (size-effectiveK)-th node
        // cut off, set next to null
        // and set the tail->next = head
        // need to memorize the size-effectiveK)-th node and the last node

        ListNode* curr = head;
        ListNode* newTail = nullptr;
        ListNode* tail = nullptr;
        for (int i=0; i<size; i++) {
            if (i == size-effectiveK-1) {
                newTail = curr;
            } else if (i == size-1) {
                tail = curr;
            }
            curr = curr->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        return newHead;
    }

    private:
    int getSizeOfLL(ListNode* head)
    {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }
};