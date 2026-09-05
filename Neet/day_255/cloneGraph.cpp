/*
// Definition for a Node.
class Node {
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
*/

class Solution 
{
    public:
    Node* cloneGraph(Node* node) 
    {
        if (!node) return node;
        queue<Node*> q;
        unordered_map<Node*, Node*> oldToNew;

        Node* cloneRoot = new Node(node->val);
        oldToNew[node] = cloneRoot;
        q.push(node);

        while (!q.empty()) {
            Node* oldNode = q.front();
            q.pop();
            for (Node* neighbor : oldNode->neighbors) {
                // if this node was not mapped yet
                if (!oldToNew.count(neighbor)) {
                    // map it old to new
                    oldToNew[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                oldToNew[oldNode]->neighbors.push_back(oldToNew[neighbor]);
            }
        }
        return cloneRoot;
    }
};