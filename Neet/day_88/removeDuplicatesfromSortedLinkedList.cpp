/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // 1 1 2 3 3
 class Solution 
 {
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0); // dummy does not move
        ListNode* newHead = dummy; // this newhead starts from dummy, but will move
        
        while (head) { // 1  2  3
            while (head->next && head->val == head->next->val) {  // 1==1  3==3
                head =  head->next;  // 1  3  
            }
 
            ListNode* newNode = new ListNode(head->val);  // 1  2  3
            newHead->next = newNode; // 0->1->2->3
            newHead = newHead->next; // 1  2  3

            head = head->next;  // 2  3  nullptr
        }

        return dummy->next;
    }
};