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
 class Solution 
 {
     public:
     ListNode* sortList(ListNode* head) 
     {
         if (!head || !head->next) return head;
 
         ListNode* m = getMiddleOfLL(head);
         ListNode* second = m->next;
         ListNode* first = head;
         m->next = nullptr;
 
         first = sortList(first);
         second = sortList(second);
         return merge2LL(first, second);
     }
 
     private:
     ListNode* getMiddleOfLL(ListNode* head)
     {
         if (!head || !head->next) return head;
         ListNode* slow = head;
         ListNode* fast = head->next;
 
         while (fast && fast->next) {
             slow = slow->next;
             fast = fast->next->next;
         }
         return slow;
     }
 
     ListNode* merge2LL(ListNode* l1, ListNode* l2)
     {
         if (!l1) return l2;
         if (!l2) return l1;
 
         ListNode* dummy = new ListNode();
         ListNode* curr = dummy;
         while (l1 && l2) {
             if (l1->val < l2->val) {
                 curr->next = l1;
                 l1 = l1->next;
             } else {
                 curr->next = l2;
                 l2 = l2->next;
             }
             curr = curr->next;
         }
 
         curr->next = l1 ? l1 : l2;
         return dummy->next;
     }
 };