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
        return dfs(node);
    }

    private:
    unordered_map<Node*, Node*> oldToNew;
    Node* dfs(Node* node)
    {
        if (!node) return node;
        if (oldToNew.count(node)) return oldToNew[node];

        // copy this node
        Node* newNode = new Node(node->val);
        oldToNew[node] = newNode;

        for (auto& nb : node->neighbors) {
            newNode->neighbors.push_back(dfs(newNbNode));
        }
        return newNode;
    }
};