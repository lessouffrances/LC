

// Time: O(N), each node was visited once
// Space: O(h), h = height of the tree

class Solution 
{
    public:
    void recoverTree(TreeNode* root)
    {
        if (!root) return;
        inOrderTraverse(root);
        if (firstPos && secondPos) swap(firstPos->val, secondPos->val);
        return;
    }
    private:
    TreeNode* predecessor;
    TreeNode* firstPos;
    TreeNode* secondPos;

    void inOrderTraverse(TreeNode* node)
    {
        if (!node) return;

        inOrderTraverse(node->left);
        if (predecessor != nullptr && node->val <= predecessor->val) {
            if (!firstPos) {
                firstPos = predecessor;
            }
            secondPos = node;
        }
        predecessor = node;
        inOrderTraverse(node->right);
    }

};