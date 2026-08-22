// head = d [1,2,6,3,4,5,6], val = 6
//             p         c
class Solution 
{
    public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (!head) return head;
        
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) { //1 2 6 3 4 5 6 
            if (curr->val == val) { //F F T F F F T
                curr = curr->next;//3 null
                continue;
            } 

            prev->next = curr; //1 3 4 5
            prev = prev->next; //1 2 3 4 5
            curr = curr->next; //2 6 4 5 6
        }
        prev->next = nullptr;
        return dummy->next;
    }
};