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
 class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode* lessHead = new ListNode(0);
            ListNode* greaterHead = new ListNode(0);
    
            ListNode* less = lessHead;
            ListNode* greater = greaterHead;
    
            while (head) {
                if (head->val >= x) {
                    greater->next = head;
                    greater = greater->next;
                } else {
                    less->next = head;
                    less = less->next;
                }
                head = head->next;
            }
    
            greater->next = nullptr; // attach the tail 
            less->next = greaterHead->next; // connecting 2 Link Lists
            return lessHead->next;        
        }
    };