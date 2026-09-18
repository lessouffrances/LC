

//         1 2 3 4 5
// head = [1,2,3,4,5], n = 2
// go to the (size-n)-th node, memorize it as before
// go to the before->next->next, memorize it as after
// before->next = after

class Solution 
{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (!head) return head;
        int size = getSizeOfLL(head);
        if (size == n) return head->next;

        ListNode* before = head;
        for (int i=0; i<size-n-1; i++) {
            before = before->next;
        }

        ListNode* after = before->next ? before->next->next : nullptr;
        before->next = after;
        return head;
    }

    private:
    int getSizeOfLL(ListNode* head)
    {
        ListNode* curr = head;
        int size = 0;
        while (curr) {
            size++;
            curr = curr->next;
        }
        return size;
    }
};