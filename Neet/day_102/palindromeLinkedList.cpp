


//           s
// 1 -> 2 -> 3 -> 3 -> 2 -> 1

class Solution 
{
    public:
    bool isPalindrome(ListNode* head) 
    {
        // find middle
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // cut at middle
        ListNode* secondPtr = slow->next;
        slow->next = nullptr;

        // reverse the 2ns half
        ListNode* second = reverseLinkedList(secondPtr);

        // compare value
        


        
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