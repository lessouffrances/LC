


//                s
// 1 -> 2 -> 3 -> 3 -> 2 -> 1

class Solution 
{
    public:
    bool isPalindrome(ListNode* head) 
    {
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the 2nd half
        ListNode* second = reverseLinkedList(slow);

        // compare value
        while (second) {
            if (second->val != head->val) {
                return false;
            }
            second = second->next;
            head = head->next;
        }

        return true;
    }
    private:
    ListNode* reverseLinkedList(ListNode* head)
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