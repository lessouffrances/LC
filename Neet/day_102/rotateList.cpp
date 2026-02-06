

//           nt   nh
// 1 -> 2 -> 3 -> 4 -> 5, k=2

// 4 -> 5 -> 1 -> 2 -> 3
class Solution 
{
    public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head) return nullptr;
        
        ListNode* curr = head;
        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }

        // effective k 
        if (k % length == 0) return head;
        k = k % length;

        // the new tail is at length - k pos 
        // go to the new tail and reconnect 

        int i = 1;
        ListNode* newTail = head; //1 
        while (i < length - k) { //1<3, 2<3
            newTail = newTail->next; // 2 3
            i++;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        // go to original tail
        ListNode* originalTail = newHead;
        while (originalTail->next) {
            originalTail = originalTail->next;
        }
        originalTail->next = head;
        return newHead;
    }
};