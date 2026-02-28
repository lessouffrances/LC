
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode() : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
    public:
    void flatten(TreeNode* root) 
    {
        if (!root) return;
        TreeNode* curr = root;
        stack<TreeNode*> deck;

        while (curr) {
            // if not our desired direction
            if (curr->left) {
                // push onto stack for future use
                if (curr->right) {
                    deck.push(curr->right);
                }

                // reconnect
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