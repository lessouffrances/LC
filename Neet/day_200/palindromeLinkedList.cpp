class Solution 
{
    public:
    bool isPalindrome(ListNode* head) 
    {
        if (!head || !head->next) return true;

        // go to the middle of the LL
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow will be at the middle of this LL
        ListNode* reversedSecond = reverseLL(slow);

        // two-pointer
        ListNode* curr = head;
        while (reversedSecond) {
            if (reversedSecond->val == curr->val) {
                reversedSecond = reversedSecond->next;
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
        if (!head || !head->next) return head;

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
};