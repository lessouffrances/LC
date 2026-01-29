class Solution 
{
    public:
    void flatten(TreeNode* root)
    {
        if (!root) return;

        stack<TreeNode* > deck;
        TreeNode* curr = root;

        while (curr || !deck.empty()) {
            if (curr) {
                if (curr->right) {
                    deck.push(curr->right);
                }

                // connect left to right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            
            if (!curr->right && !deck.empty()) {
                TreeNode* savedNode = deck.top();
                deck.pop();
                curr->right = savedNode;
            }

            curr = curr->right;
        }
    }
};