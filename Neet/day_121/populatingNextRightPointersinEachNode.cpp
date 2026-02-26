

class Solution 
{
    public:
    Node* connect(Node* root) 
    {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            vector<Node*> currLevel; // to collect nodes
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();
                currLevel.push_back(node);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            linkEachLevel(currLevel);
        }
        return root;
    }
    private:
    // 1->2->3->4
    void linkEachLevel(vector<Node*> nodes)
    {
        int n = nodes.size();
        for (int i=0; i<n-1; i++) {
            nodes[i]->next = nodes[i+1];
        }
        nodes[n-1]->next = nullptr; // last to nullptr
    }
};