
class Solution 
{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;

        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> currLevel;

            for (int i=0; i<size; i++) {
                auto node = q.front(); 
                q.pop();
                currLevel.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (depth % 2 != 0) {
                reverse(currLevel.begin(), currLevel.end());
            }
            res.push_back(currLevel);
            depth++;
        }
        return res;
    }
};