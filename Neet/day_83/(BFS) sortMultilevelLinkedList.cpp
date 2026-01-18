class Node 
{
    public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution 
{
    public:
    Node* sortMultilevelList(Node* head) 
    {
        if (!head) return nullptr;

        // Collect nodes in BFS order
        vector<Node*> nodes;
        queue<Node*> q;
        q.push(head);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            nodes.push_back(node);

            if (node->next) {
                q.push(node->next);
            }
            if (node->child) {
                q.push(node->child);
            }
        }

        vector<int> vals;
        for (int i=0; i<nodes.size(); i++) {
            vals.push_back(nodes[i]->val);
        }

        sort(vals.begin(), vals.end());
        for (int i=0; i<nodes.size(); i++) {
            nodes[i]->val = vals[i];
        }

        return head;
    }
};

