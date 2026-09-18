


class Solution 
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {

        auto comp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq{comp};
        // seed all heads
        for (auto& head : lists) {
            if (head) pq.push(head);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            if (node->next) pq.push(node->next);
            
            curr->next = node;
            curr = curr->next;
            
        }
        return dummy->next;
    }
};