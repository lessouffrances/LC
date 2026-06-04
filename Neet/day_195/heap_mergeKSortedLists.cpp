
class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        auto comp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };

        // maintain a minheap that contains ListNode
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for (auto& node : lists) {
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next) pq.push(node->next);
        }

        return dummy->next;
    }
};