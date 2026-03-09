

// 0    1    2    3    4
// 1 -> 2 -> 3 -> 4 -> 5, n=2, length=5
// edge cases:
// edge case 1) delete head, when n = length
// edge case 2) delete the last node when n=1

// indexToDelete = length-n
// go to the (length-n-1) node, prev
// go to the (length+1-n) node, next

// reconnect the prev with the next


// Time: O(N)
// Space: O(1)

class Solution 
{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (!head) return nullptr;
        ListNode* curr = head;
        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }

        if (n > length) return nullptr;

        // edge case 1: delete the first one
        if (n == length) {
            return head->next;
        }

        // edge case 2: delete the last one
        if (n == 1) {
            curr = head;
            while (curr->next->next) {
                curr = curr->next;
            }
            curr->next = nullptr;
            return head;
        }
        
        // go to the prev
        curr = head;
        for (int i=0; i<length-n-1; i++) {
            curr = curr->next;
        }
        ListNode* prev = curr;
        // go to the next
        ListNode* next = curr->next->next;

        prev->next = next;
        return head;
    }
};