/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution 
{
    public:
    Node* treeToDoublyList(Node* root) 
    {
        dfs(root);
        return head;
    }

    private:
    Node* prev = nullptr;
    Node* head = nullptr; // why we need to memorize head?
    void dfs(Node* node)
    {
        if (!node) return;

        dfs(node->left);

        if (prev) {
            prev->right = node;
            node->left = prev;
        } else {
            head = node;
        }
        prev = node;

        dfs(node->right);
    }
};
