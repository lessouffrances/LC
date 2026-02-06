





// 1 -> 2 -> 3 -> 4 -> 5



// 1 -> 2 -> 3 -> 4 -> 5 -> 6

 class Solution 
 {
    public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow = head; //1
        ListNode* fast = head; //1

        while (fast && fast->next) { //1 && 2, 3 && 4, 5 && 6
            slow = slow->next; //2 3 4
            fast = fast->next->next;//3 5 null
        }
        return slow;//4
    }
};