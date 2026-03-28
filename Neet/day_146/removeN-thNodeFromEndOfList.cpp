


// 1 -> 2 -> 3 -> 4 -> 5

// Time: O(N)
// Space: O(1)

class Solution 
{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (!head) return nullptr;

        // get the length of the LL
        int len = getLength(head);
        // edge case
        if (n > len) return nullptr;

        // if remove the first node
        if (n == len) {
            ListNode* next = head->next;
            head->next = nullptr;
            return next;
        }

        // if remove the last node
        if (n == 1) {
            // go the second last node
            ListNode* curr = head;
            while (curr->next->next) {
                curr = curr->next;
            }
            curr->next = nullptr;
            return head;
        }

        // remove a node inbetween
        // stop at the prev node
        int m = len-n-1; // steps we should take
        ListNode* curr = head;
        while (m > 0) {
            m--;
            curr = curr->next;
        }

        // bypass next
        ListNode* next = curr->next->next;
        curr->next = next;
        return head;
    }
    private:
    int getLength(ListNode* head)
    {
        if (!head) return 0;
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};