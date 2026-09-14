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
        dfs(root);
        return root;
    }

    private:
    // preorder, top-down
    // given the perfect binary condition
    // a node must have both left and right children 
    void dfs(Node* node)
    {
        if (!node || !node->left) return;

        if (node->left && node->right) {
            node->left->next = node->right;
        }
        if (node->next) {
            node->right->next = node->next->left;
        }

        dfs(node->left);
        dfs(node->right);
    }
};