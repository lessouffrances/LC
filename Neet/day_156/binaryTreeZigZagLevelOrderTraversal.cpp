



class Solution 
{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (!root) return {};

        // if odd level, from right to left
        queue<TreeNode* > q;
        q.push(root);
        int level = 0;

        vector<vector<int>> res;
        while (!q.empty()) {
            int size = q.size();
            vector<int> currLevel;
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                currLevel.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (level % 2 != 0 && !currLevel.empty()) {
                reverse(currLevel.begin(), currLevel.end());
            }
            if (!currLevel.empty()) {
                res.push_back(currLevel);
            }
            level++;
        }
        return res;
    }
};