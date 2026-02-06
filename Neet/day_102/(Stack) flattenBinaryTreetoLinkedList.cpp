
 class Solution 
 {
    public:
        void flatten(TreeNode* root) {
            if (!root) return;
    
            TreeNode* curr = root;
            stack<TreeNode*> deck;
            while (curr) {
                if (curr->left) {
                    // save right
                    if (curr->right) {
                        deck.push(curr->right);
                    }
    
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