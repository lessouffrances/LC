

class Solution 
{
    public:
    bool isPalindrome(ListNode* head) 
    {
        if (!head) return true;

        // go to the mid
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow will be at the mid of this LL
        ListNode* reverseSecondHalf = reverseLL(slow);

        ListNode* curr = head;
        while (reverseSecondHalf) {
            if (reverseSecondHalf->val == curr->val) {
                reverseSecondHalf = reverseSecondHalf->next;
                curr = curr->next;
            } else {
                return false;
            }
        }
        return true;
    }

    private:
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};