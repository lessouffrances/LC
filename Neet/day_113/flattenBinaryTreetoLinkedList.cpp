// struct TreeNode
// {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(): val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
// };

class Solution 
{
    public:
    void flatten(TreeNode* root) 
    {
        if (!root) return;

        TreeNode* curr = root;
        stack<TreeNode*> deck;

        while (curr) {
            if (curr->left) {
                if (curr->right) {
                    deck.push(curr->right);
                }
                curr->right = curr->left;
                curr->left = nullptr;
            }

            if (!curr->right && !deck.empty()) {
                TreeNode* saved = deck.top();
                deck.pop();
                curr->right = saved;
            }
            curr = curr->right;
        }
    }
};