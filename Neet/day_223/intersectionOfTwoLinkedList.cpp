class Solution 
{
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if (!headA || !headB) return nullptr;

        while (headB) {
            ListNode* pA = headA;
            while (pA) {
                if (pA == headB) {
                    return pA;
                }
                pA = pA->next;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};