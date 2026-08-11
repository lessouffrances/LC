class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;
        auto comp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val; // a minheap for LL
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq{comp};
        for (auto& head : lists) {
            if (head) pq.push(head); // will arrange the smallest upfront
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (!pq.empty()) {
            auto node = pq.top();
            curr->next = node;
            curr = curr->next;
            if (node->next) pq.push(node->next);
            pq.pop();
        }
        return dummy->next;
    }
};