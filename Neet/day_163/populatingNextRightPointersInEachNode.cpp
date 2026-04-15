/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

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

            vector<Node*> levelNodes;
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();
                levelNodes.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // set the next pointer to the right one
            for (int i=0; i<size-1; i++) {
                levelNodes[i]->next = levelNodes[i+1];
            }
        }
        return root;
    }
};