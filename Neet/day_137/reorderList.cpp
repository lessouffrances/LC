
//           m
// 1 -> 2 -> 3 -> 4 -> 5

// first:
// 1 -> 2 -> 3
// second:
// 5 -> 4

// 1 -> 5 -> 2 -> 4 -> 3

// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    void reorderList(ListNode* head) 
    {
        if (!head) return;

        ListNode* mid = findMiddle(head);
        ListNode* preSecond = mid->next;
        mid->next = nullptr;
        ListNode* first = head;
        ListNode* second = reverseLL(preSecond);

        // merge 2 LL in-place!
        while (first && second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }

    }
    private:
    ListNode* reverseLL(ListNode* head)
    {
        if (!head) return nullptr;

        ListNode* curr = head;
        ListNode* prev = nullptr;

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