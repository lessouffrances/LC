

class Solution 
{
    public:
    Node* cloneGraph(Node* node) 
    {
        if (!node) return nullptr;
        return dfs(node);
    }

    private:
    unordered_map<Node*, Node*> oldToNew;

    Node* dfs(Node* node)
    {
        if (oldToNew.count(node)) return oldToNew[node];

        Node* cloneNode = new Node(node->val);
        oldToNew[node] = cloneNode;

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(dfs(neighbor));
        }
        return cloneNode;
    }
};