








// 1 -> 2 -> 3 -> 4 -> 5


// 4 -> 5 -> 1 -> 2 -> 3

class Solution 
{
    public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head) return nullptr;

        // get the length of the LL
        ListNode* curr = head;
        int length = 0; // 5
        while (curr) { // 1  2  3  4  5
            length++; // 1  2  3  4  5
            curr = curr->next;// 2  3  4  5  nullptr
        } 
        k = k % length; // the effective k = 2
        if (k == 0) return head;

        // the newTail is located at length - k - 1 pos of the original LL 
        ListNode* newTail = head; // 1
        int i = 0;
        while (i < length - k - 1) {// 1<3  2<3
            newTail = newTail->next; // 2  3
            i++;// 2 3
        }
        ListNode* newHead = newTail->next; // 4

        ListNode* originalTail = newHead;// 4
        while (originalTail->next) { // 5  nullptr
            originalTail = originalTail->next; // 5
        }

        originalTail->next = head;
        newTail->next = nullptr;

        return newHead;
    }
};