class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;
        // customize the comparator
        // [] => anything to be catch outside this scope?
        // () the subject to compare
        // { } return the desired sequence
        auto comp = [](const ListNode* node1, const ListNode* node2){
            return node1->val > node2->val;
        };
        // STL: T, container<T>, comparator
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        // push all heads of LLs onto the pq
        for (auto& h : lists) {
            if (h) pq.push(h);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (!pq.empty()) {
            auto node = pq.top(); // the smallest one
            pq.pop();

            curr->next = node;
            curr = curr->next;
            if (node->next) pq.push(node->next);
        }
        return dummy->next;
    }
};