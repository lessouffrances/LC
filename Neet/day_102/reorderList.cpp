





//      p    s         f
// 1 -> 2 -> 3 -> 4 -> 5
// 1 -> 5 -> 2 -> 4 -> 3



// f
// 1 -> 2
// s
// 5 -> 4 -> 3



class Solution 
{
    public:
    void reorderList(ListNode* head) 
    {
        if (!head) return;

        // find middle;
        ListNode* slow = head; //1
        ListNode* fast = head; //1
        while (fast && fast->next) { //1 && 2, 3 && 4
            slow = slow->next; //2 3
            fast = fast->next->next; //3 5
        }

        // reverse the 2nd LL
        ListNode* second = reverseLinkedList(slow);

        // merge 2 LL in-place
        ListNode* first = head;
        while (second->next) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
    private:
    ListNode* reverseLinkedList(ListNode* head)
    {
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