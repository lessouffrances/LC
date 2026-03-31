

// 1 -> 2 -> 3 -> 4
// f
//     s

// Time: O(N) — one recursive call per pair, visiting each node once.
// Space: O(N) — recursive call stack depth is n/2 pairs, which is O(n).
class Solution 
{
    public:
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head || !head->next) return head;

        ListNode* first = head;
        ListNode* second = head->next;

        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};