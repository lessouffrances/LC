class Node 
{
    public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution 
{
    public:
    Node* cloneGraph(Node* node) 
    {
        if (!node) return nullptr;

        queue<Node*> q;
        q.push(node);
        // deep copy the root node
        Node* newRoot = new Node(node->val);
        oldToNew[node] = newRoot;

        while (!q.empty()) {
            auto oldNode = q.front();
            q.pop();

            for (Node* neighbor : oldNode->neighbors) {
                if (!oldToNew.count(neighbor)) {
                    // deep copy the neighbor node
                    Node* newNeighbor = new Node(neighbor->val);
                    oldToNew[neighbor] = newNeighbor;
                    q.push(neighbor);
                }

                oldToNew[oldNode]->neighbors.push_back(oldToNew[neighbor]);
            }
        }
        return newRoot;
    }
    private:
    unordered_map<Node*, Node*> oldToNew;
};