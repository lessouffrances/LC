
//    h
// p<-1<-2->3->4->5
//          c
//       p  


//       h
//    2->1->3->4->5     head->next = reverseKGroup(curr, k)
//          c
//    p 

//              h
//    2->1->  <-3<-4->5     head->next = reverseKGroup(curr, k)
//                    c
//                 p  

//                    h
//           2->1->4->3->5     head->next = reverseKGroup(5, k)
//                       c
//                 p 

//                       h
//           2->1->4->3->5     head->next = reverseKGroup(5, k)
//                       c
//                     p 


class Solution 
{
    public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // base case
        if (!head || !head->next) return head;

        // if there are k nodes left
        ListNode* curr = head;
        for (int i=0; i<k; i++) {
            if (!curr) return head;
            curr = curr->next;
        }

        // fact: there are k nodes left
        curr = head;
        ListNode* prev = nullptr;
        for (int i=0; i<k; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head->next = reverseKGroup(curr, k);
        return prev;
    }
};