/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
    public:
    int maxDepth(Node* root) 
    {
        return dfs(root);
    }

    // postorder
    long long dfs(Node* node)
    {
        if (!node) return 0;
        
        long long maxPath = 0;
        for (auto& child : node->children) {
            maxPath = max(maxPath, dfs(child));
        }

        return 1 + maxPath;
    }
};