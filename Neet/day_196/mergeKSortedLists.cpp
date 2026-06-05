class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        auto comp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val; // let the ListNode with the smallest val sit on top
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        // push all the heads of LL onto the pq for start
        for (auto& node : lists) {
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (!pq.empty()) {
            auto node = pq.top();            
            pq.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next) pq.push(node->next);
        }
        return dummy->next;
    }
};