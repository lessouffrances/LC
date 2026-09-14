class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // define the comparator for the pq
        auto comp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val; 
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq{comp};

        // seed all heads 
        for (auto& ll : lists) {
            if (ll) pq.push(ll);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (!pq.empty()) {
            auto currNode = pq.top();
            curr->next = currNode;
            curr = curr->next;

            if (currNode->next) {
                pq.push(currNode->next);
            }
            pq.pop();
        }
        return dummy->next;
    }
};