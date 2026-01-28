class Solution 
{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        int idx = 0;
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (level.empty()) {
                idx++;
                continue;
            }

            if (idx % 2 != 0) {
                reverse(level.begin(), level.end());
            } 
            res.push_back(level);
            idx++;
        }
        return res;
    }
};