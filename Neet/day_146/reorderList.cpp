

// 1 -> 2 -> 3 -> 4 -> 5
//           s
//                     f

// 1 -> 2 -> 3
// 5 -> 4

// Time: O(N)
// Space: O(1)

class Solution 
{
    public:
    void reorderList(ListNode* head) 
    {
        if (!head) return;

        // find the middle
        ListNode* mid = findMiddle(head);
        ListNode* first = head;
        ListNode* second = mid->next;
        mid->next = nullptr;

        // reverse the second;
        ListNode* reversedSecond = reverseLL(second);

        // merge 2 LL in-place
        while (first && reversedSecond) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = reversedSecond->next;

            first->next = reversedSecond;
            reversedSecond->next = tmp1;

            first = tmp1;
            reversedSecond = tmp2;
        }
    }

    private:
    ListNode* reverseLL(ListNode* head)
    {
        if (!head) return nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* findMiddle(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
