

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        // res need to collect the last one on each level
        vector<int> res;

        while (!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                if (i == size-1) {
                    res.push_back(node->val);
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};