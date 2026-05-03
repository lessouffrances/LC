class Solution 
{
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if (!headA || !headB) return nullptr;
        
        // inner loop and outer loop
        while (headA != nullptr) {
            ListNode* pB = headB;
            while (pB) {
                if (headA == pB) {
                    return headA;
                }
                pB = pB->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};