




// 1 -> 2 -> 3 -> 4 -> 5
// 1 -> 5 -> 2 -> 4 -> 3


class Solution {
public:
    void reorderList(ListNode* head) {
        // find middle 
        ListNode* slow = head; //1
        ListNode* fast = head->next; //2 
        while (fast && fast->next) {  //t t
            slow = slow->next; //2 3
            fast = fast->next->next; //4 nullptr 
        }

        ListNode* second = slow->next; //4
        slow->next = nullptr; // split the LL at 3=> 1 -> 2 -> 3 and 4 -> 5

        // reverse the second 
        ListNode* prev = nullptr; 
        while (second) { 
            ListNode* temp = second->next; 
            second->next = prev; 
            prev = second; 
            second = temp; 
        }
        // prev became: 5 -> 4
        
        // merge two halves
        ListNode* first = head;// 1
        second = prev; // 5 -> 4
        while (second) {
            ListNode* temp1 = first->next; // 2  3
            ListNode* temp2 = second->next;// 4  nullptr

            first->next = second; // 1 -> 4  
            second->next = temp1; // 1 -> 4 -> 2

            first = temp1; //2
            second = temp2; //4
        }
    }
};