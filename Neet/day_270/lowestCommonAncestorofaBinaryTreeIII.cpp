/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution 
{
    public:
    Node* lowestCommonAncestor(Node* p, Node * q) 
    {
        Node* curr = p;
        
        // collect all ancestors of p
        unordered_set<Node*> ancestors;
        while (curr) {
            ancestors.insert(curr);
            curr = curr->parent;
        }

        curr = q;
        while (curr) {
            if (ancestors.count(curr)) return curr;
            curr = curr->parent;
        }
        return nullptr;
    }
};