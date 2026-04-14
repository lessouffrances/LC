



class Solution 
{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;

        // if it is odd level, reverse
        int level = 0;
        while (!q.empty()) {
            vector<int> levelNodes;
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                levelNodes.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (level % 2 != 0) {
                reverse(levelNodes.begin(), levelNodes.end());
            }
            res.push_back(levelNodes);
            level++;
        }

        return res;
    }
};