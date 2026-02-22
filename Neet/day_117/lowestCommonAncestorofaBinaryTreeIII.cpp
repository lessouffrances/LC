
// Definition for a Node.
class Node 
{
    public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution 
{
    public:
    Node* lowestCommonAncestor(Node* p, Node * q) 
    {
        unordered_set<Node*> commonAncestor;

        // collect all p's ancestors
        Node* curr = p;
        while (curr) {
            commonAncestor.insert(curr);
            curr = curr->parent;
        }

        curr = q;
        while (curr) {
            if (commonAncestor.count(curr)) {
                return curr;
            }
            curr = curr->parent;
        }
        return nullptr;
    }
};
