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

 // length of the LL
 // effective k

 class Solution 
 {
    public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head) return nullptr;

        int len = getLengthOfLL(head);
        int effectiveK = k % len;
        if (effectiveK == 0) return head;

        // effective K means that you need to count from the tail to the head
        // for k nodes and do a reconnect
        // k=2, len=5
        // 1->2->3->4->5
        //       s  f
        // 4->5->1->2->3
        // need to walk from the head for __len-k__ nodes == len-k-1 steps?
        ListNode* second = head;
        for (int i=0; i<len-effectiveK-1; i++) {
            second = second->next;
        }
        ListNode * first = second->next;

        // go to the tail
        ListNode* tail = first;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;
        second->next = nullptr;
        return first;
    }

    private:
    int getLengthOfLL(ListNode* head)
    {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        } 
        return len;
    }
};