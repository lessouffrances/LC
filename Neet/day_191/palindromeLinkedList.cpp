
//                
// 1 -> 2 -> 2 -> 1
//           s
//                    f

// 1 -> 2 -> 2 -> 1
// 1 -> 2
class Solution 
{
    public:
    bool isPalindrome(ListNode* head) 
    {
        if (!head) return true;

        // go the middle 
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow will land on the starting pt of the second half
        ListNode* second = reverseLL(slow);

        ListNode* curr = head;
        while (second) {
            if (curr->val != second->val) return false;
            curr = curr->next;
            second = second->next;
        }
        return true;
    }
    private:
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};