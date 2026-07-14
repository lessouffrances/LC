class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;

        // write a comparator to sort the ListNode on a heap
        auto comp = [](const ListNode* node1, const ListNode* node2) {
            return node1->val > node2->val; // put smaller vals on top
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        // push all heads onto the pq
        for (auto& head : lists) {
            if (head) pq.push(head);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        // 1. continue push all the nextNode onto the pq
        // 2. connect to the curr 
        while (!pq.empty()) {
            auto node = pq.top();
            curr->next = node;
            pq.pop();
            curr = curr->next;
            if (node->next) pq.push(node->next);
        }
        return dummy->next;
    }
};