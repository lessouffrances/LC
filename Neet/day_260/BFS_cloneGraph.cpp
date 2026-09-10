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

        // want to build this link by some traversal thru the graph
        unordered_map<Node*, Node*> oldToNew;
        Node* clonedRoot = Node(node->val);
        oldToNew[node] = cloneRoot;

        queue<Node*> q;
        while (!q.empty()) {
            auto oldNode = q.front();
            q.pop();

            for (Node* neighbor : oldNode->neighbors) {
                if (!oldToNew.count(neighbor)) {
                    oldToNew[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                oldToNew[oldNode].push_back(oldToNew[neighbor]);
            }
        }
        return clonedRoot;
    }
};