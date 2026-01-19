// Definition for a Node.
class Node 
{
    public:
    int val;
    Node* next;
    Node* child;
};
    
class Solution 
{
    public:
    Node* sortMultilevelLinkedList(Node* head) 
    {
        if (!head) return nullptr;
        queue<Node*> q;
        q.push(head);

        vector<Node*> bfsOrderNodes;

        // Use BFS to pull out the values, the vector to preserve the bfs order
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            bfsOrderNodes.push_back(node);

            if (node->child) {
                q.push(node->child);
            }
            if (node->next) {
                q.push(node->next);
            }
        }

        // extract the vals and sort the vals
        vector<int> vals;
        for (const auto& node : bfsOrderNodes) {
            vals.push_back(node->val);
        }
        sort(vals.begin(), vals.end());

        int idx = 0;
        for (auto& node : bfsOrderNodes) {
            node->val = vals[idx];
            idx++;
        }

        return head;
    }
};